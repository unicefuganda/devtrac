<?php
// $Id: proxy.processors.inc,v 1.1 2010/01/31 15:28:37 zzolo Exp $

/**
 * @file
 * This file holds implementation of proxy_processors
 *
 * @ingroup proxy
 */

/**
 * Implementation of hook_proxy_processors(). (Internal function)
 */
function _proxy_proxy_processors() {
  $processors = array();

  // Proxify URLs so that links in the page also go through
  // proxy
  $processors['proxy_processor_proxify_urls'] = array(
    'title' => t('Proxify URLs'),
    'description' => t('Updates all URLs (links, images, etc) so that they use local proxy.'),
    'path' => drupal_get_path('module', 'proxy') . '/processors',
    'file' => 'proxy_processor_proxify_urls.inc',
    'processor' => array(
      'class' => 'proxy_processor_proxify_urls',
      'parent' => 'proxy_processor',
    ),
  );

  return $processors;
}