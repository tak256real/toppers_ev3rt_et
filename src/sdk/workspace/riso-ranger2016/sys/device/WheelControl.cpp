///////////////////////////////////////////////////////////
//  WheelControl.cpp
//  Implementation of the Class WheelControl
//  Created on:      2016/07/15 16:04:13
//  Original author: 039889
///////////////////////////////////////////////////////////

#include "WheelControl.h"
#include "balancer.h"

#include "Temp.h"

WheelControl::WheelControl(WheelMotor* wheelMotorL, WheelMotor* wheelMotorR){
	m_RefSpeed = 0;
	m_RefTurn = 0;
	m_WheelMotorL = NULL;
	m_WheelMotorR = NULL;
	m_TwoWheelMode = false;
	m_WheelMotorL = wheelMotorL;
	m_WheelMotorR = wheelMotorR;
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
			(float)Temp::getGyro(),//gyro,TODO どこから取得するか
			(float)Temp::getGyroOffset(),//GYRO_OFFSET,TODO どこから取得するか
			(float)m_WheelMotorL->GetEnc(),
			(float)m_WheelMotorR->GetEnc(),
			(float)Temp::getBattery(),//volt, TODO どこから取得するか
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


/**
 * 倒立走行と尻尾走行の切り替え
 */
void WheelControl::SetTwoWheelMode(bool onoff){

	if(m_TwoWheelMode == false && onoff == true) {
	    // 倒立振子制御初期化
		balance_init();
		//TODO エンコーダも初期化が必要かもしれない
	}

	m_TwoWheelMode = onoff;
}
