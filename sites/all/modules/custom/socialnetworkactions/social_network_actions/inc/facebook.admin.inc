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

  $form['facebook_general_setting'] = array(
    '#type' => 'fieldset',
    '#title' => t('Facebook General Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['facebook_general_setting']['social_network_actions_facebook_api_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook API ID'),
    '#default_value' => variable_get('social_network_actions_facebook_api_id', ''),
    '#required' => TRUE,
    '#description' => t('Enter Facebook API ID'),
  );
  
  $form['facebook_general_setting']['social_network_actions_facebook_page'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook Page'),
    '#default_value' => variable_get('social_network_actions_facebook_page', 'http://www.facebook.com/mywed'),
    '#required' => TRUE,
    '#description' => t('Enter your Facebook adress. I.E: http://www.facebook.com/mywed'),
  );

  $form['facebook_direct_post'] = array(
    '#type' => 'fieldset',
    '#title' => t('Facebook Direct Post'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  
  $form['facebook_direct_post']['social_network_actions_facebook_status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Active'),
    '#default_value' => variable_get('social_network_actions_facebook_status', ''),
  );

  $form['facebook_direct_post']['social_network_actions_facebook_block_image_button'] = array(
    '#title' => t('Image'),
    '#type' => 'managed_file',
    '#description' => t('Upload the image for the button here'),
    '#default_value' => variable_get('social_network_actions_facebook_block_image_button', ''),
    '#upload_location' => 'public://public/file/',
    '#required' => FALSE,
  );
  
  $facebook_messager = variable_get('social_network_actions_facebook_messager', array('value' => '', 'format' => 'plain_text'));

  $form['facebook_direct_post']['social_network_actions_facebook_messager'] = array(
    '#type' => 'text_format',
    '#format' => $facebook_messager['format'],
    '#title' => t('Message'),
    '#description' => t('Enter the message you want to post in the user’s wall.'),
    '#default_value' => $facebook_messager['value'],
  );
  
  $form['facebook_like_button'] = array(
    '#type' => 'fieldset',
    '#title' => t('Facebook Like Button'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['facebook_like_button']['social_network_actions_div_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width(px)'),
    '#default_value' => variable_get('social_network_actions_div_width', '450'),
    '#description' => t('Choose the button’s width container.'),
  );

  $form['facebook_like_button']['social_network_actions_type_tpl'] = array(
    '#type' => 'select',
    '#title' => t('Type Template'),
    '#options' => array('div' => 'Div',
    'iframe' => 'iFrame'),
    '#default_value' => variable_get('social_network_actions_type_tpl', 'div'),
    '#description' => t('Choose the block\'s rendering method.'),
  );

  $form['facebook_like_button']['social_network_actions_facebook_send'] = array(
    '#type' => 'checkbox',
    '#title' => t('Send Button'),
    '#description' => t('Mark this option so the ‘Like’ button appears next to the ‘Send’ button'),
    '#default_value' => variable_get('social_network_actions_facebook_send', ''),
  );

  $form['facebook_like_button']['social_network_actions_layout'] = array(
    '#type' => 'select',
    '#title' => t('Layout style'),
    '#options' => array('standard' => t('Standard'), 'box_count' => t('Box Count'), 'button_count' => t('Button Count')),
    '#default_value' => variable_get('social_network_actions_layout', 'standard'),
    '#description' => t('Determines the size and amount of social context next to the button.'),
  );

  $form['facebook_like_button']['social_network_actions_action'] = array(
    '#type' => 'select',
    '#title' => t('Verb to display'),
    '#options' => array('like' => t('Like'), 'recommend' => t('Recommend')),
    '#default_value' => variable_get('social_network_actions_action', 'like'),
    '#description' => t('The verbiage to display inside the button itself.'),
  );

  $form['facebook_like_button']['social_network_actions_font'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#options' => array('arial' => 'Arial',
    'lucida+grande' => 'Lucida Grande',
    'segoe+ui' => 'Segoe UI',
    'tahoma' => 'Tahoma',
    'trebuchet+ms' => 'Trebuchet MS',
    'verdana' => 'Verdana'),
    '#default_value' => variable_get('social_network_actions_font', 'arial'),
    '#description' => t('The font with which to display the text of the button.'),
  );

  return system_settings_form($form);
}