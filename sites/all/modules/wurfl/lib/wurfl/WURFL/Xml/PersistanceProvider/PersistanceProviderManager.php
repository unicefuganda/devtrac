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
class WURFL_Xml_PersistanceProvider_PersistanceProviderManager {

    private static $_persistanceProvider;

    public static function getPersistanceProvider() {
    	
    	if (!isset(self::$_persistanceProvider)) {
    		self::_initialize();
    	}
		
    	return self::$_persistanceProvider;
    }
    
    private static function _initialize() {
    	
    	$persistanceParams = WURFL_Configuration_ConfigHolder::getWURFLConfig()->persistance;
    	$provider = $persistanceParams["provider"];
    	
    	switch ($provider) {
    		case WURFL_Constants::MEMCACHE:
    			self::$_persistanceProvider = new WURFL_Xml_PersistanceProvider_MemcachePersistanceProvider($persistanceParams);
    		break;
    		case WURFL_Constants::APC:
    			self::$_persistanceProvider = new WURFL_Xml_PersistanceProvider_APCPersistanceProvider($persistanceParams);
    			break;
    		case WURFL_Constants::MYSQL:
    			self::$_persistanceProvider = new WURFL_Xml_PersistanceProvider_MysqlPersistanceProvider($persistanceParams);
    			break;
    		default:
    			self::$_persistanceProvider = new WURFL_Xml_PersistanceProvider_FilePersistanceProvider($persistanceParams);
    			break;	
    	}	
    }
    
    
}