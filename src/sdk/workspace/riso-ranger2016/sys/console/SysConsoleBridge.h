///////////////////////////////////////////////////////////
//  SysConsoleBridge.h
//  Implementation of the Class SysConsoleBridge
//  Created on:      2016/07/22 10:54:33
//  Original author: 037789
///////////////////////////////////////////////////////////

#if !defined(EA_E1803B3D_627D_4e1b_8CFD_37BC8EFA79DF__INCLUDED_)
#define EA_E1803B3D_627D_4e1b_8CFD_37BC8EFA79DF__INCLUDED_

#include "SubsystemBridge.h"
#include "SysConsoleIf.h"

class SysConsoleBridge : public SubsystemBridge
{

public:
	SysConsoleBridge();
	virtual ~SysConsoleBridge();
	
	SysConsoleBridge* getInstance();

protected:


private:
	static SysConsoleBridge* instance;
	SysConsoleIf *the_if;

	virtual void actInitialize();
    virtual void actReceiveMessage(uint16 rv_msg_code, uint16* rv_message);

};
#endif // !defined(EA_E1803B3D_627D_4e1b_8CFD_37BC8EFA79DF__INCLUDED_)
