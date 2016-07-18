///////////////////////////////////////////////////////////
//  WheelControl.cpp
//  Implementation of the Class WheelControl
//  Created on:      2016/07/15 16:04:13
//  Original author: 039889
///////////////////////////////////////////////////////////

#include "WheelControl.h"




WheelControl::WheelControl(){
	m_RefSpeed = 0;
	m_RefTurn = 0;
	m_WheelMotorL = NULL;
	m_WheelMotorR = NULL;
	m_TwoWheelMode = false;
}


WheelControl::~WheelControl(){

}


// 4ms周期実行 要リアルタイム性
void WheelControl::Control(){

	if(m_TwoWheelMode == true) {	// 倒立走行

	}
	else {							// 尻尾走行

	}

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
