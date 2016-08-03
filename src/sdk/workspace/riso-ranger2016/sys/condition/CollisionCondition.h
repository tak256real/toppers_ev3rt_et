///////////////////////////////////////////////////////////
//  CollisionCondition.h
//  Implementation of the Class CollisionCondition
//  Created on:      2016/08/03 12:28:36
//  Original author: 039389
///////////////////////////////////////////////////////////

#if !defined(EA_B9D80660_930A_4a06_AEF8_377875A921FD__INCLUDED_)
#define EA_B9D80660_930A_4a06_AEF8_377875A921FD__INCLUDED_

#include "Condition.h"

class CollisionCondition : public Condition
{

public:
	CollisionCondition();
	virtual ~CollisionCondition();

	virtual bool check();

};
#endif // !defined(EA_B9D80660_930A_4a06_AEF8_377875A921FD__INCLUDED_)
