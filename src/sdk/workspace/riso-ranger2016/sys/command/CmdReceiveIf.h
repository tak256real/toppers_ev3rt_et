///////////////////////////////////////////////////////////
//  CmdReciveIf.h
//  Implementation of the Class CmdReciveIf
//  Created on:      2016/05/25 14:35:21
//  Original author: 037789
///////////////////////////////////////////////////////////

#if !defined(EA_45AC726F_4704_49f7_8F47_CD304E459117__INCLUDED_)
#define EA_45AC726F_4704_49f7_8F47_CD304E459117__INCLUDED_

#include "SubsystemIf.h"

class SysDeviceBridge;

class CmdReceiveIf : public SubsystemIf
{

public:
	virtual ~CmdReceiveIf();
	static CmdReceiveIf* getInstance();
	void doInitialze();

private:
	static CmdReceiveIf* instance;
	SysDeviceBridge* the_rcv_device;

	CmdReceiveIf();
	virtual void actInitialze();
};
#endif // !defined(EA_45AC726F_4704_49f7_8F47_CD304E459117__INCLUDED_)