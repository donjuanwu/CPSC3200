/*
-- Developer    : Don Dang
-- Project      : Project 4
-- Instructor   : Dr. Dingle
-- File Name    : flipExcessC.cpp
-- File Version : 1.0
-- Due Date	    : 5/15/2019
-- Course Name  : CPSC 3200
*/

#include "flipExcessC.h"
flipExcessC::flipExcessC() : excessC(), flip() { }
flipExcessC::flipExcessC(unsigned int len, bool isOn, string password) : excessC(len, isOn), flip(password){ }

bool flipExcessC::flipExcessCCharacter(unsigned int uIndex)
{
	string flippedEx = flipChar(uIndex);
	return ValidatePassword(flippedEx);

}