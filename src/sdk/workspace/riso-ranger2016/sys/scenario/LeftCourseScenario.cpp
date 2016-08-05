///////////////////////////////////////////////////////////
//  LeftCourseScenario.cpp
//  Implementation of the Class LeftCourseScenario
//  Created on:      2016/08/04 13:35:24
//  Original author: 039389
///////////////////////////////////////////////////////////

#include "LeftCourseScenario.h"
#include "Scenario.h"


LeftCourseScenario::LeftCourseScenario(){

}



LeftCourseScenario::~LeftCourseScenario(){

}


void LeftCourseScenario::start(){

	Sequence* sequence;
	Sequence* firstSequence;
	firstSequence = 							new Sequence(new SitWaitAction(90),			new TimeCondition(5000)		);
	sequence = firstSequence->setNextSequence(	new Sequence(new LineTraceAction(30, 60),	new DistanceCondition(720))		);
	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(10, 30),	new DistanceCondition(360))		);
	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(30, 60),	new DistanceCondition(720))		);
	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(10, 80),	new DistanceCondition(360))		);

	m_Sequencer->startSequence(firstSequence);
}
