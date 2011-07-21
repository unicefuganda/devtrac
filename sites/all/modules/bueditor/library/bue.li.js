// $Id: bue.li.js,v 1.3.2.3 2010/11/08 07:10:25 ufku Exp $

//Automatically insert a new list item when enter-key is pressed at the end of a list item.
//Requires: none
BUE.preprocess.li = function(E, $) {

  $(E.textArea).bind('keyup.bue', function(e) {
    if (!e.ctrlKey && !e.shiftKey && !e.originalEvent.altKey && e.keyCode == 13) {
      var prefix = E.getContent().substr(0, E.posSelection().start);
      /<\/li>\s*$/.test(prefix) && E.tagSelection('<li>', '</li>');
    }
  });
 
};