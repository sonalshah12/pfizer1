<?php

/**
 * @file
 * Social Network Actions Form Adminitration
 * social_network_actions
 */

/**
 * Callback function for Social Setwork Actions admin hook_menu item.
 *
 * @param type $form
 * @param type $form_state
 * @return type
 */
function social_network_actions_admin_form($form, &$form_state) {
  $form = array();

  $form['google_general_setting'] = array(
    '#type' => 'fieldset',
    '#title' => t('Google+ General Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['google_general_setting']['social_network_actions_google_language'] = array(
    '#type' => 'select',
    '#title' => t('Language'),
    '#options' => array('af' => 'Afrikaans', 'am' => 'Amharic', 'ar' => 'Arabic', 'eu' => 'Basque', 'bn' => 'Bengali', 'bg' => 'Bulgarian', 'ca' => 'Catalan', 'zh-HK' => 'Chinese (Hong Kong)', 'zh-CN' => 'Chinese (Simplified)', 'zh-TW' => 'Chinese (Traditional)', 'hr' => 'Croatian', 'cs' => 'Czech', 'da' => 'Danish', 'nl' => 'Dutch', 'en-GB' => 'English (UK)', 'en-US' => 'English (US)', 'et' => 'Estonian', 'fil' => 'Filipino', 'fi' => 'Finnish', 'fr' => 'French', 'fr-CA' => 'French (Canadian)', 'gl' => 'Galician', 'de' => 'German', 'el' => 'Greek', 'gu' => 'Gujarati', 'iw' => 'Hebrew', 'hi' => 'Hindi', 'hu' => 'Hungarian', 'is' => 'Icelandic', 'id' => 'Indonesian', 'it' => 'Italian', 'ja' => 'Japanese', 'kn' => 'Kannada', 'ko' => 'Korean', 'lv' => 'Latvian', 'lt' => 'Lithuanian', 'ms' => 'Malay', 'ml' => 'alayalam', 'mr' => 'Marathi', 'no' => 'Norwegian', 'fa' => 'Persian', 'pl' => 'Polish', 'pt-BR' => 'Portuguese (Brazil)', 'pt-PT' => 'Portuguese (Portugal)', 'ro' => 'Romanian', 'ru' => 'Russian', 'sr' => 'Serbian', 'sk' => 'Slovak', 'sl' => 'Slovenian', 'es' => 'Spanish', 'es-419' => 'Spanish (Latin America)', 'sw' => 'Swahili', 'sv' => 'Swedish', 'ta' => 'Tamil', 'te' => 'Telugu', 'th' => 'Thai', 'tr' => 'Turkish', 'uk' => 'Ukrainian', 'ur' => 'Urdu', 'vi' => 'Vietnamese', 'zu' => 'Zulu'),
    '#default_value' => variable_get('social_network_actions_google_language', 'en-US'),
    '#description' => t('Choose a language.'),
  );

  $form['#attributes'] = array('enctype' => "multipart/form-data");

  $form['google+1'] = array(
    '#type' => 'fieldset',
    '#title' => t('Google +1'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['google+1']['social_network_actions_google1_url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL'),
    '#default_value' => variable_get('social_network_actions_google1_url', ''),
    '#description' => t('Enter the destiny URL to add the +1'),
    '#required' => TRUE,
  );

  $form['google+1']['social_network_actions_google1_size'] = array(
    '#type' => 'select',
    '#title' => t('Size'),
    '#options' => array('small' => 'Small',
    'medium' => 'Medium',
    'standard' => 'Standard',
    'tall' => 'Large'),
    '#default_value' => variable_get('social_network_actions_google1_size', 'small'),
    '#description' => t('Choose the button’s size.'),
  );

  $form['google+1']['social_network_actions_google1_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width(px)'),
    '#default_value' => variable_get('social_network_actions_google1_width', '450'),
    '#description' => t('Choose the button’s width container.'),
  );

  $form['google+1']['social_network_actions_google1_annotation'] = array(
    '#type' => 'select',
    '#title' => t('Annotation'),
    '#options' => array('inline' => 'inline',
    'bubble' => 'bubble',
    'none' => 'none'),
    '#default_value' => variable_get('social_network_actions_google1_annotation', 'none'),
    '#description' => t('Choose the button’s look'),
  );

  $form['google_share'] = array(
    '#type' => 'fieldset',
    '#title' => t('Google Share'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['google_share']['social_network_actions_google_share_size'] = array(
    '#type' => 'select',
    '#title' => t('Size'),
    '#options' => array('15' => 'Small',
    '20' => 'Medium',
    '24' => 'Large'),
    '#default_value' => variable_get('social_network_actions_google_share_size', 'small'),
    '#description' => t('Choose the button’s size.'),
  );

  $form['google_share']['social_network_actions_google_share_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width(px)'),
    '#default_value' => variable_get('social_network_actions_google_share_width', '450'),
    '#description' => t('Choose the button’s width container.'),
  );

  $form['google_share']['social_network_actions_google_share_annotation'] = array(
    '#type' => 'select',
    '#title' => t('Annotation'),
    '#options' => array('inline' => 'inline',
    'bubble' => 'bubble (horizontal)',
    'vertical-bubble' => 'bubble (vertical)',
    'none' => 'none'),
    '#default_value' => variable_get('social_network_actions_google_share_annotation', 'none'),
    '#description' => t('Choose the button’s look'),
  );

  return system_settings_form($form);
}    