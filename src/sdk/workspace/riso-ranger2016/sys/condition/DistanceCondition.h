///////////////////////////////////////////////////////////
//  DistanceCondition.h
//  Implementation of the Class DistanceCondition
//  Created on:      2016/08/03 12:28:33
//  Original author: 039389
///////////////////////////////////////////////////////////

#if !defined(EA_34E09B17_35C3_4016_801D_2788BFA732ED__INCLUDED_)
#define EA_34E09B17_35C3_4016_801D_2788BFA732ED__INCLUDED_

#include "Condition.h"

class DistanceCondition : public Condition
{

public:
	DistanceCondition();
	virtual ~DistanceCondition();

	virtual bool check();

};
#endif // !defined(EA_34E09B17_35C3_4016_801D_2788BFA732ED__INCLUDED_)
