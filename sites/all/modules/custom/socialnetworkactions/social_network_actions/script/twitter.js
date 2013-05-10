function tweet() {
  var url_twitter = "https://twitter.com/intent/tweet?text=" + Drupal.settings.social_network_actions.twitter.post.value;
  if(Drupal.settings.social_network_actions.twitter.url != ''){
    url_twitter += "&url=" + Drupal.settings.social_network_actions.twitter.url;
  }
  if(Drupal.settings.social_network_actions.twitter.via != ''){
    url_twitter += "&via=" + Drupal.settings.social_network_actions.twitter.via;
  }
  return url_twitter;
}

(function ($) {
  $(document).ready (function() {
    if(document.getElementById('twitter-block-link')) {
      document.getElementById('twitter-block-link').href = tweet();
    }
  });
})(jQuery);