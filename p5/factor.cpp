/*
-- Developer    : Don Dang
-- Project      : Project 5
-- Instructor   : Dr. Dingle
-- File Name    : factor.cpp
-- File Version : 1.1
-- Due Date	    : 5/24/2019
-- Course Name  : CPSC 3200


-------------------------------------------------------------------------------
FACTOR Feedback:
  -2 number passed to div is an uint but it is stored in an int.  Uints may not fit in an int.
	-2 confusingly similar variable names.  initialFactor and INITIAL_FACTOR
	-5 no way to check if factor is active
	-3 div should return whether or not the value was a multiple not the div count
	-1 GetDivCount not descriptive of actual value returned.  Try GetMultiplesCount

----------------------------------------------------------------------------------
-- WHEN     WHO		WHAT
	 5/17/19  DD    Ported factor.cs to factor.cpp
	                Updated factor.cpp from feedback (See above Factor Feedback section)
*/


#include "factor.h"

factor::factor(unsigned int uFactor)
{ 
	if (uFactor <= 1)
	{
		divFactor = INITIAL_FACTOR_VALUE;
	}
	divFactor = uFactor;
	multiplesCount = INITIAL_MULTIPLESCOUNT;
	isObjectActive = true;
	lastNumber = INITIAL_LAST_NUMBER;
}
factor::~factor() { }

unsigned factor::GetMultiplesCount()
{
	return multiplesCount;
}

bool factor::Div(unsigned int number)
{
	if (isObjectActive)
	{

		if (number != lastNumber) 
		{
			lastNumber = number;
			if (number % divFactor == 0)
			{
				return true;
			}
		}

		isObjectActive = false;
	}
	return false;
}

void factor::Reset()
{
	multiplesCount = INITIAL_MULTIPLESCOUNT;
	lastNumber = INITIAL_LAST_NUMBER;
	isObjectActive = true;
}

bool factor::GetFactorStatus()
{
	return isObjectActive;
}

ostream& operator << (ostream& os, const factor & f)
{
	os << "Object status: " << f.isObjectActive << "div factor: " << f.Div << endl;

	return os << endl;
}