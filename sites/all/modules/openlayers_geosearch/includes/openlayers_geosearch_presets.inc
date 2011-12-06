<?php

/**
 * @file
 * This file contains preset implementations
 *
 * @ingroup openlayers
 */

/**
 * Preset Implementation
 *
 * Internal callback for openlayers preset implementation.
 *
 * @return
 *   Array of presets
 */
function _openlayers_geosearch_openlayers_presets() {
  // Create full preset array
  $default = new stdClass();
  $default->api_version = 1;
  $default->name = 'geosearch';
  $default->title = t('Default Geosearch Map');
  $default->description = t('This is the default map preset that comes with the OpenLayers Geosearch module.');
  $default->data = array(
    'projection' => '900913',
    'width' => 'auto',
    'height' => '400px',
    'default_layer' => 'osm_mapnik',
    'center' => array(
      'initial' => array(
        'centerpoint' => '0,0',
        'zoom' => '2'
      )
    ),
    'displayProjection' => '4326',
    'maxExtent' => openlayers_get_extent('4326'),
    'behaviors' => array(
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_layerswitcher' => array(),
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_navigation' => array(),
      'openlayers_behavior_tooltip' => array(
        'layers' => array(
          'openlayers_searchresult_layer' => 'openlayers_searchresult_layer',
        ),
      ),
    ),
    'default_layer' => 'osm_mapnik',
    'layers' => array(
      'osm_mapnik' => 'osm_mapnik',
      'openlayers_searchresult_layer' => 'openlayers_searchresult_layer',
    ),
    'layer_styles' => array(),
    'layer_activated' => array(
      'openlayers_searchresult_layer' => 'openlayers_searchresult_layer',
    ),
  );
  return array('geosearch' => $default);
}
