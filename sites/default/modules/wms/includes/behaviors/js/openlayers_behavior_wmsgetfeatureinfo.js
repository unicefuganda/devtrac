// $Id: wfs_behavior_virtualclick.js,v 1.1.2.3 2010/05/07 20:18:07 tmcw Exp $

/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * WMSGetFeatureinfo Behavior
 * http://dev.openlayers.org/releases/OpenLayers-2.9/doc/apidocs/files/OpenLayers/Control/WMSGetFeatureInfo-js.html
 */
Drupal.behaviors.openlayers_behavior_wmsgetfeatureinfo = function(context) {
  // if there are already links on the page (like in bubbles), then make sure they are ajaxified here
  $('.getfeatureaddlink').bind("click",Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo.click);
  
  
  
  var layer;
  var data = $(context).data('openlayers');

  if (data && data.map.behaviors['openlayers_behavior_wmsgetfeatureinfo']) {
    if (data.map.behaviors['openlayers_behavior_wmsgetfeatureinfo'].getfeatureinfo_usevisiblelayers == false) { 
      layer = data.openlayers.getLayersBy('drupalID', 
        data.map.behaviors['openlayers_behavior_wmsgetfeatureinfo'].getfeatureinfo_layers);  // TODO Make this multiple select! 
    }
    Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo.getfeatureinfo_htmlelement = 
      data.map.behaviors['openlayers_behavior_wmsgetfeatureinfo'].getfeatureinfo_htmlelement;
    Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo.getfeatureinfo_usevisiblelayers = 
      data.map.behaviors['openlayers_behavior_wmsgetfeatureinfo'].getfeatureinfo_usevisiblelayers;
    Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo.getfeatureinfo_processlink = 
      data.map.behaviors['openlayers_behavior_wmsgetfeatureinfo'].getfeatureinfo_processlink;
    

    
    // support GetFeatureInfo
    /* This is the simple, old-fashioned way. 
     * # Create an array of options
     * # let openlayers turn that into a URL
     * # call the URL with custom Drupal ajax, with your js function as a callback
     * 
     * This option is good, if you want to call the ajax menu function in the wms module and use the proxy module to do the call
     * This is the best way to be able to create a _hook that would allow 3d party modules to process the result of the call
     * and make nice themed tables or blocks or whatever people want to do
     * 
     *  Unfortunatly, for now i have to give up, as (you can find that in the code) i can not load the 
     *  result from the call into an XML parser, though it is valid XML.
     *  So, for now, this code is commented out.
     */

    /*

    data.openlayers.events.register('click', data.openlayers, function (e) {
            document.getElementById(Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo.getfeatureinfo_htmlelement).innerHTML = "Loading... please wait...";
            var params = {
                REQUEST: "GetFeatureInfo",
                EXCEPTIONS: "application/vnd.ogc.se_xml",
                BBOX: layer[0].getExtent().toBBOX(),
                X: e.xy.x,
                Y: e.xy.y,
                INFO_FORMAT: 'application/vnd.ogc.gml', // can also be 'text/html', // 
                QUERY_LAYERS: layer[0].params.LAYERS,
                FEATURE_COUNT: 50,
                Srs: 'EPSG:4326', // TODO take the maps EPSG
                Layers: layer[0].params.LAYERS, 
                Styles: '',
                WIDTH: data.openlayers.size.w,
                HEIGHT: data.openlayers.size.h,
                format: 'image/png'}; // TODO parameterize this, like ...?
            
            
            url =  layer[0].getFullRequestString(params);
            var drupalparams =  {
              url: url
            };
            
            ajaxurl = Drupal.settings.basePath + 'openlayers/wms/wmsgetfeatureinfo';
            $.ajax({ 
              type: 'POST', 
              url: Drupal.settings.basePath + 'openlayers/wms/wmsgetfeatureinfo',
              data: { 
                'ajax' : true, 
                'url' : url 
              },
              success: Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo.fillHTML,
              fail: Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo.fillHTMLerror,
            });
            OpenLayers.Event.stop(e);
        });
*/

  /* This is the more modern way to do it.
   * It works wonderfully, as a control. 
   * You probably need the proxy module to make it work, as the calls this control do 
   * may not go to anything else than the same URL that your site is running on.
   * So, http://localhost/openlayers != http://localhost:8080/geoserver
   * 
   * Documentation about the control can be found at:
   * http://dev.openlayers.org/docs/files/OpenLayers/Control/WMSGetFeatureInfo-js.html
   */  

    infoControls = {
        click: new OpenLayers.Control.WMSGetFeatureInfo({
            title: 'Identify features by clicking',
            layers:  layer,
            queryVisible: true
        })
    };
         
    /*
     * Can't see a 'failed' event in the documentation. For example when there is an Access Denied. 
     */
    infoControls['click'].events.register("getfeatureinfo", this, Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo.getfeatureinfo);
    infoControls['click'].events.register("beforegetfeatureinfo", this, Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo.beforegetfeatureinfo);
    infoControls['click'].events.register("nogetfeatureinfo", this, Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo.nogetfeatureinfo);
       
    // TODO: These should be parameters
    infoControls['click'].infoFormat = 'application/vnd.ogc.gml'; // can also be 'text/html', //
    infoControls['click'].drillDown = true;
    infoControls['click'].maxFeatures = 10;
//    infoControls['click'].vendorParams = {radius: 5 };

    
    data.openlayers.addControl(infoControls['click']); 
    infoControls['click'].activate();

  }
  Drupal.OpenLayersPlusBlockswitcher.redraw(); // sorry tom, i had to do this else your block stays empty
}

