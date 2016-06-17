///////////////////////////////////////////////////////////
//  PIDControl.h
//  Implementation of the Class PIDControl
//  Created on:      2016/06/17 10:57:18
//  Original author: 039889
///////////////////////////////////////////////////////////

#if !defined(EA_CBA4C248_459C_456e_9B7C_A937A059C146__INCLUDED_)
#define EA_CBA4C248_459C_456e_9B7C_A937A059C146__INCLUDED_

class PIDControl
{

public:
	PIDControl();
	virtual ~PIDControl();

	void PIDCalculation();

private:
	float D;
	float I;
	float P;

};
#endif // !defined(EA_CBA4C248_459C_456e_9B7C_A937A059C146__INCLUDED_)
