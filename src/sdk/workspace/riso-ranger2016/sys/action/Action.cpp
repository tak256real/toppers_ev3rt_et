///////////////////////////////////////////////////////////
//  Action.cpp
//  Implementation of the Class Action
//  Created on:      2016/07/27 11:47:44
//  Original author: 039389
///////////////////////////////////////////////////////////

#include "Action.h"




Action::Action(){

}


Action::~Action(){

}


void Action::init(StateObserver* stateObserver, TailControl* tailControl, WheelControl* wheelControl){
	m_StateObserver = stateObserver;
	m_TailControl = tailControl;
	m_WheelControl = wheelControl;

}

void Action::EmergencyStop(){

}


StateObserver* Action::getStateObserver(){
	return m_StateObserver;
}


TailControl* Action::getTailControl(){
	return m_TailControl;
}


WheelControl* Action::getWheelControl(){
	return m_WheelControl;
}
