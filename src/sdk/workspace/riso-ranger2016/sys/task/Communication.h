///////////////////////////////////////////////////////////
//  Communication.h
//  Implementation of the Class Communication
//  Created on:      2016/05/30 9:06:08
//  Original author: 037789
///////////////////////////////////////////////////////////

#if !defined(EA_EA80FAD2_FCFE_437a_9A0F_B8F4487849D4__INCLUDED_)
#define EA_EA80FAD2_FCFE_437a_9A0F_B8F4487849D4__INCLUDED_

#include "Task.h"

class Communication : public Task
{

public:
	Communication(sint32 rv_tsk_id, sint32 rv_mbox_id);
	virtual ~Communication();

	virtual void start();

protected:

private:
	virtual bool isOwnMessage(EmSubsystemId rv_subsys_id);

};
#endif // !defined(EA_EA80FAD2_FCFE_437a_9A0F_B8F4487849D4__INCLUDED_)
