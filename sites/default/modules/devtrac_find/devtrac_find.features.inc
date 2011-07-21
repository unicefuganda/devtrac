<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function devtrac_find_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "openlayers" && $api == "openlayers_presets") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_views_api().
 */
function devtrac_find_views_api() {
  return array(
    'api' => '2',
  );
}
