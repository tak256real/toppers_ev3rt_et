///////////////////////////////////////////////////////////
//  SubsystemBridge.cpp
//  Implementation of the Class SubsystemBridge
//  Created on:      2016/04/13 12:52:15
//  Original author: 037789
///////////////////////////////////////////////////////////

#include "SubsystemBridge.h"


SubsystemBridge::SubsystemBridge(){

}



SubsystemBridge::~SubsystemBridge(){

}


void SubsystemBridge::doInitialize(){
    actInitialize();
}


void SubsystemBridge::receiveMessage(uint16* rv_message){

}


void SubsystemBridge::sendMessage(void* rv_message, rv_size uint16){

}


void SubsystemBridge::actInitialize(){
    // 初期化処理をサブクラスで記述する.
}


void SubsystemBridge::actReceiveMessage(uint16* rv_message){

}
