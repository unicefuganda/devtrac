<?php

/**
 * ALL code here is taken from the Drupal core's update module and MODIFIED for
 * integration with prod_monitor. prod_check recommends that you turn the update
 * module off. prod_check provides the VERY BASIC functionality to get a list of
 * the installed modules with version info and transfer this to prod_monitor
 * over XMLRPC (alot of data here!) so that prod_monitor can do all the update
 * checking locally.
 */

/**
 * Taken from Core: modules/update/update.fetch.inc, line 25 and MODIFIED!
 *
 * Fetch project info via XML from a central server.
 */
function _prod_monitor_update_refresh($id, $projects, $site_key) {
  static $fail = array();
  global $base_url;

  // contains update_xml_parser class
  module_load_include('inc', 'update', 'update.fetch');

  $available = array();
  $data = array();

  // As replacement for DRUPAL_CORE_COMPATIBILITY since prod_check and
  // prod_monitor should be site independant.
  $core = explode('.', $projects['drupal']['info']['version']);
  $core = $core[0].'.x';

  $max_fetch_attempts = UPDATE_MAX_FETCH_ATTEMPTS;

  // Prepare object to store generated data to DB.
  $modules = new stdClass();
  $modules->id = $id;

  foreach ($projects as $key => $project) {
    $url = _prod_monitor_update_build_fetch_url($project, $site_key, $core);
    $fetch_url_base = _prod_monitor_update_get_fetch_url_base($project);
    if (empty($fail[$fetch_url_base]) || count($fail[$fetch_url_base]) < $max_fetch_attempts) {
      $xml = drupal_http_request($url);
      if (isset($xml->data)) {
        $data[] = $xml->data;
      }
      else {
        // Connection likely broken; prepare to give up.
        $fail[$fetch_url_base][$key] = 1;
      }
    }
    else {
      // Didn't bother trying to fetch.
      $fail[$fetch_url_base][$key] = 1;
    }
  }

  if ($data) {
    $parser = new update_xml_parser;
    $available = $parser->parse($data);
  }
  if (!empty($available) && is_array($available)) {
    // Record the projects where we failed to fetch data.
    foreach ($fail as $fetch_url_base => $failures) {
      foreach ($failures as $key => $value) {
        $available[$key]['project_status'] = 'not-fetched';
      }
    }
    $modules->available = serialize($available);
    watchdog('prod_monitor', 'Attempted to fetch information about all available new releases and updates for %link.', array('%link' => _prod_monitor_get_url($id)), WATCHDOG_NOTICE, l(t('view'), 'admin/reports/prod-monitor/'.$id.'/updates'));
  }
  else {
    watchdog('prod_monitor', 'Unable to fetch any information about available new releases and updates for %link.', array('%link' => _prod_monitor_get_url($id)), WATCHDOG_ERROR, l(t('view'), 'admin/reports/prod-monitor/'.$id.'/updates'));
  }
  // Whether this worked or not, we did just (try to) check for updates.
  $modules->lastupdate = time();
  $result = drupal_write_record('prod_monitor_site_modules', $modules, array('id'));
  if (!$result) {
    watchdog('prod_monitor', 'Could not update module data for %link', array('%link' => _prod_monitor_get_url($id)), WATCHDOG_ERROR);
  }

  return $available;
}

/**
 * Taken from Core: modules/update/update.fetch.inc, line 107 and MODIFIED!
 *
 * Generates the URL to fetch information about project updates.
 *
 * This figures out the right URL to use, based on the project's .info file
 * and the global defaults. Appends optional query arguments when the site is
 * configured to report usage stats.
 *
 * @param $project
 *   The array of project information from update_get_projects().
 * @param $site_key
 *   The anonymous site key hash (optional).
 *
 * @see update_refresh()
 * @see update_get_projects()
 */
function _prod_monitor_update_build_fetch_url($project, $site_key = '', $core) {
  $name = $project['name'];
  $url = _prod_monitor_update_get_fetch_url_base($project);
  $url .= '/'. $name .'/'. $core;
  // Only append a site_key and the version information if we have a site_key
  // in the first place, and if this is not a disabled module or theme. We do
  // not want to record usage statistics for disabled code.
  if (!empty($site_key) && (strpos($project['project_type'], 'disabled') === FALSE)) {
    $url .= (strpos($url, '?') === TRUE) ? '&' : '?';
    $url .= 'site_key=';
    $url .= rawurlencode($site_key);
    if (!empty($project['info']['version'])) {
      $url .= '&version=';
      $url .= rawurlencode($project['info']['version']);
    }
  }
  return $url;
}

