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

LeftCourseScenario::LeftCourseScenario(){

}



LeftCourseScenario::~LeftCourseScenario(){

}


void LeftCourseScenario::start(){

	// シーケンス順設定
	Sequence* sequence;
	Sequence* firstSequence;
	firstSequence = 							new Sequence(new SitWaitAction(90),			new TimeCondition(5000)		);
	sequence = firstSequence->setNextSequence(	new Sequence(new LineTraceAction(30, 60),	new DistanceToObjectCondition(20))		);
	sequence = sequence->setNextSequence(		new Sequence(new TailBrakeAction(),	new TimeCondition(1000))		);
	sequence = sequence->setNextSequence(		new Sequence(new RecliningAction(-5),	new InclinationCondition(45))		);
	sequence = sequence->setNextSequence(		new Sequence(new TailRunAction(20, 0),	new DistanceCondition(400))		);
	sequence = sequence->setNextSequence(		new Sequence(new TailRunAction(-20, 0),	new DistanceCondition(400))		);
	sequence = sequence->setNextSequence(		new Sequence(new TailRunAction(20, 0),	new DistanceCondition(400))		);
	sequence = sequence->setNextSequence(		new Sequence(new RecliningAction(5),	new InclinationCondition(90))		);
	sequence = sequence->setNextSequence(	new Sequence(new LineTraceAction(30, 60),	new DistanceToObjectCondition(20))		);


	// シーケンス開始
	m_Sequencer->startSequence(firstSequence);
}
