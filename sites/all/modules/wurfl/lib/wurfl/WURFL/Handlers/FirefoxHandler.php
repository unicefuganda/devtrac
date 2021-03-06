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

/**
 * FirefoxUserAgentHanlder
 *
 *
 * @category   WURFL
 * @package    WURFL/UserAgentHandlers
 * @copyright  WURFL-PRO SRL, Rome, Italy
 * @license
 * @version    1.0.0
 */
class WURFL_Handlers_FirefoxHandler extends WURFL_Handlers_Handler {

	protected $prefix = "FIREFOX";

	const FIREFOX_TOLLERANCE = 5;

	/**
	 * Intercept all UAs Containing Firefox and are not mobile browsers
	 *
	 * @param string $userAgent
	 * @return boolean
	 */
	public function canHandle($userAgent) {
		if(WURFL_Handlers_Utils::isMobileBrowser($userAgent)) {
			return false;
		}

		return WURFL_Handlers_Utils::checkIfContains($userAgent, "Firefox");
	}

	
	/**
	 * Applies Tokens matching strategy
	 *
	 */
	function lookForMatchingUserAgent($userAgent) {
		
		$firefoxTokensProvider = new WURFL_Handlers_Matcher_FirefoxTokensProvider();
		if ($firefoxTokensProvider->canApply($userAgent)) {
			$tokenMatcher = new WURFL_Handlers_Matcher_TokenMatcher($firefoxTokensProvider);
			return $tokenMatcher->match(array_keys($this->userAgentsWithDeviceID), $userAgent, 2);
		}

		return WURFL_Handlers_Utils::ldMatch(array_keys($this->userAgentsWithDeviceID), $userAgent, self::FIREFOX_TOLLERANCE);
	}



}