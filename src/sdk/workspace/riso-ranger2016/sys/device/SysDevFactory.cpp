///////////////////////////////////////////////////////////
//  SysDevFactory.cpp
//  Implementation of the Class SysDevFactory
//  Created on:      2016/07/20 10:51:03
//  Original author: tak
///////////////////////////////////////////////////////////

#include "SysDevFactory.h"


SysDevFactory::SysDevFactory(){

}



SysDevFactory::~SysDevFactory(){

}





void SysDevFactory::create(){

    // 常駐インスタンス生成.
    SerialCom *at_serial_com = new SerialComEV3BT_SPP();

    //関連貼り.
    SysDeviceIf::getInstance()->set_the_serial(at_serial_com);

}
