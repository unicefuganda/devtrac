<?php


class WURFLServiceTestSuite extends TestSuite
{
    /**
     * constructor
     */
    public function __construct()
    {
        $this->TestSuite('WURFL Test Suite');
        $this->addTestFile(dirname(__FILE__) . '/WURFLManagerTestCase.php'); 
		$this->addTestFile(dirname(__FILE__) . '/WURFLRequestFactoryTestCase.php');               
    }
}
?>
