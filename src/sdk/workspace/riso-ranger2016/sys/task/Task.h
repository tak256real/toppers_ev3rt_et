///////////////////////////////////////////////////////////
//  Task.h
//  Implementation of the Class Task
//  Created on:      2016/04/28 11:49:10
//  Original author: 037789
///////////////////////////////////////////////////////////

#if !defined(EA_C47B409B_FB08_431b_B2E8_7EFDD1752A11__INCLUDED_)
#define EA_C47B409B_FB08_431b_B2E8_7EFDD1752A11__INCLUDED_

class Task
{

public:
	Task();
	virtual ~Task();

	virtual void start() = 0;

private:
	sint32 task_id;
	sint32 msg_box_id;

	virtual void loop() = 0;
	virtual void initialize() = 0;

};
#endif // !defined(EA_C47B409B_FB08_431b_B2E8_7EFDD1752A11__INCLUDED_)