//Initialize settings array.
Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo = {};

Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo.beforegetfeatureinfo = function(request) {
  if (Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo.getfeatureinfo_usevisiblelayers == false) { 
    document.getElementById(Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo.getfeatureinfo_htmlelement).innerHTML = Drupal.t('Searching...');
    return; 
  }
  
  var layers = [];
  var layernames = "";
  for (layerindex in request.object.map.layers) {
    layer = request.object.map.layers[layerindex];
    if ((layer.CLASS_NAME == "OpenLayers.Layer.WMS") && layer.visibility && (layer.isBaseLayer == false)) {
      layers.push( layer );
      layernames = layernames + layer.name;
    } 
  }
  if (layers.length == 0 ) {
    document.getElementById(Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo.getfeatureinfo_htmlelement).innerHTML = Drupal.t('No layer selected');
    return;
  }
  request.object.layers = layers;  
  
  document.getElementById(Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo.getfeatureinfo_htmlelement).innerHTML = Drupal.t('Searching in ' + layernames);
  return;
};

Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo.nogetfeatureinfo = function(response) {
  /* I have not seen the code pass throught this function yet. */
  document.getElementById(Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo.getfeatureinfo_htmlelement).innerHTML = Drupal.t('No actual data found.');
};

Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo.getfeatureinfo = function(response) {

  if (response.features.length == 0) {
    /* it seems the nogetfeatureinfo function doesnt always work*/
    document.getElementById(Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo.getfeatureinfo_htmlelement).innerHTML = Drupal.t('No data found.');
    return ;
  } 
  var header = [];
  var isheader = true;
  var rows = [];
  var ftype;
  var html = "";
  for (feature in response.features) {
    var row = [];
    tpftype = response.features[feature].fid.substring(0, response.features[feature].fid.indexOf("."));
    if ((isheader == false) && (ftype != tpftype)) {
      html = html + "<h5>"+ ftype + "</h5>" + Drupal.theme('table', header, rows);
      header = [];
      rows = [];
      ftype = tpftype;
      isheader = true;
    }
    ftype = tpftype;
      for (attribute in response.features[feature].attributes) {
        if (isheader) {
          header.push(attribute);
        }
        row.push(response.features[feature].attributes[attribute]);
      }
      if (isheader) {    
        if (Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo.getfeatureinfo_processlink) {
          header.push ('Layer');  // its not really relevant to show the layername in the rows, unless we are going to post this to the server
          header.push ('Add');
        }
      }
      isheader = false; //only add the header once
      if (Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo.getfeatureinfo_processlink) {
        // Create the link to our hook function on the server
        params = response.features[feature].attributes;
        params['layer'] = ftype;
        params['geometry'] = response.features[feature].geometry.toString();
        params['arg'] = Drupal.settings.request.q; // i need this, the args of the original page request, and this seems the most generic way to implement.  
        var attribs = {
            'attributes' : {
              'class': 'getfeatureaddlink'
               },
            'query':params
        };
        
        $link = Drupal.l('Add', 'openlayers/wms/wmsgetfeatureinfo_process', attribs);

        row.push(ftype); // the layername
        row.push ($link); 
      }
      
      rows.push(row);
   }
   
   html = html + "<h5>"+ ftype + "</h5>" + Drupal.theme('table', header, rows);
   document.getElementById(Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo.getfeatureinfo_htmlelement).innerHTML = html;
   $('#' + Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo.getfeatureinfo_htmlelement + ' .getfeatureaddlink').bind("click",Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo.click);
};

Drupal.openlayers.openlayers_behavior_wmsgetfeatureinfo.click = function(me) {
  $(this).addClass('getfeatureinfo-submitting');
  var url = this.href;
  if (url == undefined) {
    url = me.href;
  }
  if (url == undefined) {
    return true;
  }
  $.ajax({
    url: url,
    type: 'GET',
    success: function(response) {
      // Call all callbacks.
      if (response.__callbacks) {
        $.each(response.__callbacks, function(i, callback) {
          eval(callback)(element, response);
        });
      }
      alert(response.content);
      //$(element).html(response.content);
    },
    error: function(response) {
        alert(response.content);
        $(this).removeClass('getfeatureinfo-submitting');
    },
    dataType: 'json'
  });
  return false;
}

  
