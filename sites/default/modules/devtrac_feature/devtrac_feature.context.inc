<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function devtrac_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'all_pages';
  $context->description = 'Blocks that are active on all pages';
  $context->tag = '';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-1' => array(
          'module' => 'menu_block',
          'delta' => 1,
          'region' => 'footer',
          'weight' => 0,
        ),
        'menu_block-2' => array(
          'module' => 'menu_block',
          'delta' => 2,
          'region' => 'footer',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks that are active on all pages');
  $export['all_pages'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'context_ui-section-homepage';
  $context->description = 'The anonymous homepage';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'place_type/all' => 'place_type/all',
        'homepage' => 'homepage',
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-devtrac_frontpage-block_1' => array(
          'module' => 'views',
          'delta' => 'devtrac_frontpage-block_1',
          'region' => 'contentlayerleft',
          'weight' => 0,
        ),
        'devtrack_module-5' => array(
          'module' => 'devtrack_module',
          'delta' => 5,
          'region' => 'contentlayerright',
          'weight' => 0,
        ),
        'devtrack_module-1' => array(
          'module' => 'devtrack_module',
          'delta' => 1,
          'region' => 'contentlayerright',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('The anonymous homepage');
  $export['context_ui-section-homepage'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'context_ui-section-navigation';
  $context->description = 'Taxonomy Term items for Navigation';
  $context->tag = 'taxonomy';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'taxonomy/term/*' => 'taxonomy/term/*',
        'funding_partner/*' => 'funding_partner/*',
        'place_type/1*' => 'place_type/1*',
        'place_type/2*' => 'place_type/2*',
        'place_type/3*' => 'place_type/3*',
        'place_type/4*' => 'place_type/4*',
        'place_type/5*' => 'place_type/5*',
        'place_type/6*' => 'place_type/6*',
        'place_type/7*' => 'place_type/7*',
        'place_type/8*' => 'place_type/8*',
        'place_type/9*' => 'place_type/9*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-funding-partners' => array(
          'module' => 'menu',
          'delta' => 'menu-funding-partners',
          'region' => 'contentlayerright',
          'weight' => 0,
        ),
        'menu-menu-placetype-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-placetype-menu',
          'region' => 'contentlayerright',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Taxonomy Term items for Navigation');
  t('taxonomy');
  $export['context_ui-section-navigation'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'node-view-actionitem';
  $context->description = 'Blocks on Action Items';
  $context->tag = 'nodetype';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'actionitem' => 'actionitem',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-my_homepage_picture-block_4' => array(
          'module' => 'views',
          'delta' => 'my_homepage_picture-block_4',
          'region' => 'contentlayerright',
          'weight' => 0,
        ),
        'devtrack_module-0' => array(
          'module' => 'devtrack_module',
          'delta' => 0,
          'region' => 'layeroneleft',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks on Action Items');
  t('nodetype');
  $export['node-view-actionitem'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'node-view-ftreportitem';
  $context->description = 'Show on Field Trip Report Items';
  $context->tag = 'nodetype';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'ftritem' => 'ftritem',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-6c53fdb94aea1a79057df1f32b462fc2' => array(
          'module' => 'views',
          'delta' => '6c53fdb94aea1a79057df1f32b462fc2',
          'region' => 'contentlayerleft',
          'weight' => 0,
        ),
        'devtrack_module-0' => array(
          'module' => 'devtrack_module',
          'delta' => 0,
          'region' => 'contentlayerleft',
          'weight' => 1,
        ),
        'views-7c76452c07db7027df5fa7b830e52787' => array(
          'module' => 'views',
          'delta' => '7c76452c07db7027df5fa7b830e52787',
          'region' => 'contentlayermiddle',
          'weight' => 0,
        ),
        'views-my_homepage_picture-block_4' => array(
          'module' => 'views',
          'delta' => 'my_homepage_picture-block_4',
          'region' => 'contentlayerright',
          'weight' => 0,
        ),
        'views-my_homepage_picture-block_5' => array(
          'module' => 'views',
          'delta' => 'my_homepage_picture-block_5',
          'region' => 'contentlayerright',
          'weight' => 1,
        ),
        'views-side_block_map-block_1' => array(
          'module' => 'views',
          'delta' => 'side_block_map-block_1',
          'region' => 'contentlayerright',
          'weight' => 2,
        ),
        'views-side_block_map-block_3' => array(
          'module' => 'views',
          'delta' => 'side_block_map-block_3',
          'region' => 'contentlayerright',
          'weight' => 3,
        ),
        'views-c8fc7e0ba137d31339cf5fffceffe21b' => array(
          'module' => 'views',
          'delta' => 'c8fc7e0ba137d31339cf5fffceffe21b',
          'region' => 'layertwoleft',
          'weight' => 0,
        ),
        'views-Questions-block_1' => array(
          'module' => 'views',
          'delta' => 'Questions-block_1',
          'region' => 'layertworight',
          'weight' => 0,
        ),
        'views-67588c60d2487fe75c1e360fc884bc49' => array(
          'module' => 'views',
          'delta' => '67588c60d2487fe75c1e360fc884bc49',
          'region' => 'layerthree',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Show on Field Trip Report Items');
  t('nodetype');
  $export['node-view-ftreportitem'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'node-view-page';
  $context->description = 'Context for Pages';
  $context->tag = 'nodetype';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'book' => 'book',
        'page' => 'page',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'book-0' => array(
          'module' => 'book',
          'delta' => 0,
          'region' => 'contentlayerleft',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for Pages');
  t('nodetype');
  $export['node-view-page'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'node-view-place';
  $context->description = 'To be shown on Place pages';
  $context->tag = 'nodetype';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'place' => 'place',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'devtrack_module-0' => array(
          'module' => 'devtrack_module',
          'delta' => 0,
          'region' => 'contentlayerleft',
          'weight' => 0,
        ),
        'views-d230b1c9ce347b33351941ba1ad71ec6' => array(
          'module' => 'views',
          'delta' => 'd230b1c9ce347b33351941ba1ad71ec6',
          'region' => 'contentlayermiddle',
          'weight' => 0,
        ),
        'views-side_block_map-block_2' => array(
          'module' => 'views',
          'delta' => 'side_block_map-block_2',
          'region' => 'contentlayerright',
          'weight' => 0,
        ),
        'views-Questions-block_2' => array(
          'module' => 'views',
          'delta' => 'Questions-block_2',
          'region' => 'contentlayerright',
          'weight' => 1,
        ),
        'views-user_report_items_map-block_4' => array(
          'module' => 'views',
          'delta' => 'user_report_items_map-block_4',
          'region' => 'layertwoleft',
          'weight' => 0,
        ),
        'views-5434d886d29a54bd5bcf8c8235f32f30' => array(
          'module' => 'views',
          'delta' => '5434d886d29a54bd5bcf8c8235f32f30',
          'region' => 'layertworight',
          'weight' => 0,
        ),
        'views-0106a5ca96b71c6172d5486848b7bf16' => array(
          'module' => 'views',
          'delta' => '0106a5ca96b71c6172d5486848b7bf16',
          'region' => 'layerthree',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('To be shown on Place pages');
  t('nodetype');
  $export['node-view-place'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'node_view_field_trip';
  $context->description = 'Field Trip page';
  $context->tag = 'nodetype';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'fieldtrip' => 'fieldtrip',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-d5cb2e3de82fea26843f448cb4fdfaff' => array(
          'module' => 'views',
          'delta' => 'd5cb2e3de82fea26843f448cb4fdfaff',
          'region' => 'contentlayerleft',
          'weight' => 0,
        ),
        'devtrack_module-0' => array(
          'module' => 'devtrack_module',
          'delta' => 0,
          'region' => 'contentlayerleft',
          'weight' => 1,
        ),
        'views-2326fe1662ce17c4dbac5e21e4de9922' => array(
          'module' => 'views',
          'delta' => '2326fe1662ce17c4dbac5e21e4de9922',
          'region' => 'contentlayermiddle',
          'weight' => 0,
        ),
        'views-my_homepage_picture-block_4' => array(
          'module' => 'views',
          'delta' => 'my_homepage_picture-block_4',
          'region' => 'contentlayerright',
          'weight' => 0,
        ),
        'views-my_homepage_picture-block_5' => array(
          'module' => 'views',
          'delta' => 'my_homepage_picture-block_5',
          'region' => 'contentlayerright',
          'weight' => 1,
        ),
        'views-fe5f6d4111d9bf8d5e5bbad09680099b' => array(
          'module' => 'views',
          'delta' => 'fe5f6d4111d9bf8d5e5bbad09680099b',
          'region' => 'contentlayerright',
          'weight' => 2,
        ),
        'views-8656ee277feb02e7dab0daebd8ae7663' => array(
          'module' => 'views',
          'delta' => '8656ee277feb02e7dab0daebd8ae7663',
          'region' => 'layertwoleft',
          'weight' => 0,
        ),
        'devtrack_module-4' => array(
          'module' => 'devtrack_module',
          'delta' => 4,
          'region' => 'layertworight',
          'weight' => 0,
        ),
        'views-field_trip_report_items-block_1' => array(
          'module' => 'views',
          'delta' => 'field_trip_report_items-block_1',
          'region' => 'layerthree',
          'weight' => 0,
        ),
        'views-27bfb79d1104dca82ed308659446916e' => array(
          'module' => 'views',
          'delta' => '27bfb79d1104dca82ed308659446916e',
          'region' => 'layerthree',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Field Trip page');
  t('nodetype');
  $export['node_view_field_trip'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'places';
  $context->description = 'The view(s) to find places';
  $context->tag = 'taxonomy';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'places/*' => 'places/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'wms-0' => array(
          'module' => 'wms',
          'delta' => 0,
          'region' => 'contentlayerleft',
          'weight' => 0,
        ),
        'openlayers_plus-blockswitcher' => array(
          'module' => 'openlayers_plus',
          'delta' => 'blockswitcher',
          'region' => 'contentlayerright',
          'weight' => 0,
        ),
        'quicktabs-geosearch' => array(
          'module' => 'quicktabs',
          'delta' => 'geosearch',
          'region' => 'contentlayerright',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('The view(s) to find places');
  t('taxonomy');
  $export['places'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_view_my_home_page';
  $context->description = 'A User\'s Home Page';
  $context->tag = 'user';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user/*' => 'user/*',
        '~user/*/*' => '~user/*/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'devtrack_module-0' => array(
          'module' => 'devtrack_module',
          'delta' => 0,
          'region' => 'contentlayerleft',
          'weight' => 0,
        ),
        'views-82b405e48615f4f718a3de0caf6ad948' => array(
          'module' => 'views',
          'delta' => '82b405e48615f4f718a3de0caf6ad948',
          'region' => 'contentlayerleft',
          'weight' => 1,
        ),
        'views-bb81c6932c49ceae6c11cf399465f5ce' => array(
          'module' => 'views',
          'delta' => 'bb81c6932c49ceae6c11cf399465f5ce',
          'region' => 'contentlayermiddle',
          'weight' => 0,
        ),
        'views-user_report_items_map-block_4' => array(
          'module' => 'views',
          'delta' => 'user_report_items_map-block_4',
          'region' => 'contentlayerright',
          'weight' => 0,
        ),
        'views-my_homepage_picture-block_2' => array(
          'module' => 'views',
          'delta' => 'my_homepage_picture-block_2',
          'region' => 'contentlayerright',
          'weight' => 1,
        ),
        'devtrack_module-2' => array(
          'module' => 'devtrack_module',
          'delta' => 2,
          'region' => 'contentlayerright',
          'weight' => 2,
        ),
        'views-cac0f8a4b9f539757b67cf65047d5197' => array(
          'module' => 'views',
          'delta' => 'cac0f8a4b9f539757b67cf65047d5197',
          'region' => 'layertwoleft',
          'weight' => 0,
        ),
        'views-my_homepage_picture-block_3' => array(
          'module' => 'views',
          'delta' => 'my_homepage_picture-block_3',
          'region' => 'layertworight',
          'weight' => 0,
        ),
        'views-87cfc5888b93ec2b557b2215e685ab74' => array(
          'module' => 'views',
          'delta' => '87cfc5888b93ec2b557b2215e685ab74',
          'region' => 'layerthree',
          'weight' => 0,
        ),
        'views-e2873ecf875782fff940de052e22939c' => array(
          'module' => 'views',
          'delta' => 'e2873ecf875782fff940de052e22939c',
          'region' => 'layerthree',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('A User\'s Home Page');
  t('user');
  $export['user_view_my_home_page'] = $context;

  return $export;
}
