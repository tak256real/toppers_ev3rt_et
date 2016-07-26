///////////////////////////////////////////////////////////
//  SerialCom.cpp
//  Implementation of the Class SerialCom
//  Created on:      2016/05/26 13:07:03
//  Original author: 037789
///////////////////////////////////////////////////////////

#include "SerialCom.h"

SerialCom::SerialCom()
    : the_tx_buff(NULL),
      the_rx_buff(NULL)
{

}



SerialCom::~SerialCom(){

}





void SerialCom::doInitialze(){
    actInitialze();
}


void SerialCom::doComOpen(){

}


/**
 * 今回、シリアルは Buletooth の SSP による仮想シリアルとなる. 通常のシリアルとは制御が異なるため、サブクラス化の余地を残すがそのまま実装する.
 */
void SerialCom::actInitialze(){
    
}

void SerialCom::ntfTimeOut(EmTiemrId rv_timer_id){
    actTimeOut(rv_timer_id);
}

void SerialCom::actTimeOut(EmTiemrId rv_timer_id){

}


