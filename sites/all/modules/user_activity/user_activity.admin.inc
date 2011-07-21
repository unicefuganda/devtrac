<?php
/* $Id: user_activity.admin.inc,v 1.1.2.1 2008/07/18 19:15:14 sanduhrs Exp $ */

/**
 * User activity
 */

/**
 * Settings page
 */
function user_activity_settings() {
  $weighting = drupal_map_assoc(array(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25));
  $form['user_activity'] = array(
    '#type' => 'fieldset',
    '#title' => t('Calculation options'),
    '#description' => t('Adjust the Options to influence the activity calculation.'),
  );
  $form['user_activity']['user_activity_pis'] = array(
    '#type' => 'select',
    '#title' => t('Page impressions'),
    '#default_value' => variable_get('user_activity_pis', 1),
    '#options' => $weighting,
  );
  $form['user_activity']['user_activity_logins'] = array(
    '#type' => 'select',
    '#title' => t('User logins'),
    '#default_value' => variable_get('user_activity_logins', 1),
    '#options' => $weighting,
  );
  $form['user_activity']['user_activity_nodes'] = array(
    '#type' => 'select',
    '#title' => t('Nodes created'),
    '#default_value' => variable_get('user_activity_nodes', 1),
    '#options' => $weighting,
  );
  $form['user_activity']['user_activity_comments'] = array(
    '#type' => 'select',
    '#title' => t('Comments created'),
    '#default_value' => variable_get('user_activity_comments', 1),
    '#options' => $weighting,
  );
  return system_settings_form($form);
}

function user_activity_settings_submit($form_id, $form_values) {
  if (is_numeric($form_values['user_activity_pis']))      variable_set('user_activity_pis',      $form_values['user_activity_pis']);
  if (is_numeric($form_values['user_activity_logins']))   variable_set('user_activity_logins',   $form_values['user_activity_logins']);
  if (is_numeric($form_values['user_activity_pis']))      variable_set('user_activity_nodes',    $form_values['user_activity_nodes']);
  if (is_numeric($form_values['user_activity_comments'])) variable_set('user_activity_comments', $form_values['user_activity_comments']);
}