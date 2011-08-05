<?php

/**
 * Implementation of hook_custom_breadcrumbs_config_features_default_settings().
 */
function devtrac_breadcrumbs_custom_breadcrumbs_config_features_default_settings() {
  $custom_breadcrumbs_configs = array();

  $custom_breadcrumbs_configs[] = array(
    'actionitem-5' => array(
      'name' => 'actionitem',
      'titles' => '[title]',
      'paths' => 'node/[nid]',
      'visibility_php' => '',
      'node_type' => 'actionitem',
      'language' => '',
      'machine_name' => 'actionitem-5',
    ),
  );
  $custom_breadcrumbs_configs[] = array(
    'fieldtrip-4' => array(
      'name' => 'fieldtrip',
      'titles' => '[title]',
      'paths' => 'node/[nid]',
      'visibility_php' => '',
      'node_type' => 'fieldtrip',
      'language' => '',
      'machine_name' => 'fieldtrip-4',
    ),
  );
  $custom_breadcrumbs_configs[] = array(
    'ftritem-1' => array(
      'name' => 'ftritem',
      'titles' => '[field_ftritem_field_trip-title]
[field_ftritem_place-title]',
      'paths' => 'node/[field_ftritem_field_trip-nid]
node/[field_ftritem_place-nid]
',
      'visibility_php' => '',
      'node_type' => 'ftritem',
      'language' => '',
      'machine_name' => 'ftritem-1',
    ),
  );
  return $custom_breadcrumbs_configs;
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
    'node/all-8' => array(
      'name' => 'node/*',
      'titles' => '[title]',
      'paths' => 'node/[nid]',
      'visibility_php' => '$arg2 = arg(2);
$result = ((arg(0) == \'node\') && (is_numeric(arg(1))) && (!isset($arg2)));
return $result;',
      'specific_path' => 'node/*',
      'language' => '',
      'machine_name' => 'node/all-8',
    ),
  );
  $custom_breadcrumbs_paths_configs[] = array(
    'node/all-9' => array(
      'name' => 'node/*',
      'titles' => '<?php
$ri = node_load(arg(1));
$ft = node_load($ri->field_ftritem_field_trip[0][\'nid\']);
$p = node_load($ri->field_ftritem_place[0][\'nid\']);
return array(
  $ft->title,
  $p->title,
);
?>',
      'paths' => '<?php
$ri = node_load(arg(1));
return array(
  \'node/\'. $ri->field_ftritem_field_trip[0][\'nid\'],
  \'node/\'. $ri->field_ftritem_place[0][\'nid\'],
);
?>',
      'visibility_php' => '$result = node_load(arg(1));
return ($result->type == \'ftritem\');',
      'specific_path' => 'node/*',
      'language' => '',
      'machine_name' => 'node/all-9',
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
$realname = $user->realname;
return array (
  $realname,
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
  $fieldtrip->title,
);
?>',
      'paths' => '<?php
return array(
  \'/node/\'. arg(2),
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
      'visibility_php' => '',
      'views_path' => 'taxonomy/term/%',
      'language' => '',
      'machine_name' => 'taxonomy/term/arg-2',
    ),
  );
  return $custom_breadcrumbs_views_configs;
}
