/*
-- Developer    : Don Dang
-- Project      : Project 4
-- Instructor   : Dr. Dingle
-- File Name    : excessC.cpp
-- File Version : 1.0
-- Due Date	    : 5/15/2019
-- Course Name  : CPSC 3200
*/


#include "excessC.h"

excessC::excessC() : pwdCheck() 
{
	exPwdLength = INIT_PASSWORD_LENGTH;
	exActiveStatus = false;
	isInteger = false;
	isMixedCase = false;
}
excessC::excessC(unsigned int len, bool isOn) : pwdCheck(len) 
{
	if (len < INIT_PASSWORD_LENGTH)
	{
		len = INIT_PASSWORD_LENGTH;
	}
	exPwdLength = len;
	exActiveStatus = isOn;
	isInteger = false;
	isMixedCase = false;
}

bool excessC::ValidatePassword(string pwd)
{
	if (exActiveStatus)
	{
		return IsPasswordValid(pwd);
	}
	return pwdCheck::ValidatePassword(pwd);
}

bool excessC::IsPasswordValid(string str)
{
	return IsInteger(str) && IsStringMixedCase(str) && IsDollarSign(str);
	
}


bool excessC::IsInteger(string str)
{
	if (str.length() >= exPwdLength)
	{
		if (isdigit(str[exPwdLength - 1]))
		{
			isInteger = true;
			return true;
		}
	} 
	return false;
}


bool excessC::IsStringMixedCase(string str)
{
	bool isLower = false;
	bool isUpper = false;

	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (isupper(str[i]))
		{
			isUpper = true;
		}
		if (islower(str[i]))
		{
			isLower = true;
		}
		if (isUpper && isLower)
		{
			isMixedCase = true;
			return true;
		}
			
	}

	return false;
}

bool excessC::IsDollarSign(string str) 
{

	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] == DOLLAR_SIGN)
		{
			return true;
		}
	}
	return false;
}

bool excessC::GetExObjectStatus()
{
	return exActiveStatus;
}

bool excessC::GetIsInteger()
{
	return isInteger;
}

bool excessC::GetIsMixedCase()
{
	return isMixedCase;
}
