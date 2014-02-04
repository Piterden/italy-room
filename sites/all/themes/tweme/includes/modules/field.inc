<?php

/**
 * @file
 * Provides theme overrides and implementations for the Field module.
 */

/**
 * Overrides theme_field__FIELD_ID() for field_tags.
 */
function tweme_field__field_tags($vars) {
  $out = '';
  foreach ($vars['items'] as $item) {
    $item['#options']['attributes']['class'][] = 'badge';
    $out .= ' ' . drupal_render($item);
  }
  return '<div class="'. $vars['field_name_css'] .'">' . $out . '</div>';
}

function tweme_field__field_image__product_display($vars) {

  // Teaser by Views (_custom_display)

  if ($vars['element']['#view_mode'] == '_custom_display') {

    $output = '';

    // Render the label, if it's not hidden.
    if (!$vars['label_hidden']) {
      $output .= '<div class="field-label"' . $vars['title_attributes'] . '>' . $vars['label'] . ':&nbsp;</div>';
    }

    // Render the items.
    $output .= '<div class="field-items"' . $vars['content_attributes'] . '><div class="swiper-container"><div class="swiper-wrapper">';
    foreach ($vars['items'] as $delta => $item) {
      $classes = 'field-item swiper-slide ' . ($delta % 2 ? 'odd' : 'even');
      $output .= '<div class="' . $classes . '"' . $vars['item_attributes'][$delta] . '>' . drupal_render($item) . '</div>';
    }
    $output .= '</div><div class="swiper-pagination"></div></div></div>';

    // Render the top-level DIV.
    $output = '<div class="' . $vars['classes'] . '"' . $vars['attributes'] . '>' . $output . '</div>';

    return $output;

  }

  // Full by drupal (full)

  if ($vars['element']['#view_mode'] == 'full') {

    $output = '';
    $public = file_create_url('public://');

    // Render the label, if it's not hidden.
    if (!$vars['label_hidden']) {
      $output .= '<div class="field-label"' . $vars['title_attributes'] . '>' . $vars['label'] . ':&nbsp;</div>';
    }

    // Render the items.
    $output .= '<img id="img_01" ';
    $output .= 'src="' . $public . 'styles/product_image/public/' . $vars['items'][0]['#item']['filename'] . '" ';
    $output .= 'data-zoom-image="' . $public . $vars['items'][0]['#item']['filename'] . '"/>' ;
    $output .= '<div id="gal1">';
    foreach ($vars['items'] as $delta => $item) {
      $data_image = $public . 'styles/product_image/public/' . $item['#item']['filename'];
      $data_zoom_image = $public . $item['#item']['filename'];
      $output .= '<a href="#" data-image="' . $data_image . '" data-zoom-image="' . $data_zoom_image . '">';
      $output .= '<img src="' . $public . 'styles/thumbnail/public/' . $item['#item']['filename'] . '"/>';
      $output .= '</a>';
    }
    $output .= '</div>';

    // Render the top-level DIV.
    $output = '<div class="' . $vars['classes'] . '"' . $vars['attributes'] . '>' . $output . '</div>';

    return $output;

  }

}
