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





void SysDeviceBridge::doStartConsoleDev(){
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
    the_device = initialize();
}


void SysDeviceBridge::actReceiveMessage(uint16 rv_msg_code, uint16* rv_message){

}



void SysDeviceBridge::intrNtfTimeOut(EmTimerId rv_timer_id){

    // 非タスクコンテキストにおけるメッセージングを考慮.
    // TimerId の種類によってスレッドの切り替えを判定する.
    switch(rv_timer_id) {
        case kTimerSCI:
            // ここでは非タスクコンテキストのまま If をコールする.
            the_device->ntfTimeOut(rv_timer_id);
            break;
        default:
            break;
    }

}
