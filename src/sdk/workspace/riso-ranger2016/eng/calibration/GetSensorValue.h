///////////////////////////////////////////////////////////
//  GetSensorValue.h
//  Implementation of the Class GetSensorValue
//  Created on:      2016/07/05 11:43:06
//  Original author: 039918
///////////////////////////////////////////////////////////

#if !defined(EA_68700908_8405_4358_AA2A_F9964DF0A955__INCLUDED_)
#define EA_68700908_8405_4358_AA2A_F9964DF0A955__INCLUDED_

#include "Calibration.h"

class GetSensorValue
{

public:
	virtual ~GetSensorValue();
	Calibration *m_Calibration;

	GetSensorValue();
	int SendSensorValue();

private:
	int typeSensor;

};
#endif // !defined(EA_68700908_8405_4358_AA2A_F9964DF0A955__INCLUDED_)
