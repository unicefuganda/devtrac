/* $Id: itweak_upload.js,v 1.2.2.1 2010/02/11 04:50:10 iva2k Exp $ */

Drupal.behaviors.attachment = function (context) {
  $('#attach-wrapper input[type=submit]').hide();
  $('#attach-wrapper input[type=file]').change(function(e) {
    $('#attach-wrapper input[type=submit]').trigger('mousedown');
  });
  $('#attach-wrapper #upload-attachments tr').each(function() {
    var row = $(this);
    // Description link
    var rename_input = row.children('td.file').children('div').children('input.rename');
    var name = $('<span>'+ Drupal.checkPlain(rename_input.val()) +'</span>');
    var rename_link = $('<a class="rename">'+ Drupal.t('Rename') +'</a>');
    rename_input.after(rename_link).after(name).hide();
    rename_link.toggle(
      function() {
        name.hide();
        rename_input.show();
        $(this).text(Drupal.t('Cancel'));
      },
      function() {
        name.show();
        rename_input.hide();
        rename_input.val(name.text());
        $(this).text(Drupal.t('Rename'));
      }
    );
	// Remove link
    var remove_input = row.children('td.remove').children('div').children('input.remove');
    row.children('td.remove').hide();
    if (remove_input.attr('checked')) $(this).hide();
    var remove_link = $('<a class="remove">'+ Drupal.t('Remove') +'</a>');
    rename_link.after(remove_link);
    remove_link.click(function() {
      row.hide();
      remove_input.attr('checked', true);
      var has_content = false;
      $('#upload-attachments tbody tr').each(function() {
        if ($(this).css('display') != 'none') has_content = true;
      });
      if (!has_content) $('#upload-attachments').hide();
    });
  });
};