/**
 * Taken from Core: modules/update/update.fetch.inc, line 138 and MODIFIED!
 *
 * Return the base of the URL to fetch available update data for a project.
 *
 * @param $project
 *   The array of project information from update_get_projects().
 * @return
 *   The base of the URL used for fetching available update data. This does
 *   not include the path elements to specify a particular project, version,
 *   site_key, etc.
 *
 * @see _update_build_fetch_url()
 */
function _prod_monitor_update_get_fetch_url_base($project) {
  return isset($project['info']['project status url']) ? $project['info']['project status url'] : UPDATE_DEFAULT_URL;
}

/**
 * Taken from Core: modules/update/update.compare.inc, line 296 and MODIFIED!
 *
 * Given the installed projects and the available release data retrieved from
 * remote servers, calculate the current status.
 *
 * This function is the heart of the update status feature. It iterates over
 * every currently installed project. For each one, it first checks if the
 * project has been flagged with a special status like "unsupported" or
 * "insecure", or if the project node itself has been unpublished. In any of
 * those cases, the project is marked with an error and the next project is
 * considered.
 *
 * If the project itself is valid, the function decides what major release
 * series to consider. The project defines what the currently supported major
 * versions are for each version of core, so the first step is to make sure
 * the current version is still supported. If so, that's the target version.
 * If the current version is unsupported, the project maintainer's recommended
 * major version is used. There's also a check to make sure that this function
 * never recommends an earlier release than the currently installed major
 * version.
 *
 * Given a target major version, it scans the available releases looking for
 * the specific release to recommend (avoiding beta releases and development
 * snapshots if possible). This is complicated to describe, but an example
 * will help clarify. For the target major version, find the highest patch
 * level. If there is a release at that patch level with no extra ("beta",
 * etc), then we recommend the release at that patch level with the most
 * recent release date. If every release at that patch level has extra (only
 * betas), then recommend the latest release from the previous patch
 * level. For example:
 *
 * 1.6-bugfix <-- recommended version because 1.6 already exists.
 * 1.6
 *
 * or
 *
 * 1.6-beta
 * 1.5 <-- recommended version because no 1.6 exists.
 * 1.4
 *
 * It also looks for the latest release from the same major version, even a
 * beta release, to display to the user as the "Latest version" option.
 * Additionally, it finds the latest official release from any higher major
 * versions that have been released to provide a set of "Also available"
 * options.
 *
 * Finally, and most importantly, it keeps scanning the release history until
 * it gets to the currently installed release, searching for anything marked
 * as a security update. If any security updates have been found between the
 * recommended release and the installed version, all of the releases that
 * included a security fix are recorded so that the site administrator can be
 * warned their site is insecure, and links pointing to the release notes for
 * each security update can be included (which, in turn, will link to the
 * official security announcements for each vulnerability).
 *
 * This function relies on the fact that the .xml release history data comes
 * sorted based on major version and patch level, then finally by release date
 * if there are multiple releases such as betas from the same major.patch
 * version (e.g. 5.x-1.5-beta1, 5.x-1.5-beta2, and 5.x-1.5). Development
 * snapshots for a given major version are always listed last.
 *
 * The results of this function are expensive to compute, especially on sites
 * with lots of modules or themes, since it involves a lot of comparisons and
 * other operations. Therefore, we cache the results into the {cache_update}
 * table using the 'update_project_data' cache ID. However, since this is not
 * the data about available updates fetched from the network, it is ok to
 * invalidate it somewhat quickly. If we keep this data for very long, site
 * administrators are more likely to see incorrect results if they upgrade to
 * a newer version of a module or theme but do not visit certain pages that
 * automatically clear this cache.
 *
 * @param $id
 *  int id of the site being processed.
 * @param $projects
 *  Array of data containing all the projects.
 * @param $available
 *  Array of data about available project releases.
 *
 * @see update_get_available()
 * @see update_get_projects()
 * @see update_process_project_info()
 * @see update_project_cache()
 */
