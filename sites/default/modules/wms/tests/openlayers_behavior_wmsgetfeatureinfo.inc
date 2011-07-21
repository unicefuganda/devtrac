<?php
// $Id: openlayers_behavior_getfeatureinfo.inc,v 1.1.2.2 2010/05/17 21:37:12 tmcw Exp $

/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * WMSGetfeatureinfo Behavior
 */


class openlayers_behavior_getfeatureinfo extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array();
  }

  function options_form($defaults) {
  	// TODO only return form when there is at least 1 WMS layer
    return array(
      'getfeatureinfo_layers' => array(
        '#type' => 'select',
        '#options' => $this->map['layers'], // TODO filter this on WMS layers only
        '#description' => t('Select the layer from which points are 
          pulled. This is likely a VirtualVector layer.'),
        '#default_value' => isset($defaults['getfeatureinfo_layers']) ? 
          $defaults['virtuallayer'] : NULL
      ),
/*      'getfeatureinfo_htmlelement' => array(
        '#type' => 'select',
        '#options' => array('html' => t('html'), 'url' => t('url')),
        '#description' => t('Is the link an HTML link or just a URL?'),
        '#default_value' => isset($defaults['linkas']) ? 
          $defaults['linkas'] : 'html' 
      ),*/
      'getfeatureinfo_htmlelement' => array(
        '#type' => 'textfield',
        '#description' => t('An HTML element (#id!) that will be filled
          with the query result.'),
        '#default_value' => isset($defaults['getfeatureinfo_htmlelement']) ? 
          $defaults['getfeatureinfo_htmlelement'] : NULL
      ),
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
/*    drupal_add_js(drupal_get_path('module', 'openlayers') 
      .'/includes/behaviors/js/getfeatureinfo.js');*/
    drupal_add_js(drupal_get_path('module', 'openlayers') 
      .'/includes/behaviors/js/openlayers_behavior_getfeatureinfo.js');
    return $this->options;
  }
}

