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

void Action::EmergencyStop(){

}


void Action::setStateObserver(StateObserver* stateObserver){
	m_StateObserver = stateObserver;
}


StateObserver* Action::getStateObserver(){
	return m_StateObserver;
}


void Action::setTailControl(TailControl* tailControl){
	m_TailControl = tailControl;
}


TailControl* Action::getTailControl(){
	return m_TailControl;
}


void Action::setWheelControl(WheelControl* wheelControl){
	m_WheelControl = wheelControl;
}


WheelControl* Action::getWheelControl(){
	return m_WheelControl;
}
