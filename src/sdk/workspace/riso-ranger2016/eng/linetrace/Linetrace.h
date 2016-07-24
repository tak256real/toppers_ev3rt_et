///////////////////////////////////////////////////////////
//  Linetrace.h
//  Implementation of the Class Linetrace
//  Created on:      2016/07/22 19:45:31
//  Original author: 039889
///////////////////////////////////////////////////////////

#if !defined(EA_AB462F12_6406_44a4_BFEB_52BCBBFE4724__INCLUDED_)
#define EA_AB462F12_6406_44a4_BFEB_52BCBBFE4724__INCLUDED_

#include "PIDControl.h"
#include "Calibration.h"
#include "WheelControl.h"

class Linetrace
{

public:
	WheelControl* m_WheelControl;

	Linetrace(WheelControl* wheelControl, Calibration* calibration);
	virtual ~Linetrace();
	void exec();
private:
	PIDControl* m_PidControl;
	Calibration* m_Calibration;
	int m_speed;
	float m_referenceVal;
};
#endif // !defined(EA_AB462F12_6406_44a4_BFEB_52BCBBFE4724__INCLUDED_)
