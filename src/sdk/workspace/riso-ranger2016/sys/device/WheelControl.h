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
	WheelMotor* m_WheelMotor;

	WheelControl();
	virtual ~WheelControl();
	void ControlWheel(int speed, int turn);
	void Init();
	int TwoWheelControl(bool onoff);
	void Control();
	void SetRefValue(int speed, int turn);
	void TwoWheelMode(bool onoff);

private:
	int m_RefSpeed;
	int m_RefTurn;

};
#endif // !defined(EA_AD0BBBF1_1A41_451b_9449_09D1A5901DD9__INCLUDED_)
