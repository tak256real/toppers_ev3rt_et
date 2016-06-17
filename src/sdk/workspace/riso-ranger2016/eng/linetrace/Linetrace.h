///////////////////////////////////////////////////////////
//  Linetrace.h
//  Implementation of the Class Linetrace
//  Created on:      2016/06/17 10:57:18
//  Original author: 039889
///////////////////////////////////////////////////////////

#if !defined(EA_408359DE_3715_4076_B6A9_21A122D78E17__INCLUDED_)
#define EA_408359DE_3715_4076_B6A9_21A122D78E17__INCLUDED_

#include "src\sdk\workspace\riso-ranger2016\eng\linetrace\WheelControl.h"
#include "src\sdk\workspace\riso-ranger2016\eng\linetrace\PIDControl.h"

class Linetrace
{

public:
	virtual ~Linetrace();
	WheelControl *m_WheelControl;
	PIDControl *m_PIDControl;

	void Linetrace();

};
#endif // !defined(EA_408359DE_3715_4076_B6A9_21A122D78E17__INCLUDED_)
