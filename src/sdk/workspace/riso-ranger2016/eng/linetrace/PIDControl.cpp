///////////////////////////////////////////////////////////
//  PIDControl.cpp
//  Implementation of the Class PIDControl
//  Created on:      2016/07/22 19:45:36
//  Original author: 039889
///////////////////////////////////////////////////////////

#include "PIDControl.h"


PIDControl::PIDControl(){
	m_P=80;
	m_I=0;
	m_D=80;
	m_preerror=0;
	m_sumerror=0;
}


PIDControl::~PIDControl(){

}


int PIDControl::PIDCalculation(float reference, float currentVal){
	int result=0;
	float error=0;

	error = reference - currentVal;
	m_sumerror += error;//積分計算

	result = (m_P*error) + (m_I*m_sumerror) + m_D*(error - m_preerror);
	m_preerror = error;
	
	return result;
}