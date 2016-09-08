/*
 * GlayLineCondition.cpp
 *
 *  Created on: 2016/08/31
 *      Author: Reina
 */

#include "GlayLineCondition.h"
#include "Bluetooth.h"


/**
 * 指定なし。グレーラインを検知した瞬間のみ真となる。
 */
GlayLineCondition::GlayLineCondition(){
	m_ColorValue = 0;
	m_ColorValuePrev = 0;
	m_Count = 0;
	
	//float ColorValueArray[c_arrayNum];
	ColorValueArray[c_arrayNum] = {0};
	//ColorValueArray[9] = {0};
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
	
	if (m_Count > c_arrayNum){
		m_Count = 0;
//		printf("m_ColorValue = %f\n", m_ColorValue);
	}

	m_ColorValuePrev = ColorValueArray[m_Count];
	
	m_ColorValueDif  = m_ColorValue - m_ColorValuePrev;
	
	fprintf(btlog,"m_ColorValue = %f\r\n", m_ColorValue);
//	fprintf(btlog,"ColorValue = %f\r\n, ColorValueDif = %f\r\n",  ColorValueArray[m_Count],m_ColorValueDif);
	
//	printf("ColorValue=%f\n\n\n", ColorValueArray[m_Count]);
//	printf("ColorValueDif=%f\n\n\n", m_ColorValueDif);

	
	// 条件判定
	if(m_ColorValueDif < c_dif){
		ret = true;
	}
	
	return ret;
	
}
