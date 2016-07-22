///////////////////////////////////////////////////////////
//  Linetrace.h
//  Implementation of the Class Linetrace
//  Created on:      2016/07/22 19:45:31
//  Original author: 039889
///////////////////////////////////////////////////////////

#if !defined(EA_AB462F12_6406_44a4_BFEB_52BCBBFE4724__INCLUDED_)
#define EA_AB462F12_6406_44a4_BFEB_52BCBBFE4724__INCLUDED_

#include "src\sdk\workspace\riso-ranger2016\eng\linetrace\PIDControl.h"

class Linetrace
{

public:
	WheelControl* m_WheelControl;

	void Linetrace();
	virtual ~Linetrace();
	void setCalibrationValue(float CalibrationVaue);

private:
	int colorValue;
	PIDControl* the_pidcontrol;
	float turn;

};
#endif // !defined(EA_AB462F12_6406_44a4_BFEB_52BCBBFE4724__INCLUDED_)
