///////////////////////////////////////////////////////////
//  SysDeviceFactory.cpp
//  Implementation of the Class SysDeviceFactory
//  Created on:      2016/07/24 15:18:51
//  Original author: tak
///////////////////////////////////////////////////////////

#include "SysDeviceIf.h"
#include "SerialComEV3BT_SPP.h"

#include "SysDeviceFactory.h"

SysDeviceFactory::SysDeviceFactory(){

}



SysDeviceFactory::~SysDeviceFactory(){

}





void SysDeviceFactory::create(){
    SysDeviceIf* at_ss_if = SysDeviceIf::getInstance();
    SerialComEV3BT_SPP *at_serial_com = new SerialComEV3BT_SPP();

    at_ss_if->set_the_serial_com(at_serial_com);
}
