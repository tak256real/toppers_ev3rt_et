///////////////////////////////////////////////////////////
//  SysDeviceBridge.cpp
//  Implementation of the Class SysDeviceBridge
//  Created on:      2016/05/26 11:18:09
//  Original author: 037789
///////////////////////////////////////////////////////////

#include "SysDeviceBridge.h"

SysDeviceBridge* SysDeviceBridge::instance = NULL;

SysDeviceBridge::SysDeviceBridge(uint16 rv_subsys_id, sint32 rv_mbox_id)
    :SubsystemBridge(rv_subsys_id, rv_mbox_id)
{

}



SysDeviceBridge::~SysDeviceBridge(){

}





void SysDeviceBridge::doStartRcvCommand(){
    the_device->doStartRcvCommand();
}


SysDeviceBridge* SysDeviceBridge::geInstance(){

    if(instance == NULL) {
        instance = new CmdReceiveIf();
    }
    else {
        // インスタンスが既に存在している場合は何もしない.
    }

    return instance;
}


void SysDeviceBridge::actInitialize(){
    the_device = SysDeviceIf::getInstance();
}


void SysDeviceBridge::actReceiveMessage(uint16 rv_msg_code, uint16* rv_message){

}
