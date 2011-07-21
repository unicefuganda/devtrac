<?php

require_once 'PHPUnit/Framework.php';

require_once dirname(__FILE__) . '/../../../WURFL/WURFLManagerProvider.php';

class WURFL_DeviceTest extends PHPUnit_Framework_TestCase {

	protected $wurflManager;
	protected $testData;

	const TEST_DATA_FILE = "../../resources/device-capability.yml";
	const WURFL_CONFIG_FILE = "../../resources/wurfl-config.xml";

	protected function setUp() {
		$configFilePath = dirname(__FILE__) . DIRECTORY_SEPARATOR .  self::WURFL_CONFIG_FILE;
		$this->wurflManager = WURFL_WURFLManagerProvider::getWURFLManager($configFilePath);
	}


	/**
	 * @dataProvider deviceIdCapabilityNameCapabilityValueProvider
	 */
	public function testGetCapability($deviceId, $groupId, $capabilityName, $capabilityValue) {
		$device = $this->wurflManager->getDevice($deviceId);
		$capabilityFound = $device->getCapability($capabilityName);

		$this->assertEquals($capabilityValue, $capabilityFound);
	}



	public function deviceIdCapabilityNameCapabilityValueProvider() {
		return $this->testData = $this->loadTestsData(self::TEST_DATA_FILE);
	}




	private function loadTestsData($fileName) {
		$fileName =  (dirname(__FILE__) . DIRECTORY_SEPARATOR . $fileName);

		$testData = array();

		$file_handle = fopen($fileName, "r");
		while (!feof($file_handle)) {
			$line = fgets($file_handle);
			if(strpos($line, "#") === false && strcmp($line, "\n") != 0) {
				$testData[] = explode(":", trim($line));
			}
		}
		fclose($file_handle);

		return $testData;
	}



}

?>