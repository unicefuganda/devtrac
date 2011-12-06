Drupal.openlayers_geosearch = {};
Drupal.behaviors.openlayers_geosearch = function (context) {

  /*
   * This only happens upon loading of the original block for the results
   */
  $('#openlayersgeosearchresults', context).not('.openlayersgeosearchresults-processed').each(function() {
    $(this).addClass('openlayersgeosearchresults-processed');
    // Take all the maps on the page
    Drupal.openlayers_geosearch.data = $('.openlayers-map').data('openlayers');
    if (!Drupal.openlayers_geosearch.data.map.displayProjection) {
      Drupal.openlayers_geosearch.data.map.displayProjection = 4326;
    }
    Drupal.openlayers_geosearch.displayProjection = new OpenLayers.Projection('EPSG:' + Drupal.openlayers_geosearch.data.map.displayProjection);
    Drupal.openlayers_geosearch.projection = new OpenLayers.Projection('EPSG:' + Drupal.openlayers_geosearch.data.map.projection);
    var searchLayer = Drupal.openlayers_geosearch.data.openlayers.getLayersBy('drupalID', "openlayers_searchresult_layer");
    // If the searchlayer is not selected, we just create one on the fly
    if (searchLayer.length == 0) {
      var searchLayer = new OpenLayers.Layer.Vector(
        Drupal.t("Search Layer"),
        {
          projection: new OpenLayers.Projection('EPSG:4326'),
          drupalID: 'openlayers_searchresult_layer'
        }
      );
      // We add the default styles to the layer, so we can use them when the table is clicked
      var styleMap = Drupal.openlayers.getStyleMap(Drupal.openlayers_geosearch.data.map, 'openlayers_searchresult_layer');
      searchLayer.StyleMap = styleMap;
      Drupal.openlayers_geosearch.data.openlayers.addLayer(searchLayer);
    }
    Drupal.openlayers_geosearch.vectorLayer = Drupal.openlayers_geosearch.data.openlayers.getLayersBy('drupalID', "openlayers_searchresult_layer");
  });

  $("#openlayersgeosearchtabs", context).not('.openlayersgeosearchtabs-processed').each(function() {
    $(this).tabs().addClass('.openlayersgeosearchtabs-processed');
    // here we remove the dots from the map (only before adding the first result
    Drupal.openlayers_geosearch.vectorLayer[0].removeAllFeatures();
  });

  /*
   * This only happens upon (re)loading the full set of results
   */
  var i = 0;
  $('.openlayers-geosearch-result-table', context).not('.openlayers-geosearch-result-table-processed').each(function() {
    $(this).addClass('openlayers-geosearch-result-table-processed');
    /*
     * Now we loop through all the links within the table, the links hold the lat & lon for each point to be plotted
     */
    $('.openlayers-geosearch-result-table a', context).not('.openlayers-geosearch-result-a-processed').each(function() {
      $(this).addClass('openlayers-geosearch-result-a-processed');
      // and here we add the dot to the map
      var point = Drupal.openlayers_geosearch.Geocoder.getpoint($(this)[0].href);
      var geometry = new OpenLayers.Geometry.Point(point.lon, point.lat).transform(Drupal.openlayers_geosearch.displayProjection, Drupal.openlayers_geosearch.projection);
      var bounds = new OpenLayers.Bounds(point.minx, point.miny, point.maxx, point.maxy).transform(Drupal.openlayers_geosearch.displayProjection, Drupal.openlayers_geosearch.projection);
      
      var pointfeature = new OpenLayers.Feature.Vector(geometry);
      // lets get the styles of this layer
      var styleMap = Drupal.openlayers.getStyleMap(Drupal.openlayers_geosearch.data.map, 'openlayers_searchresult_layer');
      pointfeature.style = styleMap.styles['default'].defaultStyle;
      // we store the id of the feature in our <a id="id"> tag, so we can do things when we click the link
      $(this)[0].id = pointfeature.id + ".list";
      pointfeature.attributes.name = $(this)[0].innerHTML;
      pointfeature.attributes.description = "";
      
      Drupal.openlayers_geosearch.vectorLayer[0].addFeatures([pointfeature], styleMap.styles['default'].defaultStyle);
      $(this).click(Drupal.openlayers_geosearch.Geocoder.blockclick);
    });
    Drupal.openlayers_geosearch.Geocoder.zoomtoresults();
  });
};

/**
 * openlayers_geosearch.Geocoder object
 */
Drupal.openlayers_geosearch.Geocoder = function (data) {
  this.data = data;
};

/**
 * Performs a search on the autocomplete dropdown control
 */
