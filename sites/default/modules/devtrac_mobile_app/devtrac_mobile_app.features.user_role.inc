<?php

/**
 * Implementation of hook_user_default_roles().
 */
function devtrac_mobile_app_user_default_roles() {
  $roles = array();

  // Exported role: unicef user
  $roles['unicef user'] = array(
    'name' => 'unicef user',
  );

  return $roles;
}
