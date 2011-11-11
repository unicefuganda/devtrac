<?php
// $Id$

/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * WMSGetfeatureinfo Behavior
 */


class openlayers_behavior_wmsgetfeatureinfo extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array();
  }

  function options_form($defaults) {
    $info_formats = Array(
      'text/plain' => 'text/plain',
      'text/html' => 'text/html',
      'application/vnd.ogc.gml' => 'application/vnd.ogc.gml'
    );
    // TODO only return form when there is at least 1 WMS layer
    return array(
    'getfeatureinfo_usevisiblelayers' => array(
        '#title' => "Use All Visible Layers",
        '#type' => 'checkbox',
        '#description' => t('Query all visible WMS layers on the map.'),
        '#default_value' => isset($defaults['getfeatureinfo_usevisiblelayers']) ?
          $defaults['getfeatureinfo_usevisiblelayers'] : TRUE
      ),
    'getfeatureinfo_layers' => array(
        '#title' => "Only Query",
        '#type' => 'select',
        '#options' => $this->map['layers'], // TODO filter this on WMS layers only
        '#description' => t("Select the layer from which points are
          pulled. This must be a WMS layer. 'Use Visible Layers' must be unchecked for this option to have effect"), //TODO Fix this in javascript
        '#default_value' => isset($defaults['getfeatureinfo_layers']) ?
          $defaults['getfeatureinfo_layers'] : NULL
      ),
    'getfeatureinfo_info_format' => array(
        '#title' => "Format ",
        '#type' => 'select',
        '#options' => $info_formats,
        '#description' => t("The format the server should return. text formats are displayed as-is. The Gml
          format is displayed in a Drupal table, and themeable."),
        '#default_value' => isset($defaults['getfeatureinfo_info_format']) ?
          $defaults['getfeatureinfo_info_format'] : NULL
      ),
      'getfeatureinfo_htmlelement' => array(
        '#type' => 'textfield',
        '#description' => t("An HTML element (#id!) that will be filled
          with the query result. Ommit the # here. If you use the GetFeatureInfo block, the value should be 'getfeatureinfo'"),
        '#default_value' => isset($defaults['getfeatureinfo_htmlelement']) ?
          $defaults['getfeatureinfo_htmlelement'] : "getfeatureinfo"
      ),
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'wms') . '/includes/behaviors/js/openlayers_behavior_wmsgetfeatureinfo.js');
    return $this->options;
  }
}

