/*
 * StateObserver.cpp
 *
 *  Created on: 2016/07/24
 *      Author: ryuji
 */

#include "StateObserver.h"

StateObserver::StateObserver(Motor* wheelMotorL, Motor* wheelMotorR, Motor* tailMotor, Calibration* calibration) {
	// メンバ初期化
	m_WheelMotorL = wheelMotorL;
	m_WheelMotorR = wheelMotorR;
	m_TailMotor = tailMotor;
	m_Calibration = calibration;
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
	return m_Calibration->GetNormalizedSensorValue();
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