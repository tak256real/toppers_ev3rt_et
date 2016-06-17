///////////////////////////////////////////////////////////
//  GetSensorValue.h
//  Implementation of the Class GetSensorValue
//  Created on:      2016/06/17 11:04:46
//  Original author: 039918
///////////////////////////////////////////////////////////

#if !defined(EA_D940F37C_D386_4f25_A037_A963A5E39074__INCLUDED_)
#define EA_D940F37C_D386_4f25_A037_A963A5E39074__INCLUDED_

#include "src/sdk/workspace/riso-ranger2016\eng\calibration\Calibration.h"

class GetSensorValue
{

public:
	virtual ~GetSensorValue();
	Calibration *m_Calibration;

	int GetSensorValue();
	int SendSensorValue();

private:
	int type_sensor;

};
#endif // !defined(EA_D940F37C_D386_4f25_A037_A963A5E39074__INCLUDED_)
