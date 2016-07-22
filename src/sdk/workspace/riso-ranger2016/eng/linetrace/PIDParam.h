///////////////////////////////////////////////////////////
//  PIDParam.h
//  Implementation of the Class PIDParam
//  Created on:      2016/07/22 19:45:45
//  Original author: 039889
///////////////////////////////////////////////////////////

#if !defined(EA_9E4883BB_611B_4f88_B656_6A0271FED2F8__INCLUDED_)
#define EA_9E4883BB_611B_4f88_B656_6A0271FED2F8__INCLUDED_

class PIDParam
{

public:
	PIDParam();
	virtual ~PIDParam();

private:
	float D;
	float I;
	float P;

};
#endif // !defined(EA_9E4883BB_611B_4f88_B656_6A0271FED2F8__INCLUDED_)
