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
	m_CurrentSequence = new Sequence(new SitWaitAction(), new EndlessCondition(), NULL);  //TODO 初期シーケンス

	// 初期シーケンス開始処理
	m_CurrentSequence->getAction()->onStart();

}


Sequencer::~Sequencer(){

}


void Sequencer::startSequence(Sequence* sequence){

	// シーケンス終了処理
	m_CurrentSequence->getAction()->onStop();

	// シーケンスdelete
	m_CurrentSequence->deleteAllFollowingSequences();
	delete m_CurrentSequence;

	// シーケンス更新
	m_CurrentSequence = sequence;

	// シーケンス初期処理
	m_CurrentSequence->getAction()->onStart();

}


void Sequencer::cycle(){

	// 現在のActionの周期処理実行
	m_CurrentSequence->getAction()->onCycle();

	// 現在のConditionの判定処理実行
	if(m_CurrentSequence->getCondition()->check()) {

		// 現在のActionインスタンス取り出し
		Action* action = m_CurrentSequence->getAction();

		// Action終了処理実行
		action->onStop();

		// 次のシーケンス取得
		Sequence* sequence = m_CurrentSequence->getNextSequence();

		// Actionインスタンスの関連引き継ぎ
		sequence->getAction()->init(action->getStateObserver(), action->getTailControl(), action->getWheelControl());

		// 旧シーケンスdelete
		delete m_CurrentSequence;

		// 現在のSequenceを更新
		m_CurrentSequence = sequence;

		// 新Action開始処理実行
		m_CurrentSequence->getAction()->onStart();

	}

}

