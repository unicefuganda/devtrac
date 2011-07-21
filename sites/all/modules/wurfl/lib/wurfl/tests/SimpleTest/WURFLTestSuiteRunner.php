<?php


define ('SIMPLE_TEST', dirname(__FILE__) . '/../../lib/simpletest');

require_once SIMPLE_TEST . '/unit_tester.php';
require_once dirname(__FILE__) . '/WURFLReporter.php';
require_once dirname(__FILE__) . '/../../WURFL/WURFLManagerProvider.php';



class WURFLTestSuiteRunner {
    public function run()
    {
        $dir = dirname(__FILE__);
        $testSuite = new TestSuite('WURFL TESTS.');
        $testSuite->addTestFile($dir . '/WURFLTestSuite.php');
        if (PHP_SAPI == 'cli') {
            $reporter = new TextReporter();
        } else {
            $reporter = new WURFLReporter();
        }
        $testSuite->run($reporter);
    }
}




?>