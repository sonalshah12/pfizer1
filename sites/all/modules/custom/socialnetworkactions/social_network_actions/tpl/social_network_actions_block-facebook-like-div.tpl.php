<div id="fb-root"></div>

<script>(function(d, s, id) {
  var js, fjs = d.getElementsByTagName(s)[0];
  if (d.getElementById(id)) return;
  js = d.createElement(s); js.id = id;
  js.src = "//connect.facebook.net/es_LA/all.js#xfbml=1&<?php print $variables['conf']['appId']?>";
  fjs.parentNode.insertBefore(js, fjs);
}(document, 'script', 'facebook-jssdk'));</script>

<div class="fb-like" data-layout="<?php print $variables['conf']['layout']?>" data-send="<?php print $variables['conf']['send']?>" data-show-faces="true" data-width="<?php print $variables['conf']['width']?>" data-action="<?php print $variables['conf']['action']?>" data-font="<?php print $variables['conf']['font']?>"></div>