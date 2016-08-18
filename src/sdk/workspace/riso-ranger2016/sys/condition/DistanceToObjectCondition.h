*
 * DistanceToObjectCondition.h
 *
 *  Created on: 2016/08/12
 *      Author: Reina
 */

#ifndef WORKSPACE_RISO_RANGER2016_SYS_CONDITION_DISTANCETOOBJECTCONDITION_H_
#define WORKSPACE_RISO_RANGER2016_SYS_CONDITION_DISTANCETOOBJECTCONDITION_H_

#include "Condition.h"

class DistanceToObjectCondition : public Condition
{

public:
	DistanceToObjectCondition(int distanceDifference);
	virtual ~DistanceToObjectCondition();

	virtual void onStart();
	virtual bool check();

private:
	int m_StartDistance;		// äÓèÄãóó£
	int m_DistanceDifference;	// éwíËÇÃãóó£ïœï™

};
#endif /* WORKSPACE_RISO_RANGER2016_SYS_CONDITION_DISTANCETOOBJECTCONDITION_H_ */
 