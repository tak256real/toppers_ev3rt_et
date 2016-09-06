/*
 * GlayLineCondition.h
 *
 *  Created on: 2016/08/31
 *      Author: Reina
 */

#ifndef WORKSPACE_RISO_RANGER2016_SYS_CONDITION_GLAYLINECONDITION_H_
#define WORKSPACE_RISO_RANGER2016_SYS_CONDITION_GLAYLINECONDITION_H_

#include "Condition.h"

class GlayLineCondition : public Condition
{

public:
	GlayLineCondition();
	virtual ~GlayLineCondition();

	virtual void onStart();
	virtual bool check();

private:
	float m_ColorValue;			// カラーセンサ値
	float m_ColorValuePrev;		// 単位時間前のカラーセンサ値
	float m_ColorValueDif;		// 単位時間前と現在のカラーセンサ値の差
	const int c_dif = -20;		// 閾値 ToDo:測定して変更
	
	int m_Count;
	const int c_arrayNum = 9;		// 配列の個数 ToDo:測定して変更の必要ありかも
	float ColorValueArray[9];


};
#endif /* WORKSPACE_RISO_RANGER2016_SYS_CONDITION_GLAYLINECONDITION_H_ */