///////////////////////////////////////////////////////////
//  SerialComEV3BT_SPP.cpp
//  Implementation of the Class SerialComEV3BT_SPP
//  Created on:      2016/05/26 13:31:04
//  Original author: 037789
///////////////////////////////////////////////////////////

#include <stdio.h>

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
}


void SerialComEV3BT_SPP::actComOpen(){
    tty = ev3_serial_open_file(EV3_SERIAL_BT);
    assert(tty != NULL);

    // 通常のシリアル通信であれば、受信 or 送信の割り込みを受ける事になるのが一般的であるが、
    // EV3 の場合はベースシステムが存在するため、ポーリングを実施する.
    the_timer->startTimer(cTtyCtrlCycle, kTimerSCI);
}


void SerialComEV3BT_SPP::actTimeOut(EmTimerId rv_timer_id){
    // 接続確認
    if(!ev3_button_set_on_clicked()) {
        // 接続が切れていたらタイマセットしてリターン.
        the_timer->startTimer(cTtyCtrlCycle, kTimerSCI);
        return;
    }

    // 受信処理.
    if(tty->cnt) {
        uint8 *at_buff = new uint8[tty->cnt]; // 受信バッファ領域の作成.

        the_rx_buffer = new RxBuffer(at_buff, tty->cnt);

        // ファイル中の文字を全て刈り取る.
        while(1) {
            at_char = fgetc(tty);

            if(at_char != EOF) {
                the_rx_buffer->doWrite(at_char);
            }
            else {
                break;
            }
        }

        SysConsoleBridge::getInstance()->
    }

}
