/*
 * GlayLineCondition.cpp
 *
 *  Created on: 2016/08/31
 *      Author: Reina
 */

#include "GlayLineCondition.h"


/**
 * �w��Ȃ��B�O���[���C�������m�����u�Ԃ̂ݐ^�ƂȂ�B
 */
GlayLineCondition::GlayLineCondition(){
	m_ColorValue = 0;
	m_ColorValuePrev = 0;
}



GlayLineCondition::~GlayLineCondition(){

}



void GlayLineCondition::onStart(){

}


bool GlayLineCondition::check(){

	bool ret = false;

	m_ColorValue = m_StateObserver->GetLinePosition();
	
	m_ColorValueDif = m_ColorValue - m_ColorValuePrev;
	m_ColorValuePrev = m_ColorValue;
	
	// ��������
	if(m_ColorValue < c_dif){
		ret = true;
	}
	
	return ret;
}
