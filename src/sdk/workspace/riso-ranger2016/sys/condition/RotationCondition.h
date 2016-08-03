///////////////////////////////////////////////////////////
//  RotationCondition.h
//  Implementation of the Class RotationCondition
//  Created on:      2016/08/03 12:28:35
//  Original author: 039389
///////////////////////////////////////////////////////////

#if !defined(EA_5941CF1E_CC63_4dc3_A5CD_9E8AC88D8E4C__INCLUDED_)
#define EA_5941CF1E_CC63_4dc3_A5CD_9E8AC88D8E4C__INCLUDED_

#include "Condition.h"

class RotationCondition : public Condition
{

public:
	RotationCondition();
	virtual ~RotationCondition();

	virtual bool check();

};
#endif // !defined(EA_5941CF1E_CC63_4dc3_A5CD_9E8AC88D8E4C__INCLUDED_)
