<?php

if (! defined('SIMPLE_TEST')) {
    define('SIMPLE_TEST', '../../lib/simpletest');
}

require_once(SIMPLE_TEST . '/reporter.php');


class WURFLReporter extends HtmlReporter {

    function getTestList() {
        return array();
    }

    function WURFLReporter() {
        $this->HtmlReporter();
    }


	/*    
    function paintPass($message) {
        parent::paintPass($message);
        print "<span class=\"pass\">Pass</span>: ";
        //$breadcrumb = $this->getTestList();
        //array_shift($breadcrumb);
        print "->$message<br />\n";
    }
    */
    function _getCss() {
        return parent::_getCss() . ' .pass { color: green; }';
    }
}

?>