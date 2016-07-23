///////////////////////////////////////////////////////////
//  WheelMotor.h
//  Implementation of the Class WheelMotor
//  Created on:      2016/07/15 16:04:16
//  Original author: 039889
///////////////////////////////////////////////////////////

#if !defined(EA_68ADC4F5_CD7A_4d03_94F4_3F235BA26AB5__INCLUDED_)
#define EA_68ADC4F5_CD7A_4d03_94F4_3F235BA26AB5__INCLUDED_

#include "ev3api.h"

class WheelMotor
{

public:
	WheelMotor(motor_port_t PortNum);
	virtual ~WheelMotor();

	void UpdateAngularVelocity();
	void ResetEnc();
	int GetEnc();
	int GetAngularVelocity();
	void SetPWMValue(signed char PWMValue);

private :
	motor_port_t m_Port;						// ポート番号
	int m_AngularVelocity;						// 角速度[deg/sec]
	int* m_WheelEncBuf;							// 角速度算出用エンコーダバッファ
	unsigned short m_WheelEncBufNextIndex;		// 角速度算出用エンコーダバッファ格納位置

};
#endif // !defined(EA_68ADC4F5_CD7A_4d03_94F4_3F235BA26AB5__INCLUDED_)
