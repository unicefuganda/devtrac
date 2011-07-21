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
 * XMLResourceManager
 *
 *
 * @category   WURFL
 * @package    WURFL
 * @copyright  WURFL-PRO SRL, Rome, Italy
 * @license
 * @version    1.0.0
 */

class WURFL_Xml_XMLResourceManager {
	
	private $_fileManager = null;
	private $_config = null;
	private $_patchManager = null;
	
	// Parsers
	private $_wurflParser = null;
	private $_wurflPatchParser = null;
	
	private $devices;
	private $_userAgentsWithDeviceIDMap;
	private $_groupIDCapabilitiesMap = array ();
	
	private $_persistanceProvider;
	
	const WURFL_TIMEOUT = 300;
	const WURFL_LOADED = "WURFL_LOADED";
	const USER_AGENTS_WITH_DEVICE_ID_MAP = "USER_AGENTS_WITH_DEVICE_ID_MAP";
	const CAPABILITY_GROUP_MAP = "CAPABILITY_GROUP_MAP";
	const GROUP_ID_CAPABILTIIES_MAP = "GROUP_ID_CAPABILTIIES_MAP";
	
	/**
	 * Initializes the XMLResourcesManager
	 *
	 * @param WURFL_Xml_PersistanceProvider $persistanceProvider
	 * @param WURFL_Xml_PatchManager $patchManager
	 * @param WURFL_Xml_WURFLFileParser $wurflParser
	 * @param WURFL_Xml_WURFLPatchFileParser $wurflPatchParser
	 */
	function __construct(WURFL_Xml_PersistanceProvider $persistanceProvider, WURFL_Xml_PatchManager $patchManager, WURFL_Xml_WURFLFileParser $wurflParser, WURFL_Xml_WURFLPatchFileParser $wurflPatchParser) {
		$this->_config = WURFL_Configuration_ConfigHolder::getWURFLConfig ();
		$this->_patchManager = $patchManager;
		
		$this->_wurflParser = $wurflParser;
		$this->_wurflPatchParser = $wurflPatchParser;
		
		$this->_persistanceProvider = $persistanceProvider;
		
		$this->init ();
	}
	
	/**
	 * Returns an associative array containing <userAgent, deviceID>
	 *
	 * @return array
	 */
	public function getUserAgentsWithDeviceID() {
		return $this->_persistanceProvider->load ( WURFL_Xml_XMLResourceManager::USER_AGENTS_WITH_DEVICE_ID_MAP );
	}
	
	/**
	 * Returns an associative array containing <groupID, capabilities>
	 *
	 * @return array
	 */
	public function getGroupIDCapabilitiesMap() {
		return $this->_persistanceProvider->load ( WURFL_Xml_XMLResourceManager::GROUP_ID_CAPABILTIIES_MAP );
	}
	
	//*************************** PRIVATE **********************
	private function init() {
		
		if (! $this->isWURFLLoaded ()) {
			set_time_limit ( WURFL_Xml_XMLResourceManager::WURFL_TIMEOUT );
			
			$wurflFile = $this->_config->wurflFile;
			$wurflFile = WURFL_Xml_Utils::getXMLFile ( $wurflFile );
			
			$wurflParsingResult = $this->_wurflParser->parse ( $wurflFile );
			
			$this->checkDevices ($wurflParsingResult->devicesMap );
			
			// Check if it has patches
			if (is_array ( $this->_config->wurflPatches )) {
				foreach ( $this->_config->wurflPatches as $wurflPatchFile ) {
					if (isset ( $wurflPatchFile )) {
						$wurflPatchFile = WURFL_Xml_Utils::getXMLFile ( $wurflPatchFile );
						$patchParsingResult = $this->_wurflPatchParser->parse ( $wurflPatchFile );
						$wurflParsingResult = $this->_patchManager->applyPatch ( $wurflParsingResult, $patchParsingResult );
					}
				}
			}
			$this->updateAndSaveDataStuctures ( $wurflParsingResult );
			$this->setWURFLLoaded ();
		}
	}
	
	/**
	 * Checks if the map contains valid devices by
	 * 1) checking if any of the devices has a valid fallback
	 *
	 * @param array $devicesMap
	 */
	private function checkDevices(&$devicesMap) {
		
		if (! array_key_exists ( WURFL_Constants::GENERIC, $devicesMap )) {
			throw new WURFL_WURFLException ( "Generic Device is not defined." );
		}
		
		foreach ( array_values ( $devicesMap ) as $device ) {
			//Check if the fallback is defined
			$this->isFallBackDefined ( $devicesMap, $device );
		}
	
	}
	
	private function isFallBackDefined(&$devicesMap, $device) {
		if (! $this->isGeneric ( $device->id )) {
			if (! array_key_exists ( $device->fallBack, $devicesMap )) {
				throw new WURFL_WURFLException ( "Fall Back : " . $device->fallBack . " is not defined for device : " . $device->id );
			}
		}
	
	}
	
	private function updateAndSaveDataStuctures($wurflParsingResult) {
		
		$devices = $wurflParsingResult->devicesMap;
		foreach ( $devices as $deviceID => $device ) {
			$this->_userAgentsWithDeviceIDMap [$device->userAgent] = $deviceID;
			$this->_persistanceProvider->save ( $deviceID, $device );
		}
		
		$this->_persistanceProvider->save ( WURFL_Xml_XMLResourceManager::USER_AGENTS_WITH_DEVICE_ID_MAP, $this->_userAgentsWithDeviceIDMap );
		$this->_persistanceProvider->save ( WURFL_Xml_XMLResourceManager::GROUP_ID_CAPABILTIIES_MAP, $wurflParsingResult->groupIDCapabilitiesMap );
	
	}
	
	private function isWURFLLoaded() {
		return $this->_persistanceProvider->isWURFLLoaded ( self::WURFL_LOADED );
	}
	
	private function setWURFLLoaded() {
		$this->_persistanceProvider->setWURFLLoaded ( self::WURFL_LOADED );
	}
	
	private function isGeneric($deviceID) {
		if (strcmp ( $deviceID, WURFL_Constants::GENERIC ) === 0) {
			return true;
		}
		return false;
	}

} // end of class


?>