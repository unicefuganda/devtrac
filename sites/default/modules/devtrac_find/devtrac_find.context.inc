<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function devtrac_find_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tripreports';
  $context->description = 'View to search for Trip Reports';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'tripreports' => 'tripreports',
        'tripreports/*' => 'tripreports/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-trip_reports_search-page_1' => array(
          'module' => 'views',
          'delta' => '-exp-trip_reports_search-page_1',
          'region' => 'contentlayerleft',
          'weight' => 0,
        ),
        'views-trip_reports_search-block_1' => array(
          'module' => 'views',
          'delta' => 'trip_reports_search-block_1',
          'region' => 'contentlayerright',
          'weight' => 0,
        ),
      ),
    ),
    'css_injector' => array(
      12 => 12,
      1 => 0,
      2 => 0,
      3 => 0,
      8 => 0,
      9 => 0,
      10 => 0,
      11 => 0,
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('View to search for Trip Reports');

  $export['tripreports'] = $context;
  return $export;
}
