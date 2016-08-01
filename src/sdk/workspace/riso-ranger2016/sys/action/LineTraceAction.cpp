///////////////////////////////////////////////////////////
//  LineTraceAction.cpp
//  Implementation of the Class LineTraceAction
//  Created on:      2016/07/27 11:47:53
//  Original author: 039389
///////////////////////////////////////////////////////////

#include "LineTraceAction.h"


LineTraceAction::LineTraceAction(){

}


LineTraceAction::~LineTraceAction(){

}



void LineTraceAction::onStart(){

	// メンバ初期化
	m_PidControl = new PIDControl(80, 0, 80);
	m_Speed = 100;
	m_ReferenceLinePosition = 0.5;
	m_TailAngle = 0;

	// 倒立モードに切り替え
	m_WheelControl->SetTwoWheelMode(true);

}


void LineTraceAction::onCycle(){

	int turn = 0;
	float currentLinePosition = 0;

	// 現在のライン位置を取得
	currentLinePosition = m_StateObserver->GetLinePosition();

	// 旋回量を算出
	turn = m_PidControl->PIDCalculation(m_ReferenceLinePosition, currentLinePosition);

	// 前進量,旋回量を設定
	m_WheelControl->SetRefValue(m_Speed, turn);

	// 尻尾角度を設定
	m_TailControl->SetRefValue(m_TailAngle);

}


void LineTraceAction::onStop(){

	// PIDインスタンス削除
	delete m_PidControl;

}
