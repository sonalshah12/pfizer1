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

  $form['#attributes'] = array('enctype' => "multipart/form-data");

  $form['twitter'] = array(
    '#type' => 'fieldset',
    '#title' => t('Twitter general settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['twitter']['social_network_actions_twitter_status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Active'),
    '#default_value' => variable_get('social_network_actions_twitter_status', ''),
  );

  $form['twitter']['social_network_actions_twitter_language'] = array(
    '#type' => 'select',
    '#title' => t('Language'),
    '#options' => array('ar' => 'Arabic', 'da' => 'Danish', 'nl' => 'Dutch', 'en' => 'English', 'fa' => 'Farsi', 'fil' => 'Filipino', 'fi' => 'Finnish', 'fr' => 'French', 'de' => 'German', 'he' => 'Hebrew', 'hi' => 'Hindi', 'hu' => 'Hungarian', 'id' => 'Indonesian', 'it' => 'Italian', 'ja' => 'Japanese', 'ko' => 'Korean', 'msa' => 'Malay', 'no' => 'Norwegian', 'pl' => 'Polish', 'pt' => 'Portuguese', 'ru' => 'Russian', 'zh-cn' => 'Simplified Chinese', 'es' => 'Spanish', 'sv' => 'Swedish', 'th' => 'Thai', 'zh-tw' => 'Traditional Chinese', 'tr' => 'Turkish', 'ur' => 'Urdu'),
    '#default_value' => variable_get('social_network_actions_twitter_language', 'en'),
    '#description' => t('Choose a language.'),
  );

  $form['twitter']['social_network_actions_twitter_url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL'),
    '#description' => t('Enter a URL to be displayed in the message'),
    '#default_value' => variable_get('social_network_actions_twitter_url', ''),
    '#required' => FALSE,
  );

  $form['twitter']['social_network_actions_twitter_via'] = array(
    '#type' => 'textfield',
    '#title' => t('Via'),
    '#description' => t('Enter a Via to be displayed in the message'),
    '#default_value' => variable_get('social_network_actions_twitter_via', ''),
    '#required' => FALSE,
  );  
 
  $twitter_messager = variable_get('social_network_actions_twitter_messager', array('value' => '', 'format' => 'plain_text'));

  $form['twitter']['social_network_actions_twitter_messager'] = array(
    '#type' => 'text_format',
    '#format' => $twitter_messager['format'],
    '#title' => t('Message'),
    '#description' => t('Enter the message you want to tweet.'),
    '#default_value' => $twitter_messager['value'],
    '#required' => TRUE,
  );

  $form['twitter_direct_post'] = array(
    '#type' => 'fieldset',
    '#title' => t('Twitter Share'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['twitter_direct_post']['social_network_actions_twitter_block_image_button'] = array(
    '#title' => t('Image'),
    '#type' => 'managed_file',
    '#description' => t('Upload the image for the button here'),
    '#default_value' => variable_get('social_network_actions_twitter_block_image_button', ''),
    '#upload_location' => 'public://public/file/',
    '#required' => FALSE,
  );

  $form['twitter_button'] = array(
    '#type' => 'fieldset',
    '#title' => t('Twitter Button'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['twitter_button']['social_network_actions_twitter_displays'] = array(
    '#type' => 'select',
    '#title' => t('Display'),
    '#options' => array('none' => 'None',
    'horizontal' => 'Horizontal',
    'vertical' => 'Vertical'),
    '#default_value' => variable_get('social_network_actions_twitter_displays', 'none'),
    '#description' => t('Choose the button’s look'),
  );

  return system_settings_form($form);
}