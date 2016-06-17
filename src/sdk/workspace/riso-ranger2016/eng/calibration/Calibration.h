///////////////////////////////////////////////////////////
//  Calibration.h
//  Implementation of the Class Calibration
//  Created on:      2016/06/17 11:04:46
//  Original author: 039918
///////////////////////////////////////////////////////////

#if !defined(EA_435C4C1D_B5C9_4c6d_8550_2CED725466F8__INCLUDED_)
#define EA_435C4C1D_B5C9_4c6d_8550_2CED725466F8__INCLUDED_

class Calibration
{

public:
	Calibration();
	virtual ~Calibration();

	int BandAdjustment();

private:
	int light_value_black;
	int light_value_white;

};
#endif // !defined(EA_435C4C1D_B5C9_4c6d_8550_2CED725466F8__INCLUDED_)
