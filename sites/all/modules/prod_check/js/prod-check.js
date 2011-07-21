/* $Id: prod-check.js,v 1.1.2.1 2011/01/24 15:26:18 malc0mn Exp $ */

/* Prod monitor settings page styling */

$(document).ready(function() {
  $('#edit-prod-check-module-list-time').mask('99:99');
  $('#prod-check-settings').equalHeights('px');
  $('#prod-check-settings').equalWidths('px');
});

$('#prod-check-nagios').change(function() {
  $('#prod-check-settings').equalHeights('px');
  $('#prod-check-settings').equalWidths('px');
});
