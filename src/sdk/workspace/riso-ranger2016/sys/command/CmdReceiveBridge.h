///////////////////////////////////////////////////////////
//  CmdReceiveBridge.h
//  Implementation of the Class CmdReceiveBridge
//  Created on:      2016/05/25 9:57:26
//  Original author: 037789
///////////////////////////////////////////////////////////

#if !defined(EA_7AB53012_644D_46e1_A514_1ACE3F175789__INCLUDED_)
#define EA_7AB53012_644D_46e1_A514_1ACE3F175789__INCLUDED_

#include "SubsystemBridge.h"

class CmdReceiveIf;

class CmdReceiveBridge : public SubsystemBridge
{

public:
	virtual ~CmdReceiveBridge();
	static CmdReceiveBridge* getInstance();

private:
	CmdReceiveIf *the_receiver;
	static CmdReceiveBridge* instance;

	CmdReceiveBridge(uint16 rv_subsys_id, sint32 rv_mbox_id);
	virtual void actInitialize();
	virtual void actReceiveMessage(uint16 rv_msg_code, uint16* rv_message);

};


#endif // !defined(EA_7AB53012_644D_46e1_A514_1ACE3F175789__INCLUDED_)
