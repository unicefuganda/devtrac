<?php
// $Id: prod_check.admin.inc,v 1.7.2.2 2011/01/27 11:20:13 malc0mn Exp $

/**
 * Build status page.
 */
function prod_check_status() {
  drupal_set_title(t('Production check status'));

  $output = '';

  // Execute all functions per set as defined in the functions array in
  // _prod_check_functions().
  $functions = _prod_check_functions();
  unset($functions['prod_mon']);
  foreach ($functions as $set => $data) {
    $result = array();
    foreach ($data['functions'] as $function => $title) {
      $func = '_prod_check_' . $function;
      // $func() will execute the function with the name we composed above.
      $result = array_merge($result, $func());
    }
    $output .= '<h2>'.t($data['title']).'</h2>'."\n";
    $output .= '<div class="description"><p><em>'.t($data['description']).'</em></p></div>'."\n";
    $output .= theme('status_report', $result);
  }

  return $output;
}

/**
 * Build settings form.
 */
function prod_check_settings_form(&$form_state) {
  drupal_set_title(t('Production check settings'));
  $base = drupal_get_path('module', 'prod_check');
  drupal_add_css($base.'/css/prod-check.css');
  drupal_add_js($base.'/js/jquery.equalheights.js', 'module', 'header');
  drupal_add_js($base.'/js/jquery.maskedinput.min.js', 'module', 'header');
  drupal_add_js($base.'/js/prod-check.js', 'module', 'header');

  $form = array();

  // E-mail settings.
  $form['prod_check_general'] = array(
    '#type' => 'fieldset',
    '#title' => t('General settings'),
    '#description' => t('Settings to allow certain checks to function properly.'),
    '#collapsible' => FALSE,
  );
  $form['prod_check_general']['prod_check_sitemail'] = array(
    '#type' => 'textfield',
    '#title' => t('Sitemail check'),
    '#default_value' => variable_get('prod_check_sitemail', ''),
    '#size' => 60,
    '#description' => t('Enter (part of) the e-mail address you always use in the !link when developing a website. This is used in a regular expression in the "Site e-mail" check.', prod_check_link_array('site-information settings', 'admin/settings/site-information')),
    '#required' => FALSE,
  );

  $form['prod_check_apc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced APC settings'),
    '#description' => t(
      'These settings are used in the !link functionality.', prod_check_link_array('advanced APC', 'admin/reports/status/apc')),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // APC userd.
  $form['prod_check_apc']['prod_check_apcuser'] = array(
    '#type' => 'textfield',
    '#title' => t('APC advanced features username'),
    '#default_value' => variable_get('prod_check_apcuser', 'apc'),
    '#size' => 60,
    '#description' => t('The username for logging in to the APC settings page.'),
    '#required' => FALSE,
  );
  // APC password.
  $form['prod_check_apc']['prod_check_apcpass'] = array(
    '#type' => 'password_confirm',
    '#title' => t('APC advanced features password'),
    '#size' => 60,
    '#description' => t('The password for logging in to the APC settings page.'),
    '#required' => FALSE,
  );


  // XMLRPC settings.
  $form['prod_check_xmlrpc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Production monitor integration.'),
    '#description' => t('You can set up integration with the Production monitor module here.'),
    '#collapsible' => FALSE,
  );
  $form['prod_check_xmlrpc']['prod_check_enable_xmlrpc'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable XMLRPC API'),
    '#default_value' => variable_get('prod_check_enable_xmlrpc', 0),
    '#description' => t('Tick this box if you would like to the module to open up the XMLRPC api so that it can be queried externally to supply information to a base site for monitoring purposes.'),
    '#ahah' => array(
      'path' => 'admin/settings/prod-check/xmlrpc',
      'wrapper' => 'prod-check-xmlrpc',
      'effect' => 'fade',
    ),
    '#required' => FALSE,
  );
  // The #value here is necessary for the markup field to be rendered :-(
  $form['prod_check_xmlrpc']['xmlrpc'] = array(
    '#type' => 'markup',
    '#prefix' => '<div id="prod-check-xmlrpc">',
    '#value' => '&nbsp;',
    '#suffix' => '</div>',
  );
  // Only show when the checkbox above is selected.
  if (!isset($form_state['values']['prod_check_enable_xmlrpc'])) {
    $form_state['values']['prod_check_enable_xmlrpc'] = variable_get('prod_check_enable_xmlrpc', 0);
  }
  if ($form_state['values']['prod_check_enable_xmlrpc']) {
    $form['prod_check_xmlrpc']['xmlrpc']['prod_check_xmlrpc_key'] = array(
      '#type' => 'textfield',
      '#title' => t('API key'),
      '#default_value' => variable_get('prod_check_xmlrpc_key', ''),
      '#maxlength' => 128,
      '#size' => 60,
      '#description' => t('Enter a key here to ensure secure transfer of data over the API. Use a mixture of alphanumeric and special characters for increased security.'),
      '#required' => FALSE,
    );
    $form['prod_check_xmlrpc']['xmlrpc']['prod_check_module_list_day'] = array(
      '#type' => 'select',
      '#title' => t('Report module list every'),
      '#options' => array(t('Sunday'), t('Monday'), t('Tuesday'), t('Wednesday'), t('Thursday'), t('Friday'), t('Saturday')),
      '#default_value' => variable_get('prod_check_module_list_day', 0),
      '#description' => t('Defines which day the module list will be fetchable by Production monitor for an update status check.'),
      '#required' => FALSE,
    );
    $form['prod_check_xmlrpc']['xmlrpc']['prod_check_module_list_time'] = array(
      '#type' => 'textfield',
      '#title' => t('at this time'),
      '#default_value' => variable_get('prod_check_module_list_time', '03:00'),
      '#maxlength' => 5,
      '#size' => 5,
      '#description' => t('Defines what time (HH:MM) the module list will be fetchable by Production monitor for an update status check.'),
      '#required' => FALSE,
    );
  }

  // Nagios settings.
  $form['prod_check_nagios'] = array(
    '#type' => 'fieldset',
    '#title' => t('Nagios integration.'),
    '#description' => t('You can set up integration with the !link module here.', prod_check_link_array('Nagios', 'http://drupal.org/project/nagios')),
    '#collapsible' => FALSE,
  );
  $form['prod_check_nagios']['prod_check_enable_nagios'] = array(
    '#type' => 'checkbox',
    '#title' =>   t('Enable Nagios integration'),
    '#description' => t('Tick this box if you want to enable integration with Nagios. The !link module is required for this to function.', array('!link' => l(t('Nagios'), 'http://drupal.org/project/nagios', array('attributes' => array('title' => t('Nagios')))))),
    '#default_value' => variable_get('prod_check_enable_nagios', 0),
    '#ahah' => array(
      'path' => 'admin/settings/prod-check/nagios',
      'wrapper' => 'prod-check-nagios',
      'effect' => 'fade',
    ),
    '#required' => FALSE,
  );

  // The #value here is necessary for the markup field to be rendered :-(
  $form['prod_check_nagios']['nagios'] = array(
    '#type' => 'markup',
    '#prefix' => '<div id="prod-check-nagios">',
    '#value' => '&nbsp;',
    '#suffix' => '</div>',
  );
  // Only show when the checkbox above is selected.
  if (!isset($form_state['values']['prod_check_enable_nagios'])) {
    $form_state['values']['prod_check_enable_nagios'] = variable_get('prod_check_enable_nagios', 0);
  }
  // TODO: find a way to detect when this is rendered so we can adjust the
  // prod-check.js and apply equalheights/width
  if ($form_state['values']['prod_check_enable_nagios']) {
    $form['prod_check_nagios']['nagios']['settings'] = _prod_check_functions_as_form();
    $options = variable_get('prod_check_nagios_checks', array());
    if (!empty($options)) {
      // Just to increase readability of the source here.
      $monitor_settings = &$form['prod_check_nagios']['nagios']['settings']['prod_check_settings']['monitor_settings'];
      // Set default values to last saved state
      foreach (element_children($monitor_settings) as $set) {
        if (isset($options[$set])) {
          $monitor_settings[$set]['#default_value'] = $options[$set];
        }
        else {
          // No settings available, so uncheck all.
          $monitor_settings[$set]['#default_value'] = array();
        }
      }
    }
  }

  // Submit buttons.
  // Markup field for proper styling.
  $form['buttons'] = array(
    '#type' => 'markup',
    '#prefix' => '<div class="buttons">',
    '#value' => '&nbsp;',
    '#suffix' => '</div>',
  );
  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );
  $form['buttons']['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset to defaults'),
  );

  return $form;
}

