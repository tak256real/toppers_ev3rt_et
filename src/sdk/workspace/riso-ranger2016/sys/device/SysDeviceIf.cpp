///////////////////////////////////////////////////////////
//  SysDeviceIf.cpp
//  Implementation of the Class SysDeviceIf
//  Created on:      2016/05/26 11:27:54
//  Original author: 037789
///////////////////////////////////////////////////////////

#include "SysDeviceIf.h"

SysDeviceIf* SysDeviceIf::instance = NULL;

SysDeviceIf::SysDeviceIf(){

}



SysDeviceIf::~SysDeviceIf(){

}





void SysDeviceIf::doStartRcvCommand(){

	return 0;
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
