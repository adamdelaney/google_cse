<?php
/**
 * @file
 * Google Custom Search results template.
 */

$query_string = (drupal_get_query_parameters() ? drupal_get_query_parameters() : NULL);
?>

<h3 id="google-cse-title">Search Results</h3>

<div id="search-results"></div>

<script>

var myCallback = function() {
  google.search.cse.element.render(
  {
      div: "search-results",
      tag: 'search',
      attributes:{
        queryParameterName:'search',
        <?php
          if(variable_get('google_cse_scope') == TRUE):
            echo ("as_sitesearch:'" . $GLOBALS["base_url"] . "',");
          endif;
        ?>
      }
  });
};

window.__gcse = {
  parsetags: 'explicit',
  callback: myCallback
};

(function() {
  <?php echo ("var cx = '" . variable_get("google_cse_engine_id") . "';"); ?>
  var gcse = document.createElement('script');
  gcse.type = 'text/javascript';
  gcse.async = true;
  gcse.src = (document.location.protocol == 'https:' ? 'https:' : 'http:') +
      '//www.google.com/cse/cse.js?cx=' + cx;
  var s = document.getElementsByTagName('script')[0];
  s.parentNode.insertBefore(gcse, s);
})();

</script>
