// $Id: associated_links.js,v 1.1.2.1 2009/04/24 13:45:14 jfberroyer Exp $

if (Drupal.jsEnabled) {
  Drupal.behaviors.associated_links = function () {
    var urls = Drupal.settings.associated_links.ajax_urls;
    for (id in urls) {
  	  $('#'+id).parent().load(urls[id]);
    }
  }
}