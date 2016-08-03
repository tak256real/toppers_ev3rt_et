///////////////////////////////////////////////////////////
//  Sequencer.cpp
//  Implementation of the Class Sequencer
//  Created on:      2016/08/03 12:01:55
//  Original author: 039389
///////////////////////////////////////////////////////////

#include "Sequencer.h"
#include "Action.h"
#include "Sequence.h"



Sequencer::Sequencer(){

	// メンバ初期化
	m_CurrentSequence = new DefaultSequence();  //TODO 初期シーケンス

}


Sequencer::~Sequencer(){

}


void Sequencer::startSequence(Sequence* sequence){

	m_CurrentSequence = sequence;

}


void Sequencer::cycle(){

	// 現在のActionの周期処理実行
	m_CurrentSequence->getAction()->onCycle();

	// 現在のConditionの判定処理実行
	if(m_CurrentSequence->getCondition()->check()) {

		// 旧Action終了処理実行
		m_CurrentSequence->getAction()->onStop();

		// 現在のActionインスタンス取り出し
		Action* action = m_CurrentSequence->getAction();

		// 次のシーケンス取得
		Sequence* sequence = m_CurrentSequence->getNextSequence();

		// Actionインスタンスの関連引き継ぎ
		sequence->getAction()->init(action->getStateObserver(), action->getTailControl(), action->getWheelControl());

		// 旧シーケンスdelete
		delete m_CurrentSequence;//TODO Sequence内でaction conditionをdelete

		// 現在のSequenceを更新
		m_CurrentSequence = sequence;

		// 新Action開始処理実行
		m_CurrentSequence->getAction()->onStart();

	}

}

