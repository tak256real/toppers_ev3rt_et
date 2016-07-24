///////////////////////////////////////////////////////////
//  SysConsoleIf.h
//  Implementation of the Class SysConsoleIf
//  Created on:      2016/07/24 23:59:49
//  Original author: 037789
///////////////////////////////////////////////////////////

#if !defined(EA_9BDFF4D2_F2FD_44c5_8ECE_2B5861EEC501__INCLUDED_)
#define EA_9BDFF4D2_F2FD_44c5_8ECE_2B5861EEC501__INCLUDED_

#include "src\sdk\workspace\riso-ranger2016\sys\arch\interface\SubsystemIf.h"

class SysConsoleIf : public SubsystemIf
{

public:
	virtual ~SysConsoleIf();

	static SysConsoleIf* getInstance();
	void initialze();

private:
	static SysConsoleIf* instance;

    SysConsoleIf();

};
#endif // !defined(EA_9BDFF4D2_F2FD_44c5_8ECE_2B5861EEC501__INCLUDED_)
