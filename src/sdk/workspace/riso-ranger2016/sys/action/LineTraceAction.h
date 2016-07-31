///////////////////////////////////////////////////////////
//  LineTraceAction.h
//  Implementation of the Class LineTraceAction
//  Created on:      2016/07/27 11:47:53
//  Original author: 039389
///////////////////////////////////////////////////////////

#if !defined(EA_40F80250_C89E_4088_959C_43DF38A0AF05__INCLUDED_)
#define EA_40F80250_C89E_4088_959C_43DF38A0AF05__INCLUDED_

#include "Action.h"
#include "PIDControl.h"

class LineTraceAction : public Action
{

public:
	LineTraceAction();
	virtual ~LineTraceAction();
	virtual void cycle();

private:
	PIDControl* m_PidControl;
	int m_speed;
	float m_referenceVal;

};
#endif // !defined(EA_40F80250_C89E_4088_959C_43DF38A0AF05__INCLUDED_)
