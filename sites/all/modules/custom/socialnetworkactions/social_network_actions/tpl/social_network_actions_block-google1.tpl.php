<!-- Place this tag where you want the +1 button to render. -->
<div class="g-plusone" data-size="<?php print $variables['conf']['size']?>" data-annotation="<?php print $variables['conf']['annotation']?>" data-width="<?php print $variables['conf']['width']?>" data-href="<?php print $variables['conf']['url']?>"></div>

<!-- Place this tag after the last +1 button tag. -->
<script type="text/javascript">
  window.___gcfg = {lang: <?php print "'" . $variables['conf']['language'] . "'" ?>};
  
  (function() {
    var po = document.createElement('script'); po.type = 'text/javascript'; po.async = true;
    po.src = 'https://apis.google.com/js/plusone.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(po, s);
  })();
</script>