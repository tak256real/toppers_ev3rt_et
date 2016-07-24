///////////////////////////////////////////////////////////
//  SerialComEV3BT_SPP.cpp
//  Implementation of the Class SerialComEV3BT_SPP
//  Created on:      2016/05/26 13:31:04
//  Original author: 037789
///////////////////////////////////////////////////////////

#include "ev3api.h"
#include "Timer.h"
#include "SerialComEV3BT_SPP.h"



SerialComEV3BT_SPP::SerialComEV3BT_SPP()
    : SerialCom()
{

}



SerialComEV3BT_SPP::~SerialComEV3BT_SPP(){

}





/**
 * 今回、シリアルは Buletooth の SSP による仮想シリアルとなる. 通常のシリアルとは制御が異なるため、サブクラス化の余地を残すがそのまま実装する.
 */
void SerialComEV3BT_SPP::actInitialze(){
    /* Open Bluetooth file */
    the_timer = Timer::getInstance();
    tty = ev3_serial_open_file(EV3_SERIAL_BT);
    assert(tty != NULL);

    the_timer->startTimer(cTtyCtrlCycle, kTimerSCI);
}



void SerialComEV3BT_SPP::actTimeOut(EmTimerId rv_timer_id){
    // 接続確認
    if(!ev3_button_set_on_clicked()) {
        // 接続が切れていたらタイマセットしてリターン.
        the_timer->startTimer(cTtyCtrlCycle, kTimerSCI);
        return;
    }

    uint8 at_char = fgetc(tty);

}
