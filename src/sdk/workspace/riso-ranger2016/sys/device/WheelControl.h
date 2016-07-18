///////////////////////////////////////////////////////////
//  WheelControl.h
//  Implementation of the Class WheelControl
//  Created on:      2016/07/15 16:04:13
//  Original author: 039889
///////////////////////////////////////////////////////////

#if !defined(EA_AD0BBBF1_1A41_451b_9449_09D1A5901DD9__INCLUDED_)
#define EA_AD0BBBF1_1A41_451b_9449_09D1A5901DD9__INCLUDED_

#include "WheelMotor.h"

class WheelControl
{

public:
	WheelControl();
	virtual ~WheelControl();
	void Control();
	void SetRefValue(int speed, int turn);
	void SetTwoWheelMode(bool onoff);
	void SetWheelMotorL(WheelMotor* wheelMotorL);
	void SetWheelMotorR(WheelMotor* wheelMotorR);

private:
	bool m_TwoWheelMode;
	WheelMotor* m_WheelMotorL;
	WheelMotor* m_WheelMotorR;
	int m_RefSpeed;
	int m_RefTurn;

};
#endif // !defined(EA_AD0BBBF1_1A41_451b_9449_09D1A5901DD9__INCLUDED_)
