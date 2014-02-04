/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

(function ($, Drupal, window, document, undefined) {

  $(document).ready(function() {

    /* Responsive menu */

    var jPM = $.jPanelMenu({
      menu: '#nav-menu',
      trigger: '.navbar .btn-navbar',
      duration: 300,
			 animated: true
    });

    jPM.on();

    $('#jPanelMenu-menu > ul > li ul').hide();
    $jPM = $('#jPanelMenu-menu');
    arrowli = '<div class="arrowli icon-chevron-right"></div>';
    $jPM.find('.expanded').prepend(arrowli);
    $jPM.find('.arrowli').click(function() {
      $(this).toggleClass('icon-chevron-right').toggleClass('icon-chevron-down').nextAll('ul').slideToggle('slow').parent().toggleClass('openli');
		});

    var $swConts = $('.page-taxonomy .swiper-container').add('.front .swiper-container');
    $swConts.each(function(i,e) {
      var mySwiper = $(e).swiper({
        speed: 500,
        mode: 'horizontal',
        pagination: $(e).find('.swiper-pagination')[0],
        paginationClickable: true,
        calculateHeight: true
      });
    });

	  $("#img_01").elevateZoom({
      zoomType: 'inner',
      gallery:'gal1',
      cursor: 'crosshair',
      galleryActiveClass: 'active',
      imageCrossfade: true,
      easing: true
    });

  });

})(jQuery, Drupal, this, this.document);
