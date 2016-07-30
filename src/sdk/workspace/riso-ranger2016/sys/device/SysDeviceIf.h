///////////////////////////////////////////////////////////
//  SysDeviceIf.h
//  Implementation of the Class SysDeviceIf
//  Created on:      2016/05/26 11:27:54
//  Original author: 037789
///////////////////////////////////////////////////////////

#if !defined(EA_6C10D480_02C4_4b08_BDAB_A5037FE6C9D1__INCLUDED_)
#define EA_6C10D480_02C4_4b08_BDAB_A5037FE6C9D1__INCLUDED_

#include "SerialCom.h"
#include "SubsystemIf.h"

class SerialCom;

class SysDeviceIf : public SubsystemIf
{
private:
	static SysDeviceIf* instance;
	SerialCom *the_serial_com;

	SysDeviceIf();

public:
	virtual ~SysDeviceIf();

    void initialize();
	void doStartConsoleDev();
	virtual SysDeviceIf* getInstance();
	inline void set_the_serial_com(SerialCom* rv_obj);
	void ntfTimeOut(EmTimerId rv_timer_id);

};

inline void SysDeviceIf::set_the_serial_com(SerialCom* rv_obj){

    the_serial_com = rv_obj;
}

#endif // !defined(EA_6C10D480_02C4_4b08_BDAB_A5037FE6C9D1__INCLUDED_)
