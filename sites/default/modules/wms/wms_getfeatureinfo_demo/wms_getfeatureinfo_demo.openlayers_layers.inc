<?php

/**
 * Implementation of hook_openlayers_layers().
 */
function wms_getfeatureinfo_demo_openlayers_layers() {
  $export = array();
  $openlayers_layers = new stdClass;
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'Canada Bathymetry';
  $openlayers_layers->title = 'Canada Bathymetry';
  $openlayers_layers->description = 'Canada Bathymetry on Demis2';
  $openlayers_layers->data = array(
    'base_url' => 'http://www2.dmsolutions.ca/cgi-bin/mswms_gmap',
    'params' => array(
      'isBaseLayer' => TRUE,
      'buffer' => '2',
      'ratio' => '1.5',
      'singleTile' => 0,
      'numZoomLevels' => '16',
    ),
    'options' => array(
      'srs' => 'EPSG:4326',
      'TRANSPARENT' => 0,
      'exceptions' => 'application/vnd.ogc.se_inimage',
      'format' => 'image/png',
      'layers' => 'bathymetry',
      'styles' => '',
    ),
    'layer_type' => 'openlayers_layer_type_wms',
  );

  $export['Canada Bathymetry'] = $openlayers_layers;
  $openlayers_layers = new stdClass;
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'Canada Park';
  $openlayers_layers->title = 'Canada Park';
  $openlayers_layers->description = 'Canada Park on Demis2';
  $openlayers_layers->data = array(
    'base_url' => 'http://www2.dmsolutions.ca/cgi-bin/mswms_gmap',
    'params' => array(
      'isBaseLayer' => 0,
      'buffer' => '2',
      'ratio' => '1.5',
      'singleTile' => 0,
      'numZoomLevels' => '16',
    ),
    'options' => array(
      'srs' => 'EPSG:4326',
      'TRANSPARENT' => TRUE,
      'exceptions' => 'application/vnd.ogc.se_inimage',
      'format' => 'image/png',
      'layers' => 'park',
      'styles' => '',
    ),
    'layer_type' => 'openlayers_layer_type_wms',
  );

  $export['Canada Park'] = $openlayers_layers;
  $openlayers_layers = new stdClass;
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'Canada Populated Place';
  $openlayers_layers->title = 'Canada Populated Place';
  $openlayers_layers->description = 'Canada Populated Places on Demis2';
  $openlayers_layers->data = array(
    'base_url' => 'http://www2.dmsolutions.ca/cgi-bin/mswms_gmap',
    'params' => array(
      'isBaseLayer' => 0,
      'buffer' => '2',
      'ratio' => '1.5',
      'singleTile' => 0,
      'numZoomLevels' => '16',
    ),
    'options' => array(
      'srs' => 'EPSG:4326',
      'TRANSPARENT' => TRUE,
      'exceptions' => 'application/vnd.ogc.se_inimage',
      'format' => 'image/png',
      'layers' => 'popplace',
      'styles' => '',
    ),
    'layer_type' => 'openlayers_layer_type_wms',
  );

  $export['Canada Populated Place'] = $openlayers_layers;
  $openlayers_layers = new stdClass;
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'Canada Rail';
  $openlayers_layers->title = 'Canada Rail';
  $openlayers_layers->description = 'Canada Rail on Demis2';
  $openlayers_layers->data = array(
    'base_url' => 'http://www2.dmsolutions.ca/cgi-bin/mswms_gmap',
    'params' => array(
      'isBaseLayer' => 0,
      'buffer' => '2',
      'ratio' => '1.5',
      'singleTile' => 0,
      'numZoomLevels' => '16',
    ),
    'options' => array(
      'srs' => 'EPSG:4326',
      'TRANSPARENT' => TRUE,
      'exceptions' => 'application/vnd.ogc.se_inimage',
      'format' => 'image/png',
      'layers' => 'rail',
      'styles' => '',
    ),
    'layer_type' => 'openlayers_layer_type_wms',
  );

  $export['Canada Rail'] = $openlayers_layers;
  return $export;
}
