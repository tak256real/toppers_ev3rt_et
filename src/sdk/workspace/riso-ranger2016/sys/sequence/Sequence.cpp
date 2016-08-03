///////////////////////////////////////////////////////////
//  Sequence.cpp
//  Implementation of the Class Sequence
//  Created on:      2016/08/03 12:27:13
//  Original author: 039389
///////////////////////////////////////////////////////////

#include "Sequence.h"


Sequence::Sequence(Action* action, Condition* condition, Sequence* sequence){

	// メンバ初期化
	m_CurrentAction = action;
	m_CurrentCondition = condition;
	m_NextSequence = sequence;

}


Sequence::~Sequence(){
	delete m_CurrentAction;
	delete m_CurrentCondition;
	delete m_NextSequence;
}


Action* Sequence::getAction(){
	return  m_CurrentAction;
}


Condition* Sequence::getCondition(){
	return  m_CurrentCondition;
}


Sequence* Sequence::getNextSequence(){
	return  m_NextSequence;
}


void Sequence::deleteAllFollowingSequences(){

	// 再起的に後続シーケンスをdelete
	if(m_NextSequence != NULL){
		m_NextSequence->deleteAllFollowingSequences();
	}
	delete m_NextSequence;	// TODO NULLポインタをdeleteしても安全かどうか確認
}
