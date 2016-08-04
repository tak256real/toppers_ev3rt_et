///////////////////////////////////////////////////////////
//  InclinationCondition.h
//  Implementation of the Class InclinationCondition
//  Created on:      2016/08/03 12:28:34
//  Original author: 039389
///////////////////////////////////////////////////////////

#if !defined(EA_45A62898_0FEF_45bd_A5D6_861DDF40B9BD__INCLUDED_)
#define EA_45A62898_0FEF_45bd_A5D6_861DDF40B9BD__INCLUDED_

#include "Condition.h"

/**
 * 垂直時を0度、後方への傾斜方向を正としたロボットの傾斜角を指定
 */
class InclinationCondition : public Condition
{

public:
	InclinationCondition();
	virtual ~InclinationCondition();

	virtual void onStart();
	virtual bool check();

};
#endif // !defined(EA_45A62898_0FEF_45bd_A5D6_861DDF40B9BD__INCLUDED_)
