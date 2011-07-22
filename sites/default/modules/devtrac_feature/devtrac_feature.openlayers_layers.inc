<?php

/**
 * Implementation of hook_openlayers_layers().
 */
function devtrac_feature_openlayers_layers() {
  $export = array();
  $openlayers_layers = new stdClass;
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'UgandaHealthWMS';
  $openlayers_layers->title = 'U-Map It Health (New)';
  $openlayers_layers->description = 'Baselayer for Health in Uganda';
  $openlayers_layers->data = array(
    'base_url' => 'http://maps.u-map.it/wms',
    'params' => array(
      'isBaseLayer' => 0,
      'buffer' => '2',
      'ratio' => '1.5',
      'singleTile' => 1,
    ),
    'options' => array(
      'srs' => 'EPSG:900913',
      'TRANSPARENT' => TRUE,
      'exceptions' => 'application/vnd.ogc.se_inimage',
      'format' => 'image/jpeg',
      'layers' => 'Devtrac:HealthUnits,Devtrac:HealthCenterII,Devtrac:HealthCenterIII,Devtrac:HealthCenterIV',
      'styles' => '',
    ),
    'layer_type' => 'openlayers_layer_type_wms',
  );

  $export['UgandaHealthWMS'] = $openlayers_layers;
  $openlayers_layers = new stdClass;
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'u-map-it-health';
  $openlayers_layers->title = 'U-Map It Health';
  $openlayers_layers->description = 'Baselayer for Health in Uganda';
  $openlayers_layers->data = array(
    'base_url' => 'http://maps.u-map.it/wms',
    'params' => array(
      'isBaseLayer' => 0,
      'buffer' => '2',
      'ratio' => '1.5',
      'singleTile' => 1,
    ),
    'options' => array(
      'srs' => 'EPSG:900913',
      'TRANSPARENT' => TRUE,
      'exceptions' => 'application/vnd.ogc.se_inimage',
      'format' => 'image/jpeg',
      'layers' => 'Devtrac:HealthUnits,Devtrac:HealthCenterII,Devtrac:HealthCenterIII,Devtrac:HealthCenterIV',
      'styles' => '',
    ),
    'layer_type' => 'openlayers_layer_type_wms',
  );

  $export['u-map-it-health'] = $openlayers_layers;
  $openlayers_layers = new stdClass;
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'u-map-it-schools';
  $openlayers_layers->title = 'U-Map It Schools';
  $openlayers_layers->description = 'Baselayer for Schools in Uganda';
  $openlayers_layers->data = array(
    'base_url' => 'http://maps.u-map.it/gwc/service/wms',
    'params' => array(
      'isBaseLayer' => 0,
      'buffer' => '2',
      'ratio' => '1.5',
      'singleTile' => 0,
    ),
    'options' => array(
      'srs' => 'EPSG:900913',
      'TRANSPARENT' => 'true',
      'format' => 'image/png',
      'layers' => 'UgandaSchools',
      'styles' => '',
    ),
    'layer_type' => 'openlayers_layer_type_wms',
  );

  $export['u-map-it-schools'] = $openlayers_layers;
  $openlayers_layers = new stdClass;
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'u-map-it-schoolsWMS';
  $openlayers_layers->title = 'U-Map It Schools (New)';
  $openlayers_layers->description = 'Baselayer for Schools in Uganda in WMS for Querying';
  $openlayers_layers->data = array(
    'base_url' => 'http://maps.u-map.it/wms',
    'params' => array(
      'isBaseLayer' => 0,
      'buffer' => '2',
      'ratio' => '1.5',
      'singleTile' => 1,
    ),
    'options' => array(
      'srs' => 'EPSG:900913',
      'TRANSPARENT' => TRUE,
      'exceptions' => 'application/vnd.ogc.se_inimage',
      'format' => 'image/png',
      'layers' => 'Devtrac:Schools,Devtrac:SchoolsNorth',
      'styles' => '',
    ),
    'layer_type' => 'openlayers_layer_type_wms',
  );

  $export['u-map-it-schoolsWMS'] = $openlayers_layers;
  $openlayers_layers = new stdClass;
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'u-map-it-wash';
  $openlayers_layers->title = 'U-Map It Wash';
  $openlayers_layers->description = 'Baselayer for WASH in Uganda';
  $openlayers_layers->data = array(
    'base_url' => 'http://maps.u-map.it/gwc/service/wms',
    'params' => array(
      'isBaseLayer' => 0,
      'buffer' => '2',
      'ratio' => '1.5',
      'singleTile' => 0,
    ),
    'options' => array(
      'srs' => 'EPSG:900913',
      'TRANSPARENT' => 'true',
      'format' => 'image/png',
      'layers' => 'UgandaWash',
      'styles' => '',
    ),
    'layer_type' => 'openlayers_layer_type_wms',
  );

  $export['u-map-it-wash'] = $openlayers_layers;
  $openlayers_layers = new stdClass;
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'u-map-it-washWMS';
  $openlayers_layers->title = 'U-Map It Wash (New)';
  $openlayers_layers->description = 'Baselayer for WASH in Uganda for Querying';
  $openlayers_layers->data = array(
    'base_url' => 'http://maps.u-map.it/wms',
    'params' => array(
      'isBaseLayer' => 0,
      'buffer' => '2',
      'ratio' => '1.5',
      'singleTile' => 1,
    ),
    'options' => array(
      'srs' => 'EPSG:900913',
      'TRANSPARENT' => TRUE,
      'exceptions' => 'application/vnd.ogc.se_inimage',
      'format' => 'image/jpeg',
      'layers' => 'Devtrac:WaterSources,Devtrac:WaterSourcesNorth',
      'styles' => '',
    ),
    'layer_type' => 'openlayers_layer_type_wms',
  );

  $export['u-map-it-washWMS'] = $openlayers_layers;
  $openlayers_layers = new stdClass;
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'uganda_basemap';
  $openlayers_layers->title = 'Uganda Basemap';
  $openlayers_layers->description = 'U-Map It Uganda Basemap';
  $openlayers_layers->data = array(
    'base_url' => 'http://maps.u-map.it/gwc/service/wms',
    'params' => array(
      'isBaseLayer' => 'true',
      'buffer' => '2',
      'ratio' => '1.5',
      'singleTile' => 0,
    ),
    'options' => array(
      'srs' => 'EPSG:900913',
      'TRANSPARENT' => 0,
      'exceptions' => 'application/vnd.ogc.se_inimage',
      'format' => 'image/jpeg',
      'layers' => 'Uganda',
      'styles' => '',
    ),
    'layer_type' => 'openlayers_layer_type_wms',
  );

  $export['uganda_basemap'] = $openlayers_layers;
  return $export;
}
