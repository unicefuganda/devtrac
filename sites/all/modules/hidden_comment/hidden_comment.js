Drupal.behaviors.hidden_comment = function (context) {
  $('#edit-default-reasons').change(function() {
    $('#edit-reason').val($('#edit-default-reasons :selected').text());
  });
}
