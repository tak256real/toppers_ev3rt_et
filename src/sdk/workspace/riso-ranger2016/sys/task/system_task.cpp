///////////////////////////////////////////////////////////
//  system_task.cpp
//  Implementation of the Class system_task
//  Created on:      2016/04/28 11:21:26
//  Original author: 037789
///////////////////////////////////////////////////////////

#include "system_task.h"
#include "Main.h"

extern "C" void TaskMain(){
    Main* the_main_task = new Main();
    the_main_task->start();
}


system_task::system_task(){

}



system_task::~system_task(){

}