/**
 * Parse the functions array and return a form fieldset with different sets of
 * checkboxes so it can be inserted 'as is' in another form array for rendering.
 * This is primlarily still here for integration with Nagios. Though not in use
 * now since Nagios would create far too much needless variables in my personal
 * opinion. It's left in for easy future integration with the
 * hook_nagios_settings().
 */
function _prod_check_functions_as_form($compatibility = 'all') {
  $form = array();

  $form['prod_check_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configure what data you wish to monitor with <strong>Nagios</strong> for this site.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['prod_check_settings']['monitor_settings'] = array(
    '#type' => 'markup',
    '#prefix' => '<div id="prod-check-settings">',
    '#suffix' => '</div>',
    '#tree' => TRUE,
  );

  $i = 1;
  $functions = _prod_check_functions();
  if ($compatibility == 'all') {
    unset($functions['prod_mon']);
  }
  foreach ($functions as $set => $data) {
    $rest = $i%2;
    $form['prod_check_settings']['monitor_settings'][$set] = array(
      '#type' => 'checkboxes',
      '#title' => t($data['title']),
      '#description' => t($data['description']),
      '#options' => $data['functions'],
      '#default_value' => array_keys($data['functions']),
      '#prefix' => '<div class="prod-check-settings '.(($rest) ? 'odd' : 'even').'">',
      '#suffix' => '</div>',
    );
    $i++;
  }

  return $form;
}

