<?php

/**
 * Implementation of hook_openlayers_presets().
 */
function devtrac_find_openlayers_presets() {
  $export = array();

  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'tripreports';
  $openlayers_presets->title = 'Trip Reports Map';
  $openlayers_presets->description = 'Map for trip reports';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => 'sites/default/themes/devtrack_theme/openlayers/img/',
    'css_path' => 'sites/default/themes/devtrack_theme/openlayers/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 1,
    'center' => array(
      'initial' => array(
        'centerpoint' => '31.992187498725, 1.2743089917945',
        'zoom' => '7',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '3277619.772282,-176110.913137,3898899.938072,484305.011128',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'trip_reports_search_openlayers_1' => 'trip_reports_search_openlayers_1',
        ),
      ),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'roundedCorner' => 1,
        'roundedCornerColor' => '#000000',
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'trip_reports_search_openlayers_1',
        'point_zoom_level' => '9',
      ),
    ),
    'default_layer' => 'uganda_basemap',
    'layers' => array(
      'osm_mapnik' => 'osm_mapnik',
      'uganda_basemap' => 'uganda_basemap',
      'trip_reports_search_openlayers_1' => 'trip_reports_search_openlayers_1',
    ),
    'layer_styles' => array(
      'trip_reports_search_openlayers_1' => array(
        'default' => 'devtrac_default',
        'select' => 'devtrac_default',
        'temporary' => 'devtrac_default',
      ),
    ),
    'layer_activated' => array(
      'trip_reports_search_openlayers_1' => 'trip_reports_search_openlayers_1',
    ),
    'layer_switcher' => array(
      'trip_reports_search_openlayers_1' => 'trip_reports_search_openlayers_1',
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'placetype',
      'select' => 'placetype',
      'temporary' => 'placetype',
    ),
  );
  $export['tripreports'] = $openlayers_presets;

  return $export;
}
