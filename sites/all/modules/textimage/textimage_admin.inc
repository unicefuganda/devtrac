<?php

// $Id: textimage_admin.inc,v 1.5.4.3 2009/02/09 22:42:48 deciphered Exp $

/**
 * @file
 */

function textimage_settings_form() {
  $form = array();

  $fonts_path = variable_get("textimage_fonts_path", drupal_get_path('module', 'textimage') .'/fonts');
  $images_path = variable_get("textimage_images_path", drupal_get_path('module', 'textimage') .'/backgrounds');

  //check for GD
  if (!function_exists('imagecreate')) {
    drupal_set_message(t('Image library not available. Textimage needs the GD library extension to be installed. Please install GD.'), 'error');
  }

  //check for FreeType support
  if (!function_exists('imagettftext')) {
    drupal_set_message(t('Your image library does not seem to have TrueType font support. Textimage will work, but will use the default inbuilt font.'), 'error');
  }

  //check for clean URL support
  if (!variable_get('clean_url', FALSE)) {
    drupal_set_message(t('Textimage requires <a href="!path">clean URLs</a> be enabled. Without clean URL support Textimage is unable to cache images and can cause serious performance problems.', array('!path' => url('admin/settings/clean-urls'))), 'error');
  }

  //check for valid font path
  if ($fonts_path != '' && !is_dir(rtrim($fonts_path, '\\/'))) {
    drupal_set_message(t('The current font path is invalid. The default font will be used.'), 'error');
  }

  //check for valid image path
  if ($images_path != '' && !is_dir(rtrim($images_path, '\\/'))) {
    drupal_set_message(t('The current images path is invalid. No images will be used.'), 'error');
  }

  if (isset($fonts_path)) {
    $imagefontinfo = t('Number of fonts found:') .' '. count(_textimage_font_list($fonts_path));
  }

  if (isset($images_path)) {
    $imagefontinfo .= '<br />'. t('Number of background images found:') .' '. count(_textimage_image_list($images_path));
  }

  $gdinfo = gd_info();
  $imagefontinfo .= '<br />'. t('GD Version:') .' '. $gdinfo["GD Version"];
  $imagefontinfo .= '<br />'. t('FreeType Support:') .' ';
  $imagefontinfo .= ($gdinfo["FreeType Support"] == TRUE) ? t('True') : t('False');
  $imagefontinfo .= '<br />';

  if (!$gdinfo["FreeType Support"]) {
    drupal_set_message(t("This server's installation of GD does not have FreeType support. Textimage requires FreeType support for proper functionality."), 'error');
  }

  $form['info'] = array(
    '#type' => 'fieldset',
    '#title' => t('Image and font information'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE
  );

  $form['info']['textimage_info'] = array(
   '#type' => 'item',
   '#value' => $imagefontinfo,
  );

  //Fonts settings
  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Textimage settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE
  );

  $form['settings']['textimage_fonts_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Fonts Path'),
    '#default_value' => $fonts_path,
    '#maxlength' => 255,
    '#description' => t('Location of the directory where the Truetype (.ttf) or OpenType (.otf) fonts are stored. If you do not provide any fonts, the module will use the default font for text. Relative paths will be resolved relative to the Drupal installation directory.'),
  );

  $form['settings']['textimage_images_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Background Image Path'),
    '#default_value' => $images_path,
    '#maxlength' => 255,
    '#description' => t('Location of the directory where the background images are stored. Images in this directory can be overlaid with dynamic text in a preset. Relative paths will be resolved relative to the Drupal installation directory.'),
  );

  return system_settings_form($form);
}

function textimage_settings_form_validate($form, &$form_state) {
  //check for valid font path
  if ($form_state['values']['textimage_fonts_path'] != "" && !is_dir(rtrim($form_state['values']['textimage_fonts_path'], '\\/'))) {
    form_set_error('textimage_fonts_path', t('The entered font path is invalid'));
  }

  //check for valid image path
  if ($form_state['values']['textimage_images_path'] != "" && !is_dir(rtrim($form_state['values']['textimage_images_path'], '\\/'))) {
    form_set_error('textimage_images_path', t('The entered image path is invalid'));
  }
}

