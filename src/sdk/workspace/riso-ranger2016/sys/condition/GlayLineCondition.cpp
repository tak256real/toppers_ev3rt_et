/*
 * GlayLineCondition.cpp
 *
 *  Created on: 2016/08/31
 *      Author: Reina
 */

#include "GlayLineCondition.h"


/**
 * 指定なし。グレーラインを検知した瞬間のみ真となる。
 */
GlayLineCondition::GlayLineCondition(){
	m_ColorValue = 0;
	m_ColorValuePrev = 0;
	m_Count = 0;
	
	ColorValueArray[9] = {0};
	//float ColorValueArray[9] = {0};

}



GlayLineCondition::~GlayLineCondition(){

}



void GlayLineCondition::onStart(){

}


bool GlayLineCondition::check(){

	bool ret = false;

	m_ColorValue = m_StateObserver->GetLinePosition();
	
	ColorValueArray[m_Count] = m_ColorValue;
	
	//m_ColorValueDif  = m_ColorValue - m_ColorValuePrev;
	//m_ColorValuePrev = m_ColorValue;
	
	m_Count++;
	
	if (m_Count == c_arrayNum + 1){
		m_Count = 0;
	}

	m_ColorValuePrev = ColorValueArray[m_Count];
	
	m_ColorValueDif  = m_ColorValue - m_ColorValuePrev;
	
	// 条件判定
	if(m_ColorValue < c_dif){
		ret = true;
	}
	
	return ret;
	
}
