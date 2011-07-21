<?php



require_once dirname(__FILE__) . '../../../WURFL/WURFLManagerProvider.php';
$wurflConfigFile = dirname(__FILE__) . "../demo/resources/wurfl-config.xml";

$wurflManager = WURFL_WURFLManagerProvider::getWURFLManager($wurflConfigFile);	




define("XHTML_ADVANCED", "xhtml_advanced.php");
define("XHTML_SIMPLE", "xhtml_simple.php");
define("WML", "wml.php");

define("XHTML_SUPPORT_LEVEL", "xhtml_support_level");
define("XHTMLMP_PREFERRED_MIME_TYPE", "xhtmlmp_preferred_mime_type");



$device = $wurflManager->getDeviceForHttpRequest($_SERVER);

$markUp = $device->getCapability(XHTML_SUPPORT_LEVEL);
$contentType = $device->getCapability(XHTMLMP_PREFERRED_MIME_TYPE);

$page = getPage($markUp);
redirectToPage($page, $contentType);

function getPage($markUp) {
	$page = WML;
	switch ($markUp) {
		case 1:
		case 2:
			$page = XHTML_SIMPLE;
			break;
		case 3:
		case 4:
			$page = XHTML_ADVANCED;
			break;
		default:
			$page = WML;
			break;
	}
	return $page;
}

function redirectToPage($page, $contentType) {
	$host  = $_SERVER['HTTP_HOST'];
	$uri   = rtrim(dirname($_SERVER['PHP_SELF']), '/\\');

	header('Content-Type: ' . $contentType . '\'');
	header("Location: http://$host$uri/$page");
}

?>