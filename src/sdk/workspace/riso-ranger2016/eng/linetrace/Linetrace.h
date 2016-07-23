///////////////////////////////////////////////////////////
//  Linetrace.h
//  Implementation of the Class Linetrace
//  Created on:      2016/07/22 19:45:31
//  Original author: 039889
///////////////////////////////////////////////////////////

#if !defined(EA_AB462F12_6406_44a4_BFEB_52BCBBFE4724__INCLUDED_)
#define EA_AB462F12_6406_44a4_BFEB_52BCBBFE4724__INCLUDED_

#include "src\sdk\workspace\riso-ranger2016\eng\linetrace\PIDControl.h"
#include "src\sdk\workspace\riso-ranger2016\eng\calibration\Calibration.h"
#include "src\sdk\workspace\riso-ranger2016\sys\device\WheelControl.h"

class Linetrace
{

public:
	WheelControl* m_WheelControl;

	void Linetrace(WheelControl* wheelControl, Calibration* calibration);
	virtual ~Linetrace();
	void exec();
private:
	int colorValue;
	PIDControl* m_PidControl;
	Calibration* m_Calibration;
	int m_speed;
	float m_referenceVal;
	float m_currentVal;
	\\\\\\\\\\\\\\\\\\
	static bool m_motorFlag;
};
#endif // !defined(EA_AB462F12_6406_44a4_BFEB_52BCBBFE4724__INCLUDED_)
