<?php
// $Id$

/**
 * @file
 * Theme implementation to display getfeatureinfo result
 */

foreach ($tables as $name => $table) {
  $name = str_replace(":", " ", $name);
  print '<div class="' . $name . '">';
  print theme_table($table['header'], $table['rows'], Array('class' => $name), $name, NULL, TRUE, t("No results"));
  print '</div>';
}
