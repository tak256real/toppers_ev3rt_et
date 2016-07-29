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

Linetrace* linetrace = new Linetrace(wheelControl, calibration);

StateObserver* stateObserver = new StateObserver( wheelMotorL,  wheelMotorR,  tailMotor,  calibration);

void main_task(intptr_t unused) {

	int heartBeatCount = 0;

	tailControl->SetRefValue(45);
	wheelControl->Init();

	while(1) {

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
			wheelControl->SetTwoWheelMode(true);
		}

		tslp_tsk(4);
	}

}
