<?php
/**
 * @file
 * Cem Hub email functions
 */

/**
 * Return mail definition based on $key. Act as a gateway of each mail definition of the module.
 *
 * @param string $key
 *  Indentification of the wanted email.
 *
 * @param array $params
 *  Parameters for the function which implements the wanted email.
 *
 * @return array
 *  Array with the final email body and subject in the form of:
 *  array(
 *    'subject' => string,
 *    'body'    => array('line1', 'line2', ..., 'lineN'),
 *  );
 */
function cemhub_get_mail_definition($key, $params) {
  $email_definition = array();

  switch ($key) {
    case CEMHUB_SUCCESS_EMAIL_DEFINITION:
      $email_definition = cemhub_success_email_definition($params);
      break;

    case CEMHUB_FAILURE_EMAIL_DEFINITION:
      $email_definition = cemhub_failure_email_definition($params);
      break;
      
    case CEMHUB_NO_SUBMISSIONS_EMAIL_DEFINITION:
      $email_definition = cemhub_no_submissions_email_definition($params);
      break;
  }

  return $email_definition;
}

/**
 * Return the email definition of the Success e-mail
 *
 * @return array
 *  Array with the final email body and subject in the form of:
 *  array(
 *    'subject' => string,
 *    'body'    => array('line1', 'line2', ..., 'lineN'),
 *  );
 */
function cemhub_success_email_definition($params) {
  return array(
    'subject' => cemhub_replace_email_tokens(variable_get('cemhub_email_subject_success')),
    'body' => cemhub_replace_email_tokens(variable_get('cemhub_email_message_success')),
  );
}

/**
 * Return the email definition of the Failure e-mail
 *
 * @return array
 *  Array with the final email body and subject in the form of:
 *  array(
 *    'subject' => string,
 *    'body'    => array('line1', 'line2', ..., 'lineN'),
 *  );
 */
function cemhub_failure_email_definition($params) {
  $error_log = isset($params['error_log']) ? $params['error_log'] : NULL;
  
  $body = cemhub_replace_email_tokens(variable_get('cemhub_email_message_failure'));
  
  // Replace error log Token
  if (!empty($error_log)) {
    $body = str_replace('[errorlog]', $error_log, $body);
  }
  
  return array(
    'subject' => cemhub_replace_email_tokens(variable_get('cemhub_email_subject_failure')),
    'body' => $body,
  );
}

/**
 * Return the email definition of the no Submissions e-mail
 *
 * @return array
 *  Array with the final email body and subject in the form of:
 *  array(
 *    'subject' => string,
 *    'body'    => array('line1', 'line2', ..., 'lineN'),
 *  );
 */
function cemhub_no_submissions_email_definition($params) {
  return array(
    'subject' => cemhub_replace_email_tokens(variable_get('cemhub_email_subject_no_submissions')),
    'body' => cemhub_replace_email_tokens(variable_get('cemhub_email_message_no_submissions')),
  );
}

/**
 * Replaces the tokens with the related values in the given e-mail message
 *  
 * @param string $message
 * @return string $message
 */
function cemhub_replace_email_tokens($message) {
  $email_tokens = cemhub_get_email_tokens();
  
  foreach ($email_tokens as $token => $token_value) {
    $message = str_replace($token, $token_value, $message);    
  }
  
  return $message;
}

/**
 * Returns an array with the email tokens
 * 
 * @return array
 */
function cemhub_get_email_tokens() {
  return array(
    '[sitename]' => variable_get('site_name', 'Default site name'),
    '[siteurl]' => $_SERVER['SERVER_NAME'],
  );
}

/**
 * Returns the e-mail name from
 * 
 * @return string
 */
function cemhub_get_email_name_from() {
  return variable_get('cemhub_email_from');
}

/**
 * Returns the e-mail recipient
 * 
 * @return string
 */
function cemhub_get_email_recipient() {
  return variable_get('cemhub_email_recipient');
}

/**
 * Returns the e-mail From
 * 
 * @return string
 */
function cemhub_get_email_from() {
  return variable_get('site_mail', ini_get('sendmail_from'));
}

/**
 * Send Success Cem Hub Job E-mail
 */
function cemhub_send_email($email_definition, $params = array()) {
  $send_email_is_required = variable_get('cemhub_email_integration_cron_job', FALSE);
  if ($send_email_is_required) {
    global $language;
    $recipient = cemhub_get_email_recipient();
    $name_from = cemhub_get_email_name_from();
    $email_from = cemhub_get_email_from();
    $email_from = $name_from ? $name_from . ' <' . $email_from . '>' : $email_from;
  
  
    try {
      drupal_mail('cemhub', $email_definition, $recipient, $language, $params, $email_from);
    }
    catch(Exception $e) {
      watchdog('cemhub', t('Unable to send e-mail to: !email', array('!email' => $recipient)));
    }
  }
}

/**
 * Send Success Cem Hub Job E-mail
 */
function cemhub_send_success_job_email() {
  if (variable_get('cemhub_email_case_success', FALSE)) {
    cemhub_send_email(CEMHUB_SUCCESS_EMAIL_DEFINITION);
  }
}

/**
 * Send Failure Cem Hub Job E-mail
 * 
 * @param string $error_log
 */
function cemhub_send_failure_job_email($error_log) {
  if (variable_get('cemhub_email_case_failure', FALSE)) {
    cemhub_send_email(CEMHUB_FAILURE_EMAIL_DEFINITION, array('error_log' => $error_log));
  }
}

/**
 * Send No Submissions Cem Hub Job E-mail
 */
function cemhub_send_no_submissions_job_email() {
  if (variable_get('cemhub_email_case_no_submissions', FALSE)) {
    cemhub_send_email(CEMHUB_NO_SUBMISSIONS_EMAIL_DEFINITION);
  }
}