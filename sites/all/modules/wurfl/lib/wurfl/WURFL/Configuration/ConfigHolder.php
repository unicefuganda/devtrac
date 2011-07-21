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
class WURFL_Configuration_ConfigHolder {
	
	private function __construct() {}
	
	private function __clone() {}
	
	
	/**
	 * Returns a Configuration object
	 *
	 */
	public static function getWURFLConfig() {
		if (null === self::$_wurflConfig) {
			throw new WURFL_WURFLException("The Configuration Holder is not initialized with a valid WURFLConfig object");
			//self::$_wurflConfig = new WURFL_Configuration_Config(self::WURFL_CONFIG_LOCATION);
		}
		
		return self::$_wurflConfig;
	}
	
	
	/**
	 * Set't the Configuration object
	 *
	 * @param WURFL_Configuration_Config $wurflConfig
	 */
	public static function setWURFLConfig(WURFL_Configuration_Config $wurflConfig) {
		self::$_wurflConfig = $wurflConfig;
	}
	
	private static $_wurflConfig = null ;
	
	const WURFL_CONFIG_LOCATION = "../resources/wurfl-config.xml";
}

?>