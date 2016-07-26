///////////////////////////////////////////////////////////
//  SerialComEV3BT_SPP.h
//  Implementation of the Class SerialComEV3BT_SPP
//  Created on:      2016/05/26 13:31:04
//  Original author: 037789
///////////////////////////////////////////////////////////

#if !defined(EA_570CE649_6706_4399_B221_46C6ECA2A112__INCLUDED_)
#define EA_570CE649_6706_4399_B221_46C6ECA2A112__INCLUDED_

#include "SerialCom.h"

class Timer;

class SerialComEV3BT_SPP : public SerialCom
{

public:
	SerialComEV3BT_SPP();
	virtual ~SerialComEV3BT_SPP();

private:
    const uint32 cTtyCtrlCycle = 100;
    FILE tty;
	Timer* the_timer;
	virtual void actInitialze();
    virtual void actComOpen();
    virtual void actTimeOut(EmTiemrId rv_timer_id);

};
#endif // !defined(EA_570CE649_6706_4399_B221_46C6ECA2A112__INCLUDED_)
