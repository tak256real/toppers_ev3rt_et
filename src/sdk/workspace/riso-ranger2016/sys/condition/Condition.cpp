///////////////////////////////////////////////////////////
//  Condition.cpp
//  Implementation of the Class Condition
//  Created on:      2016/08/03 12:28:24
//  Original author: 039389
///////////////////////////////////////////////////////////

#include "Condition.h"


StateObserver* Condition::m_StateObserver;

Condition::Condition(){

}



Condition::~Condition(){

}


void Condition::init(StateObserver *stateObserver){
	Condition::m_StateObserver = stateObserver;
}
