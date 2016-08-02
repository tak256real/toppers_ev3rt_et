///////////////////////////////////////////////////////////
//  Unit.h
//  Implementation of the Class Unit
//  Created on:      2016/08/01 21:29:44
//  Original author: 039389
///////////////////////////////////////////////////////////

#if !defined(EA_FCCC6601_27E9_4f76_A2BC_B46D8060E9D3__INCLUDED_)
#define EA_FCCC6601_27E9_4f76_A2BC_B46D8060E9D3__INCLUDED_

#include "Sequence.h"

class Unit
{

public:
	Unit();
	virtual ~Unit();

	void startSequence(Sequence* sequence);
	void cycle();

private:
	Sequence* m_CurrentSequence;

	void renewSsequence();

};
#endif // !defined(EA_FCCC6601_27E9_4f76_A2BC_B46D8060E9D3__INCLUDED_)
