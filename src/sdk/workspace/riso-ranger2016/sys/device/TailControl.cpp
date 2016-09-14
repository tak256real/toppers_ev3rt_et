///////////////////////////////////////////////////////////
//  TailControl.cpp
//  Implementation of the Class TailControl
//  Created on:      2016/07/21 20:55:36
//  Original author: 039389
///////////////////////////////////////////////////////////

#include "TailControl.h"
#include "Bluetooth.h"


TailControl::TailControl(Motor* tailMotor){

	m_TailMotor = tailMotor;
	m_RefAngle = 0;

}



TailControl::~TailControl(){

}



void TailControl::init() {
	// エンコーダ初期化
	m_TailMotor->ResetEnc();
}

void TailControl::Control(){

	int pwm;
	
	// Duty比算出
	pwm = (m_RefAngle - m_TailMotor->GetEnc())*0.6; // 比例制御
	fprintf(btlog,"TailControl Duty = %d \n\r",pwm);
	// Duty比設定
	m_TailMotor->SetPWMValue(pwm);
	fprintf(btlog,"TailControl m_RefAngle = %d \n\r",m_RefAngle);

}


bool TailControl::earthingDetection(){

	// 比例制御で一定以上の誤差があるとき接地していると判断
	if(m_RefAngle - m_TailMotor->GetEnc() < TailControl::c_EarthingThreshold) {
		return false;
	}
	else {
		return true;
	}

}


void TailControl::SetRefValue(int angle){
	m_RefAngle = angle;
}
