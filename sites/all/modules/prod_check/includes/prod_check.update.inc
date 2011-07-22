<?php

/**
 * ALL code here is taken from the Drupal core's update module. prod_check
 * recommends that you turn this module off, so we provide the VERY BASIC
 * functionality to get a list of the installed modules with version info and
 * transfer this to prod_monitor over XMLRPC (alot of data here!) so that
 * prod_monitor can do all the update checking locally.
 * This approach was chosen over this approach:
 *
 *     module_load_include('module', 'update', 'update');
 *
 *     if ($available = update_get_available(TRUE)) {
 *       $data['modules'] = update_calculate_project_data($available);
 *     }
 *
 * This way, we might just as well turn on the update module and periodically
 * download the results. It's just not efficient...
 * Also note that passing TRUE to update_get_available() will bypass (refresh)
 * the caches, essentially the same as we do in _prod_check_module_list().
 * See inline comments there for more info.
 */


/**
 * Taken from Core: modules/update/update.compare.inc, line 53
 *
 * Populate an array of project data.
 */
function _prod_check_process_info_list(&$projects, $list, $project_type) {
  foreach ($list as $file) {
    // A disabled base theme of an enabled sub-theme still has all of its code
    // run by the sub-theme, so we include it in our "enabled" projects list.
    if (!$file->status && !empty($file->sub_themes)) {
      foreach ($file->sub_themes as $key => $name) {
        // Build a list of enabled sub-themes.
        if ($list[$key]->status) {
          $file->enabled_sub_themes[$key] = $name;
        }
      }
      // If there are no enabled subthemes, we should ingore this theme and go
      // on to the next one.
      if (empty($file->enabled_sub_themes)) {
        continue;
      }
    }
    elseif (empty($file->status)) {
      // Skip disabled modules or themes.
      continue;
    }

    // Skip if the .info file is broken.
    if (empty($file->info)) {
      continue;
    }

    // If the .info doesn't define the 'project', try to figure it out.
    if (!isset($file->info['project'])) {
      $file->info['project'] = _prod_check_get_project_name($file);
    }

    // If we still don't know the 'project', give up.
    if (empty($file->info['project'])) {
      continue;
    }

    // If we don't already know it, grab the change time on the .info file
    // itself. Note: we need to use the ctime, not the mtime (modification
    // time) since many (all?) tar implementations will go out of their way to
    // set the mtime on the files it creates to the timestamps recorded in the
    // tarball. We want to see the last time the file was changed on disk,
    // which is left alone by tar and correctly set to the time the .info file
    // was unpacked.
    if (!isset($file->info['_info_file_ctime'])) {
      $info_filename = dirname($file->filename) .'/'. $file->name .'.info';
      $file->info['_info_file_ctime'] = filectime($info_filename);
    }

    if (!isset($file->info['datestamp'])) {
      $file->info['datestamp'] = 0;
    }

    $project_name = $file->info['project'];

    // Add a list of sub-themes that "depend on" the project and a list of base
    // themes that are "required by" the project.
    if ($project_name == 'drupal') {
      // Drupal core is always required, so this extra info would be noise.
      $sub_themes = array();
      $base_themes = array();
    }
    else {
      // Add list of enabled sub-themes.
      $sub_themes = !empty($file->enabled_sub_themes) ? $file->enabled_sub_themes : array();
      // Add list of base themes.
      $base_themes = !empty($file->base_themes) ? $file->base_themes : array();
    }

    if (!isset($projects[$project_name])) {
      // Only process this if we haven't done this project, since a single
      // project can have multiple modules or themes.
      $projects[$project_name] = array(
        'name' => $project_name,
        // Only save attributes from the .info file we care about so we do not
        // bloat our RAM usage needlessly.
        'info' => _prod_check_filter_project_info($file->info),
        'datestamp' => $file->info['datestamp'],
        'includes' => array($file->name => $file->info['name']),
        'project_type' => $project_name == 'drupal' ? 'core' : $project_type,
        'sub_themes' => $sub_themes,
        'base_themes' => $base_themes,
      );
    }
    else {
      $projects[$project_name]['includes'][$file->name] = $file->info['name'];
      $projects[$project_name]['info']['_info_file_ctime'] = max($projects[$project_name]['info']['_info_file_ctime'], $file->info['_info_file_ctime']);
      $projects[$project_name]['datestamp'] = max($projects[$project_name]['datestamp'], $file->info['datestamp']);
      $projects[$project_name]['sub_themes'] = array_merge($projects[$project_name]['sub_themes'], $sub_themes);
      $projects[$project_name]['base_themes'] = array_merge($projects[$project_name]['base_themes'], $base_themes);
    }
  }
}

/**
 * Taken from Core: modules/update/update.compare.inc, line 153
 *
 * Given a $file object (as returned by system_get_files_database()), figure
 * out what project it belongs to.
 *
 * @see system_get_files_database()
 */
function _prod_check_get_project_name($file) {
  $project_name = '';
  if (isset($file->info['project'])) {
    $project_name = $file->info['project'];
  }
  elseif (isset($file->info['package']) && (strpos($file->info['package'], 'Core -') !== FALSE)) {
    $project_name = 'drupal';
  }
  elseif (in_array($file->name, array('bluemarine', 'chameleon', 'garland', 'marvin', 'minnelli', 'pushbutton'))) {
    // Unfortunately, there's no way to tell if a theme is part of core,
    // so we must hard-code a list here.
    $project_name = 'drupal';
  }
  return $project_name;
}

/**
 * Taken from Core: modules/update/update.compare.inc, line 684
 *
 * Filter the project .info data to only save attributes we need.
 *
 * @param array $info
 *   Array of .info file data as returned by drupal_parse_info_file().
 *
 * @return
 *   Array of .info file data we need for the Update manager.
 *
 * @see _prod_check_process_info_list()
 */
function _prod_check_filter_project_info($info) {
  $whitelist = array(
    '_info_file_ctime',
    'datestamp',
    'major',
    'name',
    'package',
    'project',
    'project status url',
    'version',
  );
  $whitelist = array_flip($whitelist);
  foreach ($info as $key => $value) {
    if (!isset($whitelist[$key])) {
      unset($info[$key]);
    }
  }
  return $info;
}
