// $Id: click_heatmap.js,v 1.1.2.1 2009/09/28 07:09:58 boombatower Exp $

/**
 * If inside the ClickHeat iframe then remove admin menu.
 */
Drupal.behaviors.click_heatmap = function()) {
  if (window.location.href != parent.location.href) {
    $('#admin-menu').remove();
  }
}
