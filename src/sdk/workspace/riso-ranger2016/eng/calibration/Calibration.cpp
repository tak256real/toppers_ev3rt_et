///////////////////////////////////////////////////////////
//  Calibration.cpp
//  Implementation of the Class Calibration
//  Created on:      2016/07/05 11:43:06
//  Original author: 039918
///////////////////////////////////////////////////////////

#include "Calibration.h"


Calibration::Calibration(GetSensorValue* getSensorValue){
	// メンバ初期化
	m_GetSensorValue = getSensorValue;
	m_LightValueMax = 100;
	m_LightValueMin = 0;
	m_CalibrationIndex = 0;
}


Calibration::~Calibration(){

}


void Calibration::onPressed(){

	if(m_CalibrationIndex == 0) {	// 白
		this->ConfigureWhiteValue();
		m_CalibrationIndex++;
	}
	else {							// 黒
		this->ConfigureLineValue();
		m_CalibrationIndex = 0;
	}

}


void Calibration::onReleased(){

}


float Calibration::GetNormalizedSensorValue(){
	
	//bool_t isPressed = ev3_touch_sensor_is_pressed(EV3_PORT_1); //タッチセンサの状態検出

	// 光センサ値を正規化
	float normalizedSensorValue = (m_GetSensorValue->getSensorValue() - m_LightValueMin) / m_LightValueMax;

	// 範囲チェック＆丸め込み
	if(normalizedSensorValue < 0.0) {
		normalizedSensorValue = 0;
	}
	else if(1.0 < normalizedSensorValue) {
		normalizedSensorValue = 1.0;
	}

	return normalizedSensorValue;

}


// private method

void Calibration::ConfigureWhiteValue(){
	m_LightValueMin = m_GetSensorValue->getSensorValue();
}


void Calibration::ConfigureLineValue(){
	m_LightValueMax = m_GetSensorValue->getSensorValue();
}
