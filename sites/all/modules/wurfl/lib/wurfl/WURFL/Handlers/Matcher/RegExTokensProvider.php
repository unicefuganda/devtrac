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

class WURFL_Handlers_Matcher_RegExTokensProvider implements WURFL_Handlers_Matcher_TokensProvider  {
    
    function __construct($regEx, $weights) {
        $this->_regEx = $regEx;
        $this->_weights = $weights;
    }
    
    public function createTokens($source) {
        preg_match($this->_regEx, $source, $matches);
        return array_slice($matches, 1);
    }
    
    public function getTokenWeight($index) {
        return $this->_weights[$index];
    }
    
    public function canApply($source) {
    	$match = preg_match($this->_regEx, $source);
    	return ($match != 0) ? TRUE : FALSE;
    }
    
    private $_regEx;
    private $_weights;
}

?>