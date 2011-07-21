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
 * Represents a device in the wurfl xml file
 *
 */
class WURFL_Xml_ModelDevice {

	function __construct($id, $userAgent, $fallBack, $actualDeviceRoot,
	$capabilities = null) {
		$this->id = $id;
		$this->userAgent = $userAgent;
		$this->fallBack = $fallBack;
		$this->actualDeviceRoot = $actualDeviceRoot;
		if (is_array($capabilities)) {
			$this->capabilities = $capabilities;
		}
	}

	function __get($name) {
		return $this->$name;
	}
	
	private $id;
	private $fallBack;
	private $userAgent;
	private $actualDeviceRoot;
	private $capabilities = array();
	
	
	
}

?>