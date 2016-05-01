///////////////////////////////////////////////////////////
//  Timer.h
//  Implementation of the Class Timer
//  Created on:      2016/04/28 14:48:14
//  Original author: 037789
///////////////////////////////////////////////////////////

#if !defined(EA_39F53CC2_6A6E_43b5_A02D_A34E96FAAC2F__INCLUDED_)
#define EA_39F53CC2_6A6E_43b5_A02D_A34E96FAAC2F__INCLUDED_

#include "TimerId.h"


class TimerEvent;

class Timer
{

public:
	virtual ~Timer();

	Timer* getInstance();
	inline TimerEvent* get_the_event();
	inline void set_the_event(TimerEvent* rv_obj);
	void tick();
    void startTimer(uint32 rv_time, EmTimerId rv_id);
    void stopTiemr(EmTimerId rv_id);


private:
    Timer();
    
	static Timer* instance;
	TimerEvent *the_event;
	uint32 time_count[kMaxTimerId];
	bool is_inuse;

};

extern "C" void Cyc1msecInterval(intptr_t exinf);

inline TimerEvent* Timer::get_the_event(){

	return the_event;
}


inline void Timer::set_the_event(TimerEvent* rv_obj){

	the_event = rv_obj;
}

#endif // !defined(EA_39F53CC2_6A6E_43b5_A02D_A34E96FAAC2F__INCLUDED_)
