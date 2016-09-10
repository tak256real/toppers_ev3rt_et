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
#include "TimeCondition.h"
#include "CollisionCondition.h"
#include "DistanceToObjectCondition.h"
#include "GlayLineCondition.h"
#include "InclinationCondition.h"
#include "DistanceCondition.h"
#include "TailRunAction.h"

LeftCourseScenario::LeftCourseScenario(){

}



LeftCourseScenario::~LeftCourseScenario(){

}


void LeftCourseScenario::start(){

	// シーケンス順設定
	Sequence* sequence;
	Sequence* firstSequence;

	firstSequence = 							new Sequence(new SitWaitAction(92),			new TimeCondition(4000)			);
//	sequence = firstSequence->setNextSequence(	new Sequence(new LineTraceAction(20, 10),	new DistanceCondition(100))		);
//	sequence = firstSequence->setNextSequence(	new Sequence(new TailBrakeAction(),			new TimeCondition(1000))		);
//	sequence = firstSequence->setNextSequence(	new Sequence(new LineTraceAction(50, 10),	new DistanceCondition(3800))	);

// グレーライン検知部

	sequence = firstSequence->setNextSequence(		new Sequence(new LineTraceAction(30, 10),	new GlayLineCondition())		);
	sequence = sequence->setNextSequence(		new Sequence(new TailBrakeAction(),			new TimeCondition(1000))		);
	sequence = sequence->setNextSequence(		new Sequence(new RecliningAction(-4),		new InclinationCondition(68))	);

	
	
	
// ルックアップゲート部
	/*
	sequence = firstSequence->setNextSequence(		new Sequence(new LineTraceAction(80, 10),	new DistanceToObjectCondition(40))		);
	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(30, 80),	new DistanceToObjectCondition(20))		);
//	sequence = sequence->setNextSequence(		new Sequence(new TailBrakeAction(),			new TimeCondition(1000))		);
	// !!! リクライニングの前に、尻尾の角度を80度にする !!！
	sequence = sequence->setNextSequence(		new Sequence(new RecliningAction(-30),		new InclinationCondition(54))	);
	sequence = sequence->setNextSequence(		new Sequence(new TailRunAction(10, 0),		new DistanceCondition(250))		);
//	sequence = sequence->setNextSequence(		new Sequence(new TailBrakeAction(),			new TimeCondition(1000))		);
	sequence = sequence->setNextSequence(		new Sequence(new TailRunAction(-5, 0),		new DistanceCondition(-300))	);
	sequence = sequence->setNextSequence(		new Sequence(new TailRunAction(10, 0),		new DistanceCondition(200))		);
//	sequence = sequence->setNextSequence(		new Sequence(new TailRunAction(-10, 0),		new DistanceCondition(-300))	);
//	sequence = sequence->setNextSequence(		new Sequence(new TailRunAction(10, 0),		new DistanceCondition(300))		);
//	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(20, 60),	new CollisionCondition())		);
	sequence = sequence->setNextSequence(		new Sequence(new RecliningAction(4),		new InclinationCondition(85))	);
	sequence = sequence->setNextSequence(		new Sequence(new TailBrakeAction(),			new TimeCondition(1000))		);
//	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(10, 60),	new DisntanceCondition(100))	);
	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(80, 60),	new CollisionCondition())		);
*/

//	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(30, 60),	new DistanceCondition(20))		);


	// シーケンス開始
	m_Sequencer->startSequence(firstSequence);
}
