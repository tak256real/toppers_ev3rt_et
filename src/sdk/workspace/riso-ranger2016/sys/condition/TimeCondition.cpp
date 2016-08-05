/*
 * TimeCondition.cpp
 *
 *  Created on: 2016/08/05
 *      Author: ryuji
 */

#include "TimeCondition.h"
#include "Timer.h"

TimeCondition::TimeCondition(unsigned int milliSecondLength) {

	// メンバ初期化
	m_StartMilliSecond = 0;
	m_MilliSecondLength = milliSecondLength;

}

TimeCondition::~TimeCondition() {

}


void TimeCondition::onStart(){

	// 開始時刻を取得
	m_StartMilliSecond = Timer::getInstance()->getAbsoluteTime();
}


bool TimeCondition::check(){

	bool ret = false;

	if(m_StartMilliSecond + m_MilliSecondLength < Timer::getInstance()->getAbsoluteTime()) {
		ret = true;
	}

	return ret;

}
