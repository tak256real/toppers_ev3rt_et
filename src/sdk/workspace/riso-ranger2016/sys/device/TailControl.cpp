///////////////////////////////////////////////////////////
//  TailControl.cpp
//  Implementation of the Class TailControl
//  Created on:      2016/07/21 20:55:36
//  Original author: 039389
///////////////////////////////////////////////////////////

#include "TailControl.h"


TailControl::TailControl(WheelMotor* tailMotor){

	m_TailMotor = tailMotor;
	m_RefAngle = 0;

}



TailControl::~TailControl(){

}





void TailControl::Control(){

	int pwm;

	// Dity比算出
	pwm = m_RefAngle - m_TailMotor->GetEnc();

	// Duty比設定
	m_TailMotor->SetPWMValue(pwm);

}


void TailControl::SetRefValue(int angle){
	m_RefAngle = angle;
}
