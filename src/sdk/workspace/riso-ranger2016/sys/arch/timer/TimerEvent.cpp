///////////////////////////////////////////////////////////
//  TimerEvent.cpp
//  Implementation of the Class TimerEvent
//  Created on:      2016/04/28 14:48:19
//  Original author: 037789
///////////////////////////////////////////////////////////

#include "TimerEvent.h"


TimerEvent::TimerEvent(){

}



TimerEvent::~TimerEvent(){

}


void TimerEvent::ntfTimeOut(EmTimerId rv_id){

    // ID 別のタイムアップ処理を記述する.
    // 非タスクコンテキストなので注意.
    switch(rv_id) {
        default:
            break;
    }

}


