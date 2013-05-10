<!-- Place this tag where you want the share button to render. -->
<div class="g-plus" data-action="share" data-width="<?php print $variables['conf']['width']?>" data-annotation="<?php print $variables['conf']['annotation']?>" data-height="<?php print $variables['conf']['size']?>"></div>

<!-- Place this tag after the last share tag. -->
<script type="text/javascript">
  window.___gcfg = {lang: <?php print "'" . $variables['conf']['language'] . "'" ?>};

  (function() {
    var po = document.createElement('script'); po.type = 'text/javascript'; po.async = true;
    po.src = 'https://apis.google.com/js/plusone.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(po, s);
  })();
</script>