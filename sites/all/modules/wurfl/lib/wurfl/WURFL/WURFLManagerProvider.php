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

/* Lib Dir*/
define('LIB_DIR', dirname(__FILE__).'/../lib');


require_once  'Log.php';

require_once 'ClassLoader.php';
// register class loader
spl_autoload_register(array('WURFL_ClassLoader', 'loadClass'));


/**
 * This Class is reponsable for creating a WURFLManager instance
 * by instantiating and wiring together all the neccessary
 * objects. e.g. WURFL_Xml_XMLResourceManager, WURFL_DeviceRepository, etc.
 *
 * @category   WURFL
 * @package    WURFL
 * @copyright  WURFL-PRO SRL, Rome, Italy
 * @license
 * @version    1.0.0
 */

class WURFL_WURFLManagerProvider {

	const CONFIGURATION_FILE_PATH = "../resources/wurfl-config.xml";
	
	/**
	 * Get an initialized WURFLManager
	 *
	 * @return object a WURFLManager object
	 */
	public static function getWURFLManager($configurationFilePath) {
		if (NULL === self::$wurflManager) {
			if(!file_exists($configurationFilePath)) {
				throw new WURFL_WURFLException("The file <" . $configurationFilePath . "> does not exist");
			}
			
			self::_init($configurationFilePath);
		}
		return self::$wurflManager;
	}
	
	
	/**
	 * Initiaizes the actual WURFLManager
	 *
	 * @param string $configurationFilePath Absolute path to the wurfl configuration file
	 */
	private static function _init($configurationFilePath) {

		$wurflConfig = new WURFL_Configuration_Config($configurationFilePath);
		WURFL_Configuration_ConfigHolder::setWURFLConfig($wurflConfig);
		
		
		$wurflFileParser = new WURFL_Xml_WURFLFileParser();
		$wurflPatchFileParser = new WURFL_Xml_WURFLPatchFileParser();
		$wurflPatchManager = new WURFL_Xml_PatchManager();

		// Persistance and Cache Providers
		$persistanceProvider = WURFL_Xml_PersistanceProvider_PersistanceProviderManager::getPersistanceProvider();
		$cacheProvider = WURFL_Cache_CacheProviderFactory::getCacheProvider();


		$xmlResourceManager = new WURFL_Xml_XMLResourceManager($persistanceProvider, $wurflPatchManager, $wurflFileParser, $wurflPatchFileParser);


		$userAgentHandlerChain = WURFL_UserAgentHandlerChainFactory::create();
		$deviceRepository = new WURFL_DeviceRepository($xmlResourceManager, $userAgentHandlerChain, $persistanceProvider);


		$wurflService = new WURFL_WURFLService($deviceRepository, $userAgentHandlerChain, $cacheProvider);

		$userAgentNormalizer = new WURFL_Request_UserAgentNormalizer();
		$requestFactory = new WURFL_Request_GenericRequestFactory($userAgentNormalizer);

		self::$wurflManager = new WURFL_WURFLManager($wurflService, $requestFactory);

	}

	private static $wurflManager = NULL;
}

?>