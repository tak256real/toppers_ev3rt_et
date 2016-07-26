///////////////////////////////////////////////////////////
//  SysDeviceIf.cpp
//  Implementation of the Class SysDeviceIf
//  Created on:      2016/05/26 11:27:54
//  Original author: 037789
///////////////////////////////////////////////////////////

#include "SysDeviceFactory.h"
#include "SysDeviceIf.h"


SysDeviceIf* SysDeviceIf::instance = NULL;

SysDeviceIf::SysDeviceIf()
    : SubsystemIf(),
      the_serial_com(NULL);
{

}



SysDeviceIf::~SysDeviceIf(){

}



void SysDeviceIf::initialize(){
    // SS 内常駐インスタンスの生成.
    SysDeviceFactory::create();

    // 初期化.
    if(the_serial_com != NULL) {
        the_serial_com->doInitialize();
    }
}



void SysDeviceIf::doStartConsoleDev(){
    the_serial_com->doComOpen();
}


SysDeviceIf* SysDeviceIf::getInstance(){
	if(instance == NULL) {
        instance = new SysDeviceIf();
    }
    else {
        // インスタンスが既に存在している場合は何もしない.
    }

	return instance;
}




void SysDeviceIf::ntfTimeOut(EmTimerId rv_timer_id){

    switch(rv_timer_id) {
        case kTimerSCI:
            the_serial_com->ntfTimeOut(EmTimerId rv_timer_id);
            break;
        default:
            break;
    }
}
