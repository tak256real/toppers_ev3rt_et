/*
 * TailRunAction.h
 *
 *  Created on: 2016/08/11
 *      Author: ryuji
 */

#ifndef WORKSPACE_RISO_RANGER2016_SYS_ACTION_TAILRUNACTION_H_
#define WORKSPACE_RISO_RANGER2016_SYS_ACTION_TAILRUNACTION_H_

#include "Action.h"

class TailRunAction: public Action {
public:
	TailRunAction();
	virtual ~TailRunAction();

	virtual void onStart();
	virtual void onCycle();
	virtual void onStop();
};

#endif /* WORKSPACE_RISO_RANGER2016_SYS_ACTION_TAILRUNACTION_H_ */
