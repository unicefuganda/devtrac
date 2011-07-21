<?php
// $Id: helpinject.admin.inc,v 1.2 2009/05/06 04:06:51 robertDouglass Exp $

/**
 * @file
 *   Administrative pages for the Help Inject module.
 */

function helpinject_settings() {
  $form = array();

  $form['helpinject_excluded_forms'] = array(
    '#type' => 'textarea',
    '#title' => t('Forms that should be excluded from the Help Inject module.'),
    '#default_value' => variable_get('helpinject_excluded_forms', "helpinject_settings\r\nmenu_overview_form"),
    '#description' => t("One form id per line. Help Inject icons won't show up on these forms."),
  );
  $form['helpinject_excluded_paths'] = array(
    '#type' => 'textarea',
    '#title' => t('Paths that should be excluded from the Help Inject module.'),
    '#default_value' => variable_get('helpinject_excluded_paths', "admin/build/helpinject\r\nadmin/settings/helpinject"),
    '#description' => t("Enter one page per line as Drupal paths. The '*' character is a wildcard. Example paths are blog for the blog page and blog/* for every personal blog. <front> is the front page."),
  );
  return system_settings_form($form);
}
