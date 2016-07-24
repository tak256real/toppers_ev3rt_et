/*
 * StateObserver.h
 *
 *  Created on: 2016/07/24
 *      Author: ryuji
 */

#ifndef WORKSPACE_RISO_RANGER2016_SYS_DEVICE_STATEOBSERVER_H_
#define WORKSPACE_RISO_RANGER2016_SYS_DEVICE_STATEOBSERVER_H_

class StateObserver {
public:
	StateObserver(WheelMotor* wheelMotorL, WheelMotor* wheelMotorR, WheelMotor* tailMotor);
	virtual ~StateObserver();

	void Calc();					// 周期計算
	int GetDirection();				// 初期状態からの相対方位[deg]取得
	float GetLinePosition();		// ライン位置(カラーセンサ値)取得
	int GetTailAngularVelocity();	// 尻尾角速度[deg/sec]取得
	int GetRunningDistance();		// 走行距離[mm]取得

private:
	WheelMotor* m_WheelMotorL;	// 左モータ
	WheelMotor* m_WheelMotorR;	// 右モータ
	WheelMotor* m_TailMotor;	// 尻尾モータ

	const int c_WheelWidth = 165;			// 車輪幅[mm]
	const int c_WheelDiameter = 60;			// 車輪直径[mm]
	const float c_CalcInterval = 0.004;		// 計算周期[sec]
	const float c_DirectionAdjustParam = 1;	// 方位計算誤差調整値

	// 計算短縮用係数
	// 時計回りを正とすると
	// 車体回転速度[deg/sec] = 360[deg] * (左車輪周速度[mm/sec] - 右車輪周速度[mm/sec]) / (2*π*車輪幅[mm])
	// 左車輪周速度[mm/sec] = (左車輪角速度[deg/sec]/360[deg]) * (π*車輪直径[mm])
	// 右車輪も同様
	// よって方位変分[deg] = 車体回転速度[deg/sec]*計算周期[sec] = (左車輪角速度[deg/sec]-右車輪角速度[deg/sec])*車輪直径[mm] / (2*車輪幅[mm]) * 計算周期[sec]
	// c_DirCalcCoefficient = 車輪直径[mm] / (2*車輪幅[mm]) * 計算周期[sec]
	const float c_DirCalcCoefficient = c_WheelDiameter/(2*c_WheelWidth)*c_CalcInterval*c_DirectionAdjustParam;

	float m_direction;						// 方位[deg]


};
#endif /* WORKSPACE_RISO_RANGER2016_SYS_DEVICE_STATEOBSERVER_H_ */

