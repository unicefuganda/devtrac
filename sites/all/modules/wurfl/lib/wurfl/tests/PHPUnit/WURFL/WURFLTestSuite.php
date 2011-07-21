<?php

require_once 'PHPUnit/Framework/TestSuite.php';

class WURFL_WURFLTestSuite {
    
	public static function suite() {
        $suite = new PHPUnit_Framework_TestSuite('WURFL PHP API');
        $suite->addTestSuite('WURFL_WURFLManagerTest');
        $suite->addTestSuite('WURFL_DeviceTest');
        return $suite;
    }
}


?>