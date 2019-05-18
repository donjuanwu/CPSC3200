/*
-- Developer    : Don Dang
-- Project      : Project 5
-- Instructor   : Dr. Dingle
-- File Name    : factor.h
-- File Version : 1.1
-- Due Date	    : 5/24/2019
-- Course Name  : CPSC 3200
----------------------------------------------------------------------------------
-- WHEN     WHO		WHAT
	 5/17/19  DD    Ported factor.cs to factor.h
									Updated factor.h from feedback (See Factor Feeback in factor.cpp file)
*/



#ifndef FACTOR_H
#define FACTOR_H
#include <iostream>
using namespace std;
class factor
{
	friend ostream & operator << (ostream& os, const factor & f);


private:
	unsigned int divFactor;
	unsigned int multiplesCount;
	unsigned int lastNumber;
	bool isObjectActive;
	static const int INITIAL_LAST_NUMBER = -1;
	static const int INITIAL_MULTIPLESCOUNT = 0;
	static const int INITIAL_FACTOR_VALUE = 1;
	static const int RETURN_INACTIVE = -1;


public:
	factor(unsigned int initFactor = INITIAL_FACTOR_VALUE);
	~factor();

	unsigned int GetMultiplesCount();
	bool Div(unsigned int number);
	void Reset();
	bool GetFactorStatus();
};

#endif 


