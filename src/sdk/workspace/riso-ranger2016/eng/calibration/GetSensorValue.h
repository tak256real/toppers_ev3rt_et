///////////////////////////////////////////////////////////
//  GetSensorValue.h
//  Implementation of the Class GetSensorValue
//  Created on:      2016/07/05 11:43:06
//  Original author: 039918
///////////////////////////////////////////////////////////

#if !defined(EA_68700908_8405_4358_AA2A_F9964DF0A955__INCLUDED_)
#define EA_68700908_8405_4358_AA2A_F9964DF0A955__INCLUDED_

#include "ev3api.h"

class GetSensorValue
{

public:
	GetSensorValue(sensor_port_t port);
	virtual ~GetSensorValue();

	int getSensorValue();

private:
	sensor_port_t m_Port;

};
#endif // !defined(EA_68700908_8405_4358_AA2A_F9964DF0A955__INCLUDED_)
