<?php
// $Id: theme.inc,v 1.1 2009/12/17 13:05:59 snpower Exp $

/**
 * Display the view as a two column table.
 */
function template_preprocess_views_view_two_column_table(&$vars) {
  template_preprocess_views_view_table($vars);
}
