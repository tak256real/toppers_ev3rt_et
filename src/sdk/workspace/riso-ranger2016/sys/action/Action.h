///////////////////////////////////////////////////////////
//  Action.h
//  Implementation of the Class Action
//  Created on:      2016/07/27 11:47:44
//  Original author: 039389
///////////////////////////////////////////////////////////

#if !defined(EA_328EF76F_92B6_4a4a_BB28_306BB0AD8654__INCLUDED_)
#define EA_328EF76F_92B6_4a4a_BB28_306BB0AD8654__INCLUDED_

#include "StateObserver.h"
#include "TailControl.h"
#include "WheelControl.h"

class Action
{

public:
	Action();
	virtual ~Action();

	virtual void cycle()=0;
	virtual void init(StateObserver* stateObserver, TailControl* tailControl, WheelControl* wheelControl) final;	// オーバーライド禁止

	StateObserver* getStateObserver();
	TailControl* getTailControl();
	WheelControl* getWheelControl();

protected:
	StateObserver* m_StateObserver;
	TailControl* m_TailControl;
	WheelControl* m_WheelControl;

private:
	void EmergencyStop();

};
#endif // !defined(EA_328EF76F_92B6_4a4a_BB28_306BB0AD8654__INCLUDED_)
