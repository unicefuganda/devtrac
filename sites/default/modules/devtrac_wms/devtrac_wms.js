/**
 * 
 */

Drupal.behaviors.devtracwms = function (context) {
  $('.getfeatureaddlink:not(.wmsdevtrac-processed)', context)
    .click (function() {
      return Drupal.devtracwms.click(this);
    })

  .addClass('wmsdevtrac-processed');
};

//Initialize settings array.
Drupal.devtracwms = {};

Drupal.devtracwms.click = function(me) {
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
      myPath = window.location.pathname.split('/');
      
      window.location = Drupal.settings.basePath + 'node/' + myPath[3];
      //$(element).html(response.content);
    },
    error: function(response) {
        alert(response.content);
        $(this).removeClass('getfeatureinfo-submitting');
    },
    dataType: 'json'
  });
  return false;
}



