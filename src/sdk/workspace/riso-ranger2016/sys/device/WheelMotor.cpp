///////////////////////////////////////////////////////////
//  WheelMotor.cpp
//  Implementation of the Class WheelMotor
//  Created on:      2016/07/15 16:04:16
//  Original author: 039889
///////////////////////////////////////////////////////////

#include "WheelMotor.h"


WheelMotor::WheelMotor(motor_port_t PortNum){

	//TODO ポート設定

}


WheelMotor::~WheelMotor(){

}


void WheelMotor::ResetEnc(){

	//TODO エンコーダリセット

}


/**
 * エンコーダ値を取得
 */
int WheelMotor::GetEnc(){

	//TODO
	return 0;

}


void WheelMotor::SetPWMValue(signed char PWMValue){

	// 範囲チェック
	if(PWMValue < -100) {
		PWMValue = -100;
	}
	else if(100 < PWMValue) {
		PWMValue = 100;
	}

	//TODO PWM設定

}
