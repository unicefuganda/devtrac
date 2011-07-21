/**
*
* Copyright Rob Schmitt
* form-default-value.js
*
* This script searches the current page for all form input fields
* that have a 'default-value' class applied. The script then changes
* the color of whatever default text has been provided to the value
* of 'inactive_color'. If the user clicks on the input field, the
* default text is blanked, and the color changed to 'active_color'.
* If the user clicks away from the input field, the script will revert
* back to the default text (changing the color back to 'inactive_color',
* unless the user has entered some text.
*/

/**
* The following variables may be adjusted
*/
var active_color = 'red'; // Color of user provided text
var inactive_color = 'blue'; // Color of default text

/**
* Do not modify anything below this line
*/

if (Drupal.jsEnabled) {
  $(document).ready(function() {
    $("input.default-value").css("color", inactive_color);
    var default_values = new Array();
    $("input.default-value").focus(function() {
      if (!default_values[this.id]) {
        default_values[this.id] = this.value;
      }
      if (this.value == default_values[this.id]) {
        this.value = '';
        this.style.color = active_color;
      }
      $(this).blur(function() {

        if (this.value == '') {
          this.style.color = inactive_color;
          this.value = default_values[this.id];
        }
      });
    });
  });
}