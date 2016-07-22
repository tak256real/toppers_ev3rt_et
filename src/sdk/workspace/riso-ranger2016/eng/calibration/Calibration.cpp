///////////////////////////////////////////////////////////
//  Calibration.cpp
//  Implementation of the Class Calibration
//  Created on:      2016/07/05 11:43:06
//  Original author: 039918
///////////////////////////////////////////////////////////

//#include <kernel.h>
//#include "ev3api.h"
#include "Calibration.h"


Calibration::Calibration(){

}



Calibration::~Calibration(){

}

uint8_t Calibration::GetLightValue(){
	
	bool_t isPressed = ev3_touch_sensor_is_pressed(EV3_PORT_1); //タッチセンサの状態検出
	if( isPressed == true){
		ev3_sensor_config(EV3_PORT_2, COLOR_SENSOR); //カラーセンサを初期化
		uint8_t light = ev3_color_sensor_get_reflect(EV3_PORT_2); //カラーセンサから明度を取得

		return(light);
	}	
	
}

uint8_t Calibration::SendLightValue(uint8_t lightValueMax, uint8_t lightValueMin){
	
	return 0;
}
