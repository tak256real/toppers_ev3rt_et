///////////////////////////////////////////////////////////
//  InclinationCondition.cpp
//  Implementation of the Class InclinationCondition
//  Created on:      2016/08/03 12:28:34
//  Original author: 039389
///////////////////////////////////////////////////////////

#include "InclinationCondition.h"

/**
 * –Ú•WŒXÎw’è
 */
InclinationCondition::InclinationCondition(int inclinationTarget){
	m_InclinationTarget = inclinationTarget;
}



InclinationCondition::~InclinationCondition(){

}



void InclinationCondition::onStart(){

	// Šî€ŒXÎæ“¾
	m_StartInclination = m_StateObserver->GetInclination();

}


bool InclinationCondition::check(){

	bool ret = false;

	// ğŒ”»’è
	

	return ret;

}
