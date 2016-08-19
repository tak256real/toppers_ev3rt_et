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
	m_StartDistance = m_UltrasonicControl->getUltrasonicValue();
}


bool DistanceToObjectCondition::check(){

	bool ret = false;

	// ğŒ”»’è
	if(m_DistanceDifference < 0 &&  m_UltrasonicControl->getUltrasonicValue() <= m_StartDistance + m_DistanceDifference) {			// Œ¸­•ûŒü
		ret = true;
	}
	else if(0 <= m_DistanceDifference &&  m_StartDistance + m_DistanceDifference <= m_UltrasonicControl->getUltrasonicValue()) {	// ‘‰Á•ûŒü
		ret = true;
	}

	return ret;
}
