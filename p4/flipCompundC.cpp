/*
-- Developer    : Don Dang
-- Project      : Project 4
-- Instructor   : Dr. Dingle
-- File Name    : flipCompundC.cpp
-- File Version : 1.0
-- Due Date	    : 5/15/2019
-- Course Name  : CPSC 3200
*/


#include "flipCompundC.h"

flipCompundC::flipCompundC(unsigned int len, unsigned int toggleNum, string password) : compundC(len, toggleNum), flip (password){ }

bool flipCompundC::flipCompundCCharacter(unsigned int uIndex)
{
	string flippedComp = flipChar(uIndex);
	return ValidatePassword(flippedComp);
}



