<?php

/**
 * @file
 * Create a drush command for the Devtrac module.
 */

/**
 * Implementation of hook_drush_command().
 */
function devtrack_module_drush_command() {
  $items = array();

  $items['publishfieldtrips'] = array(
    'description' => 'Publish all field trips.',
    'drupal dependencies' => array('devtrack_module'),
    'aliases' => array('dtpf'),
  );
  return $items;
}

/**
 * Implementation of hook_drush_help().
 */
function devtrack_module_drush_help($section) {
  switch ($section) {
    case 'meta:devtrac:title':
      return dt('Devtrac commands');
    case 'meta:devtrac:summary':
      return dt('Do Devtrac stuff.');
    case 'drush:publishfieldtrips':
      return dt("Publish field trips which was necessary in update 6001 but after the update.");
  }
}



function drush_devtrack_module_publishfieldtrips() {
  drush_print("going to update");
  devtrack_module_fieldtrip_publish_all_field_trips();
  drush_print("published all field trips");
  drush_log('Done.', 'success');
}
