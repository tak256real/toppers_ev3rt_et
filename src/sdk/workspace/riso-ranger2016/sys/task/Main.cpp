///////////////////////////////////////////////////////////
//  Main.cpp
//  Implementation of the Class Main
//  Created on:      2016/04/28 11:49:13
//  Original author: 037789
///////////////////////////////////////////////////////////

#include "Main.h"
#include "Timer.h"
#include "TimerEvent.h"
#include "RTOS.h"


Main::Main(){

}



Main::~Main(){

}


void Main::start(){

    // システムアーキ関連の初期化処理
    //   - タイマ生成/稼動開始
    Timer* at_the_timer = Timer::getInstance();
    TimerEvent* at_the_timer_event = new TimerEvent();

    // 関連張り.
    at_the_timer->set_the_event(at_the_timer_event);

    // カーネルオブジェクト生成.
    RTOS::startCyclicHandler(ID_EV3CYC_1MS); // Timer クラス用周期ハンドラを起動.

    // 生成したカーネルオブジェクトに稼動と初期化の指示.

    // システムスタート指示.

}


void Main::create(){

	return 0;
}


void Main::roop(){

}


void Main::initialize(){

}