function textimage_preset_edit(&$form_state, $op, $pid = NULL) {
  $preset = array();
  $image_presets = array();

  if ($op == 'edit' && is_numeric($pid)) {
    $preset = _textimage_preset_load($pid);
  }

  $fonts_path = variable_get('textimage_fonts_path', drupal_get_path('module', 'textimage') .'/fonts');
  $font_options = _textimage_font_list($fonts_path);

  $images_path = variable_get('textimage_images_path', drupal_get_path('module', 'textimage') .'/backgrounds');
  $image_files = drupal_map_assoc(_textimage_image_list($images_path));

  $presets = textimage_get_presets();
  foreach ($presets as $p) {
    if ($p->pid != $pid) {
      $image_presets[$p->pid] = $p->name;
    }
  }

  $image_options = array(
    t('Default:') => array('' => t('Default (use background color)')),
    t('Use the result of a Textimage Preset:') => $image_presets,
    t('Use a Background Image:') => $image_files,
  );

  $form = array();
  $form['#tree'] = TRUE;

  if ($op == 'edit') {
    $form['pid'] = array(
      '#type' => 'hidden',
      '#value' => $pid,
    );
  }

  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Preset Name'),
    '#description' => t('Preset names should be short and only use alphanumeric characters. This name will be used in the image path for all generated images.'),
    '#default_value' => isset($preset['name']) ? $preset['name']: '',
    '#required' => TRUE,
  );

  $form['settings']['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#description' => t('A short description displayed in the list of presets.'),
    '#default_value' => isset($preset['settings']['description']) ? $preset['settings']['description'] : '',
    '#rows' => 1,
  );

  $form['settings']['text'] = array(
    '#type' => 'fieldset',
    '#title' => t('Text Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['settings']['text']['font'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#options' => $font_options,
    '#default_value' => isset($preset['settings']['text']['font']) ? $preset['settings']['text']['font'] : '',
    '#description' => t('Select the font to be used in this image. If no fonts are listed, check the <a href="!path">settings for Fonts Path</a>.', array('!path' => url('admin/settings/textimage'))),
    '#required' => TRUE,
  );

  $form['settings']['text']['size'] = array(
    '#type' => 'textfield',
    '#title' => t('Font Size'),
    '#description' => t('Enter the size in pixels of the text to be generated.'),
    '#default_value' => isset($preset['settings']['text']['size']) ? $preset['settings']['text']['size'] : 16,
    '#maxlength' => 4,
    '#size' => 4,
    '#required' => TRUE,
    '#validate' => array('_textimage_number_validate' => array('size')),
  );

  $form['settings']['text']['color'] = array(
    '#type' => 'textfield',
    '#title' => t('Text Color'),
    '#description' => t('Enter the hex color code you wish to use for the generated text (i.e. #000000).'),
    '#default_value' => isset($preset['settings']['text']['color']) ? $preset['settings']['text']['color'] : '',
    '#maxlength' => 7,
    '#size' => 7,
    '#validate' => array('_textimage_hex_validate' => array('color')),
    '#required' => TRUE,
  );

  $form['settings']['text']['maximum_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum width'),
    '#field_suffix' => t('pixels'),
    '#description' => t('Text lines wider than this will be wrapped. Leave blank to disable wrapping.'),
    '#default_value' => isset($preset['settings']['text']['maximum_width']) ? $preset['settings']['text']['maximum_width'] : '',
    '#maxlength' => 4,
    '#size' => 4,
  );

  $form['settings']['text']['fixed_width'] = array(
    '#type' => 'checkbox',
    '#title' => t('Fixed width?'),
    '#description' => t('If checked the size of generated image will always be equal to the max width') .'.',
    '#default_value' => isset($preset['settings']['text']['fixed_width']) ? $preset['settings']['text']['fixed_width'] : '',
  );

  $form['settings']['text']['align'] = array(
    '#type' => 'select',
    '#title' => t('Text Align'),
    '#description' => t('Only works when fixed width is enabled') .'.',
    '#options' => array(ALIGN_LEFT => t('Left'), ALIGN_CENTER => t('Center'), ALIGN_RIGHT => t('Right')),
    '#default_value' => isset($preset['settings']['text']['align']) ? $preset['settings']['text']['align'] : '',
  );

  $form['settings']['text']['angle'] = array(
    '#type' => 'textfield',
    '#title' => t('Text Rotation'),
    '#description' => t('Enter the angle in degrees at which the text will be displayed. Positive numbers rotate the text clockwise, negative numbers counter-clockwise.'),
    '#default_value' => isset($preset['settings']['text']['angle']) ? $preset['settings']['text']['angle'] : 0,
    '#maxlength' => 4,
    '#size' => 4,
    '#validate' => array('_textimage_number_validate' => array('angle')),
  );

  $form['settings']['text']['case'] = array(
    '#type' => 'select',
    '#title' => t('Convert to case'),
    '#options' => array('' => t('Default'), 'upper' => t('UPPERCASE'), 'lower' => t('lowercase'), 'ucwords' => t('Uppercase Words'), 'ucfirst' => t('Uppercase first')),
    '#description' => t('Covert the input text to a consistent format. The default makes no changes to input text.'),
    '#default_value' => isset($preset['settings']['text']['case']) ? $preset['settings']['text']['case'] : '',
  );

  $form['settings']['text']['stroke_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Outline Width'),
    '#description' => t('Optionally add a stroke outline around the text. Enter the stroke width in pixels.'),
    '#default_value' => isset($preset['settings']['text']['stroke_width']) ? $preset['settings']['text']['stroke_width'] : '',
    '#maxlength' => 1,
    '#size' => 4,
    '#validate' => array('_textimage_number_validate' => array('stroke_width')),
  );

  $form['settings']['text']['stroke_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Outline Color'),
    '#description' => t('Enter the hex color code you wish to use for the stroke outline (i.e. #000000).'),
    '#default_value' => isset($preset['settings']['text']['stroke_color']) ? $preset['settings']['text']['stroke_color'] : '',
    '#maxlength' => 7,
    '#size' => 7,
    '#validate' => array('_textimage_hex_validate' => array('color')),
  );

  $form['settings']['text']['margin_top'] = array(
    '#type' => 'textfield',
    '#title' => t('Text Margin Top'),
    '#default_value' => isset($preset['settings']['text']['margin_top']) ? $preset['settings']['text']['margin_top'] : 0,
    '#maxlength' => 4,
    '#size' => 4,
    '#validate' => array('_textimage_number_validate' => array('margin_top')),
  );

  $form['settings']['text']['margin_right'] = array(
    '#type' => 'textfield',
    '#title' => t('Text Margin Right'),
    '#default_value' => isset($preset['settings']['text']['margin_right']) ? $preset['settings']['text']['margin_right'] : 0,
    '#maxlength' => 4,
    '#size' => 4,
    '#validate' => array('_textimage_number_validate' => array('margin_top')),
  );

  $form['settings']['text']['margin_bottom'] = array(
    '#type' => 'textfield',
    '#title' => t('Text Margin Bottom'),
    '#default_value' => isset($preset['settings']['text']['margin_bottom']) ? $preset['settings']['text']['margin_bottom'] : 0,
    '#maxlength' => 4,
    '#size' => 4,
    '#validate' => array('_textimage_number_validate' => array('margin_bottom')),
  );

  $form['settings']['text']['margin_left'] = array(
    '#type' => 'textfield',
    '#title' => t('Text Margin Left'),
    '#description' => t('Specify the margin in pixels to be added around the generated text.'),
    '#default_value' => isset($preset['settings']['text']['margin_left']) ? $preset['settings']['text']['margin_left'] : 0,
    '#maxlength' => 4,
    '#size' => 4,
    '#validate' => array('_textimage_number_validate' => array('margin_left')),
  );

  $form['settings']['background'] = array(
    '#type' => 'fieldset',
    '#title' => t('Background settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['settings']['background']['color'] = array(
    '#type' => 'textfield',
    '#title' => t('Background Color'),
    '#description' => t('Enter the hex color code you wish to use for the background of the generated image (i.e. #FFFFFF). Leave blank for transparent.'),
    '#default_value' => isset($preset['settings']['background']['color']) ? $preset['settings']['background']['color'] : '',
    '#maxlength' => 7,
    '#size' => 7,
    '#validate' => array('_textimage_hex_validate' => array('color')),
  );

  $form['settings']['background']['image'] = array(
    '#type' => 'select',
    '#title' => t('Background Type'),
    '#options' => $image_options,
    '#default_value' => isset($preset['settings']['background']['image']) ? $preset['settings']['background']['image'] : '',
    '#description' => t('Select the background type to be used in this image.'),
  );

  $form['settings']['background']['xoffset'] = array(
    '#type' => 'textfield',
    '#title' => t('Text X-Offset'),
    '#default_value' => isset($preset['settings']['background']['xoffset']) ? $preset['settings']['background']['xoffset'] : 0,
    '#maxlength' => 4,
    '#size' => 4,
    '#validate' => array('_textimage_number_validate' => array('xoffset')),
  );

  $form['settings']['background']['yoffset'] = array(
    '#type' => 'textfield',
    '#title' => t('Text Y-Offset'),
    '#description' => t('Specify the x and y coordinates on the image you where the top-left corner of the dynamic text should be positioned.'),
    '#default_value' => isset($preset['settings']['background']['yoffset']) ? $preset['settings']['background']['yoffset'] : 0,
    '#maxlength' => 4,
    '#size' => 4,
    '#validate' => array('_textimage_number_validate' => array('yoffset')),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

function textimage_preset_edit_validate($form, &$form_state) {
  // Check for illegal characters in preset names
  if (preg_match('/[^0-9a-zA-Z_\-]/', $form_state['values']['name'])) {
    form_set_error('name', t('Please only use alphanumic characters, underscores (_), and hyphens (-) for preset names.'));
  }

  // Check for numbers at beginning of preset names
  if (preg_match('/^[0-9]/', $form_state['values']['name'])) {
    form_set_error('name', t('Preset names can\'t begin with a number.'));
  }

  // Check for duplicate preset names
  $preset = _textimage_preset_load($form_state['values']['name']);
  if ($preset['name'] && (!isset($form_state['values']['pid']) || $form_state['values']['pid'] != $preset['pid'])) {
    form_set_error('name', t('The name %name is already in use by another preset.', array('%name' => $form_state['values']['name'])));
  }
}

function textimage_preset_edit_submit($form, &$form_state) {
  if (!isset($form_state['values']['pid'])) {
    $return = _textimage_preset_create($form_state['values']['name'], $form_state['values']['settings']);
  }
  elseif (is_numeric($form_state['values']['pid'])) {
    $return = _textimage_preset_update($form_state['values']['pid'], $form_state['values']['name'], $form_state['values']['settings']);
  }

  if ($return) {
    drupal_set_message(t('Updated preset %name', array('%name' => $form_state['values']['name'])));
    drupal_goto('admin/settings/textimage/preset/list');
  }
  else {
    drupal_set_message(t('The preset was unable to be updated.'), 'error');
  }
}

function textimage_preset_list() {
  $fonts_path = variable_get('textimage_fonts_path', drupal_get_path('module', 'textimage') .'/fonts');
  $presets = textimage_get_presets();

  $header = array(t('Name'), t('Summary'), t('Description'), array('data' => t('Operations'), 'colspan' => '3'));
  $rows = array();

  foreach ($presets as $preset) {
    $font = _textimage_font_name($fonts_path .'/'. $preset->settings['text']['font']);

    $row = array();
    $row[] = $preset->name;
    $row[] = $font['name'] .' '. $preset->settings['text']['size'] . t('px');
    $row[] = $preset->settings['description'];
    $row[] = l(t('edit'), 'admin/settings/textimage/preset/'. $preset->pid .'/edit');
    $row[] = l(t('delete'), 'admin/settings/textimage/preset/'. $preset->pid .'/delete');
    $row[] = l(t('flush cache'), 'admin/settings/textimage/preset/'. $preset->pid .'/flush');

    $rows[] = $row;
  }

  if (empty($rows)) {
    $rows[] = array(array('data' => t('No presets defined. <a href="!url">Create a new preset</a>.', array('!url' => url('admin/settings/textimage/preset/new'))), 'colspan' => '6', 'class' => 'message'));
  }

  return theme('table', $header, $rows);
}

function textimage_preset_delete_confirm(&$form_state, $pid) {
  $preset = _textimage_preset_load($pid);

  $form['pid'] = array('#type' => 'value', '#value' => $preset['pid']);
  $form['name'] = array('#type' => 'value', '#value' => $preset['name']);

  return confirm_form($form,
    t('Are you sure you want to delete the preset %name?', array('%name' => $preset['name'])),
    isset($_GET['destination']) ? $_GET['destination'] : 'admin/settings/textimage/preset/list',
    t('This action cannot be undone.'),
    t('Delete'), t('Cancel')
  );
}

function textimage_preset_delete_confirm_submit($form, &$form_state) {
  _textimage_preset_delete($form_state['values']['pid']);
  drupal_set_message(t('Deleted preset %name', array('%name' => $form_state['values']['name'])));
  drupal_goto('admin/settings/textimage/preset/list');
}

function textimage_preset_flush_confirm(&$form_state, $pid) {
  $preset = _textimage_preset_load($pid);

  $form['pid'] = array('#type' => 'value', '#value' => $preset['pid']);
  $form['name'] = array('#type' => 'value', '#value' => $preset['name']);

  return confirm_form($form,
    t('Are you sure you want to flush the image cache for preset %name?', array('%name' => $preset['name'])),
    isset($_GET['destination']) ? $_GET['destination'] : 'admin/settings/textimage/preset/list',
    t('This action cannot be undone.'),
    t('Flush Cache'), t('Cancel')
  );
}

function textimage_preset_flush_confirm_submit($form, &$form_state) {
  _textimage_preset_flush($form_state['values']['pid']);
  drupal_goto('admin/settings/textimage/preset/list');
}

function textimage_get_presets() {
  static $presets = array();

  if (empty($presets)) {
    $result = db_query('SELECT pid, name, settings FROM {textimage_preset} ORDER BY name');
    $presets = array();
    while ($preset = db_fetch_object($result)) {
      $preset->settings = unserialize($preset->settings);
      $presets[$preset->name] = $preset;
    }
  }

  return $presets;
}

/**
 * create a preset
 * @param name
 *    name of the preset to be created.
 */
function _textimage_preset_create($name, $settings) {
  return db_query('INSERT INTO {textimage_preset} (name, settings) VALUES (\'%s\', \'%s\')', $name, serialize($settings));
}

/**
 * update a preset
 * @param id
 *    preset id
 * @param name
 *    new name for the preset
 */
function _textimage_preset_update($id, $name, $settings) {
  $name = check_plain($name);
  _textimage_preset_flush($id);
  return db_query('UPDATE {textimage_preset} SET name =\'%s\', settings =\'%s\' WHERE pid = %d', $name, serialize($settings), $id);
}

function _textimage_preset_delete($id) {
  _textimage_preset_flush($id);
  return db_query('DELETE FROM {textimage_preset} where pid = %d', $id);
}

/**
 * flush cached media for a preset.
 * @param pid
 *   a preset id.
 */
function _textimage_preset_flush($pid) {
  drupal_set_message(t('Flushed Preset Images (ID: @pid)', array('@pid' => $pid)));

  $preset = _textimage_preset_load($pid);
  $presetdir = realpath(file_directory_path() .'/textimage/'. $preset['pid']);

  if (is_dir($presetdir)) {
    _textimage_recursive_delete($presetdir);
    @unlink($presetdir);
  }

  // Flush Legacy directory
  $legacydir = realpath(file_directory_path() .'/textimage/'. $preset['name']);

  if (is_dir($legacydir)) {
    _textimage_recursive_delete($legacydir);
    @unlink($legacydir);
  }

  db_query('DELETE FROM {textimage_image} where pid = %d', $pid);
}

/**
 * Recursively delete all files and folders in the specified filepath, then
 * delete the containing folder Note that this only deletes visible files with
 * write permission
 *
 * @param string $path
 *   An absolute filepath (relative to the filesystem) to delete
 */
function _textimage_recursive_delete($path) {
  $listing = $path ."/*";

  foreach (glob($listing) as $file) {
    if (is_file($file) === TRUE) {
      @unlink($file);
    }
    elseif (is_dir($file) === TRUE) {
      _textimage_recursive_delete($file);
      @rmdir($file);
    }
  }

  @rmdir($path);
}

/**
 * Returns an array of files with .otf/.ttf extensions in the specified directory.
 *
 * @param $fontdir
 *   Full path of the font directory.
 * @return
 *   Array of font files.
 */
function _textimage_font_list($fontdir) {
  $filelist = array();
  if (is_dir($fontdir) && $handle = opendir($fontdir)) {
    while ($file = readdir($handle)) {
      if (preg_match("/\.[ot]tf$/i", $file) == 1) {
        $font = _textimage_font_name($fontdir .'/'. $file);
        $filelist[$file] = $font['name'];
      }
    }
    closedir($handle);
  }

  asort($filelist);
  return $filelist;
}

function _textimage_font_name($filename) {
  $fd = fopen($filename, "r");
  $text = fread($fd, filesize($filename));
  fclose($fd);

  $number_of_tabs = _textimage_dec2hex(ord($text[4])) . _textimage_dec2hex(ord($text[5]));
  for ($i=0; $i < hexdec($number_of_tabs); $i++) {
    $tag = $text[12 + $i *16] . $text[12 + $i * 16 + 1] . $text[12 + $i * 16 + 2] . $text[12 + $i * 16 + 3];
    if ($tag == "name") {
      $offset_name_table_hex = _textimage_dec2hex(ord($text[12 + $i * 16 + 8])) . _textimage_dec2hex(ord($text[12 + $i * 16 + 8 + 1])) . _textimage_dec2hex(ord($text[12 + $i * 16 + 8 + 2])) . _textimage_dec2hex(ord($text[12 + $i * 16 + 8 + 3]));
      $offset_name_table_dec = hexdec($offset_name_table_hex);
      $offset_storage_hex = _textimage_dec2hex(ord($text[$offset_name_table_dec+4])) . _textimage_dec2hex(ord($text[$offset_name_table_dec + 5]));
      $offset_storage_dec = hexdec($offset_storage_hex);
      $number_name_records_hex = _textimage_dec2hex(ord($text[$offset_name_table_dec + 2])) . _textimage_dec2hex(ord($text[$offset_name_table_dec + 3]));
      $number_name_records_dec = hexdec($number_name_records_hex);
      break;
    }
  }

  $storage_dec = $offset_storage_dec + $offset_name_table_dec;
  $storage_hex = drupal_strtoupper(dechex($storage_dec));
  $font = array('copyright' => '', 'family' => '', 'subfamily' => '', 'name' => '');

  for ($j = 0; $j < $number_name_records_dec; $j++) {
    $platform_id_hex = _textimage_dec2hex(ord($text[$offset_name_table_dec + 6 + $j * 12 + 0])) . _textimage_dec2hex(ord($text[$offset_name_table_dec + 6 + $j * 12 + 1]));
    $platform_id_dec = hexdec($platform_id_hex);
    $name_id_hex = _textimage_dec2hex(ord($text[$offset_name_table_dec + 6 + $j * 12 + 6])) . _textimage_dec2hex(ord($text[$offset_name_table_dec + 6 + $j * 12 + 7]));
    $name_id_dec = hexdec($name_id_hex);
    $string_length_hex = _textimage_dec2hex(ord($text[$offset_name_table_dec + 6 + $j * 12 + 8])) . _textimage_dec2hex(ord($text[$offset_name_table_dec + 6 + $j * 12 + 9]));
    $string_length_dec = hexdec($string_length_hex);
    $string_offset_hex = _textimage_dec2hex(ord($text[$offset_name_table_dec + 6 + $j * 12 + 10])) . _textimage_dec2hex(ord($text[$offset_name_table_dec + 6 + $j * 12 + 11]));
    $string_offset_dec = hexdec($string_offset_hex);

    if ($name_id_dec == 0 && empty($font['copyright'])) {
      for ($l = 0; $l < $string_length_dec; $l++) {
        if (ord($text[$storage_dec + $string_offset_dec + $l]) >= 32) {
          $font['copyright'] .= $text[$storage_dec + $string_offset_dec + $l];
        }
      }
    }

    if ($name_id_dec == 1 && empty($font['family'])) {
      for ($l = 0; $l < $string_length_dec; $l++) {
        if (ord($text[$storage_dec + $string_offset_dec + $l]) >= 32) {
          $font['family'] .= $text[$storage_dec + $string_offset_dec + $l];
        }
      }
    }

    if ($name_id_dec == 2 && empty($font['subfamily'])) {
      for ($l = 0; $l < $string_length_dec; $l++) {
        if (ord($text[$storage_dec + $string_offset_dec + $l]) >= 32) {
          $font['subfamily'] .= $text[$storage_dec + $string_offset_dec + $l];
        }
      }
    }

    if ($name_id_dec == 4 && empty($font['name'])) {
      for ($l = 0; $l < $string_length_dec; $l++) {
        if (ord($text[$storage_dec + $string_offset_dec + $l]) >= 32) {
          $font['name'] .= $text[$storage_dec + $string_offset_dec + $l];
        }
      }
    }

    if ($font['copyright'] != "" && $font['family'] != "" && $font['subfamily'] != "" && $font['name'] != "") {
      break;
    }
  }

  return $font;
}

function _textimage_dec2hex($dec) {
  $hex = dechex($dec);
  return str_repeat("0", 2 - drupal_strlen($hex)) . drupal_strtoupper($hex);
}

function _textimage_number_validate($field, $field_name) {
  if (!empty($field['#value']) && !is_numeric($field['#value'])) {
    form_set_error($field_name, t('The value for %field must be a number.', array('%field' => $field['#title'])));
  }
}

function _textimage_hex_validate($field, $field_name) {
  if (!empty($field['#value']) && !preg_match('/^#[0123456789ABCDEF]{1,6}$/i', $field['#value'])) {
    form_set_error($field_name, t('The value for %field must be in a hexidecimal format (i.e. #FFFFFF is white).', array('%field' => $field['#title'])));
  }
}

/**
 * Returns an array of files with jpg, png, and gif extensions in the specified directory.
 *
 * @param $imagesdir
 *   Full path of the images directory.
 * @return
 *   Array of image files.
 */
function _textimage_image_list($imagesdir) {
  $filelist = array();
  if (is_dir($imagesdir) && $handle = opendir($imagesdir)) {
    while ($file = readdir($handle)) {
      if (preg_match("/\.gif|\.png|\.jpg$/i", $file) == 1) {
        $filelist[] = $imagesdir .'/'. $file;
      }
    }
    closedir($handle);
  }

  return $filelist;
}
