///////////////////////////////////////////////////////////
//  InclinationCondition.cpp
//  Implementation of the Class InclinationCondition
//  Created on:      2016/08/03 12:28:34
//  Original author: 039389
///////////////////////////////////////////////////////////

#include "InclinationCondition.h"

/**
 * �ڕW�X�Ύw��
 */
InclinationCondition::InclinationCondition(int inclinationTarget){
	m_InclinationTarget = inclinationTarget;
}



InclinationCondition::~InclinationCondition(){

}



void InclinationCondition::onStart(){

	// ��X�Ύ擾
	m_StartInclination = m_StateObserver->GetInclination();

}


bool InclinationCondition::check(){

	bool ret = false;

	// ��������
	

	return ret;

}
