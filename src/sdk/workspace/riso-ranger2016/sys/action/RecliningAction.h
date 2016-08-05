///////////////////////////////////////////////////////////
//  RecliningAction.h
//  Implementation of the Class RecliningAction
//  Created on:      2016/07/27 11:48:03
//  Original author: 039389
///////////////////////////////////////////////////////////

#if !defined(EA_3A51595F_764E_4c5a_A951_CE06C5F6745F__INCLUDED_)
#define EA_3A51595F_764E_4c5a_A951_CE06C5F6745F__INCLUDED_

#include "Action.h"

class RecliningAction : public Action
{

public:
	RecliningAction(int angularVelocity);	// 尻尾角速度 [deg/sec]
	virtual ~RecliningAction();

	virtual void onStart();
	virtual void onCycle();
	virtual void onStop();

private:
	int m_AngularVelocity;	// 尻尾角速度 [deg/sec]

};
#endif // !defined(EA_3A51595F_764E_4c5a_A951_CE06C5F6745F__INCLUDED_)
