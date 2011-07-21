<?php
// $Id: acl.api.php,v 1.1.2.2 2010/07/17 02:03:24 salvis Exp $

/**
 * @file
 * API documentation for ACL.
 */

/**
 * Explain what your ACL grant records mean.
 */
function hook_acl_explain($acl_id, $name, $users = NULL) {
  if (empty($users)) {
    return "ACL (id=$acl_id) would grant access to $name.";
  }
  return "ACL (id=$acl_id) grants access to $name to the listed user(s).";
}

