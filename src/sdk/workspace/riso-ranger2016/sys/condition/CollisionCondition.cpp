///////////////////////////////////////////////////////////
//  CollisionCondition.cpp
//  Implementation of the Class CollisionCondition
//  Created on:      2016/08/03 12:28:36
//  Original author: 039389
///////////////////////////////////////////////////////////

#include "CollisionCondition.h"


CollisionCondition::CollisionCondition(){
	
}



CollisionCondition::~CollisionCondition(){

}


void CollisionCondition::onStart(){

}


bool CollisionCondition::check(){

	m_Velocity = m_StateObserver->getVelocity();
	m_VelocityPrev = m_Velocity;
	
	m_Aacceleration = m_Velocity - m_VelocityPrev;
	m_AaccelerationPrev = m_Aacceleration;
	
	m_AaccelerationDifference = m_Aacceleration - m_AaccelerationPrev;
	
	
	bool ret = false;

	// ğŒ”»’è
	if(m_AaccelerationDifference < c_dif) {
		ret = true;
	}

	return ret;
}
