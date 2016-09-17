///////////////////////////////////////////////////////////
//  RightCourseSenario.cpp
//  Implementation of the Class RightCourseSenario
//  Created on:      2016/08/04 13:35:25
//  Original author: 039389
///////////////////////////////////////////////////////////

#include "RightCourseScenario.h"

#include "SitWaitAction.h"
#include "LineTraceAction.h"
#include "TailBrakeAction.h"
#include "RecliningAction.h"
#include "TailRunAction.h"
#include "TailCalibrationAction.h"

#include "TimeCondition.h"
#include "CollisionCondition.h"
#include "DistanceToObjectCondition.h"
#include "InclinationCondition.h"
#include "DistanceCondition.h"
#include "TailStopCondition.h"
#include "EmptyCondition.h"

RightCourseScenario::RightCourseScenario(){

}



RightCourseScenario::~RightCourseScenario(){

}


void RightCourseScenario::start(){

	// シーケンス順設定
	Sequence* sequence;
	Sequence* firstSequence;

	// 尻尾キャリブレーション部
	firstSequence = 							new Sequence(new TailCalibrationAction(),	new TailStopCondition(1000)		);						// 尻尾キャリブレーション
	sequence = firstSequence->setNextSequence(new Sequence(new SitWaitAction(98),			new TimeCondition(4000))			);					// 座って待機

	// スタート部
	sequence = sequence->setNextSequence(	new Sequence(new LineTraceAction(20, 45, new PIDControl(40, 0, 0), 0.5),	new DistanceCondition(300))		);	// スタート直後はゆっくり走行
//	sequence = sequence->setNextSequence(	new Sequence(new LineTraceAction(80, 45, new PIDControl(80, 0, 3000)),	new EmptyCondition())		);	// 直線終わりまで

	// 階段
	sequence = sequence->setNextSequence(	new Sequence(new LineTraceAction(10, 80, new PIDControl(40, 0, 0), 0.5),	new CollisionCondition())		);	// スタート直後はゆっくり走行
	sequence = sequence->setNextSequence(	new Sequence(new SitWaitAction(75),									new TimeCondition(4000))		);	// 座って待機
	sequence = sequence->setNextSequence(	new Sequence(new TailRunAction(-20, 0),								new DistanceCondition(-200))		);	// 一定距離バック
	sequence = sequence->setNextSequence(	new Sequence(new TailRunAction(100, 0),								new DistanceCondition(350))		);	// 勢いをつけて登る

	// シーケンス開始
	m_Sequencer->startSequence(firstSequence);

}
