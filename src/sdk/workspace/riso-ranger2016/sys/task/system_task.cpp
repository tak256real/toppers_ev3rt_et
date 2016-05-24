///////////////////////////////////////////////////////////
//  system_task.cpp
//  Implementation of the Class system_task
//  Created on:      2016/04/28 11:21:26
//  Original author: 037789
///////////////////////////////////////////////////////////

#include "ev3api.h"
#include "system_task.h"
#include "Main.h"
#include "HighPriority.h"
#include "Engine.h"

extern "C" void TaskMain(){
    Main::getInstance()->start();
}

extern "C" void TaskHighPriority(){
//  HighPriority *at_high_priority_task = new HighPriority(ID_TASK_HIGH_PRIORITY, ID_MSG_BOX_HIGH_PRIORITY);
    HighPriority* at_task = static_cast<HighPriority *>(Main::getInstance()->get_the_task(kTaskHighPriority));

    if(at_task != NULL) {
        at_task->start();
    }
    else {
        ev3_lcd_draw_string("SYS::ERROR:: HIGH PRIORITY TASK OBJECT IS NOT EXSIST.", 0, CALIB_FONT_HEIGHT*1);
    }
}


extern "C" void TaskEngine(){
    Engine *at_task = static_cast<Engine *>(Main::getInstance()->get_the_task(kTaskEngine));

    if(at_task != NULL) {
        at_task->start();
    }
    else {
        ev3_lcd_draw_string("SYS::ERROR:: ENGINE TASK OBJECT IS NOT EXSIST.", 0, CALIB_FONT_HEIGHT*1);
    }
}

extern "C" void TaskDebugConsole(){
    Engine *at_task = static_cast<Engine *>(Main::getInstance()->get_the_task(kTaskDebugConsole));

    if(at_task != NULL) {
        at_task->start();
    }
    else {
        ev3_lcd_draw_string("SYS::ERROR:: DEBUG CONSOLE OBJECT IS NOT EXSIST.", 0, CALIB_FONT_HEIGHT*1);
    }
}

system_task::system_task(){

}



system_task::~system_task(){

}
