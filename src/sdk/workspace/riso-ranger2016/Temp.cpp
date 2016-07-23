///////////////////////////////////////////////////////////
//  Temp.cpp
//  Implementation of the Class Temp
//  Created on:      2016/07/21 19:58:14
//  Original author: 039389
///////////////////////////////////////////////////////////

#include "Temp.h"

int gyroOffset;

WheelMotor* Temp::wheelMotorL = new WheelMotor(Temp::wheelLPort);
WheelMotor* Temp::wheelMotorR = new WheelMotor(Temp::wheelRPort);
WheelMotor* Temp::tailMotor = new WheelMotor(tailPort);

WheelControl* Temp::wheelControl = new WheelControl(Temp::wheelMotorL, Temp::wheelMotorR);
TailControl* Temp::tailControl = new TailControl(tailMotor);

GetSensorValue* Temp::getSensorValue = new GetSensorValue(Temp::colorSensorPort);
Calibration* Temp::calibration = new Calibration(Temp::getSensorValue);

Linetrace Temp::linetrace = new Linetrace(Temp::wheelControl, Temp::calibration);

int Temp::gyroOffset = Temp::getGyroOffset();

Temp::Temp(){

}


Temp::~Temp(){

}


void Temp::init(){

	wheelControl->Init();
}


void Temp::cycle(){

	linetrace->exec();

	wheelMotorL->UpdateAngularVelocity();
	wheelMotorR->UpdateAngularVelocity();

	wheelControl->Control();
	tailControl->Control();

}


int Temp::getBattery(){

	return ev3_battery_voltage_mV();
}


int Temp::getGyro(){

	return ev3_gyro_sensor_get_rate(gyroPort);
}

int Temp::getGyroOffset(){
	return gyroOffset;
}
