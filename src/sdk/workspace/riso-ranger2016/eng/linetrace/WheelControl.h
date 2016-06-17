///////////////////////////////////////////////////////////
//  WheelControl.h
//  Implementation of the Class WheelControl
//  Created on:      2016/06/17 10:57:18
//  Original author: 039889
///////////////////////////////////////////////////////////

#if !defined(EA_439B1865_F219_46bd_BF6A_1B15A6F95D81__INCLUDED_)
#define EA_439B1865_F219_46bd_BF6A_1B15A6F95D81__INCLUDED_

#include "src\sdk\workspace\riso-ranger2016\eng\linetrace\WheelMotor.h"

class WheelControl
{

public:
	virtual ~WheelControl();
	WheelMotor *m_WheelMotor;

	void WheelControl();

private:
	float PID_Value;

};
#endif // !defined(EA_439B1865_F219_46bd_BF6A_1B15A6F95D81__INCLUDED_)
