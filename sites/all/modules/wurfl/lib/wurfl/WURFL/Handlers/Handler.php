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
 * UserAgentHandler is the base class that combines the classification of
 * the user agents and the matching process.
 *
 * @category   WURFL
 * @package    WURFL
 * @copyright  WURFL-PRO SRL, Rome, Italy
 * @license
 * @version    1.0.0
 */
abstract class WURFL_Handlers_Handler implements WURFL_Handlers_Filter, WURFL_Handlers_Matcher {
	
	protected $prefix;
	
	protected $userAgentsWithDeviceID;
	
	private $nextHandler;
	
	protected $fileManager;
	
	protected $persistanceProvider;
	
	// Log
	protected $logger;
	private $udetectedDeviceLogger;
	
	const LOG_ENABLED = false;
	
	function __construct() {
		
		$this->_initializeLogger ();
		
		$this->persistanceProvider = WURFL_Xml_PersistanceProvider_PersistanceProviderManager::getPersistanceProvider ();
	}
	
	private function _initializeLogger() {
		
		//$conf = array ('mode' => 0644, 'timeFormat' => '%X %x' );
		
		//$logFile = "wurfl.log";
		//$udetectedDeviceLog = "undetected_devices.log";
		//$this->logger = &Log::singleton ( 'console', $logFile, 'ident', $conf );
		//$this->udetectedDeviceLogger = &Log::singleton ( 'console', $udetectedDeviceLog, '', $conf );
	
		$this->logger = &Log::singleton('null');
		$this->udetectedDeviceLogger = &Log::singleton('null');
	}
	
	/**
	 * Sets the next Handler
	 *
	 * @param WURFL_Handlers_UserAgentHandler $handler
	 */
	public function setNextHandler($handler) {
		$this->nextHandler = $handler;
	}
	
	abstract function canHandle($userAgent);
	
	//********************************************************
	//
	//     Classification of the User Agents
	//
	//********************************************************
	/**
	 *
	 * @param string $userAgent
	 * @param string $deviceID
	 */
	function filter($userAgent, $deviceID) {
		if ($this->canHandle ( $userAgent )) {
			$this->updateUserAgentsWithDeviceIDMap ( $userAgent, $deviceID );
			return;
		}
		if (isset ( $this->nextHandler )) {
			return $this->nextHandler->filter ( $userAgent, $deviceID );
		}
	}
	
	/**
	 * Updates the map containing the classified user agents
	 * Before adding the user agent to the map it normalizes by using the normalizeUserAgent
	 * function.
	 *
	 * If you need to normalize the user agent you need to override the funcion in
	 * the speficific user agent handler
	 *
	 *
	 * @param string $userAgent
	 * @param string $deviceID
	 */
	final function updateUserAgentsWithDeviceIDMap($userAgent, $deviceID) {
		$this->userAgentsWithDeviceID [$this->normalizeUserAgent ( $userAgent )] = $deviceID;
	}
	
	protected function normalizeUserAgent($userAgent) {
		return $userAgent;
	}
	
	//********************************************************
	//	Persisting The classified user agents
	//
	//********************************************************
	/**
	 * Persists the classified user agents on the filesystem
	 *
	 */
	function persistData() {
		// we sort the array first, useful for doing ris match
		if (! empty ( $this->userAgentsWithDeviceID )) {
			ksort ( $this->userAgentsWithDeviceID );
			$this->persistanceProvider->save ( $this->prefix, $this->userAgentsWithDeviceID );
		}
	}
	
	//********************************************************
	//	Matching
	//
	//********************************************************
	/**
	 * Finds the device id for the given request.
	 * if it is not found it delegates to the next available handler
	 *
	 *
	 * @param WURFL_GenericRequest $request
	 * @return string
	 */
	public function match(WURFL_Request_GenericRequest $request) {
		$userAgent = $request->userAgent;
		if ($this->canHandle ( $userAgent )) {
			return $this->applyMatch ( $request );
		}
		
		if (isset ( $this->nextHandler )) {
			return $this->nextHandler->match ( $request );
		}
		
		return WURFL_Constants::GENERIC;
	}
	
