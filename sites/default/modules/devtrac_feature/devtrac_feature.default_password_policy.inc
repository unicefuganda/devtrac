<?php

/**
 * Implementation of hook_default_password_policy().
 */
function devtrac_feature_default_password_policy() {
  $export = array();

  $password_policy = new stdClass;
  $password_policy->disabled = FALSE; /* Edit this to true to make a default password_policy disabled initially */
  $password_policy->api_version = 1;
  $password_policy->name = 'standard policy';
  $password_policy->description = 'Standard Devtrac Password policy';
  $password_policy->enabled = FALSE;
  $password_policy->policy = 'a:4:{s:6:"length";s:1:"7";s:7:"history";s:1:"3";s:10:"complexity";s:1:"3";s:8:"username";s:1:"1";}';
  $password_policy->created = 0;
  $password_policy->expiration = 0;
  $password_policy->warning = '';
  $password_policy->weight = FALSE;
  $export['standard policy'] = $password_policy;

  return $export;
}
