///////////////////////////////////////////////////////////
//  Calibration.cpp
//  Implementation of the Class Calibration
//  Created on:      2016/06/17 11:04:46
//  Original author: 039918
///////////////////////////////////////////////////////////

#include "Calibration.h"

#define BAND_MAX		700
#define BAND_MIN		500


Calibration::Calibration(){

}



Calibration::~Calibration(){

}




int Calibration::BandAdjustment(){

	light_value_black = ev3_color_sensor_get_ambient (EV3_PORT_1); 
	
	
	return 0;
}