	/**
	 * Template method
	 *
	 * @param string $userAgent
	 * @return string
	 */
	function applyMatch(WURFL_Request_GenericRequest $request) {
		
		$userAgent = $request->userAgent;
		
		// Get The data associated with this current handler
		$this->userAgentsWithDeviceID = $this->persistanceProvider->load ( $this->prefix );
		
		$deviceID = NULL;
		
		// we start with direct match
		if (array_key_exists ( $userAgent, $this->userAgentsWithDeviceID )) {
			return $this->userAgentsWithDeviceID [$userAgent];
		}
		
		// Try with the conclusive Match
		$deviceID = $this->applyConclusiveMatch ( $userAgent );
		
		if ($deviceID == NULL || strcmp ( $deviceID, "generic" ) === 0 || strlen ( trim ( $deviceID ) ) == 0) {
			// Log the ua profile
			$this->udetectedDeviceLogger->log ( $request->userAgentProfile );
			$deviceID = $this->applyRecoveryMatch ( $userAgent );
		}
		// Try with catch all recovery Match
		if ($deviceID == NULL || strcmp ( $deviceID, "generic" ) === 0 || strlen ( trim ( $deviceID ) ) == 0) {
			$deviceID = $this->applyRecoveryCatchAllMatch ( $userAgent );
		}
		
		if (! isset ( $deviceID ) || $deviceID == '') {
			return WURFL_Constants::GENERIC;
		}
		
		return $deviceID;
	}
	
	/**
	 
	 * @param string $userAgent
	 * @return string
	 */
	function applyConclusiveMatch($userAgent) {
		$match = $this->lookForMatchingUserAgent ( $userAgent );
		
		if (! empty ( $match )) {
			return $this->userAgentsWithDeviceID [$match];
		}
		
		return NULL;
	
	}
	
	/**
	 * Override this method to give an alternative way to do the matching
	 *
	 * @param string $userAgent
	 * @return string
	 */
	function lookForMatchingUserAgent($userAgent) {
		$this->logger->log ( "$this->prefix :Applying Conclusive Match for ua: $userAgent" );
		$tollerance = WURFL_Handlers_Utils::firstSlash ( $userAgent );
		return WURFL_Handlers_Utils::risMatch ( array_keys ( $this->userAgentsWithDeviceID ), $userAgent, $tollerance );
	}
	
	/**
	 * Applies Recovery Match
	 *
	 * @param unknown_type $userAgent
	 */
	function applyRecoveryMatch($userAgent) {
	}
	
