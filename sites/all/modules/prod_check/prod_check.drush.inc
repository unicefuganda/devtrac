<?php

/**
 * Implementation of hook_drush_command().
 */
function prod_check_drush_command() {
  $items = array();

  $items['prod-check'] = array(
    'callback' => 'drush_prod_check_statuspage',
    'description' => "Display the Production Check status page",
    'aliases' => array('pchk'),
  );
  
  return $items;
}

/**
 * Status page callback
 */
function drush_prod_check_statuspage() {
  // Map error codes to shell colours.
  $severity = array (
    REQUIREMENT_INFO => '1',
    REQUIREMENT_OK => '1;32',
    REQUIREMENT_WARNING => '1;33',
    REQUIREMENT_ERROR => '1;31',
  );
  $error = 0;

  foreach (_prod_check_functions() as $set => $data) {
    $rows[] = array('');
    $rows[] = array("\033[1m".dt($data['title'])."\033[0m");
    foreach ($data['functions'] as $function => $title) {
      $func = '_prod_check_' . $function;
      // $func() will execute the function with the name we composed above.
      $result = $func();
      $func = ltrim($func, '_');
      if (!empty($result)) {
        $rows[] = array(
          $result[$func]['title'],
          "\033[".$severity[$result[$func]['severity']].'m'.strip_tags($result[$func]['value'])."\033[0m",
        );
        if ($error < $result[$func]['severity']) {
          $error = $result[$func]['severity'];
        }
      }
    }
  }
  drush_print("\033[1m".dt('Production Check status')."\033[0m", 1);
  drush_print_table($rows);
  if ($error > 0) {
    // Would be cool if we could prefix the admin path with http://<host>/ so it
    // will become a clickable link in some terminals. Any ideas?
    drush_print("\033[1m".dt('Some errors were reported!')."\033[0m ".dt('Check the full status page on')." \033[1m".'admin/reports/prod-check'."\033[0m ".dt('for details.'));
  }
}
