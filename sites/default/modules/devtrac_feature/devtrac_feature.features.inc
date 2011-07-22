<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function devtrac_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "openlayers" && $api == "openlayers_layers") {
    return array("version" => 1);
  }
  elseif ($module == "openlayers" && $api == "openlayers_presets") {
    return array("version" => 1);
  }
  elseif ($module == "openlayers" && $api == "openlayers_styles") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function devtrac_feature_imagecache_default_presets() {
  $items = array(
    'images_block' => array(
      'presetname' => 'images_block',
      'actions' => array(
        '0' => array(
          'weight' => '-10',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '380',
            'height' => '290',
          ),
        ),
        '1' => array(
          'weight' => '-9',
          'module' => 'imagecache_canvasactions',
          'action' => 'canvasactions_definecanvas',
          'data' => array(
            'RGB' => array(
              'HEX' => 'FFFFFF',
            ),
            'under' => 1,
            'exact' => array(
              'width' => '380',
              'height' => '290',
              'xpos' => 'center',
              'ypos' => 'center',
            ),
            'relative' => array(
              'leftdiff' => '',
              'rightdiff' => '',
              'topdiff' => '',
              'bottomdiff' => '',
            ),
          ),
        ),
        '2' => array(
          'weight' => '-8',
          'module' => 'imagecache_canvasactions',
          'action' => 'canvasactions_roundedcorners',
          'data' => array(
            'radius' => '8',
            'independent_corners_set' => array(
              'independent_corners' => 0,
              'radii' => array(
                'tl' => '',
                'tr' => '',
                'bl' => '',
                'br' => '',
              ),
            ),
          ),
        ),
        '3' => array(
          'weight' => '0',
          'module' => 'imagecache_canvasactions',
          'action' => 'canvasactions_file2canvas',
          'data' => array(
            'xpos' => '325',
            'ypos' => '244',
            'alpha' => '80',
            'path' => 'sites/default/themes/devtrack_theme/images/devtrac_logo_watermark_small.png',
          ),
        ),
      ),
    ),
    'images_block_thumbnail' => array(
      'presetname' => 'images_block_thumbnail',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '55',
            'height' => '45',
          ),
        ),
        '1' => array(
          'weight' => '0',
          'module' => 'imagecache_canvasactions',
          'action' => 'canvasactions_definecanvas',
          'data' => array(
            'RGB' => array(
              'HEX' => 'FFFFFF',
            ),
            'under' => 1,
            'exact' => array(
              'width' => '55',
              'height' => '45',
              'xpos' => 'center',
              'ypos' => 'center',
            ),
            'relative' => array(
              'leftdiff' => '',
              'rightdiff' => '',
              'topdiff' => '',
              'bottomdiff' => '',
            ),
          ),
        ),
        '2' => array(
          'weight' => '0',
          'module' => 'imagecache_canvasactions',
          'action' => 'canvasactions_roundedcorners',
          'data' => array(
            'radius' => '6',
            'independent_corners_set' => array(
              'independent_corners' => 0,
              'radii' => array(
                'tl' => '',
                'tr' => '',
                'bl' => '',
                'br' => '',
              ),
            ),
          ),
        ),
      ),
    ),
    'images_page' => array(
      'presetname' => 'images_page',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '600',
            'height' => '380',
          ),
        ),
        '1' => array(
          'weight' => '0',
          'module' => 'imagecache_canvasactions',
          'action' => 'canvasactions_definecanvas',
          'data' => array(
            'RGB' => array(
              'HEX' => 'FFFFFF',
            ),
            'under' => 1,
            'exact' => array(
              'width' => '600',
              'height' => '',
              'xpos' => 'center',
              'ypos' => 'center',
            ),
            'relative' => array(
              'leftdiff' => '',
              'rightdiff' => '',
              'topdiff' => '',
              'bottomdiff' => '',
            ),
          ),
        ),
        '2' => array(
          'weight' => '0',
          'module' => 'imagecache_canvasactions',
          'action' => 'canvasactions_file2canvas',
          'data' => array(
            'xpos' => '570',
            'ypos' => '505',
            'alpha' => '100',
            'path' => 'sites/default/themes/devtrack_theme/images/devtrac_logo_watermark_small.png',
          ),
        ),
        '3' => array(
          'weight' => '0',
          'module' => 'imagecache_canvasactions',
          'action' => 'canvasactions_roundedcorners',
          'data' => array(
            'radius' => '',
            'independent_corners_set' => array(
              'independent_corners' => 1,
              'radii' => array(
                'tl' => '12',
                'tr' => '12',
                'bl' => '0',
                'br' => '0',
              ),
            ),
          ),
        ),
      ),
    ),
    'user_big' => array(
      'presetname' => 'user_big',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '200',
            'height' => '200',
          ),
        ),
        '1' => array(
          'weight' => '0',
          'module' => 'imagecache_canvasactions',
          'action' => 'canvasactions_definecanvas',
          'data' => array(
            'RGB' => array(
              'HEX' => 'FFFFFF',
            ),
            'under' => 1,
            'exact' => array(
              'width' => '200',
              'height' => '200',
              'xpos' => 'center',
              'ypos' => 'center',
            ),
            'relative' => array(
              'leftdiff' => '',
              'rightdiff' => '',
              'topdiff' => '',
              'bottomdiff' => '',
            ),
          ),
        ),
      ),
    ),
    'user_medium' => array(
      'presetname' => 'user_medium',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '100',
            'height' => '100',
          ),
        ),
        '1' => array(
          'weight' => '0',
          'module' => 'imagecache_canvasactions',
          'action' => 'canvasactions_definecanvas',
          'data' => array(
            'RGB' => array(
              'HEX' => 'FFFFFF',
            ),
            'under' => 1,
            'exact' => array(
              'width' => '100',
              'height' => '100',
              'xpos' => 'center',
              'ypos' => 'center',
            ),
            'relative' => array(
              'leftdiff' => '',
              'rightdiff' => '',
              'topdiff' => '',
              'bottomdiff' => '',
            ),
          ),
        ),
        '2' => array(
          'weight' => '0',
          'module' => 'imagecache_canvasactions',
          'action' => 'canvasactions_roundedcorners',
          'data' => array(
            'radius' => '4',
            'independent_corners_set' => array(
              'independent_corners' => 0,
              'radii' => array(
                'tl' => '',
                'tr' => '',
                'bl' => '',
                'br' => '',
              ),
            ),
          ),
        ),
      ),
    ),
    'user_small' => array(
      'presetname' => 'user_small',
      'actions' => array(
        '0' => array(
          'weight' => '-10',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '50',
            'height' => '50',
          ),
        ),
        '1' => array(
          'weight' => '-9',
          'module' => 'imagecache_canvasactions',
          'action' => 'canvasactions_definecanvas',
          'data' => array(
            'RGB' => array(
              'HEX' => 'FFFFFF',
            ),
            'under' => 1,
            'exact' => array(
              'width' => '50',
              'height' => '50',
              'xpos' => 'center',
              'ypos' => 'center',
            ),
            'relative' => array(
              'leftdiff' => '',
              'rightdiff' => '',
              'topdiff' => '',
              'bottomdiff' => '',
            ),
          ),
        ),
        '2' => array(
          'weight' => '-8',
          'module' => 'imagecache_canvasactions',
          'action' => 'canvasactions_roundedcorners',
          'data' => array(
            'radius' => '8',
            'independent_corners_set' => array(
              'independent_corners' => 0,
              'radii' => array(
                'tl' => '',
                'tr' => '',
                'bl' => '',
                'br' => '',
              ),
            ),
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function devtrac_feature_node_info() {
  $items = array(
    'actionitem' => array(
      'name' => t('Action Item'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'book' => array(
      'name' => t('Book page'),
      'module' => 'features',
      'description' => t('A <em>book page</em> is a page of content, organized into a collection of related entries collectively known as a <em>book</em>. A <em>book page</em> automatically displays links to adjacent pages, providing a simple navigation system for organizing and reviewing structured content.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'fieldtrip' => array(
      'name' => t('Field Trip'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'ftritem' => array(
      'name' => t('Field Trip Report Item'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'page' => array(
      'name' => t('Page'),
      'module' => 'features',
      'description' => t('A <em>page</em>, similar in form to a <em>story</em>, is a simple method for creating and displaying information that rarely changes, such as an "About us" section of a website. By default, a <em>page</em> entry does not allow visitor comments and is not featured on the site\'s initial home page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'place' => array(
      'name' => t('Place'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'user_profile' => array(
      'name' => t('User Profile'),
      'module' => 'features',
      'description' => t('This is the nodetype used to store user related information like taxonomy'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_rules_defaults().
 */
function devtrac_feature_rules_defaults() {
  return array(
    'rules' => array(
      'devtrac_feature_1' => array(
        '#type' => 'rule',
        '#set' => 'event_node_presave',
        '#label' => 'Submit Field Trip To Manager',
        '#active' => 0,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'Field Trip',
          '1' => 'devtrac_feature',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#type' => 'condition',
            '#settings' => array(
              'field_name' => 'field_fieldtrip_status',
              '#argument map' => array(
                'node' => 'node',
                'node_unchanged' => 'node_unchanged',
              ),
            ),
            '#name' => 'content_rules_field_changed',
            '#info' => array(
              'label' => 'Saved content\'s field \'field_fieldtrip_status\' has been changed',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content containing changes',
                ),
                'node_unchanged' => array(
                  'type' => 'node',
                  'label' => 'Content not containing changes',
                ),
              ),
              'module' => 'CCK',
            ),
            '#weight' => 0,
          ),
          '1' => array(
            '#info' => array(
              'label' => 'Status = Submitted',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'eval input' => array(
                '0' => 'code',
                '1' => 'value|0|value',
              ),
              'module' => 'CCK',
            ),
            '#name' => 'content_rules_field_has_value',
            '#settings' => array(
              'field_name' => 'field_fieldtrip_status',
              '#argument map' => array(
                'node' => 'node',
              ),
              'value' => array(
                '0' => array(
                  'value' => 'Submitted',
                ),
              ),
              'code' => '',
            ),
            '#type' => 'condition',
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              'type' => 'user_profile',
              '#argument map' => array(
                'user' => 'author',
                'profile_node' => 'author_profile_node',
              ),
            ),
            '#name' => 'content_profile_action_load',
            '#info' => array(
              'label' => 'Load content\'s author\'s User Profile',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'User, whose profile should be loaded',
                ),
              ),
              'new variables' => array(
                'author_profile_node' => array(
                  'label' => 'Author Profile',
                  'label callback' => FALSE,
                  'type' => 'node',
                ),
              ),
              'module' => 'Content Profile',
            ),
            '#weight' => -9,
          ),
          '1' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Load Manager',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content containing the user reference field',
                ),
              ),
              'new variables' => array(
                'author_manager' => array(
                  'label' => 'Author Manager',
                  'label callback' => FALSE,
                  'type' => 'user',
                ),
              ),
              'module' => 'CCK',
            ),
            '#name' => 'userreference_rules_action_load',
            '#settings' => array(
              'field' => 'field_user_superior',
              '#argument map' => array(
                'node' => 'author_profile_node',
                'referenced_user' => 'author_manager',
              ),
            ),
            '#type' => 'action',
          ),
          '2' => array(
            '#type' => 'action',
            '#settings' => array(
              'ops' => array(
                'update' => 'update',
              ),
              '#argument map' => array(
                'node' => 'node',
                'user' => 'author_manager',
              ),
            ),
            '#name' => 'content_access_action_acl_grant_access',
            '#info' => array(
              'label' => 'Grant access for Author Manager.',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
                'user' => array(
                  'type' => 'user',
                  'label' => 'User',
                ),
              ),
              'module' => 'Content access',
            ),
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
      'devtrac_feature_2' => array(
        '#type' => 'rule',
        '#set' => 'event_node_presave',
        '#label' => 'Approve Field Trip',
        '#active' => 0,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'Field Trip',
          '1' => 'devtrac_feature',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Saved content\'s field \'field_fieldtrip_status\' has been changed',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content containing changes',
                ),
                'node_unchanged' => array(
                  'type' => 'node',
                  'label' => 'Content not containing changes',
                ),
              ),
              'module' => 'CCK',
            ),
            '#name' => 'content_rules_field_changed',
            '#settings' => array(
              'field_name' => 'field_fieldtrip_status',
              '#argument map' => array(
                'node' => 'node',
                'node_unchanged' => 'node_unchanged',
              ),
            ),
            '#type' => 'condition',
          ),
          '1' => array(
            '#weight' => 0,
            '#type' => 'condition',
            '#settings' => array(
              'field_name' => 'field_fieldtrip_status',
              '#argument map' => array(
                'node' => 'node',
              ),
              'value' => array(
                '0' => array(
                  'value' => 'Approved',
                ),
              ),
              'code' => '',
            ),
            '#name' => 'content_rules_field_has_value',
            '#info' => array(
              'label' => 'Status = Approved',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'eval input' => array(
                '0' => 'code',
                '1' => 'value|0|value',
              ),
              'module' => 'CCK',
            ),
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => -9,
            '#info' => array(
              'label' => 'Load content\'s author\'s User Profile',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'User, whose profile should be loaded',
                ),
              ),
              'new variables' => array(
                'author_profile_node' => array(
                  'label' => 'Author Profile',
                  'label callback' => FALSE,
                  'type' => 'node',
                ),
              ),
              'module' => 'Content Profile',
            ),
            '#name' => 'content_profile_action_load',
            '#settings' => array(
              'type' => 'user_profile',
              '#argument map' => array(
                'user' => 'author',
                'profile_node' => 'author_profile_node',
              ),
            ),
            '#type' => 'action',
          ),
          '1' => array(
            '#type' => 'action',
            '#settings' => array(
              'field' => 'field_user_superior',
              '#argument map' => array(
                'node' => 'author_profile_node',
                'referenced_user' => 'author_manager',
              ),
            ),
            '#name' => 'userreference_rules_action_load',
            '#info' => array(
              'label' => 'Load Manager',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content containing the user reference field',
                ),
              ),
              'new variables' => array(
                'author_manager' => array(
                  'label' => 'Author Manager',
                  'label callback' => FALSE,
                  'type' => 'user',
                ),
              ),
              'module' => 'CCK',
            ),
            '#weight' => 0,
          ),
          '2' => array(
            '#type' => 'action',
            '#settings' => array(
              'message' => 'You are not the manager. You can not approve this item.',
              'error' => 1,
            ),
            '#name' => 'rules_action_drupal_message',
            '#info' => array(
              'label' => 'Show "You are not a manager"',
              'label callback' => FALSE,
              'module' => 'System',
              'eval input' => array(
                '0' => 'message',
              ),
            ),
            '#weight' => 0,
          ),
          '3' => array(
            '#type' => 'action',
            '#settings' => array(
              'field_name' => 'field_fieldtrip_status',
              '#argument map' => array(
                'node' => 'node',
              ),
              'value' => array(
                '0' => array(
                  'value' => 'Submitted',
                ),
              ),
              'code' => '',
            ),
            '#name' => 'content_rules_action_populate_field',
            '#info' => array(
              'label' => 'Populate saved content\'s field \'field_fieldtrip_status\'',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'eval input' => array(
                '0' => 'code',
                '1' => 'value|0|value',
              ),
              'module' => 'CCK',
            ),
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
      'devtrac_feature_3' => array(
        '#type' => 'rule',
        '#set' => 'event_node_presave',
        '#label' => 'Approve Field Trip by Manager',
        '#active' => 0,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'Field Trip',
          '1' => 'devtrac_feature',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#type' => 'condition',
            '#settings' => array(
              'field_name' => 'field_fieldtrip_status',
              '#argument map' => array(
                'node' => 'node',
                'node_unchanged' => 'node_unchanged',
              ),
            ),
            '#name' => 'content_rules_field_changed',
            '#info' => array(
              'label' => 'Saved content\'s field \'field_fieldtrip_status\' has been changed',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content containing changes',
                ),
                'node_unchanged' => array(
                  'type' => 'node',
                  'label' => 'Content not containing changes',
                ),
              ),
              'module' => 'CCK',
            ),
            '#weight' => 0,
          ),
          '1' => array(
            '#info' => array(
              'label' => 'Status = Approved',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'eval input' => array(
                '0' => 'code',
                '1' => 'value|0|value',
              ),
              'module' => 'CCK',
            ),
            '#name' => 'content_rules_field_has_value',
            '#settings' => array(
              'field_name' => 'field_fieldtrip_status',
              '#argument map' => array(
                'node' => 'node',
              ),
              'value' => array(
                '0' => array(
                  'value' => 'Approved',
                ),
              ),
              'code' => '',
            ),
            '#type' => 'condition',
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              'type' => 'user_profile',
              '#argument map' => array(
                'user' => 'author',
                'profile_node' => 'author_profile_node',
              ),
            ),
            '#name' => 'content_profile_action_load',
            '#info' => array(
              'label' => 'Load content\'s author\'s User Profile',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'User, whose profile should be loaded',
                ),
              ),
              'new variables' => array(
                'author_profile_node' => array(
                  'label' => 'Author Profile',
                  'label callback' => FALSE,
                  'type' => 'node',
                ),
              ),
              'module' => 'Content Profile',
            ),
            '#weight' => -9,
          ),
          '1' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Load Manager',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content containing the user reference field',
                ),
              ),
              'new variables' => array(
                'author_manager' => array(
                  'label' => 'Author Manager',
                  'label callback' => FALSE,
                  'type' => 'user',
                ),
              ),
              'module' => 'CCK',
            ),
            '#name' => 'userreference_rules_action_load',
            '#settings' => array(
              'field' => 'field_user_superior',
              '#argument map' => array(
                'node' => 'author_profile_node',
                'referenced_user' => 'author_manager',
              ),
            ),
            '#type' => 'action',
          ),
          '2' => array(
            '#info' => array(
              'label' => 'Show "The Field Trip Item was Approved"',
              'label callback' => FALSE,
              'module' => 'System',
              'eval input' => array(
                '0' => 'message',
              ),
            ),
            '#name' => 'rules_action_drupal_message',
            '#settings' => array(
              'message' => 'The Field Trip Item was Approved',
              'error' => 0,
            ),
            '#type' => 'action',
            '#weight' => 0,
          ),
          '3' => array(
            '#weight' => 0,
            '#type' => 'action',
            '#settings' => array(
              'ops' => array(
                'update' => 'update',
              ),
              '#argument map' => array(
                'node' => 'node',
                'user' => 'author_manager',
              ),
            ),
            '#name' => 'content_access_action_acl_revoke_access',
            '#info' => array(
              'label' => 'Revoke access for Author Manager.',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
                'user' => array(
                  'type' => 'user',
                  'label' => 'User',
                ),
              ),
              'module' => 'Content access',
            ),
          ),
        ),
        '#version' => 6003,
      ),
    ),
  );
}

/**
 * Implementation of hook_views_api().
 */
function devtrac_feature_views_api() {
  return array(
    'api' => '2',
  );
}
