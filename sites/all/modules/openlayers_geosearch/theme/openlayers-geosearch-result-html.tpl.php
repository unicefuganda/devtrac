<?php
/**
 * @file: openlayers-geocoder-result-html.tpl.php
 *
 * Template file theming geosearch's response results.
 */

  print '<table class="openlayers-geosearch-result-table">';
//  print "<caption>" . $provider . "</caption>";
  print "<thead>";
  $headers = array_keys($locations[0]['locations']['components']);
  foreach ($headers as $header) {
    print "<th>" . t($header) . "</th>";
  }
  print "</thead>";
  foreach ($locations as $location) {
    $firstcolum = TRUE;
    print "<tr>";
    $fid = 1; // We are going to give every feature an id, this should never happen in a template file, so TODO fix this.
    foreach ($location['locations']['components'] as $key => $component) {
      if ($firstcolum) {
        print '<td><a class="openlayers-geosearch-result-link" href="?lat=' . $location['locations']['location']['lat'] .
          '&lon=' . $location['locations']['location']['lng'] .
          '&minx=' . $location['locations']['bounds']['southwest']->lng .
          '&miny=' . $location['locations']['bounds']['southwest']->lat .
          '&maxx=' . $location['locations']['bounds']['northeast']->lng .
          '&maxy=' . $location['locations']['bounds']['northeast']->lat .
          '&fid=' . $provider . '_' . $fid.
        '">' . $component .'</a></td>';
        $firstcolum = FALSE;
        $fid++; 
      }
      else {
        print "<td>" . $component ."</td>";
      }
    }
    print "</tr>";
  }
  print "</table>";
