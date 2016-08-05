/*
 * StateObserver.h
 *
 *  Created on: 2016/07/24
 *      Author: ryuji
 */

#ifndef WORKSPACE_RISO_RANGER2016_SYS_DEVICE_STATEOBSERVER_H_
#define WORKSPACE_RISO_RANGER2016_SYS_DEVICE_STATEOBSERVER_H_

#include "Motor.h"
#include "Calibration.h"

class StateObserver {
public:
	ColorSensor *m_ColorSensor;
	StateObserver(Motor* wheelMotorL, Motor* wheelMotorR, Motor* tailMotor, Calibration* calibration);
	virtual ~StateObserver();

	void Calc();					// 周期計算
	float GetLinePosition();		// ライン位置(カラーセンサ値)取得
	int GetTailAngularVelocity();	// 尻尾角速度[deg/sec]取得
	int GetDirection();				// 初期状態からの相対方位[deg]取得
	int GetRunningDistance();
	int getTilt();		// 走行距離[mm]取得

private:
	Motor* m_WheelMotorL;	// 左モータ
	Motor* m_WheelMotorR;	// 右モータ
	Motor* m_TailMotor;	// 尻尾モータ
	Calibration* m_Calibration;	// キャリブレーション

	float m_Direction;							// 方位[deg]
	float m_RunningDistance;					// 走行距離[mm]

	//TODO 実機を測定して反映
	const int c_WheelWidth = 165;				// 車輪幅[mm]
	const int c_WheelDiameter = 60;				// 車輪直径[mm]
	const float c_CalcInterval = 0.004;			// 計算周期[sec]
	const float c_DirCalcAdjustParam = 1;		// 方位計算誤差調整値
	const float c_RunDisCalcAdjustParam = 1;	// 走行距離計算誤差調整値

	// 方位計算短縮用係数
	// 時計回りを正とすると
	// 車体回転速度[deg/sec] = 360[deg] * (左車輪周速度[mm/sec] - 右車輪周速度[mm/sec]) / (2*π*車輪幅[mm])
	// 左車輪周速度[mm/sec] = (左車輪角速度[deg/sec]/360[deg]) * (π*車輪直径[mm])
	// 右車輪も同様
	// よって方位変分[deg] = 車体回転速度[deg/sec]*計算周期[sec] = (左車輪角速度[deg/sec]-右車輪角速度[deg/sec])*車輪直径[mm] / (2*車輪幅[mm]) * 計算周期[sec]
	// c_DirCalcCoefficient = 車輪直径[mm] / (2*車輪幅[mm]) * 計算周期[sec]
	const float c_DirCalcCoefficient = c_WheelDiameter/(2*c_WheelWidth)*c_CalcInterval*c_DirCalcAdjustParam;

	// 走行距離計算短縮用係数
	// 走行距離変分[mm] = (左車輪周速度[mm/sec] + 右車輪周速度[mm/sec)/2 * 計算周期[sec]
	// 上記より定数部を抜き出すと
	// c_RunDisCalcCoefficient = 車輪直径[mm] * π * 計算周期[sec] / (2*360[deg])
	const float c_RunDisCalcCoefficient = c_WheelDiameter*3.141592*c_CalcInterval/720;

};
#endif /* WORKSPACE_RISO_RANGER2016_SYS_DEVICE_STATEOBSERVER_H_ */

