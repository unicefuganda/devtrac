<?php

/**
 * @file
 * Theme implementation to display getfeatureinfo result
 */

print '<div class="layers">';
if ($tables)
  foreach ($tables as $name => $table) {
    $name = str_replace(":", " ", $name);
    print '<div class="layer ' . $name . '">';
    print theme_table($table['header'], $table['rows'], Array('class' => $name), $name, NULL, TRUE, t("No results"));
    print '</div>';
  }
  else {
    print t("No results found");
  }

print '</div>';


$referrer = $_SERVER['HTTP_REFERER'];
$q = drupal_substr($referrer, strpos($referrer, '/', 7) + 1);
$q = drupal_substr($q, 0, strpos($q, '?'));

$args = explode("/", $q);
print "<ul>";
print _devtrack_module_getbutton(t("Add another Place"), "node/" . $args[2] . "/addplaceform", NULL);
print _devtrack_module_getbutton(t("Back to Field Trip"), "node/" . $args[2], NULL);
print "</ul>";
