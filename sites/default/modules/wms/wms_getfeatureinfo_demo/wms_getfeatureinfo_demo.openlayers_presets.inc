<?php

/**
 * Implementation of hook_openlayers_presets().
 */
function wms_getfeatureinfo_demo_openlayers_presets() {
  $export = array();
  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'canada_getfeatureinfo_demo';
  $openlayers_presets->title = 'Canada Getfeatureinfo Demo';
  $openlayers_presets->description = 'Canada Getfeatureinfo Demo';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => '',
    'css_path' => '',
    'proxy_host' => 'proxy?request=',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '-99.316406246057, 56.848971978764',
        'zoom' => '3',
      ),
      'restrict' => array(
        'restrictextent' => 1,
        'restrictedExtent' => '-16319611.284075,4852834.0509,-4891969.809375,11818999.05945',
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
        'zoomWheelEnabled' => 1,
      ),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_wmsgetfeatureinfo' => array(
        'getfeatureinfo_processlink' => 0,
        'getfeatureinfo_usevisiblelayers' => 1,
        'getfeatureinfo_layers' => 'Canada Bathymetry',
        'getfeatureinfo_info_format' => 'text/html',
        'getfeatureinfo_htmlelement' => 'getfeatureinfo',
      ),
    ),
    'default_layer' => 'Canada Bathymetry',
    'layers' => array(
      'Canada Bathymetry' => 'Canada Bathymetry',
      'Canada Rail' => 'Canada Rail',
      'Canada Populated Place' => 'Canada Populated Place',
      'Canada Park' => 'Canada Park',
    ),
    'layer_styles' => array(),
    'layer_activated' => array(
      'Canada Populated Place' => 'Canada Populated Place',
      'Canada Park' => 'Canada Park',
    ),
    'layer_switcher' => array(
      'Canada Rail' => 'Canada Rail',
      'Canada Populated Place' => 'Canada Populated Place',
      'Canada Park' => 'Canada Park',
    ),
    'projection' => '4326',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'Red Outline',
      'select' => 'Red Outline',
      'temporary' => 'Red Outline',
    ),
  );

  $export['canada_getfeatureinfo_demo'] = $openlayers_presets;
  return $export;
}
