///////////////////////////////////////////////////////////
//  SysDeviceIf.h
//  Implementation of the Class SysDeviceIf
//  Created on:      2016/05/26 11:27:54
//  Original author: 037789
///////////////////////////////////////////////////////////

#if !defined(EA_6C10D480_02C4_4b08_BDAB_A5037FE6C9D1__INCLUDED_)
#define EA_6C10D480_02C4_4b08_BDAB_A5037FE6C9D1__INCLUDED_

#include "SubsystemIf.h"

class SysDeviceIf : public SubsystemIf
{
private:
	static SysDeviceIf* instance;

	SysDeviceIf();

public:
	virtual ~SysDeviceIf();

	void doStartRcvCommand();
	virtual SysDeviceIf* getInstance();

};
#endif // !defined(EA_6C10D480_02C4_4b08_BDAB_A5037FE6C9D1__INCLUDED_)
