<?php

/**
 * Implementation of hook_quicktabs_default_quicktabs().
 */
function devtrac_feature_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass;
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'geosearch';
  $quicktabs->ajax = 1;
  $quicktabs->hide_empty_tabs = 1;
  $quicktabs->default_tab = FALSE;
  $quicktabs->title = 'Geosearch QT';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'openlayers_geosearch_delta_1',
      'hide_title' => 0,
      'title' => 'Results',
      'weight' => '-99',
      'type' => 'block',
    ),
    1 => array(
      'bid' => 'devtrack_module_delta_1',
      'hide_title' => 0,
      'title' => 'Legend',
      'weight' => '-98',
      'type' => 'block',
    ),
  );
  $quicktabs->style = 'Zen';
  $export['geosearch'] = $quicktabs;

  return $export;
}
