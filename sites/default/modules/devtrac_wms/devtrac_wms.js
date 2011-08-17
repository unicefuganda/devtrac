/**
 * 
 */

Drupal.behaviors.devtracwms = function (context) {
  $('.getfeatureaddlink:not(.wmsdevtrac-processed)', context)
    .click (function() {
    $(this).addClass('getfeatureinfo-submitting');
    var url = this.href;
    
    if (url == undefined) {
      url = me.href;
    }
    if (url == undefined) {
      return true;
    }
    $.ajax({
      url: url,
      type: 'GET',
      success: function(response) {
        // Call all callbacks.
        if (response.__callbacks) {
          $.each(response.__callbacks, function(i, callback) {
            eval(callback)(element, response);
          });
        }
        alert(response.content);
        //$(element).html(response.content);
      },
      error: function(response) {
          alert(response.content);
          $(this).removeClass('getfeatureinfo-submitting');
      },
      dataType: 'json'
    });
    return false;
    })

  .addClass('wmsdevtrac-processed');
};