Drupal.openlayers_geosearch.Geocoder.prototype.process = function (query) {
  
  var fieldname = $(this.data.input).attr('fieldname');
  var dashed = $(this.data.input).attr('dashed');
  if (!fieldname) {
    var mapid = $(this.data.input).attr('mapid');
  } else {
    var mapid = '#openlayers-cck-widget-map-' + fieldname;
  }
    
  var data = {
    query:query,
    fieldname: fieldname,
    content_type: $('#edit-' + dashed + '-openlayers-geosearch-content-type').val()
  };

  $.ajax({
    type: 'POST',
    url: this.data.db.uri + '/process',
    data: data,
    dataType: 'json',
    success: function(point) {

      if (point.longitude && point.latitude) {

        var data = $(mapid).data('openlayers');
        if (!data.map.displayProjection) {
          data.map.displayProjection = 4326;
        }
        var displayProjection = new OpenLayers.Projection('EPSG:' + data.map.displayProjection);
        var projection = new OpenLayers.Projection('EPSG:' + data.map.projection);
        var vectorLayer = data.openlayers.getLayersBy('drupalID', "openlayers_drawfeatures_layer");
        var geometry = new OpenLayers.Geometry.Point(point.longitude, point.latitude).transform(displayProjection, projection);
        var bounds = new OpenLayers.Bounds(point.box.west, point.box.south, point.box.east, point.box.north).transform(displayProjection, projection);

        //Remove all points, unless CCK widget settings prevent it.
        if (point.keep_points) {
          data.openlayers.setCenter(new OpenLayers.LonLat(point.longitude, point.latitude).transform(displayProjection, projection));
        }
        else {
          vectorLayer[0].removeFeatures(vectorLayer[0].features);
          data.openlayers.zoomToExtent(bounds);
          // Adding CCK fields autocompletion
          if (point.fields) {
            jQuery.each(point.fields, function () {
              $(this.type + "[name*='" + this.name + "']").attr('value', this.value);
              if (!this.override) {
                $(this.type + "[name*='" + this.name + "']").attr('readonly', 'TRUE').addClass('readonly');
              }
            });
          }
        }
        
        //Add point to map.
        vectorLayer[0].addFeatures([new OpenLayers.Feature.Vector(geometry)]);
      }
    }
  });

}

/**
 * Performs a search on the a links in the Results Block
 */
Drupal.openlayers_geosearch.Geocoder.blockclick = function () {
  // the lat + lon are passed in the url of the href as lat=123&lon=456
  var point = Drupal.openlayers_geosearch.Geocoder.getpoint(this.href);
  // the id is passed as OpenLayers.Features.id.list (so we remove the .list from the string to get the id)
  var id = this.id.substring(0, this.id.length -5 );
  // find the results layer
  var vectorLayer = Drupal.openlayers_geosearch.data.openlayers.getLayersBy('drupalID', "openlayers_searchresult_layer");
  // find the feature
  var feature = vectorLayer[0].getFeatureById(id);
  // redraw the feature using the select style
  var styleMap = Drupal.openlayers.getStyleMap(Drupal.openlayers_geosearch.data.map, 'openlayers_searchresult_layer');
  feature.style = styleMap.styles['select'].defaultStyle;
  vectorLayer[0].drawFeature(feature, styleMap.styles['select'].defaultStyle);
  
  // Put the new dot in the middle. We are not zooming (yet, might do in the future)
  Drupal.openlayers_geosearch.data.openlayers.setCenter(new OpenLayers.LonLat(point.lon, point.lat).transform(Drupal.openlayers_geosearch.displayProjection, Drupal.openlayers_geosearch.projection));
  var controls = vectorLayer[0].map.getControlsByClass('OpenLayers.Control.SelectFeature');
  if (controls.length > 0) {
    if (feature != 'undefined') { // there is a very small chance, if you click like a madman this happens
      controls[0].select(feature);
    }
  }
  // Find the currently selected feature and redraw that in the default style
  var that = $('.openlayers-geosearch-result-table a.openlayers-geosearch-selected');
  if (!(that.length == 0)) {
    var point = Drupal.openlayers_geosearch.Geocoder.getpoint(that[0].href);
    var id = that[0].id.substring(0, that[0].id.length -5 );
    var feature = vectorLayer[0].getFeatureById(id);
    feature.style = styleMap.styles['default'].defaultStyle;
    vectorLayer[0].drawFeature(feature, styleMap.styles['default'].defaultStyle);
    if (controls.length > 0) {
      if (feature != 'undefined') { // there is a very small chance, if you click like a madman this happens
        controls[0].unselect(feature);
      }
    }
    $(that[0]).removeClass("openlayers-geosearch-selected");
  }
  // and select our current item
  $(this).addClass("openlayers-geosearch-selected");
  // bye bye
  return false;
}

/*
 *  Returns a Point from the href we have crafted
 */

Drupal.openlayers_geosearch.Geocoder.getpoint = function(href) {
//  var path = href.substring(Drupal.settings.basePath.length + location.pathname.length + 4); // 4 is for http:
  var mainparts = href.split("?");
  var parts = mainparts[1].split("&");
  var point = {};
  for (var i in parts) {
    part = parts[i].split("=");
    point[part[0]] = part[1];
  }
  return point;  
}

Drupal.openlayers_geosearch.Geocoder.zoomtoresults = function() {
  var layerextent = Drupal.openlayers_geosearch.vectorLayer[0].getDataExtent();

  // Check for valid layer extent
  if (layerextent != null) {
    Drupal.openlayers_geosearch.data.openlayers.zoomToExtent(layerextent);
    
    // If unable to find width due to single point,
    // zoom in with point_zoom_level option.
    // Lets try to change this to the Bounding box of the Point.
    if (layerextent.getWidth() == 0.0) {
      Drupal.openlayers_geosearch.data.openlayers.zoomTo(Drupal.openlayers_geosearch.data.map.behaviors['openlayers_behavior_zoomtolayer'].point_zoom_level);
    }
  }
}
