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
class WURFL_Xml_PersistanceProvider_FilePersistanceProvider extends WURFL_Xml_PersistanceProvider_AbstractPersistanceProvider {

    private $_persistanceDir;
    
    protected $persistanceIdentifier = "FILE_PERSISTANCE_PROVIDER";
    
    
    const DIR = "dir";
    
    public function __construct($params) {
    	$this->initialize($params);
    }
    
    /**
     * Initializes the Persistance Dir
     *
     * @param array of parameters for configuring the Persistance Provider
     */
    function initialize($params) {
		
    	if (is_array($params)) {
			if (!array_key_exists(self::DIR, $params)) {
				throw new WURFL_WURFLException("Specify a valid Persistance dir in wurfl-config.xml");
			}
			
			// Check if the directory exist and it is also write access
    		if (!is_writable($params[self::DIR])) {
				throw new WURFL_WURFLException("The diricetory specified <" . $params[self::DIR]. "> for the persistance provider does not exist or it is not writable\n");	
    		}

    		$this->_persistanceDir = $params[self::DIR] . DIRECTORY_SEPARATOR . $this->persistanceIdentifier;
    		
    		WURFL_FileManager::createDir($this->_persistanceDir);
		} 
    }

    /**
     * Saves the object on the file system
     * 
     *
     * @param string $objectId
     * @param mixed $object
     */
    public function save($objectId, $object) {
    	WURFL_FileManager::save($this->encode($objectId), $object, $this->_persistanceDir);
    }

    public function load($objectId) {
    	return WURFL_FileManager::fetch($this->encode($objectId), $this->_persistanceDir);
    }

    public function remove($objectId) {
    	return WURFL_FileManager::remove(encode($objectId), $this->_persistanceDir);
    }

    
    /**
     * Clears the persistance provider by removing the directory 
     *
     */
    public function clear() {
    	@rmdir($this->_persistanceDir);    	
    }
}