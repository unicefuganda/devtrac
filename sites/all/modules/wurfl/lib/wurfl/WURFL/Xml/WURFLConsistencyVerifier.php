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

class WURFL_Xml_WURFLConsistencyVerifier {

	/**
	 * Verifies the correctness of the wurfl devices
	 *
	 * @param array $devicesMap
	 */
	public static function verify($devicesMap) {

		$devicesMapByUserAgent = array();
		$hierarchyVerifiedDeviceIds = array();

		// Verifiy the existance of the Generic Device
		self::verifyGenericDeviceExistance($devicesMap);

		foreach (array_values($devicesMap) as $device) {
				
			self::verifyUserAgentUniqueness($devicesMapByUserAgent, $device->userAgent);
			$devicesMapByUserAgent[$device->userAgent] = $device;
				
			self::verifyHierarchy($devicesMap, $hierarchyVerifiedDeviceIds, $device);
			$hierarchyVerifiedDeviceIds[] = $device->id;
				
			self::verifyGroups($devicesMap, $device);
				
			self::verifyCapabilities($devicesMap, $device);
		}

	}

	/**
	 * Verifies the existance of the generic device
	 *
	 * @param array $devicesMap
	 */
	private static function verifyGenericDeviceExistance($devicesMap) {
		if (!array_key_exists(WURFL_Constants::GENERIC, $devicesMap)) {
			throw new WURFL_WURFLException("Generic Device is not defined.");
		}
	}


	/**
	 * Verifies the uniqueness of the user agent
	 *
	 * @param array $devicesMapByUserAgent
	 * @param string $userAgent
	 */
	private static function verifyUserAgentUniqueness($devicesMapByUserAgent, $userAgent) {
		$device = $devicesMapByUserAgent[$userAgent];

		if ($device != null) {
			throw new WURFL_WURFLException("user agent " . $userAgent . " is already defined by device " .  $device->id);
		}

	}


	/**
	 * Verifies it every device has a valid fall back and that there is no
	 * cicular fall backs references
	 *
	 * @param array $devicesMap
	 * @param array $hierarchyVerifiedDeviceIds
	 * @param mixed $device
	 */
	private static function verifyHierarchy($devicesMap, $hierarchyVerifiedDeviceIds, $deviceToCheck) {

		$hierarchy = array();

		$id = $deviceToCheck->id;

		while (strcmp(WURFL_Constants::GENERIC, $id) !== 0) {
			$device = $devicesMap[$id];
			$fallBack = $device->fallBack;
				
			if (array_search($fallBack, $hierarchyVerifiedDeviceIds)) {
				return;
			}
				
			if (!array_key_exists($fallBack, $devicesMap)) {
				throw new WURFL_WURFLException("Fall Back not found for device : " . $id);
			}
				
			// Check for circular hierarchy
				
				
			$id = $fallBack;
				
		}

	}

	/**
	 * Verifies
	 *
	 * @param unknown_type $devicesMap
	 * @param unknown_type $device
	 */
	private static function verifyGroups($devicesMap, $device) {
		
	}

	
	private static function getGenericDevice($devicesMap) {
		return $devicesMap[WURFL_Constants::GENERIC];
	}
	
	/**
	 * Verifies 
	 *
	 * @param unknown_type $devicesMap
	 * @param unknown_type $device
	 */
	private static function verifyCapabilities($devicesMap, $device){
		
	}
	
	private function __construct() { }

	private function __clone() { }



}

?>