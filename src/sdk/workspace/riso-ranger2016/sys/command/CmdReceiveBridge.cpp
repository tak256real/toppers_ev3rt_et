///////////////////////////////////////////////////////////
//  CmdReceiveBridge.cpp
//  Implementation of the Class CmdReceiveBridge
//  Created on:      2016/05/25 9:57:27
//  Original author: 037789
///////////////////////////////////////////////////////////
#include "CmdReceiveIf.h"
#include "CmdReceiveBridge.h"


CmdReceiveBridge* CmdReceiveBridge::instance = NULL;

CmdReceiveBridge::CmdReceiveBridge(uint16 rv_subsys_id, sint32 rv_mbox_id)
    : SubsystemBridge(rv_subsys_id, rv_mbox_id)
{

}



CmdReceiveBridge::~CmdReceiveBridge(){

}





void CmdReceiveBridge::actInitialize(){

    // 関連取得.
    the_receiver = CmdReceiveIf::getInstance();
    the_receiver->doInitialize();
}


void CmdReceiveBridge::actReceiveMessage(uint16 rv_msg_code, uint16* rv_message){

}



CmdReceiveBridge* CmdReceiveBridge::getInstance(){

	if(instance == NULL) {
        instance = new CmdReceiveBridge(kSubsysCommand, ID_MSG_BOX_SS_CMD_RCV);
    }
    else {
        // インスタンスが既に存在している場合は何もしない.
    }

    return instance;
}

