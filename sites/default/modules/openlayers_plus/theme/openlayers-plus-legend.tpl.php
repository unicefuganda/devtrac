<div class='legend legend-count-<?php print count($legend) ?> clear-block' id='openlayers-legend-<?php print $layer['name'] ?>'>
  <?php if (!empty($layer['title'])): ?>
    <h2 class='legend-title'><?php print check_plain($layer['title']) ?></h2>
  <?php endif; ?>
  <?php foreach ($legend as $key => $item): ?>
    <div class='legend-item clear-block'>
      <?php if(!empty($item['image_url'])): ?>
        <img src="<?php print check_url($item['image_url']) ?>" />
      <?php else: ?>
        <span class='swatch' style='background-color:<?php print check_plain($item['color']) ?>'></span>
        <?php print check_plain($item['title']) ?>
      <?php endif; ?>
    </div>
  <?php endforeach; ?>
</div>
