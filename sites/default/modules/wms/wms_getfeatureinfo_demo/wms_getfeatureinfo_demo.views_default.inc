<?php

/**
 * Implementation of hook_views_default_views().
 */
function wms_getfeatureinfo_demo_views_default_views() {
  $views = array();

  // Exported view: canada
  $view = new view;
  $view->name = 'canada';
  $view->description = 'Canada Getfeatureinfo Demo';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => 'Title',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'nid' => array(
      'operator' => '<',
      'value' => array(
        'value' => '0',
        'min' => '',
        'max' => '',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Canada');
  $handler->override_option('footer', 'Map hosted by <a href="http://www.dmsolutions.ca/">DMSolutions</a>');
  $handler->override_option('footer_format', '1');
  $handler->override_option('footer_empty', 1);
  $handler = $view->new_display('openlayers', 'Canada Openlayers Data', 'openlayers_1');
  $handler->override_option('style_plugin', 'openlayers_data');
  $handler->override_option('row_plugin', '');
  $handler->override_option('displays', array());
  $handler = $view->new_display('page', 'Canada Map Page', 'page_1');
  $handler->override_option('style_plugin', 'openlayers_map');
  $handler->override_option('style_options', array(
    'preset' => 'canada_getfeatureinfo_demo',
  ));
  $handler->override_option('path', 'openlayers/wms/canada/demo');
  $handler->override_option('menu', array(
    'type' => 'normal',
    'title' => 'Canada',
    'description' => 'Canada Getfeatureinfo Demo',
    'weight' => '10',
    'name' => 'primary-links',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));

  $views[$view->name] = $view;

  return $views;
}
