///////////////////////////////////////////////////////////
//  SysConsoleIf.cpp
//  Implementation of the Class SysConsoleIf
//  Created on:      2016/07/24 23:59:49
//  Original author: 037789
///////////////////////////////////////////////////////////

#include "SysConsoleIf.h"

SysConsoleIf* SysConsoleIf::instance = NULL;

SysConsoleIf::SysConsoleIf()
    : SubsystemIf();
{

}



SysConsoleIf::~SysConsoleIf(){

}





SysConsoleIf* SysConsoleIf::getInstance(){
    
	if(instance == NULL) {
        instance = new SysConsoleIf();
    }
    else {
        // インスタンスが既に存在している場合は何もしない.
    }

	return instance;
}


void SysConsoleIf::initialze(){

}