	function applyRecoveryCatchAllMatch($userAgent) {
		
		//Openwave
		if (WURFL_Handlers_Utils::checkIfContains ( $userAgent, "UP.Browser/7.2" )) {
			return "opwv_v72_generic";
		}
		if (WURFL_Handlers_Utils::checkIfContains ( $userAgent, "UP.Browser/7" )) {
			return "opwv_v7_generic";
		}
		if (WURFL_Handlers_Utils::checkIfContains ( $userAgent, "UP.Browser/6.2" )) {
			return "opwv_v62_generic";
		}
		if (WURFL_Handlers_Utils::checkIfContains ( $userAgent, "UP.Browser/6.1" )) {
			return "opwv_v6_generic";
		}
		if (WURFL_Handlers_Utils::checkIfContains ( $userAgent, "UP.Browser/6" )) {
			return "opwv_v6_generic";
		}
		if (WURFL_Handlers_Utils::checkIfContains ( $userAgent, "UP.Browser/5" )) {
			return "upgui_generic";
		}
		if (WURFL_Handlers_Utils::checkIfContains ( $userAgent, "UP.Browser/4" )) {
			return "uptext_generic";
		}
		if (WURFL_Handlers_Utils::checkIfContains ( $userAgent, "UP.Browser/3" )) {
			return "uptext_generic";
		}
		
		//Series 60
		if (WURFL_Handlers_Utils::checkIfContains ( $userAgent, "Series60" )) {
			return "nokia_generic_series60";
		}
		
		// Access/Net Front
		if (WURFL_Handlers_Utils::checkIfContains ( $userAgent, "NetFront/3.0" ) || WURFL_Handlers_Utils::checkIfContains ( $userAgent, "ACS-NF/3.0" )) {
			return "netfront_ver3";
		}
		if (WURFL_Handlers_Utils::checkIfContains ( $userAgent, "NetFront/3.1" ) || WURFL_Handlers_Utils::checkIfContains ( $userAgent, "ACS-NF/3.1" )) {
			return "netfront_ver3_1";
		}
		if (WURFL_Handlers_Utils::checkIfContains ( $userAgent, "NetFront/3.2" ) || WURFL_Handlers_Utils::checkIfContains ( $userAgent, "ACS-NF/3.2" )) {
			return "netfront_ver3_2";
		}
		if (WURFL_Handlers_Utils::checkIfContains ( $userAgent, "NetFront/3.3" ) || WURFL_Handlers_Utils::checkIfContains ( $userAgent, "ACS-NF/3.3" )) {
			return "netfront_ver3_3";
		}
		if (WURFL_Handlers_Utils::checkIfContains ( $userAgent, "NetFront/3.4" )) {
			return "netfront_ver3_4";
		}
		if (WURFL_Handlers_Utils::checkIfContains ( $userAgent, "NetFront/3.5" )) {
			return "netfront_ver3_5";
		}
		
		//Windows CE
		if (WURFL_Handlers_Utils::checkIfContains ( $userAgent, "Windows CE" )) {
			return "ms_mobile_browser_ver1";
		}
		
		if (WURFL_Handlers_Utils::checkIfContains ( $userAgent, "Mozilla" )) {
			return WURFL_Constants::GENERIC_XHTML;
		}
		
		/**
		 * Teleca-Obigo Browser
		 */
		if (WURFL_Handlers_Utils::checkIfContains ( $userAgent, "ObigoInternetBrowser/Q03C" ) || WURFL_Handlers_Utils::checkIfContains ( $userAgent, "AU-MIC/2" ) || WURFL_Handlers_Utils::checkIfContains ( $userAgent, "AU-MIC-" ) || WURFL_Handlers_Utils::checkIfContains ( $userAgent, "AU-OBIGO/" ) || WURFL_Handlers_Utils::checkIfContains ( $userAgent, "Obigo/Q03" ) || WURFL_Handlers_Utils::checkIfContains ( $userAgent, "Obigo/Q04" ) || WURFL_Handlers_Utils::checkIfContains ( $userAgent, "ObigoInternetBrowser/2" ) || WURFL_Handlers_Utils::checkIfContains ( $userAgent, "Teleca Q03B1" )) {
			return WURFL_Constants::GENERIC_XHTML;
		}
		
		//web browsers?
		if (! (strpos ( $userAgent, "Mozilla/4.0" ) === false)) {
			return "generic_web_browser";
		}
		if (! (strpos ( $userAgent, "Mozilla/5.0" ) === false)) {
			return "generic_web_browser";
		}
		if (! (strpos ( $userAgent, "Mozilla/6.0" ) === false)) {
			return "generic_web_browser";
		}
		
		// Opera Mini
		if (WURFL_Handlers_Utils::checkIfContains ( $userAgent, "Opera Mini/1" )) {
			return "opera_mini_ver1";
		}
		if (WURFL_Handlers_Utils::checkIfContains ( $userAgent, "Opera Mini/2" )) {
			return "opera_mini_ver2";
		}
		if (WURFL_Handlers_Utils::checkIfContains ( $userAgent, "Opera Mini/3" )) {
			return "opera_mini_ver3";
		}
		if (WURFL_Handlers_Utils::checkIfContains ( $userAgent, "Opera Mini/4" )) {
			return "opera_mini_ver4";
		}
		
		/**
		 * Mozilla of some kind
		 */
		if (WURFL_Handlers_Utils::checkIfContains ( $userAgent, "Mozilla/" )) {
			return WURFL_Constants::GENERIC_XHTML;
		}
		
		// DoCoMo
		if ((strpos ( $userAgent, "DoCoMo" ) === 0) || (strpos ( $userAgent, "KDDI" ) === 0)) {
			return "docomo_generic_jap_ver1";
		}
		
		return WURFL_Constants::GENERIC;
	}
	
	public function getPrefix() {
		return $this->prefix;
	}
	
	public function getUserAgentsWithDeviceID() {
		return $this->userAgentsWithDeviceID;
	}

}

?>