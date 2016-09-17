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
#include "RotationCondition.h"


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

	
	
// ルックアップゲート部
	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(10, 10),	new TimeCondition(3000))	);	
	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(30, 10),	new DistanceToObjectCondition(40))		);
	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(30, 80),	new DistanceToObjectCondition(20))		);
	sequence = sequence->setNextSequence(		new Sequence(new TailBrakeAction(),			new TimeCondition(300))		);
	// !!! リクライニングの前に、尻尾の角度を80度にする !!!
	sequence = sequence->setNextSequence(		new Sequence(new RecliningAction(-20),		new InclinationCondition(65))	);
	sequence = sequence->setNextSequence(		new Sequence(new TailRunAction(10, 0),		new DistanceCondition(270))		);
	sequence = sequence->setNextSequence(		new Sequence(new TailBrakeAction(),			new TimeCondition(500))		);

	sequence = sequence->setNextSequence(		new Sequence(new TailRunAction(0, 15),		new RotationCondition(176))	);
	sequence = sequence->setNextSequence(		new Sequence(new TailBrakeAction(),			new TimeCondition(500))		);
	
	sequence = sequence->setNextSequence(		new Sequence(new TailRunAction(10, 0),		new DistanceCondition(270))		);
	sequence = sequence->setNextSequence(		new Sequence(new TailBrakeAction(),			new TimeCondition(500))		);
	
	sequence = sequence->setNextSequence(		new Sequence(new TailRunAction(0, 15),		new RotationCondition(176))	);
	sequence = sequence->setNextSequence(		new Sequence(new TailBrakeAction(),			new TimeCondition(500))		);

	sequence = sequence->setNextSequence(		new Sequence(new TailRunAction(10, 0),		new DistanceCondition(270))		);
	sequence = sequence->setNextSequence(		new Sequence(new TailBrakeAction(),			new TimeCondition(500))		);

// 尻尾走行からの倒立走行切り替え
	sequence = sequence->setNextSequence(		new Sequence(new TailRunAction(-10, 0),		new TimeCondition(500))		);
	sequence = sequence->setNextSequence(		new Sequence(new RecliningAction(80),		new InclinationCondition(115))	);
	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(30, 97),	new DistanceCondition(1000))	);


// グレーライン検知部 トレース位置は0.15
	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(10, 10),	new TimeCondition(3000))	);
	sequence = sequence->setNextSequence(		new Sequence(new LineTraceAction(30, 10),	new GlayLineCondition())	);
	sequence = sequence->setNextSequence(		new Sequence(new TailBrakeAction(),			new TimeCondition(1000))		);
	sequence = sequence->setNextSequence(		new Sequence(new RecliningAction(-4),		new InclinationCondition(68))	);

	
	// シーケンス開始
	m_Sequencer->startSequence(firstSequence);
}
