///////////////////////////////////////////////////////////
//  Timer.cpp
//  Implementation of the Class Timer
//  Created on:      2016/04/28 14:48:15
//  Original author: 037789
///////////////////////////////////////////////////////////

#include "Timer.h"
#include "TimerEvent.h"


Timer * Timer::instance = NULL;

Timer::Timer() : the_event(NULL) {
    // 配列メンバの初期化.
    for(uint8 i = 0; i < kMaxTimerId; i++) {
        time_count[i] = 0;
    }
}



Timer::~Timer(){

}





Timer* Timer::getInstance(){

    if(instance == NULL) {
        instance = new Timer();
    }
    else {
    }
    return  instance;
}


void Timer::tick(){

    for(uint8 i = 0; i < kMaxTimerId; i++) {

        if(time_count[i] > 0) {
            // デクリメント結果でカウント 0 となったらタイムアップ通知.
            if(--time_count[i]) {
                the_event->ntfTimeOut(i);
            }
        }
        else {
            // Don't care.
        }
    }
}

void startTimer(uint32 rv_time, EmTimerId rv_id) {
    // カウントを設定してタイマの起動を行なう.
    time_count[rv_id] = rv_time;
}


void stopTiemr(EmTimerId rv_id) {
    // カウント 0 にしてタイムアウト通知をキャンセルする.
    time_count[rv_id] = 0;
}



extern "C" void Cyc1msecInterval(intptr_t exinf) {
    // 1000usec ID_EV3CYC_1MS サイクリックハンドラ.
    Timer::getInstance()->tick();
}
