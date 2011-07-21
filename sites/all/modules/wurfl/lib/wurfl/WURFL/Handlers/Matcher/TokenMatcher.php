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

class WURFL_Handlers_Matcher_TokenMatcher implements WURFL_Handlers_Matcher_Interface {
    
	/**
	 * Enter description here...
	 *
	 * @param WURFL_Handlers_Matcher_GroupsInfoProvider $groupsInfoProvider
	 */
	function __construct(WURFL_Handlers_Matcher_TokensProvider $tokensProvider) {
	   $this->_tokensProvider = $tokensProvider;
	}
	
	/**
	 * 
	 *
	 * @param array $collection
	 * @param string $needle
	 * @param string $tollerance
	 */
	public function match(&$collection, $needle, $tollerance) {
        $needleGroups = $this->_tokensProvider->createTokens($needle);
		$bestMatch = NULL;
		$bestDiff = $tollerance + 1;
        foreach ($collection as $userAgent) {
        	$userAgentGroups = $this->_tokensProvider->createTokens($userAgent);
        	$userAgentGroupCount = count($userAgentGroups);
        	if (count($userAgentGroups) == count($needleGroups)) {
        		$weightDiff = 0;
      
        		for($groupIndex = 0; $groupIndex < $userAgentGroupCount && $weightDiff < $tollerance; $groupIndex += 1) {
        		  if($needleGroups[$groupIndex] != $userAgentGroups[$groupIndex]) {
        		  	$weightDiff += $this->_tokensProvider->getTokenWeight($groupIndex);
        		  }	
        		}
        		if ($weightDiff < $bestDiff) {	
        			$bestDiff = $weightDiff;
        			$bestMatch = $userAgent;
        		}
        		
        	}
        	
        }
        return $bestMatch;
        
	}
	
	private $_tokensProvider;
}

?>