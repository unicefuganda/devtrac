<?php // $Id: page.tpl.php,v 1.15.4.7 2008/12/23 03:40:02 designerbrent Exp $ ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>">
<head>
  <title><?php print $head_title ?></title>
  <meta http-equiv="content-language" content="<?php print $language->language ?>" />
  <?php print $meta; ?>
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts ?>
  <!--[if lte IE 8]>
    <link rel="stylesheet" href="<?php print $path; ?>blueprint/blueprint/ie.css" type="text/css" media="screen, projection">
    <link href="<?php print $path; ?>css/ie.css" rel="stylesheet"  type="text/css"  media="screen, projection" />
  <![endif]-->  
  <!--[if lte IE 6]>
    <link href="<?php print $path; ?>css/ie6.css" rel="stylesheet"  type="text/css"  media="screen, projection" />
  <![endif]-->  
</head>

<body class="<?php print $body_classes; ?>">
<div class="wrapper"> <!-- holds container and push to hold down the footer menu  --> 
<div class="container">
  <div id="header">
    <div id="tpblock">
      <div id="username">
      <?php
        global $user;
        print theme('username',  $user);
      ?>
      </div>
    <?php
      if (isset($search_box)) : 
      print $search_box;
      endif;
    ?>
    </div>
    <h1 id="logo">
      <a title="<?php print $site_name; ?><?php if ($site_slogan != '') print ' &ndash; '. $site_slogan; ?>" href="<?php print url(); ?>"><?php print $site_name; ?><?php if ($site_slogan != '') print ' &ndash; '. $site_slogan; ?></a>
    </h1>
    <?php print $header; ?>
    <?php if (isset($primary_links)) : ?>
      <?php print theme('links', $primary_links, array('id' => 'nav', 'class' => 'links')) ?>
    <?php endif; ?>
    <?php if (isset($secondary_links)) : ?>
      <?php print theme('links', $secondary_links, array('id' => 'subnav', 'class' => 'links')) ?>
    <?php endif; ?>    
  </div>
  
  <div class="breadcrumbheadercontainer clearfix">
    <div id="breadcrumbheader" class="span-24 last">
  
    <?php
      if ($breadcrumb != '') {
        print $breadcrumb;
      }
      if ($messages != '') {
        print '<div id="messages">'. $messages .'</div>';
      }
      ?>
    </div>
  </div> 

  
  <div class="<?php print $center_classes; ?>">
  <div id="contentcontainer" class="span-24 last">

    <div class="col-content_contentlayerleft span-6">
    <?php
      if ($tabs != '') {
        print '<div class="tabsaslist"><div class="tabsaslist-title">User</div>'. $tabs_primary .'</div>';
      }
    ?>
    <?php
      print $help; // Drupal already wraps this one in a class      
      print $feed_icons;
    if ((arg(2) == '') && (user_is_logged_in())) {  // if not editing but when logged in 
    ?>
    <div class="<?php print $contentlayerleft_classes; ?>"><?php print $contentlayerleft; ?></div>
    
    </div>

    <div id="titlediv" class="span-18 last">
      <?php
        if ($title != '') {
          print '<h2>'. $title .'</h2>';
        }
      ?>
    </div>

    <div class="col-content_contentlayermiddle span-10">
      <div class="<?php print $contentlayermiddle_classes; ?>"><?php print $contentlayermiddle; ?></div>
    </div>
    <div class="col-content_contentlayerright span-8 last">
      <div class="<?php print $contentlayerright_classes; ?>"><?php print $contentlayerright; ?></div>
    </div>
    <?php } else { ?>
        </div>
    <div class="col-content_contentlayermiddle span-16 last">
    <?php if ($tabs_secondary) { ?> 
<!-- Eve has an issue on the login page with the secondary tabs. Commenting this out solves that for now. -->
      <div class="tabs_secondary_container clearfix">
        <div class="col-content_tabs_secondary span-28 last">
          <div class="tabs-secondary"><?php print trim($tabs_secondary);?></div>
        </div>
      </div>
<!-- end comment-->
    <?php }
    
       print $content;?>
    </div>
    
    <?php } ?>
    </div>
  </div>


  <?php if ($layeroneleft): ?> 
    <div class="layerone clearfix">
    <div class="col-content_layeroneleft span-8">
      <div class="<?php print $layeroneleft_classes; ?>"><?php print $layeroneleft; ?></div>
    </div>
    <div class="col-content_layeronemiddle span-8">
      <div class="<?php print $layeronemiddle_classes; ?>"><?php print $layeronemiddle; ?></div>
    </div>
    <div class="col-content_layeroneright span-8 last">
      <div class="<?php print $layeroneright_classes; ?>"><?php print $layeroneright; ?></div>
    </div>
  </div>
  <?php endif ?>

  <?php if ($layertwoleft): ?> 
    <div class="layertwo clearfix">
    <div class="col-content_layertwoleft span-16">
      <div class="<?php print $layertwoleft_classes; ?>"><?php print $layertwoleft; ?></div>
    </div>
    <div class="col-content_layertworight span-8 last">
      <div class="<?php print $layertworight_classes; ?>"><?php print $layertworight; ?></div>
    </div>
  </div>
  <?php endif ?>




  <?php if ($layerthree): ?> 
    <div class="layerthree clearfix">
    <div class="col-content_layerthree span-24 last">
      <div class="<?php print $layerthree_classes; ?>"><?php print $layerthree; ?></div>
    </div>
  </div>
  <?php endif ?>
  
  <?php if ($footernavigation): ?> 
    <div class="footernavigation clearfix">
      <div class="col-content_footernavigation span-24 last">   
        <div class="<?php print $footernavigation_classes; ?>"><?php print $footernavigation; ?></div>
      </div>
    </div>
  <?php endif ?>
  </div> <!--  container -->
    <div class="push"></div>   
    <!-- This class sole purpose is to push the container 
    to a min-height allowing the footermenubar to be always 
    displayed at the bottom of the page -->

  </div> <!-- wrapper -->

  <div id="footermenubar">
    <?php print $footer; ?>
    <?php if ($footer_message): ?>
      <div id="footer-message"><?php print $footer_message; ?></div>
    <?php endif; ?>
  </div> 
  <?php print $closure; ?>

</body>
</html>