/**
 * Callback to add xmlrpc settings.
 */
function prod_check_enable_xmlrpc() {
  $form = _prod_check_ahah_helper();

  $xmlrpc = $form['prod_check_xmlrpc']['xmlrpc'];
  // Remove the wrapper so we don't double it up.
  unset($xmlrpc['#prefix'], $xmlrpc['#suffix']);

  $output = drupal_render($xmlrpc);

  // Final rendering callback.
  print drupal_json(array('status' => TRUE, 'data' => $output));
  exit();
}

/**
 * Callback to add nagios settings.
 */
function prod_check_enable_nagios() {
  $form = _prod_check_ahah_helper();

  $nagios = $form['prod_check_nagios']['nagios'];
  // Remove the wrapper so we don't double it up.
  unset($nagios['#prefix'], $nagios['#suffix']);

  $output = drupal_render($nagios);

  // Final rendering callback.
  print drupal_json(array('status' => TRUE, 'data' => $output));
  exit();
}

/**
 * Does the very standard things that must be done in any normal callback.
 */
function _prod_check_ahah_helper() {
  $form_state = array('storage' => NULL, 'submitted' => FALSE);
  $form_build_id = $_POST['form_build_id'];
  $form = form_get_cache($form_build_id, $form_state);
  $args = $form['#parameters'];
  $form_id = array_shift($args);
  $form_state['post'] = $form['#post'] = $_POST;
  // Enable the submit/validate handlers to determine whether AHAH-submittted.
  $form_state['ahah_submission'] = TRUE;
  $form['#programmed'] = $form['#redirect'] = FALSE;
  drupal_process_form($form_id, $form, $form_state);
  $form = drupal_rebuild_form($form_id, $form_state, $args, $form_build_id);

  return $form;
}

/**
 * Validation for settings form.
 */
