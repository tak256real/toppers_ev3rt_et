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
	m_speed = 50;
	m_referenceVal = 0.5;
}


Linetrace::~Linetrace(){

}


void Linetrace::exec(){
	static bool motorFlag = true;
	int turn = 0;
	float currentVal = 0;

	if(motorFlag == true){  //TODO 走行開始時に実行
		m_WheelControl->SetTwoWheelMode(motorFlag);
		motorFlag = false;
	}

	currentVal = m_Calibration->GetNormalizedSensorValue();
	turn = m_PidControl->PIDCalculation(m_referenceVal, currentVal);
	m_WheelControl->SetRefValue(m_speed, turn);
}
