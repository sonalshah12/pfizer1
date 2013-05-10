function login() {
  fb.login(function(){ 
    if (fb.logged) {
      document.getElementById("conectar_facebook").innerHTML = html;
    } else {
      alert(Drupal.t("Incorrect login.") );
    }
  })
};

var publish = function () {
    var msj = Drupal.settings.social_network_actions.facebook.post.value;
    fb.publish({
      message : msj
    },function(published){ 
      if (published)
       alert(Drupal.t("Your FB message was successfully sent."));
      else
       alert(Drupal.t("Your message was already published or you have permission problems."));
           
    });
}