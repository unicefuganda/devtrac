<?php

/**
 * Implementation of hook_views_default_views().
 */
function devtrac_find_views_default_views() {
  $views = array();

  // Exported view: trip_reports_search
  $view = new view;
  $view->name = 'trip_reports_search';
  $view->description = 'Trip Reports Search page and block';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'field_ftritem_place_nid' => array(
      'label' => 'Place',
      'required' => 1,
      'delta' => -1,
      'id' => 'field_ftritem_place_nid',
      'table' => 'node_data_field_ftritem_place',
      'field' => 'field_ftritem_place_nid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
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
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'tid' => array(
      'label' => 'This PlaceType is used as tid_rendered in the style the output is rewritten',
      'alter' => array(
        'alter_text' => 1,
        'text' => '/sites/default/themes/devtrack_theme/icons/[tid-name]_c.png',
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
      'type' => 'separator',
      'separator' => ', ',
      'link_to_taxonomy' => 0,
      'limit' => 1,
      'vids' => array(
        '1' => 1,
        '4' => 0,
        '6' => 0,
        '5' => 0,
        '2' => 0,
      ),
      'exclude' => 0,
      'id' => 'tid',
      'table' => 'term_node',
      'field' => 'tid',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'field_ftritem_place_nid',
    ),
    'field_ftritem_public_summary_value' => array(
      'label' => '',
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
        'trim' => 1,
        'max_length' => '100',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 1,
        'strip_tags' => 1,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'none',
      'format' => 'plain',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_ftritem_public_summary_value',
      'table' => 'node_data_field_ftritem_public_summary',
      'field' => 'field_ftritem_public_summary_value',
      'relationship' => 'none',
    ),
    'field_place_lat_long_openlayers_wkt' => array(
      'label' => 'Lat-Long',
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
      'label_type' => 'widget',
      'format' => 'openlayers_wkt',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_place_lat_long_openlayers_wkt',
      'table' => 'node_data_field_place_lat_long',
      'field' => 'field_place_lat_long_openlayers_wkt',
      'relationship' => 'field_ftritem_place_nid',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'ftritem' => 'ftritem',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'tid' => array(
      'operator' => 'or',
      'value' => '',
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'tid_op',
        'identifier' => 'district',
        'label' => 'District',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
      ),
      'type' => 'textfield',
      'limit' => TRUE,
      'vid' => '6',
      'id' => 'tid',
      'table' => 'term_node',
      'field' => 'tid',
      'hierarchy' => 0,
      'relationship' => 'field_ftritem_place_nid',
      'reduce_duplicates' => 1,
    ),
    'term_node_tid_depth' => array(
      'operator' => 'or',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'term_node_tid_depth_op',
        'identifier' => 'placetype',
        'label' => 'Location Type',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
        'reduce' => 0,
      ),
      'type' => 'select',
      'limit' => TRUE,
      'vid' => '1',
      'depth' => '3',
      'id' => 'term_node_tid_depth',
      'table' => 'node',
      'field' => 'term_node_tid_depth',
      'hierarchy' => 1,
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'field_ftritem_place_nid',
      'reduce_duplicates' => 0,
    ),
    'date_filter' => array(
      'operator' => 'between',
      'value' => array(
        'min' => NULL,
        'max' => NULL,
        'value' => NULL,
        'default_date' => 'now -1 month',
        'default_to_date' => 'now',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'operator' => 'date_filter_op',
        'label' => 'Last Updated',
        'use_operator' => 0,
        'identifier' => 'date_filter',
        'optional' => 1,
        'remember' => 0,
      ),
      'date_fields' => array(
        'node.changed' => 'node.changed',
      ),
      'date_method' => 'AND',
      'granularity' => 'month',
      'form_type' => 'date_select',
      'default_date' => 'now -1 month',
      'default_to_date' => 'now',
      'year_range' => '-1:+0',
      'id' => 'date_filter',
      'table' => 'node',
      'field' => 'date_filter',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'role',
    'role' => array(
      '1' => 1,
      '5' => 5,
    ),
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Trip Reports');
  $handler->override_option('empty', 'Sorry, there are no Trip Reports that match these criteria');
  $handler->override_option('empty_format', '1');
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('exposed_block', TRUE);
  $handler = $view->new_display('openlayers', 'trip_report_search_data', 'openlayers_1');
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'ftritem' => 'ftritem',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'tid' => array(
      'operator' => 'or',
      'value' => '',
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'tid_op',
        'identifier' => 'district',
        'label' => 'District',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
      ),
      'type' => 'textfield',
      'limit' => TRUE,
      'vid' => '6',
      'id' => 'tid',
      'table' => 'term_node',
      'field' => 'tid',
      'hierarchy' => 0,
      'relationship' => 'field_ftritem_place_nid',
      'reduce_duplicates' => 1,
    ),
    'term_node_tid_depth' => array(
      'operator' => 'or',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'term_node_tid_depth_op',
        'identifier' => 'placetype',
        'label' => 'Location Type',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
        'reduce' => 0,
      ),
      'type' => 'select',
      'limit' => TRUE,
      'vid' => '1',
      'depth' => '3',
      'id' => 'term_node_tid_depth',
      'table' => 'node',
      'field' => 'term_node_tid_depth',
      'hierarchy' => 1,
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'field_ftritem_place_nid',
      'reduce_duplicates' => 0,
    ),
    'date_filter' => array(
      'operator' => 'between',
      'value' => array(
        'min' => NULL,
        'max' => NULL,
        'value' => NULL,
        'default_date' => 'now -1 month',
        'default_to_date' => 'now',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'operator' => 'date_filter_op',
        'label' => 'Last Updated',
        'use_operator' => 0,
        'identifier' => 'date_filter',
        'optional' => 1,
        'remember' => 0,
      ),
      'date_fields' => array(
        'node.changed' => 'node.changed',
      ),
      'date_method' => 'AND',
      'granularity' => 'month',
      'form_type' => 'date_select',
      'default_date' => 'now -1 month',
      'default_to_date' => 'now',
      'year_range' => '-1:+0',
      'id' => 'date_filter',
      'table' => 'node',
      'field' => 'date_filter',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'status_extra' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status_extra',
      'table' => 'node',
      'field' => 'status_extra',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('style_plugin', 'openlayers_data');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'data_source' => array(
      'value' => 'openlayers_wkt',
      'other_lat' => 'title',
      'other_lon' => 'title',
      'openlayers_wkt' => 'field_place_lat_long_openlayers_wkt',
      'other_top' => 'title',
      'other_right' => 'title',
      'other_bottom' => 'title',
      'other_left' => 'title',
      'name_field' => 'title',
      'keep_orig_name_field' => 0,
      'description_field' => 'field_ftritem_public_summary_value',
      'keep_orig_desc_field' => 0,
    ),
  ));
  $handler->override_option('row_plugin', '');
  $handler->override_option('displays', array());
  $handler = $view->new_display('page', 'Trip Report Search Map', 'page_1');
  $handler->override_option('style_plugin', 'openlayers_map');
  $handler->override_option('style_options', array(
    'preset' => 'tripreports',
  ));
  $handler->override_option('path', 'tripreports/map');
  $handler->override_option('menu', array(
    'type' => 'default tab',
    'title' => 'Trip Reports',
    'description' => 'Trip Reports Map',
    'weight' => '0',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'tab',
    'title' => 'Map',
    'description' => 'Trip Reports Map',
    'weight' => '0',
    'name' => 'navigation',
  ));
  $handler = $view->new_display('page', 'Trip Report Search List', 'page_2');
  $handler->override_option('path', 'tripreports/list');
  $handler->override_option('menu', array(
    'type' => 'tab',
    'title' => 'List',
    'description' => 'Trip Reports List',
    'weight' => '1',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler = $view->new_display('block', 'Trip Report Search List Block', 'block_1');
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);

  $views[$view->name] = $view;

  return $views;
}