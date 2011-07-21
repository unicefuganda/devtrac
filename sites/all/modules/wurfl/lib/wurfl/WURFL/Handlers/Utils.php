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

class WURFL_Handlers_Utils {

	public static function risMatch(&$collection, $needle, $tollerance) {
		return WURFL_Handlers_Matcher_RISMatcher::INSTANCE()->match($collection, $needle, $tollerance);
	}

	public static function ldMatch(&$collection, $needle, $tollerance=7) {
		return WURFL_Handlers_Matcher_LDMatcher::INSTANCE()->match($collection, $needle, $tollerance);
	}


    
    public static function isMobileBrowser($userAgent) {
        if(WURFL_Handlers_Utils::checkIfContains($userAgent, "Tablet")) {
            return true;
        }

        return false;
    }


	public static function firstSlash($string) {
		$firstSlash = strpos($string, "/");
		return $firstSlash != 0 ? $firstSlash : strlen($string);
	}

	public static function secondSlash($string) {
		$firstSlash = strpos($string, "/");
		if ($firstSlash === false)
		return strlen($string);
		return strpos(substr($string, $firstSlash+1), "/") + $firstSlash;
	}

	public static function firstSpace($string) {
		$firstSpace = strpos($string, " ");
		return ($firstSpace == 0) ? strlen($string) : $firstSpace;
	}

	public static function checkIfContains($haystack, $needle) {
		return strpos($haystack, $needle) !== FALSE;
	}

	public static function checkIfStartsWith($haystack, $needle) {
		return strpos($haystack, $needle) === 0;
	}

	const WORST_MATCH = 7;

}

?>