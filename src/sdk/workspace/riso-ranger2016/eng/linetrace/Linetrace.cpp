///////////////////////////////////////////////////////////
//  Linetrace.cpp
//  Implementation of the Class Linetrace
//  Created on:      2016/07/22 19:45:31
//  Original author: 039889
///////////////////////////////////////////////////////////

#include "Linetrace.h"



Linetrace::Linetrace(WheelControl* wheelControl, Calibration* calibration){
	m_PidControl = new PIDControl();
	m_WheelControl = wheelControl;
	m_Calibration = calibration;
	m_speed = 100;
	m_referenceVal = 0.5;

	// 倒立モードに切り替え
	m_WheelControl->SetTwoWheelMode(true);
}


Linetrace::~Linetrace(){

}


void Linetrace::exec(){

	int turn = 0;
	float currentVal = 0;

	currentVal = m_Calibration->GetNormalizedSensorValue();
	turn = m_PidControl->PIDCalculation(m_referenceVal, currentVal);
	//printf("currenval=%f,trun=%d\n",currentVal,turn);
	m_WheelControl->SetRefValue(m_speed, turn);
}
