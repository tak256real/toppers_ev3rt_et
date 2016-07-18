///////////////////////////////////////////////////////////
//  WheelMotor.cpp
//  Implementation of the Class WheelMotor
//  Created on:      2016/07/15 16:04:16
//  Original author: 039889
///////////////////////////////////////////////////////////

#include "WheelMotor.h"


WheelMotor::WheelMotor(motor_port_t PortNum){

	// メンバ初期化
	m_AngularVelocity = 0;
	m_WheelEncBuf = new int[26];
	for(int i=0; i<26; i++) this->m_WheelEncBuf[i] = 0;
	m_WheelEncBufNextIndex = 0;

	motor = new Motor(PortNum);

	//TODO ポート設定

}


WheelMotor::~WheelMotor(){

}


/**
 * 角速度[deg/sec]計算
 * 4ms周期で呼び出しが必要
 */
void WheelMotor::UpdateAngularVelocity(){

	// 角速度[deg/sec]を更新（0.1sec間の角度degの差から角速度[deg/sec]を計算）
	m_WheelEncBuf[m_WheelEncBufNextIndex] = GetEnc();
	m_AngularVelocity = (m_WheelEncBuf[m_WheelEncBufNextIndex] - m_WheelEncBuf[(m_WheelEncBufNextIndex+1)%26]) * 10;
	m_WheelEncBufNextIndex++;
	if(26 <= m_WheelEncBufNextIndex) {
		m_WheelEncBufNextIndex = 0;
	}

}


/**
 * エンコーダリセット
 * TODO 実行後0.１秒間、角速度が０になる
 */
void WheelMotor::ResetEnc(){

	//TODO エンコーダリセット

	// 角速度関連メンバを初期化
	m_AngularVelocity = 0;
	m_WheelEncBuf = new int[26];
	for(int i=0; i<26; i++) this->m_WheelEncBuf[i] = 0;
	m_WheelEncBufNextIndex = 0;

}


/**
 * エンコーダ値を取得
 */
int WheelMotor::GetEnc(){

	//TODO エンコーダ値を取得
	return 0;

}


/**
 * 角速度[deg/sec]を取得
 */
int WheelMotor::GetAngularVelocity(){
	return m_AngularVelocity;
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
