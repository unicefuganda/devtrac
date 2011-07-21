<?php
/**
 * All WURFL Tests 
 * 
 * @author
 * @version 
 */
require_once 'PHPUnit/Framework/TestSuite.php';
require_once 'WURFL/WURFLTestSuite.php';

require_once 'WURFL/WURFLManagerTest.php';
require_once 'WURFL/DeviceTest.php';

class WURFLTests extends PHPUnit_Framework_TestSuite {
	
	/**
	 * Constructs the test suite handler.
	 */
	public function __construct() {
		$this->setName ( 'WURFLTests' );
		$this->addTestSuite('WURFL_WURFLManagerTest');
        $this->addTestSuite('WURFL_DeviceTest');		
		//$this->addTestSuite ( WURFL_WURFLTestSuite::suite() );	
	}
	
	
	public static function suite() {
		return new self ( );
	}
}

