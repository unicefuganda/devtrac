Drupal.behaviors.ViewsGalleriffic = function () { 
  var settings = Drupal.settings.views_galleriffic;
  
  // Initially set opacity on thumbs and add
  // additional styling for hover effect on thumbs
  var onMouseOutOpacity = 0.67;
  $('#thumbs ul.thumbs li').css('opacity', onMouseOutOpacity)
   .hover(
     function () {
       $(this).not('.selected').fadeTo('fast', 1.0);
     },
     function () {
      $(this).not('.selected').fadeTo('fast', onMouseOutOpacity);
     }
   );

        // Initialize Advanced Galleriffic Gallery
        var gallery = $('#thumbs').galleriffic({ 
          delay:                  settings.delay,
          numThumbs:              settings.numbthumbs,
          preloadAhead:           settings.numbthumbs,
          enableTopPager:         settings.enableTopPager,
          enableBottomPager:      settings.enableBottomPager,
          imageContainerSel:      '#slideshow',
          controlsContainerSel:   '#controls',
          captionContainerSel:    '#caption',
          loadingContainerSel:    '#loading',
          renderSSControls:       settings.renderSSControls,
          renderNavControls:      settings.renderNavControls,
          playLinkText:           settings.playLinkText,
          pauseLinkText:          settings.pauseLinkText,
          prevLinkText:           settings.prevLinkText,
          nextLinkText:           settings.nextLinkText,
          nextPageLinkText:       settings.nextPageLinkText,
          prevPageLinkText:       settings.prevPageLinkText,
          enableHistory:          settings.enableHistory,
          autoStart:              settings.autoStart,
          onSlideChange: function(prevIndex, nextIndex) {
            // 'this' refers to the gallery, which is an extension of $('#thumbs')
            this.find('ul.thumbs').children()
            .eq(prevIndex).fadeTo('fast', onMouseOutOpacity).end()
            .eq(nextIndex).fadeTo('fast', 1.0);
          },
          onPageTransitionOut: function(callback) {
            this.fadeTo('fast', 0.0, callback);
          },
          onPageTransitionIn: function() {
             this.fadeTo('fast', 1.0);
          } 
        });
}










