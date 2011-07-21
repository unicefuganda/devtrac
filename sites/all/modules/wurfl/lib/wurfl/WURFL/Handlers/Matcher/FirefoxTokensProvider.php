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

class WURFL_Handlers_Matcher_FirefoxTokensProvider extends WURFL_Handlers_Matcher_RegExTokensProvider  {
	
	
	private $regex = "/Mozilla\/5.0\s*(?:\(([^;]*);?\s*U;\s*([^;]*);?\s*([^;]*);?\s*(?:rv.*);?\s*(?:.*)?\))(?:.*)Gecko\/(?:[\d]+)?(?:.*)?Firefox\/(\d.\w)(?:[\.\w]+)?\s*(.*)?/";    
    private $weight = array(1, 1, 1, 2, 0);


    function __construct() {
    	parent::__construct($this->regex, $this->weight);
    }
}

?>