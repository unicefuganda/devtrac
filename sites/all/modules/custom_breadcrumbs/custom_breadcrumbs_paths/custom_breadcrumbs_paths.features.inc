<?php

/**
 * Implementation of hook_features_export_options. [component_hook]
 *
 * This hook will alert features of which specific items of this component may
 * be exported. For instances, in this case, we want to make available all the
 * existing items.  If there are no items to be exported, this component will
 * not be made available in the features export page.
 *
 * @return array
 *   A keyed array of items, suitable for use with a FormAPI select or
 *   checkboxes element.
 */
function custom_breadcrumbs_paths_config_features_export_options() {
  $options = array();
  $query = " SELECT machine_name, specific_path FROM {custom_breadcrumbs_paths} ";
  $params = array();
  $result = db_query($query, $params);
  while ($row = db_fetch_array($result)) {
    $options[$row['machine_name']] = 'Path: '. $row['specific_path'];
  }
  return $options;
}

/**
 * Implementation of hook_features_export [component hook]
 *
 * This is a component hook, rather then a module hook, therefore this is the
 * callback from hook_features_api which relates to the specific component we
 * are looking to export.  When a specific instance of the component we are
 * looking to export is selected, this will include the necessariy item, plus
 * any dependencies into our export array.
 *
 * @param array $data
 *   this is the machine name for the component in question
 * @param array &$export
 *   array of all components to be exported
 * @param string $module_name
 *   The name of the feature module to be generated.
 * @return array
 *   The pipe array of further processors that should be called
 */
function custom_breadcrumbs_paths_config_features_export($data, &$export, $module_name) {
  //we have module dependencies in order for this module to function properly
  //so we'll add them here
  $export['dependencies']['custom_breadcrumbs_paths'] = 'custom_breadcrumbs_paths';

  // The following is the simplest implementation of a straight object export
  // with no further export processors called.
  foreach ($data as $component) {
    $export['features']['custom_breadcrumbs_paths_config'][$component] = $component;
  }
  return array();
}

/**
 * Implementation of hook_features_export_render. [component hook]
 *
 * This hook will be invoked in order to export
 * Component hook. The hook should be implemented using the name ot the
 * component, not the module, eg. [component]_features_export() rather than
 * [module]_features_export().
 *
 * Render one or more component objects to code.
 *
 * @param string $module_name
 *   The name of the feature module to be exported.
 * @param array $data
 *   An array of machine name identifiers for the objects to be rendered.
 * @param array $export
 *   The full export array of the current feature being exported. This is only
 *   passed when hook_features_export_render() is invoked for an actual feature
 *   update or recreate, not during state checks or other operations.
 * @return array
 *   An associative array of rendered PHP code where the key is the name of the
 *   hook that should wrap the PHP code. The hook should not include the name
 *   of the module, e.g. the key for `hook_example` should simply be `example`.
 */
function custom_breadcrumbs_paths_config_features_export_render($module_name, $data, $export = NULL) {
  $code = array();
  $code[] = '  $custom_breadcrumbs_paths_configs = array();';
  $code[] = '';
  foreach ($data as $option) {
    //retrieve the contest information
    $item = _custom_breadcrumbs_paths_config_get_data($option);
    //add the contest code to the feature
    if (isset($item[$option])) {
      $code[] = '  $custom_breadcrumbs_paths_configs[] = '. features_var_export($item, '  ') .';';
    }
  }
  $code[] = '  return $custom_breadcrumbs_paths_configs;';
  $code = implode("\n", $code);
  return array('custom_breadcrumbs_paths_config_features_default_settings' => $code);
}

/*
 * Basic function to retrieve the information to be exported.
 */
function _custom_breadcrumbs_paths_config_get_data($option) {
  $sql = "SELECT * FROM {custom_breadcrumbs_paths} WHERE machine_name = '%s'";
  $breadcrumb = db_fetch_array(db_query($sql, $option));
  // Remove the auto-increment value from the breadcrumb config.
  unset($breadcrumb['bid']);
  return array($option => $breadcrumb);
}

/**
 * Implementation of hook_features_rebuild(). [component_hook]
 */
function custom_breadcrumbs_paths_config_features_rebuild($module) {
  $items = module_invoke($module, 'custom_breadcrumbs_paths_config_features_default_settings');
  //loop over the items we need to recreate
  foreach ($items as $option => $item) {
    //basic function to take the array and store in the database
    $saved = _custom_breadcrumbs_paths_config_set_data($item);
  }
}

/*
 * Basic function to take the array and store in the database.
 */
function _custom_breadcrumbs_paths_config_set_data($item) {
  $values = array_values($item);
  $sql_del = "DELETE FROM {custom_breadcrumbs_paths} WHERE machine_name = '%s'";
  $result = db_query($sql_del, $values[0]['machine_name']);
  if ($result) {
    $sql_ins = "INSERT INTO {custom_breadcrumbs_paths} (name, machine_name, titles, paths, visibility_php, language, specific_path) VALUES ('%s', '%s', '%s', '%s', '%s', '%s', '%s')";
    $result = db_query($sql_ins, $values[0]['name'], $values[0]['machine_name'], $values[0]['titles'], $values[0]['paths'], $values[0]['visibility_php'], $values[0]['language'], $values[0]['specific_path']);
  }
  return $result;
}

/**
 * Implementation of hook_features_revert(). [component_hook]
 */
function custom_breadcrumbs_paths_config_features_revert($module) {
  custom_breadcrumbs_paths_config_features_rebuild($module);
}
