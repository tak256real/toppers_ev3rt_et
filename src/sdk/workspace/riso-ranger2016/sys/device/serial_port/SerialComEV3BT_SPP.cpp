///////////////////////////////////////////////////////////
//  SerialComEV3BT_SPP.cpp
//  Implementation of the Class SerialComEV3BT_SPP
//  Created on:      2016/05/26 13:31:04
//  Original author: 037789
///////////////////////////////////////////////////////////

#include "SerialComEV3BT_SPP.h"


SerialComEV3BT_SPP::SerialComEV3BT_SPP()
    : SerialCom()
{

}



SerialComEV3BT_SPP::~SerialComEV3BT_SPP(){

}





void SerialComEV3BT_SPP::actInitialze(){
    /* Open Bluetooth file */
    tty = ev3_serial_open_file(EV3_SERIAL_BT);
    assert(tty != NULL);
}
