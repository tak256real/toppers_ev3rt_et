///////////////////////////////////////////////////////////
//  CmdReciveIf.cpp
//  Implementation of the Class CmdReciveIf
//  Created on:      2016/05/25 14:35:22
//  Original author: 037789
///////////////////////////////////////////////////////////

#include "CmdReciveIf.h"

CmdReceiveIf* CmdReceiveIf::instance = NULL;

CmdReceiveIf::CmdReciveIf(){

}



CmdReceiveIf::~CmdReciveIf(){

}


CmdReceiveIf::CmdReceiveIf(){

}



CmdReceiveIf::~CmdReceiveIf(){

}


CmdReceiveIf* CmdReceiveIf::getInstance(){
	if(instance == NULL) {
        instance = new CmdReceiveIf();
    }
    else {
        // インスタンスが既に存在している場合は何もしない.
    }

    return instance;
}
