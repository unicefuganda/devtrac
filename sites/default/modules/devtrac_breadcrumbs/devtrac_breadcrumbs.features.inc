<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function devtrac_breadcrumbs_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_custom_breadcrumbs_paths_config_features_default_settings().
 */
function devtrac_breadcrumbs_custom_breadcrumbs_paths_config_features_default_settings() {
  $custom_breadcrumbs_paths_configs = array();

  $custom_breadcrumbs_paths_configs[] = array(
    'm_action_item/all-4' => array(
      'name' => 'm_action_item/*',
      'titles' => '<?php
  $titles = array();
  $titles[] = "Report Items";
  $titles[] = "Action Items";
  $titles[] = "Help";
  $titles[] = "Logout";
  return $titles;
?>',
      'paths' => '<?php
 $nid = devtrack_module_getcurrentfieldtrip();
 $path = \'m_field_trip/\'. $nid;
 $paths = array();
 $paths[] = $path ."/report_items";
 $paths[] = $path ."/action_items";
 $paths[] = $path ."/help";
 $paths[] = "logout";
 return $paths;
?>',
      'visibility_php' => 'global $user;
return (in_array(\'unicef user (Mobile)\', $user->roles));',
      'specific_path' => 'm_action_item/*',
      'language' => '',
      'machine_name' => 'm_action_item/all-4',
    ),
  );
  $custom_breadcrumbs_paths_configs[] = array(
    'm_field_trip/all-3' => array(
      'name' => 'm_field_trip/*',
      'titles' => '<?php
  $titles = array();
  $titles[] = "Report Items";
  $titles[] = "Action Items";
  $titles[] = "Help";
  $titles[] = "Logout";
  return $titles;
?>',
      'paths' => '<?php
 $nid = devtrack_module_getcurrentfieldtrip();
 $path = \'m_field_trip/\'. $nid;
 $paths = array();
 $paths[] = $path ."/report_items";
 $paths[] = $path ."/action_items";
 $paths[] = $path ."/help";
 $paths[] = "logout";
 return $paths;
?>',
      'visibility_php' => 'global $user;
return (in_array(\'unicef user (Mobile)\', $user->roles));',
      'specific_path' => 'm_field_trip/*',
      'language' => '',
      'machine_name' => 'm_field_trip/all-3',
    ),
  );
  $custom_breadcrumbs_paths_configs[] = array(
    'm_report_item/all-2' => array(
      'name' => 'm_report_item/*',
      'titles' => '<?php
  $titles = array();
  $titles[] = "Report Items";
  $titles[] = "Action Items";
  $titles[] = "Help";
  $titles[] = "Logout";
  return $titles;
?>',
      'paths' => '<?php
 $nid = devtrack_module_getcurrentfieldtrip();
 $path = \'m_field_trip/\'. $nid;
 $paths = array();
 $paths[] = $path ."/report_items";
 $paths[] = $path ."/action_items";
 $paths[] = $path ."/help";
 $paths[] = "logout";
 return $paths;
?>',
      'visibility_php' => 'global $user;
return (in_array(\'unicef user (Mobile)\', $user->roles));',
      'specific_path' => 'm_report_item/*',
      'language' => '',
      'machine_name' => 'm_report_item/all-2',
    ),
  );
  $custom_breadcrumbs_paths_configs[] = array(
    'node/add/actionitem-6' => array(
      'name' => 'node/add/actionitem',
      'titles' => '<?php
  $q = $_SERVER[\'REQUEST_URI\'];
  $r = substr($q, strpos($q, \'=%5Bnid%3A\') + 10);
  $nid = substr($r, 0, strpos($r, \'%5D\'));
  $node = node_load($nid);
  return array(
    $node->title,
  );
?>',
      'paths' => '<?php
  $q = $_SERVER[\'REQUEST_URI\'];
  $r = substr($q, strpos($q, \'=%5Bnid%3A\') + 10);
  $nid = substr($r, 0, strpos($r, \'%5D\'));
  return array(
    \'node/\'. $nid,
  );
?>',
      'visibility_php' => '',
      'specific_path' => 'node/add/actionitem',
      'language' => '',
      'machine_name' => 'node/add/actionitem-6',
    ),
  );
  $custom_breadcrumbs_paths_configs[] = array(
    'node/all-11' => array(
      'name' => 'fieldtrip',
      'titles' => '<?php
  $fieldtrip = node_load(arg(1));
  return array(
    \'Field Trip (\'. $fieldtrip->title .\')\',
  );
?>',
      'paths' => '<?php
  return array(
    \'node/\'. arg(1),
  );
?>',
      'visibility_php' => '$arg2 = arg(2);
$node = node_load(arg(1));
return ((isset($arg2)) && ($node->type == \'fieldtrip\'));',
      'specific_path' => 'node/*',
      'language' => '',
      'machine_name' => 'node/all-11',
    ),
  );
  $custom_breadcrumbs_paths_configs[] = array(
    'node/all-12' => array(
      'name' => 'place',
      'titles' => '<?php
  $location = node_load(arg(1));
  return array(
    \'Location (\'. $location->title .\')\',
  );
?>',
      'paths' => '<?php
  return array(
    \'node/\'. arg(1),
  );
?>',
      'visibility_php' => '$arg2 = arg(2);
$node = node_load(arg(1));
return ((isset($arg2)) && ($node->type == \'place\'));',
      'specific_path' => 'node/*',
      'language' => '',
      'machine_name' => 'node/all-12',
    ),
  );
  $custom_breadcrumbs_paths_configs[] = array(
    'node/all-13' => array(
      'name' => 'ftritem',
      'titles' => '<?php
  $arg2 = arg(2);
  $ftritem = node_load(arg(1));
  $fieldtrip = node_load($ftritem->field_ftritem_field_trip[0][\'nid\']);
  $location = node_load($ftritem->field_ftritem_place[0][\'nid\']);
  $titles = array(
    \'Field Trip (\'. $fieldtrip->title .\')\',
    \'Location (\'. $location->title .\')\',
  );
  if (isset($arg2)) {
    $titles[] = \'Site Report (\'. $ftritem->title .\')\';
  }
  return $titles;
?>',
      'paths' => '<?php
  $arg2 = arg(2);
  $ftritem = node_load(arg(1));
  $paths = array(
    \'node/\'. $ftritem->field_ftritem_field_trip[0][\'nid\'],
    \'node/\'. $ftritem->field_ftritem_place[0][\'nid\'],
  );
  if (isset($arg2)) {
    $paths[] = \'node/\'. arg(1);
  }
  return $paths;
?>',
      'visibility_php' => '$node = node_load(arg(1));
return ($node->type == \'ftritem\');',
      'specific_path' => 'node/*',
      'language' => '',
      'machine_name' => 'node/all-13',
    ),
  );
  $custom_breadcrumbs_paths_configs[] = array(
    'node/all-14' => array(
      'name' => 'actionitem',
      'titles' => '<?php
  $arg2 = arg(2);
  $actionitem = node_load(arg(1));
  $ftritem = node_load($actionitem->field_actionitem_ftreportitem[0][\'nid\']);
  $fieldtrip = node_load($ftritem->field_ftritem_field_trip[0][\'nid\']);
  $location = node_load($ftritem->field_ftritem_place[0][\'nid\']);
  $titles = array(
    \'Field Trip (\' .$fieldtrip->title .\')\',
    \'Location (\'. $location->title .\')\',
    \'Site Report (\'. $ftritem->title .\')\',
  );
  if (isset($arg2)) {
    $titles[] = \'Action Item (\'. $actionitem->title .\')\';
  }
  return $titles;
?>',
      'paths' => '<?php
  $arg2 = arg(2);
  $actionitem = node_load(arg(1));
  $ftritem = node_load($actionitem->field_actionitem_ftreportitem[0][\'nid\']);
  $paths = array(
    \'node/\'. $ftritem->field_ftritem_field_trip[0][\'nid\'],
    \'node/\'. $ftritem->field_ftritem_place[0][\'nid\'],
    \'node/\'. $actionitem->field_actionitem_ftreportitem[0][\'nid\'],
  );
  if (isset($arg2)) {
    $paths[] = \'node/\'. arg(1);
  }
  return $paths;
?>',
      'visibility_php' => '$node = node_load(arg(1));
return ($node->type == \'actionitem\');',
      'specific_path' => 'node/*',
      'language' => '',
      'machine_name' => 'node/all-14',
    ),
  );
  $custom_breadcrumbs_paths_configs[] = array(
    'node/all/edit/all-1' => array(
      'name' => 'node/*/edit/*',
      'titles' => '<?php
  $titles = array();
  $titles[] = "Report Items";
  $titles[] = "Action Items";
  $titles[] = "Help";
  $titles[] = "Logout";
  return $titles;
?>',
      'paths' => '<?php
 $nid = devtrack_module_getcurrentfieldtrip();
 $path = "m_field_trip/". $nid;
 $paths = array();
 $paths[] = $path ."/report_items";
 $paths[] = $path ."/action_items";
 $paths[] = $path ."/help";
 $paths[] = "logout";
 return $paths;
?>',
      'visibility_php' => 'global $user;
return FALSE;
return (in_array(\'unicef user (Mobile)\', $user->roles));',
      'specific_path' => 'node/*/edit/*',
      'language' => '',
      'machine_name' => 'node/all/edit/all-1',
    ),
  );
  $custom_breadcrumbs_paths_configs[] = array(
    'user/all-5' => array(
      'name' => 'user/*',
      'titles' => '<?php
  $user = user_load(arg(1));
  return array (
    $user->realname,
  );
?>',
      'paths' => '<?php
  return array (
    \'user/\'. arg(1),
  );
?>',
      'visibility_php' => '',
      'specific_path' => 'user/*',
      'language' => '',
      'machine_name' => 'user/all-5',
    ),
  );
  return $custom_breadcrumbs_paths_configs;
}

/**
 * Implementation of hook_custom_breadcrumbs_taxonomy_config_features_default_settings().
 */
function devtrac_breadcrumbs_custom_breadcrumbs_taxonomy_config_features_default_settings() {
  $custom_breadcrumbs_taxonomy_configs = array();

  $custom_breadcrumbs_taxonomy_configs[] = array(
    '2-1' => array(
      'name' => 'Funding Partners',
      'titles' => '',
      'paths' => 'taxonomy/term/62',
      'vid' => '2',
      'visibility_php' => '',
      'language' => '',
      'machine_name' => '2-1',
    ),
  );
  return $custom_breadcrumbs_taxonomy_configs;
}

/**
 * Implementation of hook_custom_breadcrumbs_views_config_features_default_settings().
 */
function devtrac_breadcrumbs_custom_breadcrumbs_views_config_features_default_settings() {
  $custom_breadcrumbs_views_configs = array();

  $custom_breadcrumbs_views_configs[] = array(
    'places-3' => array(
      'name' => 'places',
      'titles' => '<?php
  $fieldtrip = node_load(arg(2));
  return array(
    \'Field Trip (\'. $fieldtrip->title .\')\',
  );
?>',
      'paths' => '<?php
  return array(
    \'node/\'. arg(2),
  );
?>',
      'visibility_php' => '',
      'views_path' => 'places',
      'language' => '',
      'machine_name' => 'places-3',
    ),
  );
  $custom_breadcrumbs_views_configs[] = array(
    'taxonomy/term/arg-2' => array(
      'name' => 'taxonomy/term/%',
      'titles' => '[term]',
      'paths' => 'taxonomy/term/[term-id]',
      'visibility_php' => 'return TRUE;',
      'views_path' => 'taxonomy/term/%',
      'language' => '',
      'machine_name' => 'taxonomy/term/arg-2',
    ),
  );
  return $custom_breadcrumbs_views_configs;
}
