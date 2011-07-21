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

class WURFL_Handlers_Matcher_MSIETokensProvider implements WURFL_Handlers_Matcher_TokensProvider   {
	
	
	const MSIE_VERSION_PATTERN = "/MSIE ([\.\w]+)/";
	const PLATFORM_PATTERN = "/Windows ([\.\w\s]{0,})/";
	const NET_VERSION_PATTERN = "/NET CLR ([0-9]{1,}[\.\w]{0,})/";
	
    private $_weight = array(2, 2, 1);

    
	public function createTokens($source) {
		$tokens = array();
		
		$tokens[] = $this->_getMatch($source, self::MSIE_VERSION_PATTERN);
		$tokens[] = $this->_getMatch($source, self::PLATFORM_PATTERN);
		$tokens[] = $this->_getMatch($source, self::NET_VERSION_PATTERN);
		
		return $tokens;
    }
    
	public function getTokenWeight($index) {
        return $this->_weights[$index];
    }
    
    private function _getMatch($source, $pattern) {
    	$match = preg_match($pattern, $source, $matches);
    	if ($match == 0) {
    		return "";
    	}
    	
    	return $matches[1];
    	
    }
    
}

?>