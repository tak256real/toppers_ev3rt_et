///////////////////////////////////////////////////////////
//  Task.cpp
//  Implementation of the Class Task
//  Created on:      2016/04/28 11:49:10
//  Original author: 037789
///////////////////////////////////////////////////////////

#include "SubsystemBridge.h"
#include "Task.h"


Task::Task(sint32 rv_tsk_id, sint32 rv_mbox_id)
    : task_id(rv_tsk_id),
      msg_box_id(rv_mbox_id)
{

}



Task::~Task(){

}




// 受信したメッセージをサブシステムに分配.
void Task::loop(){
    uint16* at_msg = NULL;

    for(;;) {
        RTOS::rcvMessage(static_cast<void **>(&at_msg), msg_box_id);

        uint16 at_subsys_id = *at_msg; // 先頭 2Byte は宛先 SubSystem.
        uint16 * at_msg_data = at_msg + 1; // データ

        // SubSystem が配下に存在すればメッセージを投げる.
        if(isOwnMessage(at_subsys_id) == true) {
            the_subsystem_bridge[at_subsys_id]->receiveMessage(at_msg_data);
        }

        // メッセージ領域の開放.
        delete[] at_msg;
    }
}


void Task::initialize(){

}


void Task::start(){

}



bool Task::isOwnMessage(){

	return false;
}
