This module will allow you to use the openlayers_geosearch module with a server-side WFS request. 

The flow of the module is like this:

- The form in the browser does a request to the drupal site.
- The openlayers_geosearch module calls all enabled openlayers_geosearch modules to return a value
- the openlayers_geosearch_wfs module calls the configured WFS endpoint with the following request
(it replaces the correct layername and PropertyName)

<wfs:GetFeature service="WFS" version="1.1.0"
  xmlns:topp="http://www.openplans.org/topp"
  xmlns:wfs="http://www.opengis.net/wfs"
  xmlns:ogc="http://www.opengis.net/ogc"
  xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
  xsi:schemaLocation="http://www.opengis.net/wfs
                      http://schemas.opengis.net/wfs/1.1.0/wfs.xsd">
  <wfs:Query typeName="Devtrac:HealthCenterIII">
    <ogc:Filter>
          <PropertyIsLike matchCase="false" wildCard="*" singleChar="#" escapeChar="!">
                <PropertyName>name</PropertyName>
                <Literal>*Iiso*</Literal>
          </PropertyIsLike>
    </ogc:Filter>
    </wfs:Query>
</wfs:GetFeature>

The server will return a reply like

<wfs:FeatureCollection numberOfFeatures="1" timeStamp="2011-09-21T16:59:59.716+03:00" xsi:schemaLocation="http://www.devtrac.ug/uganda http://geoserver.mountbatten.net:8081/geoserver/wfs?service=WFS&version=1.1.0&request=DescribeFeatureType&typeName=Devtrac%3AHealthCenterIII http://www.opengis.net/wfs http://geoserver.mountbatten.net:8081/geoserver/schemas/wfs/1.1.0/wfs.xsd">
  <gml:featureMembers>
    <Devtrac:HealthCenterIII gml:id="HealthCenterIII.fid--7368d033_1328c3e8f8f_-7da2">
      <gml:name>Biiso</gml:name>
      <Devtrac:id>377</Devtrac:id>
      <Devtrac:unitid>UGH01966</Devtrac:unitid>
      <Devtrac:placetype>3</Devtrac:placetype>
      <Devtrac:code>HC III</Devtrac:code>
      <Devtrac:num>0</Devtrac:num>
      <Devtrac:district>Buliisa</Devtrac:district>
      <Devtrac:comment>BIISO</Devtrac:comment>
      <Devtrac:the_geom>
        <gml:Point srsDimension="2" srsName="urn:x-ogc:def:crs:EPSG:4326">
          <gml:pos>1.79978 31.47672</gml:pos>
        </gml:Point>
      </Devtrac:the_geom>
    </Devtrac:HealthCenterIII>
  </gml:featureMembers>
</wfs:FeatureCollection>

- The wfs module will parse this XML into the array format that the openlayers_geosearch module expects and returns it. The format looks like

 [WFS] => Array
        (
            [0] => Array
                (
                    [address] => Kampala, Uganda
                    [components] => Array
                        (
                            [locality] => Kampala
                            [administrative_area_level_2] => Kampala
                            [administrative_area_level_1] => Central Region
                            [country] => Uganda
                            [country_code] => UG
                            [street_address] => Kampala, Uganda
                        )

                    [location] => Array
                        (
                            [lat] => 0.3136111
                            [lng] => 32.5811111
                        )

                    [bounds] => Array
                        (
                            [northeast] => stdClass Object
                                (
                                    [lat] => 0.4028733
                                    [lng] => 32.7091705
                                )

                            [southwest] => stdClass Object
                                (
                                    [lat] => 0.2243482
                                    [lng] => 32.4530517
                                )

                        )

                )

        )


- The openlayers_geosearch module will theme the results from all openlayers_geosearch modules and returns the information as a table
- The openlayers_geosearch javascript replaces the results block content with the returned html and its behaviours plot the dots on the 
  map and zooms the map to the correct extend.
  