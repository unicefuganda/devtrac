/**
 * 
 */

Drupal.devtrac_popup = {};
Drupal.behaviors.devtrac_popup = function (context) {

  /*
   * This only happens upon loading of the original block for the results
   */
/*
  $('.openlayers-geosearch-popup-description', context).not('.openlayers-geosearch-popup-description-processed').each(function() {
    $(this).addClass('openlayers-geosearch-popup-description-processed');
    alert($(this).id);
  })
*/
};

/**
 * Javascript Drupal Theming function for inside of Popups
 *
 * To override
 *
 * @param feature
 *  OpenLayers feature object
 * @return
 *  Formatted HTML
 */
Drupal.theme.prototype.openlayers_geosearchPopupCustom = function(feature) {
  var popupid = feature.id + ".popup";
  popupid = popupid.replace(/\./g, '-'); // the . does not go well with css 
  var output =
    '<div class="openlayers-geosearch-popup openlayers-geosearch-popup-name">' +
      feature.attributes.name +
    '</div>' +
    '<div id="' + popupid + '" class="openlayers-geosearch-popup openlayers-geosearch-popup-description">' +
      '<a class="openlayers-geosearch-popup-link" onclick="Drupal.devtrac_popup_getfeatureinfo(\'' + feature.id + '\'); return false;" href="">Search Locations</a>' +
    '</div>';
  return output;
};

/**
 * Shows the getfeatureinfo tables in a colorbox.
 */
Drupal.devtrac_popup_getfeatureinfo = function(featureId) {
  var feature = this.openlayers_geosearch.vectorLayer[0].getFeatureById(featureId);
  // Create an object of type LonLat from the feature's coordinates.
  var lonlat = new OpenLayers.LonLat(feature.geometry.x, feature.geometry.y);
  // Turn them into pixel coordinates on the map. We need to pass these to the ClickControl, not the LonLat.
  var pixel = feature.layer.map.getPixelFromLonLat(lonlat);
  // Create an object of type myEvent. We need to pass it to the ClickControl later.
  var myEvent = new Drupal.devtrac_popup.myEvent(pixel);
  // Unselect the feature to remove the popup. It is preventing the colorbox from showing.
  Drupal.openlayers_geosearch.popupSelect.onUnselect(feature);
  // Now show the wmsgetfeatureinfo in a colorbox.
  Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo.ClickControl.onClick(myEvent);

  return false;
};

/**
 * Constructor for an object of type myEvent.
 */
Drupal.devtrac_popup.myEvent = function(evt){
  this.xy = evt;
}
