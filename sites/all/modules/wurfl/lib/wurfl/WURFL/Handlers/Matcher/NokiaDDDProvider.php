<?php
/**
 * WURFL API
 *
 * LICENSE
 *
 * This file is released under the GNU General Public License. Refer to the
 * COPYING file distributed with this package.
 *
 * Copyright (c) 2008-2009, WURFL-Pro S.r.l., Rome, Italy
 *
 *
 *
 * @category   WURFL
 * @package    WURFL
 * @copyright  WURFL-PRO SRL, Rome, Italy
 * @license
 * @version    1.0.0
 */

class WURFL_Handlers_Matcher_NokiaDDDProvider extends WURFL_Handlers_Matcher_RegExTokensProvider  {
	
	private $regex = "/(.*)\s+(Nokia.*)\/(\d+)\.(\d+)\.(\d+)(.*)/";
    private $weight = array(10, 10, 4, 2, 1, 1);
  
    
    function __construct() {
    	parent::__construct($this->regex, $this->weight);
    }
}

?>