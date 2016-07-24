/*
 * StateObserver.h
 *
 *  Created on: 2016/07/24
 *      Author: ryuji
 */

#ifndef WORKSPACE_RISO_RANGER2016_SYS_DEVICE_STATEOBSERVER_H_
#define WORKSPACE_RISO_RANGER2016_SYS_DEVICE_STATEOBSERVER_H_

class StateObserver {
public:
	StateObserver();
	virtual ~StateObserver();

	int Calc();
	int GetDirection();
	float GetLinePosision();


};
#endif /* WORKSPACE_RISO_RANGER2016_SYS_DEVICE_STATEOBSERVER_H_ */

