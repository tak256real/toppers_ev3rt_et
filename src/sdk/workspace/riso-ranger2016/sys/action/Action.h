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

/**
 * 単動作クラス
 * 本クラスの子クラス内でインスタンス生成した場合は自分でdeleteすること
 */
class Action
{

public:
	Action();
	virtual ~Action();

	virtual void init(StateObserver* stateObserver, TailControl* tailControl, WheelControl* wheelControl) final;	// オーバーライド禁止
	virtual void EmergencyStop() final;					// オーバーライド禁止

	virtual StateObserver* getStateObserver() final;	// オーバーライド禁止
	virtual TailControl* getTailControl() final;		// オーバーライド禁止
	virtual WheelControl* getWheelControl() final;		// オーバーライド禁止

	virtual void onStart() =0;							// onCycle()周期実行の開始直前に1回実行される
	virtual void onCycle() =0;							// APIのbalance_control()実行周期4msの倍数で実行する
	virtual void onStop() =0;							// onCycle()周期実行の終了直後に1回実行される

protected:
	StateObserver* m_StateObserver;
	TailControl* m_TailControl;
	WheelControl* m_WheelControl;

};
#endif // !defined(EA_328EF76F_92B6_4a4a_BB28_306BB0AD8654__INCLUDED_)
