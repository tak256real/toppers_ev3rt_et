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
	m_motorFlag =true;
	m_speed = 50;
	m_referenceVal = 0.5;
}


Linetrace::~Linetrace(){

}


void Linetrace::exec(){
	int turn = 0;
	float currentVal = 0;

	if(motorFlag == true){
		m_WheelControl->SetTwoWheelMode(motorFlag);
		motorFlag = false;
	}

	currencVal = m_Calibration->GetNormalizedSensorValue();
	turn = m_PidControl->PIDCalculation(referenceVal, currentVal);
	m_WheelControl->SetTwoWheelMode(speed,turn);
}
