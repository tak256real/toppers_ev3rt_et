///////////////////////////////////////////////////////////
//  Main.h
//  Implementation of the Class Main
//  Created on:      2016/04/28 11:49:13
//  Original author: 037789
///////////////////////////////////////////////////////////

#if !defined(EA_1786ABD9_CBEF_4442_86F2_F722887FE3A0__INCLUDED_)
#define EA_1786ABD9_CBEF_4442_86F2_F722887FE3A0__INCLUDED_

#include "system_task.h"


class Task;

class Main : public Task
{

public:
	virtual ~Main();

	virtual void start();
	inline Task* get_the_task(EmTaskId rv_id);
    Main* getInstance();

private:
    Main(sint32 rv_tsk_id, sint32 rv_mbox_id);
    
	Task *the_task[kMaxTaskId];
    static Main* instance;
    
	void create();
	virtual void loop();
	virtual void initialize();

};

inline Task* Main::get_the_task(EmTaskId rv_id){

	return the_task[EmTaskId rv_id];
}

#endif // !defined(EA_1786ABD9_CBEF_4442_86F2_F722887FE3A0__INCLUDED_)
