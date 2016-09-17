///////////////////////////////////////////////////////////
//  TailControl.h
//  Implementation of the Class TailControl
//  Created on:      2016/07/21 20:55:36
//  Original author: 039389
///////////////////////////////////////////////////////////

#if !defined(EA_AF7A7D4C_EA3F_49d8_B0CD_3F5D4A6A7B1C__INCLUDED_)
#define EA_AF7A7D4C_EA3F_49d8_B0CD_3F5D4A6A7B1C__INCLUDED_

#include "Motor.h"

class TailControl
{

public:
	TailControl(Motor* tailMotor);
	virtual ~TailControl();

	void init();		// エンコーダ初期化
	void Control();					// 周期制御
	void SetRefValue(int angle);	// 目標値セット
	bool earthingDetection();		// 尻尾接地検出

private:
	Motor* m_TailMotor;
	int m_RefAngle;

	static const int c_EarthingThreshold = 3;	// 接地検出の閾値[deg]

};
#endif // !defined(EA_AF7A7D4C_EA3F_49d8_B0CD_3F5D4A6A7B1C__INCLUDED_)
