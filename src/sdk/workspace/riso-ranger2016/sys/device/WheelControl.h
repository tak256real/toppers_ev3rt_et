///////////////////////////////////////////////////////////
//  WheelControl.h
//  Implementation of the Class WheelControl
//  Created on:      2016/07/15 16:04:13
//  Original author: 039889
///////////////////////////////////////////////////////////

#if !defined(EA_AD0BBBF1_1A41_451b_9449_09D1A5901DD9__INCLUDED_)
#define EA_AD0BBBF1_1A41_451b_9449_09D1A5901DD9__INCLUDED_

#include "Motor.h"

class WheelControl
{

public:
	WheelControl(Motor* wheelMotorL, Motor* wheelMotorR);
	virtual ~WheelControl();
	void Init();
	void Control();
	void SetRefValue(int speed, int turn);
	void SetTwoWheelMode(bool onoff);

private:
	bool m_TwoWheelMode;		// 倒立制御オンオフ
	Motor* m_WheelMotorL;	// 左モータ
	Motor* m_WheelMotorR;	// 右モータ
	int m_RefSpeed;				// 目標速度
	int m_RefTurn;				// 目標旋回速度

};
#endif // !defined(EA_AD0BBBF1_1A41_451b_9449_09D1A5901DD9__INCLUDED_)
