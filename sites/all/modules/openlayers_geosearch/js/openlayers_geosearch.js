Drupal.openlayers_geosearch = {};
Drupal.behaviors.openlayers_geosearch = function (context) {

  $('#openlayersgeosearchresults', context).not('.openlayersgeosearchresults-processed').each(function() {
    $(this).addClass('openlayersgeosearchresults-processed');
    Drupal.openlayers_geosearch.data = $('#openlayers_geosearch_map_id').data('openlayers');
    if (!Drupal.openlayers_geosearch.data.map.displayProjection) {
      Drupal.openlayers_geosearch.data.map.displayProjection = 4326;
    }
    Drupal.openlayers_geosearch.displayProjection = new OpenLayers.Projection('EPSG:' + Drupal.openlayers_geosearch.data.map.displayProjection);
    Drupal.openlayers_geosearch.projection = new OpenLayers.Projection('EPSG:' + Drupal.openlayers_geosearch.data.map.projection);
    var searchLayer = new OpenLayers.Layer.Vector(
      Drupal.t("Search Layer"),
      {
        projection: new OpenLayers.Projection('EPSG:4326'),
        drupalID: 'openlayers_searchresult_layer'
      }
    )

    searchLayer.styleMap = Drupal.openlayers.getStyleMap(Drupal.openlayers_geosearch.data.map, 'openlayers_searchresult_layer');
    Drupal.openlayers_geosearch.data.openlayers.addLayer(searchLayer);

    Drupal.openlayers_geosearch.vectorLayer = Drupal.openlayers_geosearch.data.openlayers.getLayersBy('drupalID', "openlayers_searchresult_layer");
  });

  $("#openlayersgeosearchtabs", context).not('.openlayersgeosearchtabs-processed').each(function() {
    $(this).tabs().addClass('.openlayersgeosearchtabs-processed');
  });

  var i = 0;
  $('.openlayers-geosearch-result-table', context).not('.openlayers-geosearch-result-table-processed').each(function() {
    $(this).addClass('openlayers-geosearch-result-table-processed');
    // here we remove the dots from the map
    if (i == 0) {
      Drupal.openlayers_geosearch.vectorLayer[0].removeFeatures(Drupal.openlayers_geosearch.vectorLayer[0].features);
      i++;
    }

    $('.openlayers-geosearch-result-table a', context).not('.openlayers-geosearch-result-a-processed').each(function() {
      $(this).addClass('openlayers-geosearch-result-a-processed');
      // and here we add the dot to the map
      var point = Drupal.openlayers_geosearch.Geocoder.getpoint ($(this)[0].href); 
      var geometry = new OpenLayers.Geometry.Point(point.lon, point.lat).transform(Drupal.openlayers_geosearch.displayProjection, Drupal.openlayers_geosearch.projection);
      var bounds = new OpenLayers.Bounds(point.minx, point.miny, point.maxx, point.maxy).transform(Drupal.openlayers_geosearch.displayProjection, Drupal.openlayers_geosearch.projection);
      Drupal.openlayers_geosearch.vectorLayer[0].addFeatures([new OpenLayers.Feature.Vector(geometry)]);
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
 * Performs a search on the a links in the Block
 */
Drupal.openlayers_geosearch.Geocoder.blockclick = function () {
  var point = Drupal.openlayers_geosearch.Geocoder.getpoint(this.href); 
//  var geometry = new OpenLayers.Geometry.Point(point.lon, point.lat).transform(displayProjection, projection);
//  var bounds = new OpenLayers.Bounds(point.box.west, point.box.south, point.box.east, point.box.north).transform(displayProjection, projection);

  //Remove all points, unless CCK widget settings prevent it.
  Drupal.openlayers_geosearch.data.openlayers.setCenter(new OpenLayers.LonLat(point.lon, point.lat).transform(Drupal.openlayers_geosearch.displayProjection, Drupal.openlayers_geosearch.projection));

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
