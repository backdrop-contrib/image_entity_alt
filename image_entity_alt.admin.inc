<?php

/**
 * @file
 * Admin settings form for image_entity_alt.
 */

/**
 * Settings form.
 */
function image_entity_alt_settings_form($form, &$form_state) {
  $config = config('image_entity_alt.settings');

  $form['#config'] = 'image_entity_alt.settings';

  // Build a list of plain text fields that exist on the Image file type.
  $field_options = array();
  $instances = field_info_instances('file', 'image');
  foreach ($instances as $field_name => $instance) {
    $field = field_info_field($field_name);
    if ($field && in_array($field['type'], array('text', 'text_long'), TRUE) && empty($instance['settings']['text_processing'])) {
      $field_options[$field_name] = $instance['label'] . ' (' . $field_name . ')';
    }
  }

  if (empty($field_options)) {
    backdrop_set_message(t('No plain text fields found on the Image file type. Add one at <a href="@url">Admin &rsaquo; Structure &rsaquo; File types &rsaquo; Image &rsaquo; Manage fields</a> first.', array(
      '@url' => url('admin/structure/file-types/manage/image/fields'),
    )), 'warning');
  }

  $form['alt_field_name'] = array(
    '#type' => 'select',
    '#title' => t('Alt text field'),
    '#description' => t('The machine name of the plain text field on the Image file type that stores alt text. Defaults to <code>field_alt</code>.'),
    '#default_value' => $config->get('alt_field_name') ?: 'field_alt',
    '#required' => !empty($field_options),
    '#empty_option' => t('- Select an ALT text field -'),
    '#empty_value' => '',
    '#options' => $field_options,
  );

  $form = system_settings_form($form);
  $form['actions']['submit']['#disabled'] = empty($field_options);
  return $form;
}
