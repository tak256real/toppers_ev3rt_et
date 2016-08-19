/*
 * DistanceToObjectCondition.cpp
 *
 *  Created on: 2016/08/125
 *      Author: Reina
 */

#include "DistanceToObjectCondition.h"


/**
 * �ʒu�ϕ��w��
 */
DistanceToObjectCondition::DistanceToObjectCondition(int distanceDifference){
	m_DistanceDifference = distanceDifference;
}



DistanceToObjectCondition::~DistanceToObjectCondition(){

}



void DistanceToObjectCondition::onStart(){

	// ������擾
	m_StartDistance = m_UltrasonicControl->getUltrasonicValue();
}


bool DistanceToObjectCondition::check(){

	bool ret = false;

	// ��������
	if(m_DistanceDifference < 0 &&  m_UltrasonicControl->getUltrasonicValue() <= m_StartDistance + m_DistanceDifference) {			// ��������
		ret = true;
	}
	else if(0 <= m_DistanceDifference &&  m_StartDistance + m_DistanceDifference <= m_UltrasonicControl->getUltrasonicValue()) {	// ��������
		ret = true;
	}

	return ret;
}
