///////////////////////////////////////////////////////////
//  LeftCourseScenario.cpp
//  Implementation of the Class LeftCourseScenario
//  Created on:      2016/08/04 13:35:24
//  Original author: 039389
///////////////////////////////////////////////////////////

#include "LeftCourseScenario.h"
#include "Scenario.h"

#include "SitWaitAction.h"
#include "LineTraceAction.h"
#include "TailBrakeAction.h"
#include "RecliningAction.h"
#include "TailRunAction.h"
#include "TailRunAction.h"
#include "TailCalibrationAction.h"

#include "TimeCondition.h"
#include "CollisionCondition.h"
#include "DistanceToObjectCondition.h"
#include "GlayLineCondition.h"
#include "InclinationCondition.h"
#include "DistanceCondition.h"
#include "TailStopCondition.h"
#include "EmptyCondition.h"


LeftCourseScenario::LeftCourseScenario(){

}



LeftCourseScenario::~LeftCourseScenario(){

}


void LeftCourseScenario::start(){

	// シーケンス順設定
	Sequence* sequence;
	Sequence* firstSequence;

  // 尻尾キャリブレーション部
	firstSequence = 							new Sequence(new TailCalibrationAction(),	new TailStopCondition(1000)		);
	sequence = firstSequence->setNextSequence(new Sequence(new SitWaitAction(97),			new TimeCondition(4000))			);
//	sequence = sequence->setNextSequence(	new Sequence(new LineTraceAction(80, 2),	new DistanceCondition(5000))		);
//	sequence = firstSequence->setNextSequence(	new Sequence(new TailBrakeAction(),			new TimeCondition(1000))		);
//	sequence = firstSequence->setNextSequence(	new Sequence(new LineTraceAction(50, 10),	new DistanceCondition(3800))	);

	
// グレーライン検知部
	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(10, 10),	new TimeCondition(3000))	);
	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(30, 10),	new GlayLineCondition())	);
//	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(0, 80),	new TimeCondition(1000))		);
	sequence = sequence->setNextSequence(		new Sequence(new TailBrakeAction(),			new TimeCondition(1000))		);
	sequence = sequence->setNextSequence(		new Sequence(new RecliningAction(-4),		new InclinationCondition(68))	);
	
// ルックアップゲート部
	/*
	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(80, 10),	new DistanceToObjectCondition(40))		);
	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(30, 80),	new DistanceToObjectCondition(20))		);
//	sequence = sequence->setNextSequence(		new Sequence(new TailBrakeAction(),			new TimeCondition(1000))		);
	// !!! リクライニングの前に、尻尾の角度を80度にする !!!
	sequence = sequence->setNextSequence(		new Sequence(new RecliningAction(-30),		new InclinationCondition(52))	);
	sequence = sequence->setNextSequence(		new Sequence(new TailRunAction(10, 0),		new DistanceCondition(250))		);
//	sequence = sequence->setNextSequence(		new Sequence(new TailBrakeAction(),			new TimeCondition(1000))		);
	sequence = sequence->setNextSequence(		new Sequence(new TailRunAction(-5, 0),		new DistanceCondition(-250))	);
	sequence = sequence->setNextSequence(		new Sequence(new TailRunAction(10, 0),		new DistanceCondition(250))		);

// 尻尾走行からの倒立走行切り替え
	sequence = sequence->setNextSequence(		new Sequence(new RecliningAction(4),		new InclinationCondition(85))	);
	sequence = sequence->setNextSequence(		new Sequence(new TailBrakeAction(),			new TimeCondition(1000))		);
	sequence = sequence->setNextSequence(		new Sequence(new RecliningAction(1),		new InclinationCondition(95))	);
//	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(10, 60),	new DisntanceCondition(100))	);
	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(80, 60),	new CollisionCondition())		);
*/

//	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(30, 60),	new DistanceCondition(20))		);


	// シーケンス開始
	m_Sequencer->startSequence(firstSequence);
}
