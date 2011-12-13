<?php
// $Id: click_heatmap.report.tpl.php,v 1.1.2.1 2009/09/28 06:56:28 boombatower Exp $

/**
 * @file
 * Provides Drupal context around ClickHeat interface.
 *
 * Copyright 2008-2009 by Jimmy Berry ("boombatower", http://drupal.org/user/214218)
 */
?><html>
  <head>
    <title>ClickHeat</title>
  </head>
  <body style="margin: 0; padding: 0;">
    <div style="height: 3%; background-color: #eeeeee; padding: 0 5px;">
      <a href=".."><?php print t('Back to Drupal'); ?></a>
    </div>
    <iframe src="<?php print $click_heatmap_library; ?>" style="width: 100%; height: 97%; border: 0;"></iframe>
  </body>
</html>