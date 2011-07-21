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
final class WURFL_Configuration_Config {

	const WURFL = "wurfl";
	const MAIN_FILE = "main-file";
	const PATCH = "patch";
	const CACHE = "cache";
	const PERSISTANCE = "persistance";
	const PROVIDER = "provider";
	const PARAMS = "params";

	
	const DIR = "dir";
	
	private $wurflFile;
	private $wurflPatches;
	
	private $persistance = array();
	private $cache = array();

	private $logDir = ".";


	private $_confLocation = "../../resources/wurfl-config.xml";
	private $_configurationFileDir = null;
	

	private $stack = array();
	private $persistanceOrCache = array();
	
	
	
	/**
	 * Constructor
	 *
	 * @param string $confLocation
	 */
	function __construct($confLocation) {
		if(!file_exists($confLocation)) {
			throw new WURFL_WURFLException("The configuration file " . $confLocation . " does not exist.");
		}
		$this->_confLocation = $confLocation;
		$this->_configurationFileDir = dirname($this->_confLocation) . DIRECTORY_SEPARATOR;

		$this->_loadConfig();
	}
	
	
	
	
	/**
	 * Magic Method 
	 *
	 * @param string $name
	 * @return mixed
	 */
	function __get($name){
		return $this->$name;
	}
	
	
	/**
	 * Reads the configuration file and creates the class attributes
	 *
	 */
	private function _loadConfig(){
		
		$reader = new XMLReader();
		$reader->open($this->_confLocation);

		$reader->setRelaxNGSchemaSource(self::WURFL_CONF_SCHEMA);


		libxml_use_internal_errors(TRUE);

		
		while ($reader->read()) {
			$name = $reader->name;
			switch ($reader->nodeType) {
				case XMLReader::ELEMENT:
					$this->_handleStartElement($name);
					break;
				case XMLReader::TEXT:
					$this->_handleTextElement($reader->value);
					break;
				case XMLReader::END_ELEMENT:
					$this->_handleEndElement($name);
					break;
			}
		}
		
		$reader->close();
		
	}

	/**
	 * Handles the start of an element
	 *
	 * @param string $name
	 */
	private function _handleStartElement($name) {
		array_push($this->stack, $name);
	}

	/**
	 * Handles Text Element
	 *
	 * @param array $stack
	 * @param string $name
	 * @param string $value
	 */
	private function _handleTextElement($value) {
		$currentElement = $this->array_peek($this->stack);
		switch ($currentElement) {
			case self::MAIN_FILE:				
				$this->wurflFile = $this->_getFullPath($value);
				break;
			case self::PATCH:
				$this->wurflPatches[] = $this->_getFullPath($value);
				break;
			case self::PROVIDER:
				$this->persistanceOrCache["provider"] = $value;
				break;
			case self::PARAMS:
				$this->persistanceOrCache = array_merge($this->persistanceOrCache, $this->_toArray($value));
				break;
		}

	}

	/**
	 * Handles the end of the element
	 *
	 * @param string $name
	 */
	private function _handleEndElement($name) {
		switch ($name) {
			case self::PERSISTANCE:
				$this->persistance = $this->persistanceOrCache;
			case self::CACHE:
				$this->cache = $this->persistanceOrCache;
				break;
		}
		
		array_pop($this->stack);
		
	}


	//************************* Utility Functions ********************************//

	private function _ensureExistance($fileName) {
		if($this->_fileExist($fileName)) {
			return;
		}
		die("The file " . $fileName . " does not exist \n"); 
		
	}
	
	private function _toArray($params) {
		$paramsArray = array();

		foreach (explode(",", $params) as $param) {
			$paramNameValue = explode("=", $param);
			
			if(strcmp(self::DIR, $paramNameValue[0]) == 0) {
				$paramNameValue[1] = $this->_getFullPath($paramNameValue[1]);
			}
			
			$paramsArray[$paramNameValue[0]] = $paramNameValue[1];
		}

		return $paramsArray;
	}

	private function array_peek(array &$array) {
		$var = array_pop($array);
		array_push($array, $var);
		return $var;
	}
	
	
	private function _fileExist($confLocation) {
		$fullFileLocation = $this->_getFullPath($confLocation);
		return file_exists($fullFileLocation);
	}
	
	
	/**
	 * Return the full path
	 *
	 * @param string $fileName
	 * @return string
	 */
	private function _getFullPath($fileName) {
		$fileName = trim($fileName);
		if ($fileName[0] == '/') {
			return $fileName;
		}
		$fullName = $this->_configurationFileDir . $fileName; 
		
		if(file_exists($fullName)) {
			return $fullName;
		}
		
		die("The File " . $fullName . " does not exist!!!\n");
	}



	const  WURFL_CONF_SCHEMA = '<?xml version="1.0" encoding="utf-8" ?>
	<element name="wurfl-config" xmlns="http://relaxng.org/ns/structure/1.0">
    	<element name="wurfl">
    		<element name="main-file"><text/></element>
    		<element name="patches">
    			<zeroOrMore>
      				<element name="patch"><text/></element>
    			</zeroOrMore>
  			</element>
  		</element>
  		<element name="persistance">
      		<element name="provider"><text/></element>
      		<optional>
      			<element name="params"><text/></element>
      		</optional>
  		</element>
  		<element name="cache">
      		<element name="provider"><text/></element>
      		<optional>
      			<element name="params"><text/></element>
      		</optional>
  		</element>
	</element>';
}
?>