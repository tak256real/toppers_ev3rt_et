/*
 * DistanceToObjectCondition.cpp
 *
 *  Created on: 2016/08/125
 *      Author: Reina
 */

#include "DistanceToObjectCondition.h"


/**
 * ˆÊ’u•Ï•ªw’è
 */
DistanceToObjectCondition::DistanceToObjectCondition(int distanceDifference){
	m_DistanceDifference = distanceDifference;
}



DistanceToObjectCondition::~DistanceToObjectCondition(){

}



void DistanceToObjectCondition::onStart(){

	// Šî€‹——£æ“¾
	m_StartDistance = m_StateObserver->GetObjectDistance();
}


bool DistanceToObjectCondition::check(){

	bool ret = false;

	// ğŒ”»’è
	if(m_DistanceDifference < 0 &&  m_StateObserver->GetObjectDistance() <= m_StartDistance + m_DistanceDifference) {			// Œ¸­•ûŒü
		ret = true;
	}
	else if(0 <= m_DistanceDifference &&  m_StartDistance + m_DistanceDifference <= m_StateObserver->GetObjectDistance()) {	// ‘‰Á•ûŒü
		ret = true;
	}

	return ret;
}
