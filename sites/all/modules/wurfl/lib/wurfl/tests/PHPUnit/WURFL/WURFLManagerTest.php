<?php

require_once 'PHPUnit/Framework.php';

require_once dirname(__FILE__) . '/../../../WURFL/WURFLManagerProvider.php';

class WURFL_WURFLManagerTest extends PHPUnit_Framework_TestCase {

	protected $wurflManager;
	protected $testData;

	const TEST_DATA_FILE = "../../resources/unit-test.yml";
	const WURFL_CONFIG_FILE = "../../resources/wurfl-config.xml";
	
	protected function setUp() {
		$configFilePath = dirname(__FILE__) . DIRECTORY_SEPARATOR .  self::WURFL_CONFIG_FILE;
		$this->wurflManager = WURFL_WURFLManagerProvider::getWURFLManager($configFilePath);
	}

	/**
	 * @dataProvider userAgentDeviceIdsProvider
	 */
	public function testGetDeviceForUserAgent($userAgent, $deviceIds) {
		$deviceFound = $this->wurflManager->getDeviceForUserAgent($userAgent);	
		$this->assertTrue(in_array($deviceFound->id, $deviceIds));
	}

	

	protected function tearDown() {
		$this->wurflManager = NULL;
	}


	public function userAgentDeviceIdsProvider() {
		return $this->testData = $this->loadTestsData(self::TEST_DATA_FILE);
	}
	
	
	
	
	/**
	 * Load Test File containing user-agent -> deviceids associations
	 *
	 * @param string $fileName
	 * @return array
	 */
	private function loadTestsData($fileName) {
		
		$fileName =  (dirname(__FILE__) . DIRECTORY_SEPARATOR . $fileName);
		
		$testData = array();
		$file_handle = fopen($fileName, "r");
		
		while (!feof($file_handle)) {
			$line = fgets($file_handle);
			if(strpos($line, "#") === false && strcmp($line, "\n") != 0) {
				$currentData = array();
				$line = trim($line);
				$tmp = explode(":", $line);
				$ids = substr($tmp[1], 1, strlen($tmp[1])-2);
				$ids = explode(",", $ids);
				
				$userAgent = trim($tmp[0], "\"");
				$currentData[] = $userAgent;
				$currentData[] = $ids;
				$testData[] = $currentData;
				
			}
		}
		fclose($file_handle);
		
		return $testData;
	}

}

?>