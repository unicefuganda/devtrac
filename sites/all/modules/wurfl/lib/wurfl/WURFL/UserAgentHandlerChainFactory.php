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

class WURFL_UserAgentHandlerChainFactory {
	
	private function __construct() {}
	
	/**
     * Factory
     *
     * @return WURFL_UserAgentHandlerChain
     */
    public static function create() {
    	if (!isset(self::$_userAgentHandlerChain)) {
    		self::init();
    	}
    	return self::$_userAgentHandlerChain;
    }
	
    static private function init() {
    	self::$_userAgentHandlerChain = new WURFL_UserAgentHandlerChain();
    	
    	self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_VodafoneHandler());
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_NokiaHandler());
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_SonyEricssonHandler());
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_MotorolaHandler());
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_BlackBerryHandler());

		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_SiemensHandler());
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_SagemHandler());
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_SamsungHandler());
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_PanasonicHandler());

		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_NecHandler());
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_QtekHandler());

		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_MitsubishiHandler());
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_PhilipsHandler());
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_LGHandler());
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_AppleHandler());
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_KyoceraHandler());
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_AlcatelHandler());
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_SharpHandler());
			
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_SanyoHandler());
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_BenQHandler());
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_PantechHandler());
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_ToshibaHandler());
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_GrundigHandler());
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_HTCHandler());
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_SPVHandler());
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_WindowsCEHandler());
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_PortalmmmHandler());
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_DoCoMoHandler());
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_KDDIHandler());

		// Web Browsers handlers
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_AOLHandler());
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_OperaHandler());
        self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_FirefoxHandler());
        self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_SafariHandler());
        self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_MSIEHandler());


        
		self::$_userAgentHandlerChain->addUserAgentHandler(new WURFL_Handlers_CatchAllHandler());
    	
    }
    
    static private $_userAgentHandlerChain;
}

?>