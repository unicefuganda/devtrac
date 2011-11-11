/**
 * 
 */
$(document).ready(function() {
// only on the addplace page, check these boxes by default
  if (!$.browser.msie) {
    $('input[name="reporttype"]')[0].checked = true;
    $('input[name="placetype"]')[0].checked = true;
  }
  else {
//    alert('Going to set defaults.');
    $('input[name="reporttype"]')[0].checked = true;
    $('input[name="placetype"]')[0].checked = true; 
//    alert('Defaults set.');
  }
});

Drupal.behaviors.devtrac = function (context) {
  /** Finder Page
   * All items with a placetype are Site Visits.
   */
  $('#edit-placetype:not(.processed)').each(function() {
    $(this).addClass('processed'); //this is for ourselves
      // IE does not see the change event when it happens, so we help it a bit. FUCKERS!!
      $(this).click(function() {
        if ($.browser.msie) {
          $(this).change();
          $(this).blur();

       }
      });
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
      // IE does not see the change event when it happens, so we help it a bit. FUCKERS!!
      $(this).click(function() {
        if ($.browser.msie) {
          $(this).change();
          $(this).blur();

       }
      });
    $(this).change(function() {
      $('#edit-placetype')[0].disabled = $(this)[0].selectedIndex == 2;
      return false;
    });
    // call change for initial settings
    $(this).change();
  });
  
  

  /** Add place page
   *  If adding Roadside Observation, then hide placetype 
   */
  $('#devtrack-module-addplaceform .form-radio[name="reporttype"]:not(.processed)').each(function() {
    $(this).addClass('processed'); //this is for ourselves
      // IE does not see the change event when it happens, so we help it a bit. FUCKERS!!
      $(this).click(function() {
        if ($.browser.msie) {
          $(this).change();
          $(this).blur();

       }
      });
      $(this).change(function() {
        $('input[name="placetype"]').attr('disabled', ($(this)[0].value == 1 && $(this)[0].checked));
        $('input[name="placetype"]').parent().parent().parent().parent().toggle(!($(this)[0].value == 1 && $(this)[0].checked));
        $($('input[name="placetype"]')[4]).parent().toggle(!($(this)[0].value == 0 && $(this)[0].checked));
        if ($('input[name="placetype"]')[4].checked) {
          $('input[name="placetype"]')[3].checked = ($(this)[0].value == 0 && $(this)[0].checked);
        }
        return false;
      });
      // call change for initial settings
      $(this)[0].checked = true;
      
      $(this).change();
  });
};
