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
#include "Linetrace.h"
#include "ColorSensor.h"
#include "StateObserver.h"
#include "Temp.h"

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

Motor* wheelMotorL = new Motor(Temp::wheelLPort);
Motor* wheelMotorR = new Motor(Temp::wheelRPort);
Motor* tailMotor = new Motor(Temp::tailPort);

WheelControl* wheelControl = new WheelControl(wheelMotorL, wheelMotorR);
TailControl* tailControl = new TailControl(tailMotor);

ColorSensor* getSensorValue = new ColorSensor(Temp::colorSensorPort);
Calibration* calibration = new Calibration(getSensorValue);

StateObserver* stateObserver = new StateObserver( wheelMotorL,  wheelMotorR,  tailMotor,  calibration);

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
	Linetrace* linetrace;

	Temp::init();
	tailControl->SetRefValue(90);
	wheelControl->Init();

	while(1) {

		if(1250 < heartBeatCount) {
			linetrace->exec();
		}
		tailControl->Control();
		wheelControl->Control();

		if(heartBeatCount%250 == 0) {
			ev3_led_set_color(LED_ORANGE);
		}
		else if((heartBeatCount+125)%250 == 0) {
			ev3_led_set_color(LED_GREEN);
		}
		heartBeatCount++;

		if(heartBeatCount == 1250) {
			tailControl->SetRefValue(0);
			linetrace = new Linetrace(wheelControl, calibration);
		}

		tslp_tsk(4);
	}

}
