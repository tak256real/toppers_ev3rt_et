///////////////////////////////////////////////////////////
//  GetSensorValue.cpp
//  Implementation of the Class GetSensorValue
//  Created on:      2016/07/05 11:43:06
//  Original author: 039918
///////////////////////////////////////////////////////////

#include "GetSensorValue.h"


GetSensorValue::GetSensorValue(sensor_port_t port){
	// メンバ初期化
	m_Port = port;

	//カラーセンサを初期化
	ev3_sensor_config(m_Port, COLOR_SENSOR);
}


GetSensorValue::~GetSensorValue(){

}


int GetSensorValue::getSensorValue(){
	return ev3_color_sensor_get_reflect(m_Port); //カラーセンサから明度を取得;EV3_PORT_2
}