function prod_check_settings_form_validate($form, &$form_state) {
  if (!empty($form_state['ahah_submission'])) {
    return;
  }

  // Had to add CSS again here since it was lost on form errors. Weird, doesn't
  // seem logical...
  $base = drupal_get_path('module', 'prod_check');
  drupal_add_css($base.'/css/prod-check.css');
  drupal_add_js($base.'/js/jquery.equalheights.js', 'module', 'header');
  drupal_add_js($base.'/js/jquery.maskedinput.min.js', 'module', 'header');
  drupal_add_js($base.'/js/prod-check.js', 'module', 'header');

  if ($form_state['values']['prod_check_enable_xmlrpc']) {
    if (empty($form_state['values']['prod_check_xmlrpc_key'])) {
      form_set_error('prod_check_xmlrpc_key', t('When enabling the XPLRPC API, you <strong>must</strong> enter an API key!'));
    }
  }

  if (!empty($form_state['values']['prod_check_module_list_time'])) {
    // This check in case JavaScript is not enabled / malfunctioning.
    if (strpos($form_state['values']['prod_check_module_list_time'], ':') != 2) {
      form_set_error('prod_check_module_list_time', t('Time must be input in 24 hour format: HH:MM!'));
    }
    else {
      $time = explode(':', $form_state['values']['prod_check_module_list_time']);
      if (intval($time[0]) > 23) {
        form_set_error('prod_check_module_list_time', t('Hours must range from 00 (midnight) to 23!'));
      }
      if (intval($time[1]) > 59) {
        form_set_error('prod_check_module_list_time', t('Minutes must range from 00 to 59!'));
      }
    }
  }

  if ($form_state['values']['prod_check_enable_nagios']) {
    $checks = array();
    foreach ($form_state['values']['monitor_settings'] as $set => $data) {
      foreach ($data as $check => $value) {
        if ($value) {
          $checks[$set][] = $value;
        }
      }
    }
    if (empty($checks)) {
      form_set_error('monitor_settings', t('When enabling Nagios support, you <strong>must</strong> tick at least one of the checkboxes!'));
    }
  }
}

/**
 * Submit for settings form.
 */
function prod_check_settings_form_submit($form, &$form_state) {
  if (!empty($form_state['ahah_submission'])) {
    return;
  }

  switch ($form_state['values']['op']) {
    case t('Save configuration'):
      variable_set('prod_check_sitemail', $form_state['values']['prod_check_sitemail']);
      variable_set('prod_check_apcuser', $form_state['values']['prod_check_apcuser']);
      if (!empty($form_state['values']['prod_check_apcpass'])) {
        variable_set('prod_check_apcpass', $form_state['values']['prod_check_apcpass']);
      }
      else {
        variable_set('prod_check_apcpass', 'password');
      }
      if ($form_state['values']['prod_check_enable_xmlrpc']) {
        // Enable.
        variable_set('prod_check_enable_xmlrpc', $form_state['values']['prod_check_enable_xmlrpc']);
        variable_set('prod_check_xmlrpc_key', $form_state['values']['prod_check_xmlrpc_key']);
        variable_set('prod_check_module_list_day', $form_state['values']['prod_check_module_list_day']);
        variable_set('prod_check_module_list_time', $form_state['values']['prod_check_module_list_time']);
      }
      else {
        // Disable.
        variable_set('prod_check_enable_xmlrpc', 0);
      }
      // This is why we didn't use a system_settings_form().
      if ($form_state['values']['prod_check_enable_nagios']) {
        $checks = array();
        foreach ($form_state['values']['monitor_settings'] as $set => $data) {
          foreach ($data as $check => $value) {
            if ($value) {
              $checks[$set][] = $value;
            }
          }
        }
        // Enable.
        variable_set('prod_check_enable_nagios', $form_state['values']['prod_check_enable_nagios']);
        variable_set('prod_check_nagios_checks', $checks);
      }
      else {
        // Disable.
        variable_set('prod_check_enable_nagios', 0);
      }
      drupal_set_message(t('The configuration options have been saved.'));
      break;
    case t('Reset to defaults'):
      // This beats multiple variable_del() calls.
      // Don't delete prod_check_module_list_lastrun!
      db_query('DELETE FROM {variable} WHERE name LIKE "prod_check_%" AND name <> "prod_check_module_list_lastrun"');
      cache_clear_all('variables', 'cache');
      drupal_set_message(t('The configuration options have been reset to their default values.'));
      break;
  }
}

function prod_check_apc() {
  define('ADMIN_USERNAME', variable_get('prod_check_apcuser', 'apc'));
  define('ADMIN_PASSWORD', variable_get('prod_check_apcpass', 'password'));
  include(drupal_get_path('module', 'prod_check').'/includes/prod_check.apc.inc');
  exit;
}
