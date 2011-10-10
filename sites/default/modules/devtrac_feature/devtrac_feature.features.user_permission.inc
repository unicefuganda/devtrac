<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function devtrac_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer features
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer own comments
  $permissions['administer own comments'] = array(
    'name' => 'administer own comments',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'unicef user',
      '2' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: create actionitem content
  $permissions['create actionitem content'] = array(
    'name' => 'create actionitem content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: create bbsync content
  $permissions['create bbsync content'] = array(
    'name' => 'create bbsync content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'unicef user',
      '2' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: create book content
  $permissions['create book content'] = array(
    'name' => 'create book content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'editor',
    ),
  );

  // Exported permission: create fieldtrip content
  $permissions['create fieldtrip content'] = array(
    'name' => 'create fieldtrip content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: create ftritem content
  $permissions['create ftritem content'] = array(
    'name' => 'create ftritem content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: create page content
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: create place content
  $permissions['create place content'] = array(
    'name' => 'create place content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: create user_profile content
  $permissions['create user_profile content'] = array(
    'name' => 'create user_profile content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: delete any actionitem content
  $permissions['delete any actionitem content'] = array(
    'name' => 'delete any actionitem content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete any book content
  $permissions['delete any book content'] = array(
    'name' => 'delete any book content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete any fieldtrip content
  $permissions['delete any fieldtrip content'] = array(
    'name' => 'delete any fieldtrip content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete any ftritem content
  $permissions['delete any ftritem content'] = array(
    'name' => 'delete any ftritem content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete any page content
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete any place content
  $permissions['delete any place content'] = array(
    'name' => 'delete any place content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete any user_profile content
  $permissions['delete any user_profile content'] = array(
    'name' => 'delete any user_profile content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete own actionitem content
  $permissions['delete own actionitem content'] = array(
    'name' => 'delete own actionitem content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete own book content
  $permissions['delete own book content'] = array(
    'name' => 'delete own book content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'editor',
    ),
  );

  // Exported permission: delete own fieldtrip content
  $permissions['delete own fieldtrip content'] = array(
    'name' => 'delete own fieldtrip content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete own ftritem content
  $permissions['delete own ftritem content'] = array(
    'name' => 'delete own ftritem content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete own page content
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete own place content
  $permissions['delete own place content'] = array(
    'name' => 'delete own place content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete own user_profile content
  $permissions['delete own user_profile content'] = array(
    'name' => 'delete own user_profile content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit any actionitem content
  $permissions['edit any actionitem content'] = array(
    'name' => 'edit any actionitem content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit any book content
  $permissions['edit any book content'] = array(
    'name' => 'edit any book content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'editor',
    ),
  );

  // Exported permission: edit any fieldtrip content
  $permissions['edit any fieldtrip content'] = array(
    'name' => 'edit any fieldtrip content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit any ftritem content
  $permissions['edit any ftritem content'] = array(
    'name' => 'edit any ftritem content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit any page content
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'editor',
    ),
  );

  // Exported permission: edit any place content
  $permissions['edit any place content'] = array(
    'name' => 'edit any place content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit any user_profile content
  $permissions['edit any user_profile content'] = array(
    'name' => 'edit any user_profile content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit field_actionitem_due_date
  $permissions['edit field_actionitem_due_date'] = array(
    'name' => 'edit field_actionitem_due_date',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_actionitem_followuptask
  $permissions['edit field_actionitem_followuptask'] = array(
    'name' => 'edit field_actionitem_followuptask',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_actionitem_ftreportitem
  $permissions['edit field_actionitem_ftreportitem'] = array(
    'name' => 'edit field_actionitem_ftreportitem',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_actionitem_resp_place
  $permissions['edit field_actionitem_resp_place'] = array(
    'name' => 'edit field_actionitem_resp_place',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_actionitem_responsible
  $permissions['edit field_actionitem_responsible'] = array(
    'name' => 'edit field_actionitem_responsible',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_actionitem_severity
  $permissions['edit field_actionitem_severity'] = array(
    'name' => 'edit field_actionitem_severity',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_actionitem_status
  $permissions['edit field_actionitem_status'] = array(
    'name' => 'edit field_actionitem_status',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_fieldtrip_approval_date
  $permissions['edit field_fieldtrip_approval_date'] = array(
    'name' => 'edit field_fieldtrip_approval_date',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit field_fieldtrip_approved_by
  $permissions['edit field_fieldtrip_approved_by'] = array(
    'name' => 'edit field_fieldtrip_approved_by',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit field_fieldtrip_duration
  $permissions['edit field_fieldtrip_duration'] = array(
    'name' => 'edit field_fieldtrip_duration',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_fieldtrip_narrative
  $permissions['edit field_fieldtrip_narrative'] = array(
    'name' => 'edit field_fieldtrip_narrative',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_fieldtrip_places
  $permissions['edit field_fieldtrip_places'] = array(
    'name' => 'edit field_fieldtrip_places',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_fieldtrip_proms_ta_id
  $permissions['edit field_fieldtrip_proms_ta_id'] = array(
    'name' => 'edit field_fieldtrip_proms_ta_id',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_fieldtrip_public_summary
  $permissions['edit field_fieldtrip_public_summary'] = array(
    'name' => 'edit field_fieldtrip_public_summary',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_fieldtrip_purpose_descr
  $permissions['edit field_fieldtrip_purpose_descr'] = array(
    'name' => 'edit field_fieldtrip_purpose_descr',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit field_fieldtrip_purpose_percent
  $permissions['edit field_fieldtrip_purpose_percent'] = array(
    'name' => 'edit field_fieldtrip_purpose_percent',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit field_fieldtrip_purpose_purpose
  $permissions['edit field_fieldtrip_purpose_purpose'] = array(
    'name' => 'edit field_fieldtrip_purpose_purpose',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_fieldtrip_start_end_date
  $permissions['edit field_fieldtrip_start_end_date'] = array(
    'name' => 'edit field_fieldtrip_start_end_date',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_fieldtrip_status
  $permissions['edit field_fieldtrip_status'] = array(
    'name' => 'edit field_fieldtrip_status',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_fieldtrip_user
  $permissions['edit field_fieldtrip_user'] = array(
    'name' => 'edit field_fieldtrip_user',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_ftritem_date_visited
  $permissions['edit field_ftritem_date_visited'] = array(
    'name' => 'edit field_ftritem_date_visited',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_ftritem_field_trip
  $permissions['edit field_ftritem_field_trip'] = array(
    'name' => 'edit field_ftritem_field_trip',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_ftritem_images
  $permissions['edit field_ftritem_images'] = array(
    'name' => 'edit field_ftritem_images',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_ftritem_lat_long
  $permissions['edit field_ftritem_lat_long'] = array(
    'name' => 'edit field_ftritem_lat_long',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_ftritem_narrative
  $permissions['edit field_ftritem_narrative'] = array(
    'name' => 'edit field_ftritem_narrative',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_ftritem_place
  $permissions['edit field_ftritem_place'] = array(
    'name' => 'edit field_ftritem_place',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_ftritem_public_summary
  $permissions['edit field_ftritem_public_summary'] = array(
    'name' => 'edit field_ftritem_public_summary',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_ftritem_status
  $permissions['edit field_ftritem_status'] = array(
    'name' => 'edit field_ftritem_status',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit field_place_email
  $permissions['edit field_place_email'] = array(
    'name' => 'edit field_place_email',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_place_lat_long
  $permissions['edit field_place_lat_long'] = array(
    'name' => 'edit field_place_lat_long',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_place_phone
  $permissions['edit field_place_phone'] = array(
    'name' => 'edit field_place_phone',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_place_responsible_person
  $permissions['edit field_place_responsible_person'] = array(
    'name' => 'edit field_place_responsible_person',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_place_sourcelayer
  $permissions['edit field_place_sourcelayer'] = array(
    'name' => 'edit field_place_sourcelayer',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit field_place_sourceuri
  $permissions['edit field_place_sourceuri'] = array(
    'name' => 'edit field_place_sourceuri',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit field_place_unique_id
  $permissions['edit field_place_unique_id'] = array(
    'name' => 'edit field_place_unique_id',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_place_website
  $permissions['edit field_place_website'] = array(
    'name' => 'edit field_place_website',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_user_aboutme
  $permissions['edit field_user_aboutme'] = array(
    'name' => 'edit field_user_aboutme',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_user_degree
  $permissions['edit field_user_degree'] = array(
    'name' => 'edit field_user_degree',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_user_department
  $permissions['edit field_user_department'] = array(
    'name' => 'edit field_user_department',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_user_firstname
  $permissions['edit field_user_firstname'] = array(
    'name' => 'edit field_user_firstname',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_user_function
  $permissions['edit field_user_function'] = array(
    'name' => 'edit field_user_function',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_user_superior
  $permissions['edit field_user_superior'] = array(
    'name' => 'edit field_user_superior',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_user_surname
  $permissions['edit field_user_surname'] = array(
    'name' => 'edit field_user_surname',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit field_user_title
  $permissions['edit field_user_title'] = array(
    'name' => 'edit field_user_title',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit own actionitem content
  $permissions['edit own actionitem content'] = array(
    'name' => 'edit own actionitem content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit own book content
  $permissions['edit own book content'] = array(
    'name' => 'edit own book content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit own fieldtrip content
  $permissions['edit own fieldtrip content'] = array(
    'name' => 'edit own fieldtrip content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit own ftritem content
  $permissions['edit own ftritem content'] = array(
    'name' => 'edit own ftritem content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: edit own page content
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit own place content
  $permissions['edit own place content'] = array(
    'name' => 'edit own place content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit own user_profile content
  $permissions['edit own user_profile content'] = array(
    'name' => 'edit own user_profile content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: grant own content access
  $permissions['grant own content access'] = array(
    'name' => 'grant own content access',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: hide own comments
  $permissions['hide own comments'] = array(
    'name' => 'hide own comments',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'unicef user',
      '2' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: manage features
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: sync all bbsync
  $permissions['sync all bbsync'] = array(
    'name' => 'sync all bbsync',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: sync own bbsync
  $permissions['sync own bbsync'] = array(
    'name' => 'sync own bbsync',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'unicef user',
      '2' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_actionitem_due_date
  $permissions['view field_actionitem_due_date'] = array(
    'name' => 'view field_actionitem_due_date',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_actionitem_followuptask
  $permissions['view field_actionitem_followuptask'] = array(
    'name' => 'view field_actionitem_followuptask',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_actionitem_ftreportitem
  $permissions['view field_actionitem_ftreportitem'] = array(
    'name' => 'view field_actionitem_ftreportitem',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_actionitem_resp_place
  $permissions['view field_actionitem_resp_place'] = array(
    'name' => 'view field_actionitem_resp_place',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_actionitem_responsible
  $permissions['view field_actionitem_responsible'] = array(
    'name' => 'view field_actionitem_responsible',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_actionitem_severity
  $permissions['view field_actionitem_severity'] = array(
    'name' => 'view field_actionitem_severity',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_actionitem_status
  $permissions['view field_actionitem_status'] = array(
    'name' => 'view field_actionitem_status',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_fieldtrip_approval_date
  $permissions['view field_fieldtrip_approval_date'] = array(
    'name' => 'view field_fieldtrip_approval_date',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'unicef user',
      '4' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_fieldtrip_approved_by
  $permissions['view field_fieldtrip_approved_by'] = array(
    'name' => 'view field_fieldtrip_approved_by',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'unicef user',
      '4' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_fieldtrip_duration
  $permissions['view field_fieldtrip_duration'] = array(
    'name' => 'view field_fieldtrip_duration',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'unicef user',
      '4' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_fieldtrip_narrative
  $permissions['view field_fieldtrip_narrative'] = array(
    'name' => 'view field_fieldtrip_narrative',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_fieldtrip_places
  $permissions['view field_fieldtrip_places'] = array(
    'name' => 'view field_fieldtrip_places',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'unicef user',
      '4' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_fieldtrip_proms_ta_id
  $permissions['view field_fieldtrip_proms_ta_id'] = array(
    'name' => 'view field_fieldtrip_proms_ta_id',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_fieldtrip_public_summary
  $permissions['view field_fieldtrip_public_summary'] = array(
    'name' => 'view field_fieldtrip_public_summary',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'unicef user',
      '4' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_fieldtrip_purpose_descr
  $permissions['view field_fieldtrip_purpose_descr'] = array(
    'name' => 'view field_fieldtrip_purpose_descr',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: view field_fieldtrip_purpose_percent
  $permissions['view field_fieldtrip_purpose_percent'] = array(
    'name' => 'view field_fieldtrip_purpose_percent',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: view field_fieldtrip_purpose_purpose
  $permissions['view field_fieldtrip_purpose_purpose'] = array(
    'name' => 'view field_fieldtrip_purpose_purpose',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'unicef user',
      '4' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_fieldtrip_start_end_date
  $permissions['view field_fieldtrip_start_end_date'] = array(
    'name' => 'view field_fieldtrip_start_end_date',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'unicef user',
      '4' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_fieldtrip_status
  $permissions['view field_fieldtrip_status'] = array(
    'name' => 'view field_fieldtrip_status',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_fieldtrip_user
  $permissions['view field_fieldtrip_user'] = array(
    'name' => 'view field_fieldtrip_user',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'unicef user',
      '4' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_ftritem_date_visited
  $permissions['view field_ftritem_date_visited'] = array(
    'name' => 'view field_ftritem_date_visited',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'unicef user',
      '4' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_ftritem_field_trip
  $permissions['view field_ftritem_field_trip'] = array(
    'name' => 'view field_ftritem_field_trip',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'unicef user',
      '4' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_ftritem_images
  $permissions['view field_ftritem_images'] = array(
    'name' => 'view field_ftritem_images',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'unicef user',
      '4' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_ftritem_lat_long
  $permissions['view field_ftritem_lat_long'] = array(
    'name' => 'view field_ftritem_lat_long',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'unicef user',
      '4' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_ftritem_narrative
  $permissions['view field_ftritem_narrative'] = array(
    'name' => 'view field_ftritem_narrative',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_ftritem_place
  $permissions['view field_ftritem_place'] = array(
    'name' => 'view field_ftritem_place',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'unicef user',
      '4' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_ftritem_public_summary
  $permissions['view field_ftritem_public_summary'] = array(
    'name' => 'view field_ftritem_public_summary',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'unicef user',
      '4' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_ftritem_status
  $permissions['view field_ftritem_status'] = array(
    'name' => 'view field_ftritem_status',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: view field_place_email
  $permissions['view field_place_email'] = array(
    'name' => 'view field_place_email',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_place_lat_long
  $permissions['view field_place_lat_long'] = array(
    'name' => 'view field_place_lat_long',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'unicef user',
      '4' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_place_phone
  $permissions['view field_place_phone'] = array(
    'name' => 'view field_place_phone',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_place_responsible_person
  $permissions['view field_place_responsible_person'] = array(
    'name' => 'view field_place_responsible_person',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_place_sourcelayer
  $permissions['view field_place_sourcelayer'] = array(
    'name' => 'view field_place_sourcelayer',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_place_sourceuri
  $permissions['view field_place_sourceuri'] = array(
    'name' => 'view field_place_sourceuri',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_place_unique_id
  $permissions['view field_place_unique_id'] = array(
    'name' => 'view field_place_unique_id',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_place_website
  $permissions['view field_place_website'] = array(
    'name' => 'view field_place_website',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
      '2' => 'unicef user',
      '3' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_user_aboutme
  $permissions['view field_user_aboutme'] = array(
    'name' => 'view field_user_aboutme',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'unicef user',
      '4' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_user_degree
  $permissions['view field_user_degree'] = array(
    'name' => 'view field_user_degree',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'unicef user',
      '4' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_user_department
  $permissions['view field_user_department'] = array(
    'name' => 'view field_user_department',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'unicef user',
      '4' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_user_firstname
  $permissions['view field_user_firstname'] = array(
    'name' => 'view field_user_firstname',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'unicef user',
      '4' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_user_function
  $permissions['view field_user_function'] = array(
    'name' => 'view field_user_function',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'unicef user',
      '4' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_user_superior
  $permissions['view field_user_superior'] = array(
    'name' => 'view field_user_superior',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'unicef user',
      '4' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_user_surname
  $permissions['view field_user_surname'] = array(
    'name' => 'view field_user_surname',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'unicef user',
      '4' => 'unicef user (Mobile)',
    ),
  );

  // Exported permission: view field_user_title
  $permissions['view field_user_title'] = array(
    'name' => 'view field_user_title',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'unicef user',
      '4' => 'unicef user (Mobile)',
    ),
  );

  return $permissions;
}
