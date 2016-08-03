///////////////////////////////////////////////////////////
//  Sequence.h
//  Implementation of the Class Sequence
//  Created on:      2016/08/03 12:27:13
//  Original author: 039389
///////////////////////////////////////////////////////////

#if !defined(EA_8BF75F76_FF10_44f5_BC0A_DCCAAAE0560E__INCLUDED_)
#define EA_8BF75F76_FF10_44f5_BC0A_DCCAAAE0560E__INCLUDED_

#include "Action.h"
#include "Condition.h"

class Sequence
{

public:
	Sequence();
	virtual ~Sequence();
	Action* m_CurrentAction;
	Condition* condition;

	Action* getAction();
	Condition* getCondition();
	Sequence* getNextSequence();

};
#endif // !defined(EA_8BF75F76_FF10_44f5_BC0A_DCCAAAE0560E__INCLUDED_)
