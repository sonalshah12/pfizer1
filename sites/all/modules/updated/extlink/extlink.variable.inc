<?php

function extlink_variable_info($options) {
  $variable['extlink_html_text'] = array(
    'title' => t('Disclaimer HTML text'),
    'description' => t('Disclaimer text displayed when an external link is clicked
      To use another link instead of the OK button, be sure to add the class "<strong>target-link</strong>" to it, so it will keep the same behavior.<br />
    '),
    'localize' => TRUE
  );
  
  $variable['extlink_confirm_button'] = array(
    'title' => t('External Link Confirm button text'),
    'description' => t('Confirm button text.'),
    'localize' => TRUE
  );
  
  $variable['extlink_cancel_button'] = array(
    'title' => t('External Link Cancel button text'),
    'description' => t('Cancel button text.'),
    'localize' => TRUE
  );
  
  $variable['extlink_close_button'] = array(
    'title' => t('Close button text'),
    'description' => t('Close button text.'),
    'localize' => TRUE
  );
  
  if (module_exists('mobile_tools')) {  
    $variable['extlink_html_text_mobile'] = array(
      'title' => t('Disclaimer HTML text [mobile]'),
      'description' => t('Disclaimer text displayed when an external link is clicked
        To use another link instead of the OK button, be sure to add the class "<strong>target-link</strong>" to it, so it will keep the same behavior.<br />
      '),
      'localize' => TRUE
    );

    $variable['extlink_confirm_button_mobile'] = array(
      'title' => t('External Link Confirm button text [mobile]'),
      'description' => t('Confirm button text.'),
      'localize' => TRUE
    );
  
    $variable['extlink_cancel_button_mobile'] = array(
      'title' => t('External Link Cancel button text [mobile]'),
      'description' => t('Cancel button text.'),
      'localize' => TRUE
    );
    
    $variable['extlink_close_button_mobile'] = array(
      'title' => t('Close button text [mobile]'),
      'description' => t('Close button text.'),
      'localize' => TRUE
    );
  }

  return $variable;
}
