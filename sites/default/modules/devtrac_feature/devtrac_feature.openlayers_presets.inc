<?php

/**
 * Implementation of hook_openlayers_presets().
 */
function devtrac_feature_openlayers_presets() {
  $export = array();

  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'field_trip';
  $openlayers_presets->title = 'Field Trip Map';
  $openlayers_presets->description = 'This is the default map preset for a Field Trip page.';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '300px',
    'image_path' => 'sites/default/themes/devtrack_theme/openlayers/img/',
    'css_path' => 'sites/default/themes/devtrack_theme/openlayers/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 1,
    'center' => array(
      'initial' => array(
        'centerpoint' => '32,1.2',
        'zoom' => '6',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '3285827.410659,-159925.03252,3902215.606641,466247.10308',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'field_trip_places_to_visit_openlayers_2' => 'field_trip_places_to_visit_openlayers_2',
          'field_trip_places_to_visit_openlayers_1' => 'field_trip_places_to_visit_openlayers_1',
        ),
      ),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'roundedCorner' => 1,
        'roundedCornerColor' => 'black',
      ),
      'openlayers_behavior_mouseposition' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_scaleline' => array(),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'field_trip_places_to_visit_openlayers_1',
        'point_zoom_level' => '10',
      ),
    ),
    'default_layer' => 'uganda_basemap',
    'layers' => array(
      'osm_mapnik' => 'osm_mapnik',
      'uganda_basemap' => 'uganda_basemap',
      'field_trip_places_to_visit_openlayers_2' => 'field_trip_places_to_visit_openlayers_2',
      'field_trip_places_to_visit_openlayers_1' => 'field_trip_places_to_visit_openlayers_1',
    ),
    'layer_styles' => array(
      'field_trip_places_to_visit_openlayers_2' => array(
        'default' => 'devtrac_default',
        'select' => 'devtrac_default',
        'temporary' => 'devtrac_default',
      ),
      'field_trip_places_to_visit_openlayers_1' => array(
        'default' => 'placetype',
        'select' => 'placetype',
        'temporary' => 'placetype',
      ),
    ),
    'layer_activated' => array(
      'field_trip_places_to_visit_openlayers_2' => 'field_trip_places_to_visit_openlayers_2',
      'field_trip_places_to_visit_openlayers_1' => 'field_trip_places_to_visit_openlayers_1',
    ),
    'layer_switcher' => array(),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  $export['field_trip'] = $openlayers_presets;

  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'geocoder_map';
  $openlayers_presets->title = 'Geocoder Map';
  $openlayers_presets->description = 'Map to use when Geocoding places';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => 'sites/default/themes/devtrack_theme/openlayers/img/',
    'css_path' => 'sites/default/themes/devtrack_theme/openlayers/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '32.299804686205, 1.5379012373702',
        'zoom' => '7',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '3255605.908139,-188340.837661,3901345.922977,484305.011128',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(),
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
        'zoomtolayer' => 'findplaces_districts_openlayers_2',
        'point_zoom_level' => '5',
      ),
    ),
    'default_layer' => 'uganda_basemap',
    'layers' => array(
      'osm_mapnik' => 'osm_mapnik',
      'uganda_basemap' => 'uganda_basemap',
      'u-map-it-schools' => 'u-map-it-schools',
      'u-map-it-health' => 'u-map-it-health',
      'findplaces_districts_openlayers_2' => 'findplaces_districts_openlayers_2',
      'u-map-it-wash' => 'u-map-it-wash',
    ),
    'layer_styles' => array(
      'u-map-it-wash' => array(
        'default' => 'devtrac_default',
        'select' => 'devtrac_default',
        'temporary' => 'devtrac_default',
      ),
      'u-map-it-health' => array(
        'default' => 'devtrac_default',
        'select' => 'devtrac_default',
        'temporary' => 'devtrac_default',
      ),
      'u-map-it-schools' => array(
        'default' => 'devtrac_default',
        'select' => 'devtrac_default',
        'temporary' => 'devtrac_default',
      ),
      'findplaces_districts_openlayers_2' => array(
        'default' => 'invisible',
        'select' => 'invisible',
        'temporary' => 'invisible',
      ),
    ),
    'layer_activated' => array(
      'findplaces_districts_openlayers_2' => 'findplaces_districts_openlayers_2',
    ),
    'layer_switcher' => array(
      'u-map-it-wash' => 'u-map-it-wash',
      'u-map-it-health' => 'u-map-it-health',
      'u-map-it-schools' => 'u-map-it-schools',
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default_select',
      'select' => 'default_select',
      'temporary' => 'default_select',
    ),
  );
  $export['geocoder_map'] = $openlayers_presets;

  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'places';
  $openlayers_presets->title = 'Uganda Places';
  $openlayers_presets->description = 'Preset to be used to find places';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '600px',
    'image_path' => 'sites/default/themes/devtrack_theme/openlayers/img/',
    'css_path' => 'sites/default/themes/devtrack_theme/openlayers/style.css',
    'proxy_host' => 'proxy?request=',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '32.310791014325, 1.1754546448691',
        'zoom' => '7',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '3287403.7119,-168772.958423,3896453.953167,476967.056414',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_argparser' => array(),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'findplaces_places_openlayers_1' => 'findplaces_places_openlayers_1',
          'findplaces_districts_openlayers_1' => 0,
        ),
      ),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_mouseposition' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_permalink' => array(),
      'openlayers_behavior_scaleline' => array(),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'findplaces_districts_openlayers_1',
        'point_zoom_level' => '5',
      ),
      'openlayers_plus_behavior_blockswitcher' => array(
        'map' => array(
          'enabled' => 0,
          'position' => 'se',
        ),
      ),
      'openlayers_behavior_wmsgetfeatureinfo' => array(
        'getfeatureinfo_usevisiblelayers' => 1,
        'getfeatureinfo_layers' => 'uganda_basemap',
        'getfeatureinfo_info_format' => 'application/vnd.ogc.gml',
        'getfeatureinfo_htmlelement' => 'getfeatureinfo',
      ),
    ),
    'default_layer' => 'uganda_basemap',
    'layers' => array(
      'uganda_basemap' => 'uganda_basemap',
      'findplaces_places_openlayers_1' => 'findplaces_places_openlayers_1',
      'findplaces_districts_openlayers_1' => 'findplaces_districts_openlayers_1',
      'u-map-it-schoolsWMS' => 'u-map-it-schoolsWMS',
      'UgandaHealthWMS' => 'UgandaHealthWMS',
      'u-map-it-washWMS' => 'u-map-it-washWMS',
    ),
    'layer_styles' => array(
      'findplaces_places_openlayers_1' => array(
        'default' => 'placetype',
        'select' => 'placetype',
        'temporary' => 'placetype',
      ),
      'findplaces_districts_openlayers_1' => array(
        'default' => 'invisible',
        'select' => 'invisible',
        'temporary' => 'invisible',
      ),
      'u-map-it-schoolsWMS' => array(
        'default' => 'devtrac_default',
        'select' => 'devtrac_default',
        'temporary' => 'devtrac_default',
      ),
      'UgandaHealthWMS' => array(
        'default' => 'devtrac_default',
        'select' => 'devtrac_default',
        'temporary' => 'devtrac_default',
      ),
      'u-map-it-washWMS' => array(
        'default' => 'devtrac_default',
        'select' => 'devtrac_default',
        'temporary' => 'devtrac_default',
      ),
    ),
    'layer_activated' => array(
      'findplaces_places_openlayers_1' => 'findplaces_places_openlayers_1',
      'findplaces_districts_openlayers_1' => 'findplaces_districts_openlayers_1',
    ),
    'layer_switcher' => array(
      'findplaces_places_openlayers_1' => 'findplaces_places_openlayers_1',
      'u-map-it-schoolsWMS' => 'u-map-it-schoolsWMS',
      'UgandaHealthWMS' => 'UgandaHealthWMS',
      'u-map-it-washWMS' => 'u-map-it-washWMS',
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'placetype',
      'temporary' => 'placetype',
    ),
  );
  $export['places'] = $openlayers_presets;

  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'report_items_locations';
  $openlayers_presets->title = 'Report Items (Locations)';
  $openlayers_presets->description = 'This map will show Report Items from the Report Items\' Place WKT field';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '240px',
    'image_path' => 'sites/default/themes/devtrack_theme/openlayers/img/',
    'css_path' => 'sites/default/themes/devtrack_theme/openlayers/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 1,
    'center' => array(
      'initial' => array(
        'centerpoint' => '32,1.2',
        'zoom' => '6',
      ),
      'restrict' => array(
        'restrictextent' => 1,
        'restrictedExtent' => '3285827.410659,-159925.03252,3902215.606641,466247.10308',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'roundedCorner' => 1,
        'roundedCornerColor' => 'black',
      ),
      'openlayers_behavior_mouseposition' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'side_block_map_openlayers_1',
        'point_zoom_level' => '8',
      ),
    ),
    'default_layer' => 'uganda_basemap',
    'layers' => array(
      'osm_mapnik' => 'osm_mapnik',
      'uganda_basemap' => 'uganda_basemap',
      'side_block_map_openlayers_1' => 'side_block_map_openlayers_1',
    ),
    'layer_styles' => array(
      'side_block_map_openlayers_3' => array(
        'default' => 'default',
        'select' => 'default',
        'temporary' => 'default',
      ),
      'side_block_map_openlayers_1' => array(
        'default' => 'placetype',
        'select' => 'placetype',
        'temporary' => 'placetype',
      ),
    ),
    'layer_activated' => array(
      'side_block_map_openlayers_1' => 'side_block_map_openlayers_1',
    ),
    'layer_switcher' => array(),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  $export['report_items_locations'] = $openlayers_presets;

  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'report_items_report_items';
  $openlayers_presets->title = 'Report Items (Report Items)';
  $openlayers_presets->description = 'This map will show Report Items from the Report Items WKT field';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '240px',
    'image_path' => 'sites/default/themes/devtrack_theme/openlayers/img/',
    'css_path' => 'sites/default/themes/devtrack_theme/openlayers/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 1,
    'center' => array(
      'initial' => array(
        'centerpoint' => '32,1.2',
        'zoom' => '6',
      ),
      'restrict' => array(
        'restrictextent' => 1,
        'restrictedExtent' => '3285827.410659,-159925.03252,3902215.606641,466247.10308',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'roundedCorner' => 1,
        'roundedCornerColor' => 'black',
      ),
      'openlayers_behavior_mouseposition' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'side_block_map_openlayers_3',
        'point_zoom_level' => '8',
      ),
    ),
    'default_layer' => 'uganda_basemap',
    'layers' => array(
      'osm_mapnik' => 'osm_mapnik',
      'uganda_basemap' => 'uganda_basemap',
      'side_block_map_openlayers_3' => 'side_block_map_openlayers_3',
    ),
    'layer_styles' => array(
      'side_block_map_openlayers_3' => array(
        'default' => 'devtrac_default',
        'select' => 'devtrac_default',
        'temporary' => 'devtrac_default',
      ),
    ),
    'layer_activated' => array(
      'side_block_map_openlayers_3' => 'side_block_map_openlayers_3',
    ),
    'layer_switcher' => array(),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  $export['report_items_report_items'] = $openlayers_presets;

  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'side_block_map';
  $openlayers_presets->title = 'Places Map Block';
  $openlayers_presets->description = 'Full map of Uganda with geoserver layers on top';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '240px',
    'image_path' => 'sites/default/themes/devtrack_theme/openlayers/img/',
    'css_path' => 'sites/default/themes/devtrack_theme/openlayers/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 1,
    'center' => array(
      'initial' => array(
        'centerpoint' => '32.208740234366, 1.1780320750401',
        'zoom' => '6',
      ),
      'restrict' => array(
        'restrictextent' => 1,
        'restrictedExtent' => '3285827.410659,-159925.03252,3902215.606641,466247.10308',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'side_block_map_openlayers_2' => 'side_block_map_openlayers_2',
        ),
      ),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'roundedCorner' => 1,
        'roundedCornerColor' => '#000000',
      ),
      'openlayers_behavior_mouseposition' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'side_block_map_openlayers_2',
        'point_zoom_level' => '7',
      ),
    ),
    'default_layer' => 'uganda_basemap',
    'layers' => array(
      'uganda_basemap' => 'uganda_basemap',
      'osm_mapnik' => 'osm_mapnik',
      'side_block_map_openlayers_2' => 'side_block_map_openlayers_2',
    ),
    'layer_styles' => array(
      'side_block_map_openlayers_2' => array(
        'default' => 'placetype',
        'select' => 'placetype',
        'temporary' => 'placetype',
      ),
    ),
    'layer_activated' => array(
      'side_block_map_openlayers_2' => 'side_block_map_openlayers_2',
    ),
    'layer_switcher' => array(
      'side_block_map_openlayers_2' => 'side_block_map_openlayers_2',
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  $export['side_block_map'] = $openlayers_presets;

  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'singlecolumnblock';
  $openlayers_presets->title = 'Single Column Block Preset (Obsolete)';
  $openlayers_presets->description = 'To be used in a single column block';
  $openlayers_presets->data = array(
    'width' => '200px',
    'height' => '200px',
    'image_path' => 'sites/default/themes/devtrack_theme/openlayers/img/',
    'css_path' => 'sites/default/themes/devtrack_theme/openlayers/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '31.772460936236, 1.2303741773835',
        'zoom' => '7',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '3265389.847758,-161435.003709,3898899.938072,472075.086605',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'roundedCorner' => 1,
        'roundedCornerColor' => 'darkblue',
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(),
    ),
    'default_layer' => 'osm_mapnik',
    'layers' => array(
      'osm_mapnik' => 'osm_mapnik',
      'place_openlayers_1' => 'place_openlayers_1',
    ),
    'layer_styles' => array(
      'place_openlayers_1' => array(
        'default' => 'devtrac_default',
        'select' => 'devtrac_default',
        'temporary' => 'devtrac_default',
      ),
    ),
    'layer_activated' => array(
      'place_openlayers_1' => 'place_openlayers_1',
    ),
    'layer_switcher' => array(),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  $export['singlecolumnblock'] = $openlayers_presets;

  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'uganda_map';
  $openlayers_presets->title = 'Uganda Map';
  $openlayers_presets->description = 'Full map of Uganda with geoserver layers on top';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '600px',
    'image_path' => 'sites/default/themes/devtrack_theme/openlayers/img/',
    'css_path' => 'sites/default/themes/devtrack_theme/openlayers/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '32.153808593745, 1.5844072537417',
        'zoom' => '7',
      ),
      'restrict' => array(
        'restrictextent' => 1,
        'restrictedExtent' => '3280935.44085,-166039.994781,3899769.621736,482146.004961',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'field_trip_report_items_openlayers_3' => 'field_trip_report_items_openlayers_3',
          'findplaces_districts_openlayers_1' => 0,
        ),
      ),
      'openlayers_behavior_fullscreen' => array(
        'activated' => 0,
      ),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'roundedCorner' => 1,
        'roundedCornerColor' => '#000000',
      ),
      'openlayers_behavior_mouseposition' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_permalink' => array(),
      'openlayers_behavior_scaleline' => array(),
    ),
    'default_layer' => 'uganda_basemap',
    'layers' => array(
      'osm_mapnik' => 'osm_mapnik',
      'uganda_basemap' => 'uganda_basemap',
      'u-map-it-schools' => 'u-map-it-schools',
      'u-map-it-wash' => 'u-map-it-wash',
      'field_trip_report_items_openlayers_3' => 'field_trip_report_items_openlayers_3',
      'u-map-it-health' => 'u-map-it-health',
    ),
    'layer_styles' => array(
      'user_report_items_map_openlayers_3' => array(
        'default' => 'Wash',
        'select' => 'Wash',
        'temporary' => 'Wash',
      ),
      'user_report_items_map_openlayers_1' => array(
        'default' => 'School',
        'select' => 'School',
        'temporary' => 'School',
      ),
      'field_trip_report_items_openlayers_3' => array(
        'default' => 'placetype',
        'select' => 'placetype',
        'temporary' => 'placetype',
      ),
      'u-map-it-health' => array(
        'default' => 'devtrac_default',
        'select' => 'devtrac_default',
        'temporary' => 'devtrac_default',
      ),
      'u-map-it-schools' => array(
        'default' => 'devtrac_default',
        'select' => 'devtrac_default',
        'temporary' => 'devtrac_default',
      ),
      'u-map-it-wash' => array(
        'default' => 'devtrac_default',
        'select' => 'devtrac_default',
        'temporary' => 'devtrac_default',
      ),
    ),
    'layer_activated' => array(
      'field_trip_report_items_openlayers_3' => 'field_trip_report_items_openlayers_3',
    ),
    'layer_switcher' => array(
      'field_trip_report_items_openlayers_3' => 'field_trip_report_items_openlayers_3',
      'u-map-it-health' => 'u-map-it-health',
      'u-map-it-schools' => 'u-map-it-schools',
      'u-map-it-wash' => 'u-map-it-wash',
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default_select',
      'temporary' => 'default',
    ),
  );
  $export['uganda_map'] = $openlayers_presets;

  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'user_trip_reports';
  $openlayers_presets->title = 'User Trip Reports';
  $openlayers_presets->description = 'Map to show the user trip reports';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => 'sites/default/themes/devtrack_theme/openlayers/img/',
    'css_path' => 'sites/default/themes/devtrack_theme/openlayers/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '32,1.2',
        'zoom' => '6',
      ),
      'restrict' => array(
        'restrictextent' => 1,
        'restrictedExtent' => '3285827.410659,-159925.03252,3902215.606641,466247.10308',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'user_report_items_map_openlayers_1' => 'user_report_items_map_openlayers_1',
          'user_report_items_map_openlayers_3' => 'user_report_items_map_openlayers_3',
        ),
      ),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'roundedCorner' => 1,
        'roundedCornerColor' => '#000000',
      ),
      'openlayers_behavior_mouseposition' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_scaleline' => array(),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'user_report_items_map_openlayers_3',
        'point_zoom_level' => '7',
      ),
    ),
    'default_layer' => 'uganda_basemap',
    'layers' => array(
      'osm_mapnik' => 'osm_mapnik',
      'uganda_basemap' => 'uganda_basemap',
      'user_report_items_map_openlayers_1' => 'user_report_items_map_openlayers_1',
      'user_report_items_map_openlayers_3' => 'user_report_items_map_openlayers_3',
    ),
    'layer_styles' => array(
      'field_trip_places_to_visit_openlayers_1' => array(
        'default' => 'placetype',
        'select' => 'placetype',
        'temporary' => 'placetype',
      ),
      'user_report_items_map_openlayers_1' => array(
        'default' => 'devtrac_default',
        'select' => 'devtrac_default',
        'temporary' => 'devtrac_default',
      ),
      'user_report_items_map_openlayers_3' => array(
        'default' => 'placetype',
        'select' => 'placetype',
        'temporary' => 'placetype',
      ),
    ),
    'layer_activated' => array(
      'user_report_items_map_openlayers_1' => 'user_report_items_map_openlayers_1',
      'user_report_items_map_openlayers_3' => 'user_report_items_map_openlayers_3',
    ),
    'layer_switcher' => array(),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  $export['user_trip_reports'] = $openlayers_presets;

  return $export;
}
