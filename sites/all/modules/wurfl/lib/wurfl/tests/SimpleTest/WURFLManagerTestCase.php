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
class WURFLManagerTestCase extends UnitTestCase {

	//const TEST_FILE = "../resources/unit-test-single.yml";
	const TEST_FILE = "../resources/unit-test.yml";
	const DEVICE_CAPABILITY_TEST_FILE = "../resources/device-capability.yml";

	private $wurflManager = NULL;

	private $testData = null;
	private $capabilityTestaDataProvider;

	const WURFL_CONFIG_FILE = "../resources/wurfl-config.xml";

	/**
	 * set up test resources
	 */
	public function setUp() {
		$this->testData = $this->loadTestsData(self::TEST_FILE);
		$this->loadCapabilityTestData(self::DEVICE_CAPABILITY_TEST_FILE);
		$configFilePath = dirname(__FILE__) . DIRECTORY_SEPARATOR .  self::WURFL_CONFIG_FILE;
		$this->wurflManager = WURFL_WURFLManagerProvider::getWURFLManager($configFilePath);
	}


	/**
	 * Test
	 *
	 */
	public function testGetDeviceIDForUserAgent() {
		foreach ($this->testData as $userAgent => $deviceIDSExpected) {
			$deviceFound = $this->wurflManager->getDeviceForUserAgent($userAgent);
			$commaSeparatedArray = "[" . implode(",", $deviceIDSExpected) . "]";
			$message = "" . $userAgent . " -> Found " . $deviceFound->id . "  Expected " . $commaSeparatedArray;
			$this->assertTrue(in_array($deviceFound->id, $deviceIDSExpected), $message);
		}
	}
	

	public function testGetCapabilityForDevice() {
		foreach ($this->capabilityTestaDataProvider as $capabilityTestData) {
			$expected = $capabilityTestData->capabilityValue;
			$device = $this->wurflManager->getDevice($capabilityTestData->deviceID);
			//$found = $this->wurflManager->getCapabilityForDevice($capabilityTestData->deviceID, $capabilityTestData->capabilityName);
			$found = $device->getCapability($capabilityTestData->capabilityName);
			$message = "Expected <b>" . $expected . "</b> ---> Found <b>" . $found . "</b>";
			$this->assertEqual($expected, $found, $message);
		}
	}

	
	public function testGetAllCapabilitiesForDevice() {
		foreach ($this->capabilityTestaDataProvider as $capabilityTestData) {
			$device = $this->wurflManager->getDevice($capabilityTestData->deviceID);
			$capabilities = $device->getAllCapabilities();
			//
			$expected = $capabilityTestData->capabilityValue;
			$found = $capabilities[$capabilityTestData->capabilityName];	
			$this->assertEqual($expected, $found);
		}
	}
	
	public function testUserAgentForRequest() {
		
	}
	
	
	/*
	public function testGetDeviceFallBacks() {
		$capabilities = $this->wurflManager->getAllCapabilitiesForDevice("generic_web_browser");
	}
	*/

	/**
	 * Load Test File containing user-agent -> deviceids associations
	 *
	 * @param string $fileName
	 * @return array
	 */
	private function loadTestsData($fileName) {
		$testData = array();
		$file_handle = fopen($fileName, "r");
		while (!feof($file_handle)) {
			$line = fgets($file_handle, 4096);			
			if(strpos($line, "#") === false && strcmp($line, "\n") != 0) {
				$line = trim($line);
				$tmp = explode(":", $line);
				$ids = substr($tmp[1], 1, strlen($tmp[1])-2);
				$ids = explode(",", $ids);

				$testData[trim($tmp[0], "\"")] = $ids;
			}
		}
		fclose($file_handle);

		return $testData;
	}


	private function loadCapabilityTestData($fileName) {
		$this->capabilityTestaDataProvider = array();
		$file_handle = fopen($fileName, "r");
		while (!feof($file_handle)) {
			$line = fgets($file_handle, 4096);
			if(strpos($line, "#") === false && strcmp($line, "\n") != 0) {
				$tmp = explode(":", trim($line));
				$capabilityTestData = new CapabilityTestData($tmp[0], $tmp[1], $tmp[2], $tmp[3]);
				$this->capabilityTestaDataProvider[] = $capabilityTestData;
			}
		}
		fclose($file_handle);
	}

}

class CapabilityTestData {
	private $deviceID;
	private $groupID;
	private $capabilityName;
	private $capabilityValue;

	function __construct($deviceID, $groupID, $capabilityName, $capabilityValue) {
		$this->deviceID = $deviceID;
		$this->groupID = $groupID;
		$this->capabilityName = $capabilityName;
		$this->capabilityValue = $capabilityValue;
	}

	function __get($name) {
		return $this->$name;
	}
}








