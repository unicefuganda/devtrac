<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function heatclick_user_default_permissions() {
  $permissions = array();

  // Exported permission: count click_heatmap clicks
  $permissions['count click_heatmap clicks'] = array(
    'name' => 'count click_heatmap clicks',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'editor',
      '2' => 'unicef user',
    ),
  );

  // Exported permission: view heatmaps
  $permissions['view heatmaps'] = array(
    'name' => 'view heatmaps',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'editor',
      '2' => 'unicef user',
    ),
  );

  return $permissions;
}
