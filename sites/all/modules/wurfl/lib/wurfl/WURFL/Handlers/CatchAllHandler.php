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
 * CatchAllUserAgentHanlder
 *
 *
 * @category   WURFL
 * @package    WURFL/UserAgentHandlers
 * @copyright  WURFL-PRO SRL, Rome, Italy
 * @license
 * @version    1.0.0
 */

class WURFL_Handlers_CatchAllHandler extends WURFL_Handlers_Handler {

    protected $prefix = "CATCH_ALL";
	const MOZILLA_TOLLERACE = 5;

	const MOZILLA5 = "CATCH_ALL_MOZILLA5";
	const MOZILLA4 = "CATCH_ALL_MOZILLA4";

	private $mozilla4UserAgentsWithDeviceID;
	private $mozilla5UserAgentsWithDeviceID;

	/**
	 * Final Interceptor: Intercept
	 * Everything that has not been trapped by a previous handler
	 *
	 * @param string $userAgent
	 * @return boolean always true
	 */
	function canHandle($userAgent) {
		return true;
	}

	/**
	 * If UA starts with Mozilla, apply LD with tollerance 5.
	 * If UA does not start with Mozilla, apply RIS on FS
	 *
	 * @param string $userAgent
	 * @return string
	 */
	function applyConclusiveMatch($userAgent) {

		$deviceID = WURFL_Constants::GENERIC;
		if (WURFL_Handlers_Utils::checkIfStartsWith($userAgent, "Mozilla")) {
			if ($this->isMozilla5($userAgent)) {
				$this->logger->log("Applying Catch All Conclusive Match Mozilla 5 (LD with treshold of )for ua: $userAgent");
				$this->mozilla5UserAgentsWithDeviceID = $this->persistanceProvider->load(self::MOZILLA5);
				if (!array_key_exists($userAgent, $this->mozilla5UserAgentsWithDeviceID)) {
					$match = WURFL_Handlers_Utils::ldMatch(
					array_keys($this->mozilla5UserAgentsWithDeviceID), $userAgent, self::MOZILLA_TOLLERACE);
				}
				return $this->mozilla5UserAgentsWithDeviceID[$match];
			} else if ($this->isMozilla4($userAgent)) {
				$this->logger->log("Applying Catch All Conclusive Match Mozilla 4 for ua: $userAgent");
				$this->mozilla4UserAgentsWithDeviceID = $this->persistanceProvider->load(self::MOZILLA4);
				if (!array_key_exists($userAgent, $this->mozilla4UserAgentsWithDeviceID)) {
					$match = WURFL_Handlers_Utils::ldMatch(
					array_keys($this->mozilla4UserAgentsWithDeviceID), $userAgent, self::MOZILLA_TOLLERACE);
				}
				
				if (!empty($match)) {
					return $this->mozilla4UserAgentsWithDeviceID[$match];
				}
				
				return NULL;
				
				
				
			} else {
				$this->logger->log("Applying Catch All Conclusive Match for ua: $userAgent");
				$match = WURFL_Handlers_Utils::ldMatch(array_keys($this->userAgentsWithDeviceID), $userAgent, self::MOZILLA_TOLLERACE);
				return $this->userAgentsWithDeviceID[$match];
			}
		}
		$tollerance = WURFL_Handlers_Utils::firstSlash($userAgent);
		$match =  WURFL_Handlers_Utils::risMatch(array_keys($this->userAgentsWithDeviceID), $userAgent, $tollerance);
		return $this->userAgentsWithDeviceID[$match];
	}


	function filter($userAgent, $deviceID) {
		if ($this->isMozilla4($userAgent)) {
			$this->mozilla4UserAgentsWithDeviceID[$userAgent] = $deviceID;
		}
		if ($this->isMozilla5($userAgent)) {
			$this->mozilla5UserAgentsWithDeviceID[$userAgent] = $deviceID;
		}
		parent::filter($userAgent, $deviceID);
	}

	function persistData() {
		ksort($this->mozilla4UserAgentsWithDeviceID);
		ksort($this->mozilla5UserAgentsWithDeviceID);
		$this->persistanceProvider->save(self::MOZILLA4, $this->mozilla4UserAgentsWithDeviceID);
		$this->persistanceProvider->save(self::MOZILLA5, $this->mozilla5UserAgentsWithDeviceID);
		parent::persistData();
	}


	private function loadMozillaData() {
		$this->mozilla4UserAgentsWithDeviceID = $this->persistanceProvider->find(CatchAllUserAgentHandler::MOZILLA4);
		$this->mozilla5UserAgentsWithDeviceID = $this->persistanceProvider->find(CatchAllUserAgentHandler::MOZILLA5);
	}

	private function isMozilla5($userAgent) {
		return WURFL_Handlers_Utils::checkIfStartsWith($userAgent, "Mozilla/5");
	}

	private function isMozilla4($userAgent) {
		return WURFL_Handlers_Utils::checkIfStartsWith($userAgent, "Mozilla/4");
	}

	private function isMozilla($userAgent) {
		return WURFL_Handlers_Utils::checkIfStartsWith($userAgent, "Mozilla");
	}



}

?>
