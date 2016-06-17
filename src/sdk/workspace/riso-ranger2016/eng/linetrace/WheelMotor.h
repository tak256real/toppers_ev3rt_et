///////////////////////////////////////////////////////////
//  WheelMotor.h
//  Implementation of the Class WheelMotor
//  Created on:      2016/06/17 10:57:18
//  Original author: 039889
///////////////////////////////////////////////////////////

#if !defined(EA_7C28CA0C_E54F_4931_A9F9_A733B7D6C5E2__INCLUDED_)
#define EA_7C28CA0C_E54F_4931_A9F9_A733B7D6C5E2__INCLUDED_

class WheelMotor
{

public:
	WheelMotor();
	virtual ~WheelMotor();

	void Motor();

private:
	float PID_Value;

};
#endif // !defined(EA_7C28CA0C_E54F_4931_A9F9_A733B7D6C5E2__INCLUDED_)
