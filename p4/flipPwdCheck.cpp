/*
-- Developer    : Don Dang
-- Project      : Project 4
-- Instructor   : Dr. Dingle
-- File Name    : flipPwdCheck.cpp
-- File Version : 1.0
-- Due Date	    : 5/15/2019
-- Course Name  : CPSC 3200
*/

#include "flipPwdCheck.h"

flipPwdCheck::flipPwdCheck(unsigned int length, string password) : pwdCheck(length), flip(password) { }

bool flipPwdCheck::flipPwdCheckCharacter(unsigned int uIndex)
{
	string flippedPwd = flipChar(uIndex);
	return ValidatePassword(flippedPwd);
}



