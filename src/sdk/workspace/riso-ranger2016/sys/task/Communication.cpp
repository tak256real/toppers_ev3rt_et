///////////////////////////////////////////////////////////
//  Communication.cpp
//  Implementation of the Class Communication
//  Created on:      2016/05/30 9:06:08
//  Original author: 037789
///////////////////////////////////////////////////////////

#include "Communication.h"


Communication::Communication(sint32 rv_tsk_id, sint32 rv_mbox_id)
    : Task(rv_tsk_id, rv_mbox_id)
{

}



Communication::~Communication(){

}





void Communication::start(){
    loop();
}




bool Communication::isOwnMessage(EmSubsystemId rv_subsys_id){

	return false;
}