function _prod_monitor_calculate_project_data($id, $projects, $available) {
  module_load_include('inc', 'update', 'update.compare');
  update_process_project_info($projects);
  foreach ($projects as $project => $project_info) {
    if (isset($available[$project])) {

      // If the project status is marked as something bad, there's nothing
      // else to consider.
      if (isset($available[$project]['project_status'])) {
        switch ($available[$project]['project_status']) {
          case 'insecure':
            $projects[$project]['status'] = UPDATE_NOT_SECURE;
            if (empty($projects[$project]['extra'])) {
              $projects[$project]['extra'] = array();
            }
            $projects[$project]['extra'][] = array(
              'class' => 'project-not-secure',
              'label' => t('Project not secure'),
              'data' => t('This project has been labeled insecure by the Drupal security team, and is no longer available for download. Immediately disabling everything included by this project is strongly recommended!'),
            );
            break;
          case 'unpublished':
          case 'revoked':
            $projects[$project]['status'] = UPDATE_REVOKED;
            if (empty($projects[$project]['extra'])) {
              $projects[$project]['extra'] = array();
            }
            $projects[$project]['extra'][] = array(
              'class' => 'project-revoked',
              'label' => t('Project revoked'),
              'data' => t('This project has been revoked, and is no longer available for download. Disabling everything included by this project is strongly recommended!'),
            );
            break;
          case 'unsupported':
            $projects[$project]['status'] = UPDATE_NOT_SUPPORTED;
            if (empty($projects[$project]['extra'])) {
              $projects[$project]['extra'] = array();
            }
            $projects[$project]['extra'][] = array(
              'class' => 'project-not-supported',
              'label' => t('Project not supported'),
              'data' => t('This project is no longer supported, and is no longer available for download. Disabling everything included by this project is strongly recommended!'),
            );
            break;
          case 'not-fetched':
            $projects[$project]['status'] = UPDATE_NOT_FETCHED;
            $projects[$project]['reason'] = t('Failed to fetch available update data');
            break;

          default:
            // Assume anything else (e.g. 'published') is valid and we should
            // perform the rest of the logic in this function.
            break;
        }
      }

      if (!empty($projects[$project]['status'])) {
        // We already know the status for this project, so there's nothing
        // else to compute. Just record everything else we fetched from the
        // XML file into our projects array and move to the next project.
        $projects[$project] += $available[$project];
        continue;
      }

      // Figure out the target major version.
      $existing_major = $project_info['existing_major'];
      $supported_majors = array();
      if (isset($available[$project]['supported_majors'])) {
        $supported_majors = explode(',', $available[$project]['supported_majors']);
      }
      elseif (isset($available[$project]['default_major'])) {
        // Older release history XML file without supported or recommended.
        $supported_majors[] = $available[$project]['default_major'];
      }

      if (in_array($existing_major, $supported_majors)) {
        // Still supported, stay at the current major version.
        $target_major = $existing_major;
      }
      elseif (isset($available[$project]['recommended_major'])) {
        // Since 'recommended_major' is defined, we know this is the new XML
        // format. Therefore, we know the current release is unsupported since
        // its major version was not in the 'supported_majors' list. We should
        // find the best release from the recommended major version.
        $target_major = $available[$project]['recommended_major'];
        $projects[$project]['status'] = UPDATE_NOT_SUPPORTED;
      }
      elseif (isset($available[$project]['default_major'])) {
        // Older release history XML file without recommended, so recommend
        // the currently defined "default_major" version.
        $target_major = $available[$project]['default_major'];
      }
      else {
        // Malformed XML file? Stick with the current version.
        $target_major = $existing_major;
      }

      // Make sure we never tell the admin to downgrade. If we recommended an
      // earlier version than the one they're running, they'd face an
      // impossible data migration problem, since Drupal never supports a DB
      // downgrade path. In the unfortunate case that what they're running is
      // unsupported, and there's nothing newer for them to upgrade to, we
      // can't print out a "Recommended version", but just have to tell them
      // what they have is unsupported and let them figure it out.
      $target_major = max($existing_major, $target_major);

      $version_patch_changed = '';
      $patch = '';

      // Defend ourselves from XML history files that contain no releases.
      if (empty($available[$project]['releases'])) {
        $projects[$project]['status'] = UPDATE_UNKNOWN;
        $projects[$project]['reason'] = t('No available releases found');
        continue;
      }
      foreach ($available[$project]['releases'] as $version => $release) {
        // First, if this is the existing release, check a few conditions.
        if ($projects[$project]['existing_version'] === $version) {
          if (isset($release['terms']['Release type']) &&
              in_array('Insecure', $release['terms']['Release type'])) {
            $projects[$project]['status'] = UPDATE_NOT_SECURE;
          }
          elseif ($release['status'] == 'unpublished') {
            $projects[$project]['status'] = UPDATE_REVOKED;
            if (empty($projects[$project]['extra'])) {
              $projects[$project]['extra'] = array();
            }
            $projects[$project]['extra'][] = array(
              'class' => 'release-revoked',
              'label' => t('Release revoked'),
              'data' => t('Your currently installed release has been revoked, and is no longer available for download. Disabling everything included in this release or upgrading is strongly recommended!'),
            );
          }
          elseif (isset($release['terms']['Release type']) &&
                  in_array('Unsupported', $release['terms']['Release type'])) {
            $projects[$project]['status'] = UPDATE_NOT_SUPPORTED;
            if (empty($projects[$project]['extra'])) {
              $projects[$project]['extra'] = array();
            }
            $projects[$project]['extra'][] = array(
              'class' => 'release-not-supported',
              'label' => t('Release not supported'),
              'data' => t('Your currently installed release is now unsupported, and is no longer available for download. Disabling everything included in this release or upgrading is strongly recommended!'),
            );
          }
        }

        // Otherwise, ignore unpublished, insecure, or unsupported releases.
        if ($release['status'] == 'unpublished' ||
            (isset($release['terms']['Release type']) &&
             (in_array('Insecure', $release['terms']['Release type']) ||
              in_array('Unsupported', $release['terms']['Release type'])))) {
          continue;
        }

        // See if this is a higher major version than our target and yet still
        // supported. If so, record it as an "Also available" release.
        if ($release['version_major'] > $target_major) {
          if (in_array($release['version_major'], $supported_majors)) {
            if (!isset($available[$project]['also'])) {
              $available[$project]['also'] = array();
            }
            if (!isset($available[$project]['also'][$release['version_major']])) {
              $available[$project]['also'][$release['version_major']] = $version;
            }
          }
          // Otherwise, this release can't matter to us, since it's neither
          // from the release series we're currently using nor the recommended
          // release. We don't even care about security updates for this
          // branch, since if a project maintainer puts out a security release
          // at a higher major version and not at the lower major version,
          // they must remove the lower version from the supported major
          // versions at the same time, in which case we won't hit this code.
          continue;
        }

        // Look for the 'latest version' if we haven't found it yet. Latest is
        // defined as the most recent version for the target major version.
        if (!isset($available[$project]['latest_version'])
            && $release['version_major'] == $target_major) {
          $available[$project]['latest_version'] = $version;
        }

        // Look for the development snapshot release for this branch.
        if (!isset($available[$project]['dev_version'])
            && $release['version_major'] == $target_major
            && isset($release['version_extra'])
            && $release['version_extra'] == 'dev') {
          $available[$project]['dev_version'] = $version;
        }

        // Look for the 'recommended' version if we haven't found it yet (see
        // phpdoc at the top of this function for the definition).
        if (!isset($available[$project]['recommended'])
            && $release['version_major'] == $target_major
            && isset($release['version_patch'])) {
          if ($patch != $release['version_patch']) {
            $patch = $release['version_patch'];
            $version_patch_changed = $release['version'];
          }
          if (empty($release['version_extra']) && $patch == $release['version_patch']) {
            $available[$project]['recommended'] = $version_patch_changed;
          }
        }

        // Stop searching once we hit the currently installed version.
        if ($projects[$project]['existing_version'] === $version) {
          break;
        }

        // If we're running a dev snapshot and have a timestamp, stop
        // searching for security updates once we hit an official release
        // older than what we've got. Allow 100 seconds of leeway to handle
        // differences between the datestamp in the .info file and the
        // timestamp of the tarball itself (which are usually off by 1 or 2
        // seconds) so that we don't flag that as a new release.
        if ($projects[$project]['install_type'] == 'dev') {
          if (empty($projects[$project]['datestamp'])) {
            // We don't have current timestamp info, so we can't know.
            continue;
          }
          elseif (isset($release['date']) && ($projects[$project]['datestamp'] + 100 > $release['date'])) {
            // We're newer than this, so we can skip it.
            continue;
          }
        }

        // See if this release is a security update.
        if (isset($release['terms']['Release type'])
            && in_array('Security update', $release['terms']['Release type'])) {
          $projects[$project]['security updates'][] = $release;
        }
      }

      // If we were unable to find a recommended version, then make the latest
      // version the recommended version if possible.
      if (!isset($available[$project]['recommended']) && isset($available[$project]['latest_version'])) {
        $available[$project]['recommended'] = $available[$project]['latest_version'];
      }

      // Stash the info about available releases into our $projects array.
      $projects[$project] += $available[$project];

      //
      // Check to see if we need an update or not.
      //

      if (!empty($projects[$project]['security updates'])) {
        // If we found security updates, that always trumps any other status.
        $projects[$project]['status'] = UPDATE_NOT_SECURE;
      }

      if (isset($projects[$project]['status'])) {
        // If we already know the status, we're done.
        continue;
      }

      // If we don't know what to recommend, there's nothing we can report.
      // Bail out early.
      if (!isset($projects[$project]['recommended'])) {
        $projects[$project]['status'] = UPDATE_UNKNOWN;
        $projects[$project]['reason'] = t('No available releases found');
        continue;
      }

      // If we're running a dev snapshot, compare the date of the dev snapshot
      // with the latest official version, and record the absolute latest in
      // 'latest_dev' so we can correctly decide if there's a newer release
      // than our current snapshot.
      if ($projects[$project]['install_type'] == 'dev') {
        if (isset($available[$project]['dev_version']) && $available[$project]['releases'][$available[$project]['dev_version']]['date'] > $available[$project]['releases'][$available[$project]['latest_version']]['date']) {
          $projects[$project]['latest_dev'] = $available[$project]['dev_version'];
        }
        else {
          $projects[$project]['latest_dev'] = $available[$project]['latest_version'];
        }
      }

      // Figure out the status, based on what we've seen and the install type.
      switch ($projects[$project]['install_type']) {
        case 'official':
          if ($projects[$project]['existing_version'] === $projects[$project]['recommended'] || $projects[$project]['existing_version'] === $projects[$project]['latest_version']) {
            $projects[$project]['status'] = UPDATE_CURRENT;
          }
          else {
            $projects[$project]['status'] = UPDATE_NOT_CURRENT;
          }
          break;

        case 'dev':
          $latest = $available[$project]['releases'][$projects[$project]['latest_dev']];
          if (empty($projects[$project]['datestamp'])) {
            $projects[$project]['status'] = UPDATE_NOT_CHECKED;
            $projects[$project]['reason'] = t('Unknown release date');
          }
          elseif (($projects[$project]['datestamp'] + 100 > $latest['date'])) {
            $projects[$project]['status'] = UPDATE_CURRENT;
          }
          else {
            $projects[$project]['status'] = UPDATE_NOT_CURRENT;
          }
          break;

        default:
          $projects[$project]['status'] = UPDATE_UNKNOWN;
          $projects[$project]['reason'] = t('Invalid info');
      }
    }
    else {
      $projects[$project]['status'] = UPDATE_UNKNOWN;
      $projects[$project]['reason'] = t('No available releases found');
    }
  }

  // Prepare object to store generated data to DB.
  $modules = new stdClass();
  $modules->id = $id;
  // Assume there are no updates.
  $modules->updates = 1;
  // Check final status of each project.
  foreach ($projects as $project => $project_info) {
    switch ($project_info['status']) {
      case UPDATE_NOT_SECURE:
      case UPDATE_NOT_SUPPORTED:
      case UPDATE_REVOKED:
        $modules->updates = 3;
        // Stop the foreach loop as well.
        break 2;
      case UPDATE_NOT_CURRENT:
        if ($modules->updates < 2) {
          $modules->updates = 2;
        }
        break;
    }
  }

  $result = drupal_write_record('prod_monitor_site_modules', $modules, array('id'));
  if (!$result) {
    watchdog('prod_monitor', 'Could not update module security status for %link', array('%link' => _prod_monitor_get_url($id)), WATCHDOG_ERROR);
  }

  return $projects;
}
