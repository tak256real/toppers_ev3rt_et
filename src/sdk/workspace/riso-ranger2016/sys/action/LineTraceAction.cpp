///////////////////////////////////////////////////////////
//  LineTraceAction.cpp
//  Implementation of the Class LineTraceAction
//  Created on:      2016/07/27 11:47:53
//  Original author: 039389
///////////////////////////////////////////////////////////

#include "LineTraceAction.h"


LineTraceAction::LineTraceAction(){
	// メンバ初期化
	m_PidControl = new PIDControl();
	m_speed = 100;
	m_referenceVal = 0.5;

	// 倒立モードに切り替え
	m_WheelControl->SetTwoWheelMode(true);
}


LineTraceAction::~LineTraceAction(){

}


void LineTraceAction::cycle(){

	int turn = 0;
	float currentVal = 0;

	// 現在のライン位置を取得
	currentVal = m_StateObserver->GetLinePosition();

	// 旋回量を算出
	turn = m_PidControl->PIDCalculation(m_referenceVal, currentVal);

	// 前進量,旋回量を設定
	m_WheelControl->SetRefValue(m_speed, turn);

}
