///////////////////////////////////////////////////////////
//  Action.cpp
//  Implementation of the Class Action
//  Created on:      2016/07/27 11:47:44
//  Original author: 039389
///////////////////////////////////////////////////////////

#include "Action.h"


StateObserver* Action::m_StateObserver;
TailControl* Action::m_TailControl;
WheelControl* Action::m_WheelControl;

Action::Action(){

}


Action::~Action(){

}


void Action::init(StateObserver* stateObserver, TailControl* tailControl, WheelControl* wheelControl){
	Action::m_StateObserver = stateObserver;
	Action::m_TailControl = tailControl;
	Action::m_WheelControl = wheelControl;

}

void Action::EmergencyStop(){

	// 尻尾、左右車輪を停止
	Action::m_TailControl->SetRefValue(90);
	Action::m_WheelControl->SetTwoWheelMode(false);
	Action::m_WheelControl->SetRefValue(0, 0);

}
