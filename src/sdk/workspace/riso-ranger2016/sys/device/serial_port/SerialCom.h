///////////////////////////////////////////////////////////
//  SerialCom.h
//  Implementation of the Class SerialCom
//  Created on:      2016/05/26 13:07:03
//  Original author: 037789
///////////////////////////////////////////////////////////

#if !defined(EA_18F17BD4_3195_48db_9994_10A631C11B9B__INCLUDED_)
#define EA_18F17BD4_3195_48db_9994_10A631C11B9B__INCLUDED_

#include "std.h"

class RxBuffer;
class TxBuffer;

class SerialCom
{
protected:
	RxBuffer* the_rx_buff;
	TxBuffer* the_tx_buff;
	bool is_connect;

private:

    virtual void actInitialze();
    virtual void actTimeOut(EmTiemrId rv_timer_id);

public:
	SerialCom();
	virtual ~SerialCom();

	void doInitialze();
	void doStartRcvCommand();
	void ntfTimeOut(EmTiemrId rv_timer_id);

};
#endif // !defined(EA_18F17BD4_3195_48db_9994_10A631C11B9B__INCLUDED_)
