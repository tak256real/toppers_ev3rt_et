///////////////////////////////////////////////////////////
//  Calibration.h
//  Implementation of the Class Calibration
//  Created on:      2016/07/05 11:43:06
//  Original author: 039918
///////////////////////////////////////////////////////////

#if !defined(EA_C665904E_761B_426a_B0DB_BE0B2866A22C__INCLUDED_)
#define EA_C665904E_761B_426a_B0DB_BE0B2866A22C__INCLUDED_

#include <kernel.h>
#include "ev3api.h"

class Calibration
{

public:
	Calibration();
	virtual ~Calibration();

	int lightValueMax;
	int lightValueMin;

	uint8_t GetLightValue();
	uint8_t SendLightValue(uint8_t max, uint8_t min);

private:

};
#endif // !defined(EA_C665904E_761B_426a_B0DB_BE0B2866A22C__INCLUDED_)
