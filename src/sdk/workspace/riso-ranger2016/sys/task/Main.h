///////////////////////////////////////////////////////////
//  Main.h
//  Implementation of the Class Main
//  Created on:      2016/04/28 11:49:13
//  Original author: 037789
///////////////////////////////////////////////////////////

#if !defined(EA_1786ABD9_CBEF_4442_86F2_F722887FE3A0__INCLUDED_)
#define EA_1786ABD9_CBEF_4442_86F2_F722887FE3A0__INCLUDED_

#include "src\sdk\workspace\riso-ranger2016\sys\task\Task.h"

class Main : public Task
{

public:
	Main();
	virtual ~Main();

	virtual void start();

private:
	void create();
	virtual void roop();
	virtual void initialize();

};
#endif // !defined(EA_1786ABD9_CBEF_4442_86F2_F722887FE3A0__INCLUDED_)
