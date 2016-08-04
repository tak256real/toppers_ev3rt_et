///////////////////////////////////////////////////////////
//  Condition.h
//  Implementation of the Class Condition
//  Created on:      2016/08/03 12:28:23
//  Original author: 039389
///////////////////////////////////////////////////////////

#if !defined(EA_0D1E4528_C300_4dc4_B29F_13C52339C607__INCLUDED_)
#define EA_0D1E4528_C300_4dc4_B29F_13C52339C607__INCLUDED_

#include "StateObserver.h"

class Condition
{

public:
	Condition();
	virtual ~Condition();

	void init(StateObserver *stateObserver);
	virtual void onStart()=0;
	virtual bool check() =0;

protected:
	static StateObserver *m_StateObserver;

};
#endif // !defined(EA_0D1E4528_C300_4dc4_B29F_13C52339C607__INCLUDED_)
