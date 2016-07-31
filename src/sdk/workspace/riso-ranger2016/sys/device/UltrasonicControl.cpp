///////////////////////////////////////////////////////////
//  LUltrasonicControl.cpp
//  Implementation of the Class LUltrasonicControl
//  Created on:      2016/07/15 16:04:13
//  Original author: 039889
///////////////////////////////////////////////////////////

#include "UltrasonicControl.h"


UltrasonicControl::UltrasonicControl(sensor_port_t PortNum){
	m_Port = PortNum;
}


UltrasonicControl::~UltrasonicControl(){

}
int16_t UltrasonicControl::getUltrasonicValue(){
	int16_t ultrasonicValue=0;
	ultrasonicValue = ev3_ultrasonic_sensor_get_distance(m_Port);
	return ultrasonicValue;
}

