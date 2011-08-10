<?php


function phptemplate_search_block_form($form) {
  $form['search_block_form_keys']['#value'] = 'Search this site';
  $form['search_block_form_keys']['#attributes']['class'] = 'default-value';
  return drupal_render($form);
}

function devtrack_theme_preprocess_search_theme_form(&$vars, $hook) {
	
	 // Set a default value for the search box
  $vars['form']['search_theme_form']['#value'] = t('Search this Site');
 
  // Add a custom class and placeholder text to the search box
  $vars['form']['search_theme_form']['#attributes'] = array('class' => 'default-value',
//                                                              'onfocus' => "if (this.value == 'Search...') {this.value = '';}",
//                                                              'onblur' => "if (this.value == '') {this.value = 'Search...';}",
  );
}


function devtrack_theme_preprocess_page(&$vars, $hook) {
  if ((isset($vars['node'])) && ((!(arg(2) == 'edit') && !(arg(2) == 'devel') && !(arg(2) == 'delete')))) { // all edit pages should use node-edit.tpl.php
     $vars['template_files'][] = 'page-'. str_replace('_', '-', $vars['node']->type);
  }
  
  $vars['tabs_primary'] = '<ul class="tabs primary">' . ctools_menu_primary_local_tasks() . "</ul>";
  if ($subtabs = ctools_menu_secondary_local_tasks()) {
    $vars['tabs_secondary'] = '<ul class="tabs secondary">' . $subtabs. "</ul>";
  }
}

/*
 *  Taken From http://evolvingweb.ca/story/theming-views-drupal-templates-and-preprocess-functions
 */
function devtrack_theme_preprocess_views_view(&$vars) {
  if (isset($vars['view']->name)) {
    $function = 'devtrack_theme_preprocess_views_view__'.$vars['view']->name; 
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

function devtrack_theme_preprocess_views_view__Questions(&$vars) {
  if($vars['display_id'] == 'block_1') {
    $vars['more'] = '<div class="more-link">'. l(t('more'), 'node/'. arg(1) .'/questions/questionaire', array()) .'</div';
  }
}

/*
function devtrack_theme_preprocess_breadcrumb(&$vars) {
  // This does not seem to work. Is there no breadcrumb template file defined???
}
*/

/**
 * Override, remove the title at the end again. It was introduced by blueprint.
 * Override, show Home breadcrumb on all pages.
 *
 * Return a themed breadcrumb trail.
 *
 * @param $breadcrumb
 *   An array containing the breadcrumb links.
 * @return a string containing the breadcrumb output.
 */
function devtrack_theme_breadcrumb($breadcrumb) {
  if (count($breadcrumb) > 0) {
//  if (count($breadcrumb) > 1) {
//    $breadcrumb[] = drupal_get_title();
    return '<div class="breadcrumb">'. implode(' &rsaquo; ', $breadcrumb) .'</div>';
  }
}
