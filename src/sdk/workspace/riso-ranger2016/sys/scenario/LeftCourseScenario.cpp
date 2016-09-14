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
	//sequence = sequence->setNextSequence(	new Sequence(new LineTraceAction(80, 2),	new DistanceCondition(5000))		);
	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(40, 60),	new DistanceCondition(130))	);
	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(30, 80),	new DistanceCondition(100))	);
	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(20, 80),	new DistanceCondition(40))	);	
	sequence = sequence->setNextSequence(		new Sequence(new TailBrakeAction(),			new TimeCondition(700))		);
		sequence = sequence->setNextSequence(		new Sequence(new SitWaitAction(88),			new TimeCondition(5000))		);
	
//	sequence = firstSequence->setNextSequence(	new Sequence(new TailBrakeAction(),			new TimeCondition(1000))		);
//	sequence = firstSequence->setNextSequence(	new Sequence(new LineTraceAction(50, 10),	new DistanceCondition(3800))	);
//	sequence = firstSequence->setNextSequence(		new Sequence(new LineTraceAction(100, 10),	new DistanceToObjectCondition(200))		);
/*	sequence = sequence->setNextSequence(		new Sequence(new TailBrakeAction(),			new TimeCondition(1000))		);
	sequence = sequence->setNextSequence(		new Sequence(new RecliningAction(-4),		new InclinationCondition(68))	);
	sequence = sequence->setNextSequence(		new Sequence(new TailRunAction(20, 0),		new DistanceCondition(200))		);
	sequence = sequence->setNextSequence(		new Sequence(new TailRunAction(10, 0),		new DistanceCondition(100))		);
//	sequence = aasdf
sequence = sequence->setNextSequence(		new Sequence(new TailRunAction(10, 0),		new DistanceCondition(200))		);
	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(20, 60),	new CollisionCondition())		);
	sequence = sequence->setNextSequence(		new Sequence(new TailBrakeAction(),			new TimeCondition(1000))		);
//	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(10, 60),	new DisntanceCondition(100))	);
	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(80, 60),	new CollisionCondition())		);
*/

//	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(30, 60),	new DistanceCondition(20))		);


	// シーケンス開始
	m_Sequencer->startSequence(firstSequence);
}
