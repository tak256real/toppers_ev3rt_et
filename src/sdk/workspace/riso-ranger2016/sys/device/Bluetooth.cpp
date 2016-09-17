///////////////////////////////////////////////////////////
//  Motor.cpp
//  Implementation of the Class Motor
//  Created on:      2016/07/26 18:58:12
//  Original author: 039389
///////////////////////////////////////////////////////////
#include "ev3api.h"

#include "Bluetooth.h"

FILE *btlog = NULL;


void console_task(intptr_t unused) {

    btlog = ev3_serial_open_file(EV3_SERIAL_BT);
    
	while(1) {
		while (!ev3_bluetooth_is_connected()) tslp_tsk(100);
		char c = fgetc(btlog);
		switch(c) {
            case 's':
                fprintf(btlog, "Bluetooth Start");
            break;
            case 'w':
                fprintf(btlog, "hello world\r\n");
                break;
            default:
                fprintf(btlog, "Unknown key '%c' pressed.\r\n", c);
                break;
		}
	}
}
