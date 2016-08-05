/**
 * This sample program balances a two-wheeled Segway type robot such as Gyroboy in EV3 core set.
 *
 * References:
 * http://www.hitechnic.com/blog/gyro-sensor/htway/
 * http://www.cs.bgu.ac.il/~ami/teaching/Lejos-2013/classes/src/lejos/robotics/navigation/Segoway.java
 */

#include "ev3api.h"
#include "app.h"

#include "libcpp-test.h"

#include "Motor.h"
#include "WheelControl.h"
#include "TailControl.h"
#include "ColorSensor.h"
#include "StateObserver.h"
#include "Sequencer.h"
#include "Scenario.h"
#include "LeftCourseScenario.h"
#include "Sequence.h"
#include "SitWaitAction.h"
#include "EmptyCondition.h"
#include "Battery.h"
#include "GyroSensor.h"
#include "Action.h"
#include "Condition.h"

#define DEBUG

#ifdef DEBUG
#define _debug(x) (x)
#else
#define _debug(x)
#endif

class TestClass {
public:
    TestClass() {
        //static char buf[256];
        //sprintf(buf, "Object has been created.");
        //ev3_lcd_draw_string(buf, 0, 16);
        member = 0x12345678;
    }

    void testMethod() {
        static char buf[256];
        sprintf(buf, "Member is 0x%08x.", member);
        ev3_lcd_draw_string(buf, 0, 32);
    }
private:
    int member;
};

static FILE* bt = NULL;

void idle_task(intptr_t unused) {
    while(1) {
    	fprintf(bt, "Press 'h' for usage instructions.\n");
    	tslp_tsk(1000);
    }
}


void main_task(intptr_t unused) {

    bt = ev3_serial_open_file(EV3_SERIAL_BT);

	int heartBeatCount = 0;

	// インスタンス生成、関連構築、初期化
	Sequencer* sequencer = new Sequencer(new Sequence(new SitWaitAction(90), new EmptyCondition()));
	Scenario* scenario = new LeftCourseScenario();

	Motor* leftMotor = new Motor(EV3_PORT_C);
	Motor* rightMotor = new Motor(EV3_PORT_B);
	Motor* tailMotor = new Motor(EV3_PORT_A);
	Battery* battery = new Battery();
	GyroSensor* gyroSensor = new GyroSensor(EV3_PORT_4);
	ColorSensor* colorSensor = new ColorSensor(EV3_PORT_3);

	StateObserver* stateObserver = new StateObserver(leftMotor, rightMotor, tailMotor, colorSensor);
	WheelControl* wheelControl = new WheelControl(leftMotor, rightMotor, battery, gyroSensor);
	TailControl* tailControl = new TailControl(tailMotor);

	scenario->init(sequencer);
	Action::init(stateObserver, tailControl, wheelControl);
	Condition::init(stateObserver);
	wheelControl->Init();

	// シナリオ生成
	scenario->start();

	while(1) {

		leftMotor->UpdateAngularVelocity();		// 中
		rightMotor->UpdateAngularVelocity();	// 中
		tailMotor->UpdateAngularVelocity();		// 中
		stateObserver->Calc();					// 中
		tailControl->Control();					// 高
		wheelControl->Control();				// 高
		sequencer->cycle();						// 低

		if(heartBeatCount%250 == 0) {
			ev3_led_set_color(LED_ORANGE);
		}
		else if((heartBeatCount+125)%250 == 0) {
			ev3_led_set_color(LED_GREEN);
		}
		heartBeatCount++;

		tslp_tsk(4);
	}

}
