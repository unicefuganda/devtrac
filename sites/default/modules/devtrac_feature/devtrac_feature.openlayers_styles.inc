<?php

/**
 * Implementation of hook_openlayers_styles().
 */
function devtrac_feature_openlayers_styles() {
  $export = array();

  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'placetype';
  $openlayers_styles->title = 'Placetype';
  $openlayers_styles->description = 'The style to render placetypes with. Must have a [tid] field to show the taxonomy image';
  $openlayers_styles->data = array(
    'externalGraphic' => 'http://devtrac.mbcdn.net${tid_rendered}',
    'pointRadius' => 10,
    'fillColor' => '#EE9900',
    'strokeColor' => '#EE9900',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicOpacity' => 1,
    'labelAlign' => 'cm',
  );
  $export['placetype'] = $openlayers_styles;

  return $export;
}