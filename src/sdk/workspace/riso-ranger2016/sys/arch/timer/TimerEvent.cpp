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

    // case には ID 別にタイムアップ処理を記述する.
    // 非タスクコンテキストとなるため占有時間に注意.
    //   短時間処理ならばそのままI/Fをコールして良いが、
    switch(rv_id) {
        case kDummyTimerId:
            
            break;
        default:
            break;
    }

}


