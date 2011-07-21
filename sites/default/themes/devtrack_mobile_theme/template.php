<?php

/**
 * Register original theme functions.
 * @return theme function array
 */
function devtrack_mobile_theme_theme() {
  return array(
    'breadcrumb' => array(
      'arguments' => array('breadcrumb' => $breadcrumb)
    ),
  );
}

/* Nokia_mobile theme-specific changes and additions */
/**
* Return a themed breadcrumb trail. 
*
* @param $breadcrumb
*   An array containing the breadcrumb links.
* @return
*   A string containing the breadcrumb output. 
*/
function devtrack_mobile_theme_breadcrumb($breadcrumb) {
  if (!empty($breadcrumb)) {
    $b = '<ul class="breadcrumb">';
    for($i=0;$i<count($breadcrumb);$i++) {
      $entry = $breadcrumb[$i];
      if ($i==0) {
        $b .= '<li class="first">';
      } else {
        $b .= '<li>';
      }
      $b .= $entry;
      if ($i+1 < count($breadcrumb)) {
        $b .= ' | ';
      }
      $b .= '</li>';
    }
    $b .= '</ul>';
    return $b;
  }
}
