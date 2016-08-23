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
#include "DistanceToObjectCondition.h"
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

	firstSequence = 							new Sequence(new SitWaitAction(92),			new TimeCondition(5000)		);
	sequence = firstSequence->setNextSequence(	new Sequence(new LineTraceAction(10, 60),	new DistanceCondition(200))		);
//	sequence = sequence->setNextSequence(		new Sequence(new TailBrakeAction(),			new TimeCondition(1000))		);
	sequence = sequence->setNextSequence(		new Sequence(new RecliningAction(-4),		new InclinationCondition(68))		);
	sequence = sequence->setNextSequence(		new Sequence(new TailRunAction(20, 0),		new DistanceCondition(100))		);
	sequence = sequence->setNextSequence(		new Sequence(new TailRunAction(10, 0),		new DistanceCondition(100))		);
//	sequence = sequence->setNextSequence(		new Sequence(new TailBrakeAction(),			new TimeCondition(2000))		);
	sequence = sequence->setNextSequence(		new Sequence(new TailRunAction(-10, 0),		new DistanceCondition(-100))		);
	sequence = sequence->setNextSequence(		new Sequence(new TailRunAction(10, 0),		new DistanceCondition(200))		);
//	sequence = sequence->setNextSequence(		new Sequence(new TailRunAction(20, 0),		new DistanceCondition(400))		);
//	sequence = sequence->setNextSequence(		new Sequence(new RecliningAction(5),		new InclinationCondition(85))		);
//	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(30, 60),	new DistanceCondition(20))		);


	// シーケンス開始
	m_Sequencer->startSequence(firstSequence);
}
