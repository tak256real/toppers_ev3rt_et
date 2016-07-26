///////////////////////////////////////////////////////////
//  SysConsoleBridge.cpp
//  Implementation of the Class SysConsoleBridge
//  Created on:      2016/07/22 10:54:33
//  Original author: 037789
///////////////////////////////////////////////////////////

#include "SysConsoleBridge.h"

SysConsoleBridge* SysConsoleBridge::instance = NULL;

SysConsoleBridge::SysConsoleBridge(uint16 rv_subsys_id, sint32 rv_mbox_id) :
    SubSystemBridge(rv_subsys_id, rv_mbox_id),
    the_if(NULL)
{

}



SysConsoleBridge::~SysConsoleBridge(){

}





SysConsoleBridge* SysConsoleBridge::getInstance(){

    if(instance == NULL) {
        instance = new SysConsoleBridge(kSubsysConsole, ID_MSG_BOX_DEBUG_CONSOLE);
    }
    else {
        // Don't care...
    }

	return instance;
}


void SysConsoleBridge::actReceiveMessage(uint16 rv_msg_code, uint16* rv_message){

}


void SysConsoleBridge::actInitialize(){
    the_if = SysConsoleIf::getInstance();

    the_if->initialze();

}
