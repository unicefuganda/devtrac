
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
