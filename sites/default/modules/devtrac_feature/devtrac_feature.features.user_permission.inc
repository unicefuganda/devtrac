<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function devtrac_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: edit field_actionitem_due_date
  $permissions['edit field_actionitem_due_date'] = array(
    'name' => 'edit field_actionitem_due_date',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_actionitem_followuptask
  $permissions['edit field_actionitem_followuptask'] = array(
    'name' => 'edit field_actionitem_followuptask',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_actionitem_ftreportitem
  $permissions['edit field_actionitem_ftreportitem'] = array(
    'name' => 'edit field_actionitem_ftreportitem',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_actionitem_resp_place
  $permissions['edit field_actionitem_resp_place'] = array(
    'name' => 'edit field_actionitem_resp_place',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_actionitem_responsible
  $permissions['edit field_actionitem_responsible'] = array(
    'name' => 'edit field_actionitem_responsible',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_actionitem_severity
  $permissions['edit field_actionitem_severity'] = array(
    'name' => 'edit field_actionitem_severity',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_actionitem_status
  $permissions['edit field_actionitem_status'] = array(
    'name' => 'edit field_actionitem_status',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_fieldtrip_duration
  $permissions['edit field_fieldtrip_duration'] = array(
    'name' => 'edit field_fieldtrip_duration',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_fieldtrip_narrative
  $permissions['edit field_fieldtrip_narrative'] = array(
    'name' => 'edit field_fieldtrip_narrative',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_fieldtrip_places
  $permissions['edit field_fieldtrip_places'] = array(
    'name' => 'edit field_fieldtrip_places',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_fieldtrip_proms_ta_id
  $permissions['edit field_fieldtrip_proms_ta_id'] = array(
    'name' => 'edit field_fieldtrip_proms_ta_id',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_fieldtrip_public_summary
  $permissions['edit field_fieldtrip_public_summary'] = array(
    'name' => 'edit field_fieldtrip_public_summary',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_fieldtrip_purpose_descr
  $permissions['edit field_fieldtrip_purpose_descr'] = array(
    'name' => 'edit field_fieldtrip_purpose_descr',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_fieldtrip_purpose_percent
  $permissions['edit field_fieldtrip_purpose_percent'] = array(
    'name' => 'edit field_fieldtrip_purpose_percent',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_fieldtrip_purpose_purpose
  $permissions['edit field_fieldtrip_purpose_purpose'] = array(
    'name' => 'edit field_fieldtrip_purpose_purpose',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_fieldtrip_start_end_date
  $permissions['edit field_fieldtrip_start_end_date'] = array(
    'name' => 'edit field_fieldtrip_start_end_date',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_fieldtrip_status
  $permissions['edit field_fieldtrip_status'] = array(
    'name' => 'edit field_fieldtrip_status',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_fieldtrip_user
  $permissions['edit field_fieldtrip_user'] = array(
    'name' => 'edit field_fieldtrip_user',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ftritem_field_trip
  $permissions['edit field_ftritem_field_trip'] = array(
    'name' => 'edit field_ftritem_field_trip',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ftritem_images
  $permissions['edit field_ftritem_images'] = array(
    'name' => 'edit field_ftritem_images',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ftritem_lat_long
  $permissions['edit field_ftritem_lat_long'] = array(
    'name' => 'edit field_ftritem_lat_long',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ftritem_narrative
  $permissions['edit field_ftritem_narrative'] = array(
    'name' => 'edit field_ftritem_narrative',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ftritem_place
  $permissions['edit field_ftritem_place'] = array(
    'name' => 'edit field_ftritem_place',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ftritem_public_summary
  $permissions['edit field_ftritem_public_summary'] = array(
    'name' => 'edit field_ftritem_public_summary',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_place_email
  $permissions['edit field_place_email'] = array(
    'name' => 'edit field_place_email',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_place_lat_long
  $permissions['edit field_place_lat_long'] = array(
    'name' => 'edit field_place_lat_long',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_place_phone
  $permissions['edit field_place_phone'] = array(
    'name' => 'edit field_place_phone',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_place_responsible_person
  $permissions['edit field_place_responsible_person'] = array(
    'name' => 'edit field_place_responsible_person',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
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
    ),
  );

  // Exported permission: edit field_place_website
  $permissions['edit field_place_website'] = array(
    'name' => 'edit field_place_website',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_user_aboutme
  $permissions['edit field_user_aboutme'] = array(
    'name' => 'edit field_user_aboutme',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_user_department
  $permissions['edit field_user_department'] = array(
    'name' => 'edit field_user_department',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_user_firstname
  $permissions['edit field_user_firstname'] = array(
    'name' => 'edit field_user_firstname',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_user_function
  $permissions['edit field_user_function'] = array(
    'name' => 'edit field_user_function',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_user_superior
  $permissions['edit field_user_superior'] = array(
    'name' => 'edit field_user_superior',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_user_surname
  $permissions['edit field_user_surname'] = array(
    'name' => 'edit field_user_surname',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_actionitem_due_date
  $permissions['view field_actionitem_due_date'] = array(
    'name' => 'view field_actionitem_due_date',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_actionitem_followuptask
  $permissions['view field_actionitem_followuptask'] = array(
    'name' => 'view field_actionitem_followuptask',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_actionitem_ftreportitem
  $permissions['view field_actionitem_ftreportitem'] = array(
    'name' => 'view field_actionitem_ftreportitem',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_actionitem_resp_place
  $permissions['view field_actionitem_resp_place'] = array(
    'name' => 'view field_actionitem_resp_place',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_actionitem_responsible
  $permissions['view field_actionitem_responsible'] = array(
    'name' => 'view field_actionitem_responsible',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_actionitem_severity
  $permissions['view field_actionitem_severity'] = array(
    'name' => 'view field_actionitem_severity',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_actionitem_status
  $permissions['view field_actionitem_status'] = array(
    'name' => 'view field_actionitem_status',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_fieldtrip_duration
  $permissions['view field_fieldtrip_duration'] = array(
    'name' => 'view field_fieldtrip_duration',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_fieldtrip_narrative
  $permissions['view field_fieldtrip_narrative'] = array(
    'name' => 'view field_fieldtrip_narrative',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_fieldtrip_places
  $permissions['view field_fieldtrip_places'] = array(
    'name' => 'view field_fieldtrip_places',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_fieldtrip_proms_ta_id
  $permissions['view field_fieldtrip_proms_ta_id'] = array(
    'name' => 'view field_fieldtrip_proms_ta_id',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_fieldtrip_public_summary
  $permissions['view field_fieldtrip_public_summary'] = array(
    'name' => 'view field_fieldtrip_public_summary',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_fieldtrip_purpose_descr
  $permissions['view field_fieldtrip_purpose_descr'] = array(
    'name' => 'view field_fieldtrip_purpose_descr',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_fieldtrip_purpose_percent
  $permissions['view field_fieldtrip_purpose_percent'] = array(
    'name' => 'view field_fieldtrip_purpose_percent',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_fieldtrip_purpose_purpose
  $permissions['view field_fieldtrip_purpose_purpose'] = array(
    'name' => 'view field_fieldtrip_purpose_purpose',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_fieldtrip_start_end_date
  $permissions['view field_fieldtrip_start_end_date'] = array(
    'name' => 'view field_fieldtrip_start_end_date',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_fieldtrip_status
  $permissions['view field_fieldtrip_status'] = array(
    'name' => 'view field_fieldtrip_status',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_fieldtrip_user
  $permissions['view field_fieldtrip_user'] = array(
    'name' => 'view field_fieldtrip_user',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ftritem_field_trip
  $permissions['view field_ftritem_field_trip'] = array(
    'name' => 'view field_ftritem_field_trip',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ftritem_images
  $permissions['view field_ftritem_images'] = array(
    'name' => 'view field_ftritem_images',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ftritem_lat_long
  $permissions['view field_ftritem_lat_long'] = array(
    'name' => 'view field_ftritem_lat_long',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ftritem_narrative
  $permissions['view field_ftritem_narrative'] = array(
    'name' => 'view field_ftritem_narrative',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ftritem_place
  $permissions['view field_ftritem_place'] = array(
    'name' => 'view field_ftritem_place',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ftritem_public_summary
  $permissions['view field_ftritem_public_summary'] = array(
    'name' => 'view field_ftritem_public_summary',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_place_email
  $permissions['view field_place_email'] = array(
    'name' => 'view field_place_email',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_place_lat_long
  $permissions['view field_place_lat_long'] = array(
    'name' => 'view field_place_lat_long',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_place_phone
  $permissions['view field_place_phone'] = array(
    'name' => 'view field_place_phone',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_place_responsible_person
  $permissions['view field_place_responsible_person'] = array(
    'name' => 'view field_place_responsible_person',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_place_sourcelayer
  $permissions['view field_place_sourcelayer'] = array(
    'name' => 'view field_place_sourcelayer',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_place_sourceuri
  $permissions['view field_place_sourceuri'] = array(
    'name' => 'view field_place_sourceuri',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_place_unique_id
  $permissions['view field_place_unique_id'] = array(
    'name' => 'view field_place_unique_id',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_place_website
  $permissions['view field_place_website'] = array(
    'name' => 'view field_place_website',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_user_aboutme
  $permissions['view field_user_aboutme'] = array(
    'name' => 'view field_user_aboutme',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_user_department
  $permissions['view field_user_department'] = array(
    'name' => 'view field_user_department',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_user_firstname
  $permissions['view field_user_firstname'] = array(
    'name' => 'view field_user_firstname',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_user_function
  $permissions['view field_user_function'] = array(
    'name' => 'view field_user_function',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_user_superior
  $permissions['view field_user_superior'] = array(
    'name' => 'view field_user_superior',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: view field_user_surname
  $permissions['view field_user_surname'] = array(
    'name' => 'view field_user_surname',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  return $permissions;
}
