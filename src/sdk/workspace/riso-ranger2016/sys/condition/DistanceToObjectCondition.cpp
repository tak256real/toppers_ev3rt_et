/*
 * DistanceToObjectCondition.cpp
 *
 *  Created on: 2016/08/12
 *      Author: Reina
 */

#include "DistanceToObjectCondition.h"


/**
 * ��Q���܂ł̋���[cm]���w��
 */
DistanceToObjectCondition::DistanceToObjectCondition(int distance){
	m_Distance = distance;
}



DistanceToObjectCondition::~DistanceToObjectCondition(){

}



void DistanceToObjectCondition::onStart(){

}


bool DistanceToObjectCondition::check(){

	bool ret = false;

	// ��������
	if(m_ultrasonicControl->getUltrasonicValue() <= m_Distance){
		ret = true;
	}
	
/*	
	if(m_DistanceDifference < 0 &&  m_ultrasonicControl->getUltrasonicValue() <= m_StartDistance + m_DistanceDifference) {			// ��������
		ret = true;
		printf("test %d\n\n\n\n\n\n",m_ultrasonicControl->getUltrasonicValue());

	}
	else if(0 <= m_DistanceDifference &&  m_StartDistance + m_DistanceDifference <= m_ultrasonicControl->getUltrasonicValue()) {	// ��������

		
		ret = true;
		printf("test %d\n\n\n\n\n\n",m_ultrasonicControl->getUltrasonicValue());
	

	}
*/
	
	return ret;
}
