/*
-- Developer    : Don Dang
-- Project      : Project 4
-- Instructor   : Dr. Dingle
-- File Name    : compundC.cpp
-- File Version : 1.0
-- Due Date	    : 5/15/2019
-- Course Name  : CPSC 3200
*/

#include "compundC.h"

compundC::compundC(unsigned int len, unsigned int toggleNum) : pwdCheck(len)
{
	if (toggleMax < INIT_TOGGLE_MAX)
	{
		toggleNum = INIT_TOGGLE_MAX;
	}

	countCompCRequest = 0;
	toggleMax = toggleNum;
	isCompCLocked = false;
}

bool compundC::ValidatePassword(string strPwd)
{
	return !IsObjectLocked() && pwdCheck::ValidatePassword(strPwd) && IsRepeatedChar(strPwd);
}

bool compundC::IsObjectLocked()
{
	if (!isCompCLocked)
	{
		if (++countCompCRequest == (pwdCheck::GetPasswordLength() * toggleMax * ONECYCLE))
		{
			isCompCLocked = true;
			return true;
		}
		return false;
	}
	return true;
}

bool compundC::IsRepeatedChar(string str)
{
	int arrChar[pwdCheck::GetASCIINumber()];
	int index;
	for (unsigned int i = 0; i < (unsigned) str.length(); i++)
	{
		index = (int)str[i];
		if (++arrChar[index] > 1)
		{
			return true;
		}
	}
	return false;
}

bool compundC::GetLockedStatus()
{
	return isCompCLocked;
}