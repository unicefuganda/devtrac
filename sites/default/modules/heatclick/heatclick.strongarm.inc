<?php

/**
 * Implementation of hook_strongarm().
 */
function heatclick_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'click_heatmap_admin_password';
  $strongarm->value = 'Ynaqh1!';
  $export['click_heatmap_admin_password'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'click_heatmap_admin_username';
  $strongarm->value = 'reinier';
  $export['click_heatmap_admin_username'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'click_heatmap_change_login';
  $strongarm->value = 1;
  $export['click_heatmap_change_login'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'click_heatmap_scope';
  $strongarm->value = 'all';
  $export['click_heatmap_scope'] = $strongarm;

  return $export;
}
