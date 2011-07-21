<?php

require_once dirname(__FILE__) . '../../../../WURFL/WURFLManagerProvider.php';
$wurflConfigFile = dirname(__FILE__) . "/../resources/wurfl-config.xml";

$wurflManager = WURFL_WURFLManagerProvider::getWURFLManager($wurflConfigFile);	
	

?>