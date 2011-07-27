<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function devtrac_feature_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_actionitem_status
  $groups['actionitem-group_actionitem_status'] = array(
    'group_type' => 'standard',
    'type_name' => 'actionitem',
    'group_name' => 'group_actionitem_status',
    'label' => 'Status',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '-1',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
        '5' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '-1',
    'fields' => array(),
  );

  // Exported group: group_fieldtrip_purpose
  $groups['fieldtrip-group_fieldtrip_purpose'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'fieldtrip',
    'group_name' => 'group_fieldtrip_purpose',
    'label' => 'Purpose of Travel',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '3',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset_collapsible',
          'exclude' => 1,
        ),
        'full' => array(
          'format' => 'fieldset_collapsible',
          'exclude' => 1,
        ),
        'description' => '',
        '5' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '3',
    'fields' => array(
      '0' => 'field_fieldtrip_purpose_purpose',
      '1' => 'field_fieldtrip_purpose_percent',
      '2' => 'field_fieldtrip_purpose_descr',
    ),
  );

  // Exported group: group_place_id
  $groups['place-group_place_id'] = array(
    'group_type' => 'standard',
    'type_name' => 'place',
    'group_name' => 'group_place_id',
    'label' => 'ID',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset_collapsed',
        'description' => 'Information about where the geo data originates from.',
      ),
      'display' => array(
        'weight' => '6',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'hidden',
          'exclude' => 0,
        ),
        'description' => '',
        '5' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '6',
    'fields' => array(
      '0' => 'field_place_unique_id',
      '1' => 'field_place_sourcelayer',
      '2' => 'field_place_sourceuri',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('ID');
  t('Purpose of Travel');
  t('Status');

  return $groups;
}
