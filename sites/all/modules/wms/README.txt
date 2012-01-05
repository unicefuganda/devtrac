
# WMS Module

The WMS module implements the WMSGetFeatureInfo control as a behaviour for
the openlayers module.
It allows you to query WMS layers of an Openlayers map for details on displayed
features.
It comes with a block where the results are inserted.
It is implemented as a seperate module because it implements 2 menu's.

http://dev.openlayers.org/docs/files/OpenLayers/Control/WMSGetFeatureInfo-js.html


## Requirements

* OpenLayers
* js_theming
  This is a module that makes it real easy to create a table in javascript code.
* proxy
  This module is needed for the server-side processing implementation of the getfeaturerequest.
  This is how it should be finally implemented. For now the request is done & processed on the client-side, 
  the dependency is included so you dont spend a day wondering why no data is every returned.
  After installing, make sure:
  * The correct users have the 
  * Your preset has a proxy value of 'proxy?request=' 
  * The security settings on the proxy admin page make sense http://example.com/admin/settings/proxy



## ISSUES!

# You *must* apply this patch to js_theming
  http://drupal.org/node/938998
  
# This is an alpha release. It contains more code than is actually ever executed. It also has a dependency on
a module that seems to be abandoned (the creator has not posted anything on drupal.org since a year it seems)

The major issue is that I would have liked to implement the getfeaturerequest as a server-side
call (using proxy) and then process the resulting XML on the server, using the Drupal theming 
engine and hooks for modules that would like to filter/update/add things.

I ran into trouble with the simpleXML and DOMDocument. It's probably namespacing issues. If you read this
and you know what a namespace is, i could use some help. The code is there. In order to switch to 
server-side processing:
# in the openlayers_behavior_wmsgetfeatureinfo.js file, comment out the code for the control, and enable
the code that calls the URL directly.
# in the wms.module the wms_ajax_wmsgetfeatureinfo function gets the request (that works)
# things fall apart in the wms_process_wmsgetfeatureinfo_result module
# there is an example result (the full XML) in the test.

# TODO

* more options in the UI
* add other WMS functionality (including the layer?) like the WFS module
* make the process link use a POST request instead of GET
* Ajaxify the process link
* more TODOs in the code


## Credits

* [batje](http://drupal.org/user/2696)
