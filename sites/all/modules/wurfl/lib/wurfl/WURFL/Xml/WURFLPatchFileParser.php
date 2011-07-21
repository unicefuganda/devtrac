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
class WURFL_Xml_WURFLPatchFileParser implements WURFL_Xml_Interface {

	public function parse($fileName) {

		$devicesMap = array();
		$groupIDCapabilitiesNameMap = array();
		$userAgentsWithDeviceIDMap = array();


		$deviceID = null;
		$groupID = null;

		$reader = new XMLReader();
		$reader->open($fileName);

		while ($reader->read()) {
			$nodeName = $reader->name;
			switch ($reader->nodeType) {
				case XMLReader::ELEMENT:
					switch ($nodeName) {
						case WURFL_Xml_Interface::DEVICE:
							$deviceID = $reader->getAttribute(WURFL_Xml_Interface::ID);
							$userAgent = $reader->getAttribute(WURFL_Xml_Interface::USER_AGENT);
							$fallBack = $reader->getAttribute(WURFL_Xml_Interface::FALL_BACK);
							$actualDeviceRoot = $reader->getAttribute(WURFL_Xml_Interface::ACTUAL_DEVICE_ROOT);

							$this->isDeviceIDUnique($devicesMap, $deviceID);
							$this->isDeviceUserAgentUnique($userAgentsWithDeviceIDMap, $userAgent);
							
							$currentCapabilityNameValue = array();
							if ($reader->isEmptyElement) {
								$device = new WURFL_Xml_ModelDevice($deviceID, $userAgent, $fallBack, $actualDeviceRoot);
								$devicesMap[$deviceID] = $device;
							}
							$userAgentsWithDeviceIDMap[$userAgent] = $deviceID;
							break;

						case WURFL_Xml_Interface::GROUP:
							$groupID = $reader->getAttribute(WURFL_Xml_Interface::GROUP_ID);
								
							if ($this->isGeneric($deviceID)) {
								$groupIDCapabilitiesNameMap[$groupID] = array();
							}
							break;

						case WURFL_Xml_Interface::CAPABILITY:

							$capabilityName = $reader->getAttribute(WURFL_Xml_Interface::CAPABILITY_NAME);
							$capabilityValue = $reader->getAttribute(WURFL_Xml_Interface::CAPABILITY_VALUE);
							if ($this->isGeneric($deviceID)) {
								$groupIDCapabilitiesNameMap[$groupID][] = $capabilityName;
							}
							$currentCapabilityNameValue[$capabilityName] = $capabilityValue;
							break;
					}

					break;
						case XMLReader::END_ELEMENT:
							if ($nodeName == WURFL_Xml_Interface::DEVICE) {
								$device = new WURFL_Xml_ModelDevice($deviceID, $userAgent, $fallBack, $actualDeviceRoot,
								$currentCapabilityNameValue);
								$devicesMap[$device->id] = $device;
							}
							break;
			}
		}// end of while

		$reader->close();


		return new WURFL_Xml_ParsingResult($devicesMap, $groupIDCapabilitiesNameMap);

	}

	/**
	 * Checks if the deviceID is unique in the patch file
	 *
	 * @param array $devicesMap
	 * @param string $deviceID
	 */
	private function isDeviceIDUnique($devicesMap, $deviceID) {
		if (isset($devicesMap[$deviceID])) {
			throw new WURFL_WURFLException("Duplicate Device id : " . $deviceID);
		}
	}

	/**
	 * Checks if the useragent is unique
	 *
	 * @param array $userAgentsWithDeviceIDMap
	 * @param string $userAgent
	 * @throws WURFL_WURFLException if the duplicate useragent values are found
	 */
	private function isDeviceUserAgentUnique($userAgentsWithDeviceIDMap, $userAgent) {
		if (isset($userAgentsWithDeviceIDMap[$userAgent])) {
			throw new WURFL_WURFLException("Duplicate UserAgent " . $userAgent);
		}
		return TRUE;
	}

	private function isGeneric($deviceID) {
		if (strcmp($deviceID, WURFL_Constants::GENERIC) === 0) {
			return TRUE;
		}
		return FALSE;
	}

}
?>