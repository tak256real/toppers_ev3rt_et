/*
 * StateObserver.cpp
 *
 *  Created on: 2016/07/24
 *      Author: ryuji
 */

#include "StateObserver.h"

StateObserver::StateObserver(Motor* wheelMotorL, Motor* wheelMotorR, Motor* tailMotor, ColorSensor* colorSensor) {
	// メンバ初期化
	m_ColorSensor = colorSensor;
	m_WheelMotorL = wheelMotorL;
	m_WheelMotorR = wheelMotorR;
	m_TailMotor = tailMotor;
	m_LightValueMax = 60;	// TODO キャリブレーション時に設定
	m_LightValueMin = 2;	// TODO キャリブレーション時に設定
	m_Direction = 0;
	m_RunningDistance = 0;
}

StateObserver::~StateObserver() {

}


void StateObserver::Calc() {
	// 方位[deg]
	m_Direction += (m_WheelMotorL->GetAngularVelocity() - m_WheelMotorR->GetAngularVelocity())*c_DirCalcCoefficient;

	// 走行距離[mm]
	m_RunningDistance += (m_WheelMotorL->GetAngularVelocity() + m_WheelMotorR->GetAngularVelocity())*c_RunDisCalcCoefficient;
}


float StateObserver::GetLinePosition() {

	// 光センサ値を正規化した値＝ライン位置
	float normalizedSensorValue = ((float)m_ColorSensor->getSensorValue() - (float)m_LightValueMin) /( (float)m_LightValueMax- (float)m_LightValueMin);

	// 範囲チェック＆丸め込み
	if(normalizedSensorValue < 0.0) {
		normalizedSensorValue = 0;
	}
	else if(1.0 < normalizedSensorValue) {
		normalizedSensorValue = 1.0;
	}

	return normalizedSensorValue;
}


int StateObserver::GetTailAngularVelocity() {
	return m_TailMotor->GetAngularVelocity();
}


int StateObserver::GetRunningDistance() {
	return m_RunningDistance;
}


int StateObserver::GetDirection() {
	return m_Direction;
}



int StateObserver::getTilt(){

	return 0;
}
