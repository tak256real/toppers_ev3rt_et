///////////////////////////////////////////////////////////
//  WheelControl.cpp
//  Implementation of the Class WheelControl
//  Created on:      2016/07/15 16:04:13
//  Original author: 039889
///////////////////////////////////////////////////////////

#include "WheelControl.h"
#include "balancer.h"



WheelControl::WheelControl(){
	m_RefSpeed = 0;
	m_RefTurn = 0;
	m_WheelMotorL = NULL;
	m_WheelMotorR = NULL;
	m_TwoWheelMode = false;
}


WheelControl::~WheelControl(){

}


void WheelControl::Init(){

	// モータエンコーダをリセットする
    m_WheelMotorL->ResetEnc();
    m_WheelMotorR->ResetEnc();

    // 倒立振子制御初期化
	balance_init();
}


// 4ms周期実行 要リアルタイム性
void WheelControl::Control(){

	signed char pwm_L;
	signed char pwm_R;

	if(m_TwoWheelMode == true) {	// 倒立走行

		//TODO Duty比算出
        balance_control(
            (float)m_RefSpeed,
            (float)m_RefTurn,
            (float)0,//gyro,
            (float)0,//GYRO_OFFSET,
			(float)m_WheelMotorL->GetEnc(),
			(float)m_WheelMotorR->GetEnc(),
            (float)0,//volt,
            &pwm_L,
            &pwm_R);

	}
	else {							// 尻尾走行

		pwm_L = m_RefSpeed + m_RefTurn*1.0;
		pwm_R = m_RefSpeed - m_RefTurn*1.0;

	}

	// Duty比設定
	m_WheelMotorL->SetPWMValue(pwm_L);
	m_WheelMotorR->SetPWMValue(pwm_R);

}


// 同時変更必要
void WheelControl::SetRefValue(int speed, int turn){
	m_RefSpeed = speed;
	m_RefTurn = turn;
}


void WheelControl::SetTwoWheelMode(bool onoff){
	m_TwoWheelMode = onoff;
}


void WheelControl::SetWheelMotorL(WheelMotor* wheelMotorL) {
	m_WheelMotorL = wheelMotorL;
}


void WheelControl::SetWheelMotorR(WheelMotor* wheelMotorR) {
	m_WheelMotorR = wheelMotorR;
}
