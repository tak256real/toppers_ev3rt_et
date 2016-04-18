///////////////////////////////////////////////////////////
//  SubsystemBridge.h
//  Implementation of the Class SubsystemBridge
//  Created on:      2016/04/13 12:52:15
//  Original author: 037789
///////////////////////////////////////////////////////////

#if !defined(EA_6B6C30FD_F2FC_404a_9BEA_EF84C743FB75__INCLUDED_)
#define EA_6B6C30FD_F2FC_404a_9BEA_EF84C743FB75__INCLUDED_

class SubsystemBridge
{

public:
	SubsystemBridge();
	virtual ~SubsystemBridge();
	void doInitialize();
	void receiveMessage(uint16* rv_message);


protected:
	void sendMessage(void* rv_message, rv_size uint16);

private:
	virtual void actInitialize();
	virtual void actReceiveMessage(uint16* rv_message);
};
#endif // !defined(EA_6B6C30FD_F2FC_404a_9BEA_EF84C743FB75__INCLUDED_)
