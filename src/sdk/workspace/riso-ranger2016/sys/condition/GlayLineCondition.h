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
	float m_ColorValue;			// �J���[�Z���T�l
	float m_ColorValuePrev;		// �P�ʎ��ԑO�̃J���[�Z���T�l
	float m_ColorValueDif;		// �P�ʎ��ԑO�ƌ��݂̃J���[�Z���T�l�̍�
	const int c_dif = -20;		// 臒l

};
#endif /* WORKSPACE_RISO_RANGER2016_SYS_CONDITION_GLAYLINECONDITION_H_ */