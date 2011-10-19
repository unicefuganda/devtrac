/**
 * 
 */

Drupal.behaviors.devtrac = function (context) {
  /** Finder Page
   * All items with a placetype are Site Visits.
   */
  $('#edit-placetype:not(.processed)').each(function() {
    $(this).addClass('processed'); //this is for ourselves
    $(this).change(function() {
      if ($(this)[0].selectedIndex > 0 ) {
        if (($('#edit-sitereporttype')[0].selectedIndex == 0) || ($('#edit-sitereporttype')[0].selectedIndex == 2)) { 
          $('#edit-sitereporttype')[0].selectedIndex = 1;
        }
      }
      $('#edit-sitereporttype option')[0].disabled = ($(this)[0].selectedIndex > 0);
      $('#edit-sitereporttype option')[2].disabled = ($(this)[0].selectedIndex > 0);
      return false;
    });
    // call change for initial settings
    $(this).change();
  });

  /** Finder Page
   *  If Roadside observation then dont select a Placetype
   */
  $('#edit-sitereporttype:not(.processed)').each(function() {
    $(this).addClass('processed'); //this is for ourselves
    $(this).change(function() {
      $('#edit-placetype')[0].disabled = $(this)[0].selectedIndex == 2 
      return false;
    });
    // call change for initial settings
    $(this).change();
  });

};
