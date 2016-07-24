/*
 * StateObserver.cpp
 *
 *  Created on: 2016/07/24
 *      Author: ryuji
 */

#include "StateObserver.h"

StateObserver::StateObserver(WheelMotor* wheelMotorL, WheelMotor* wheelMotorR, WheelMotor* tailMotor) {
	// メンバ初期化
	m_WheelMotorL = wheelMotorL;
	m_WheelMotorR = wheelMotorR;
	m_TailMotor = tailMotor;
	m_direction = 0;
}

StateObserver::~StateObserver() {

}


void StateObserver::Calc() {
	// 方位[deg]
	m_direction += (m_WheelMotorL->GetAngularVelocity() - m_WheelMotorR->GetAngularVelocity())*c_DirCalcCoefficient;
}


int StateObserver::GetDirection() {
}


float StateObserver::GetLinePosition() {
}


int StateObserver::GetTailAngularVelocity() {

}


int StateObserver::GetRunningDistance() {
}
