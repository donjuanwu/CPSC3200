/*
-- Developer    : Don Dang
-- Project      : Project 4
-- Instructor   : Dr. Dingle
-- File Name    : excessC.cpp
-- File Version : 1.1
-- Due Date	    : 5/15/2019
-- Course Name  : CPSC 3200
--------------------------------------------------------------------------------------------

OVERVIEW:
 - This class inherit from pwdCheck class
 - When this object is in the 'Off' state, it will acts like pwdCheck class
 - When this object is 'ON':
	 1. it requires the Pth character in the password to be a digit
	 2. password is mixed case
	 3. password contains a '$'
- If these three conditions are valid then return true
- Else, return false

---------------------------------------------------------------------------------------------------
Design Decisions and Assumptions:
 - Pth character is the required minimum length for a password defined during firing constructor
 - If Pth length is less than 4, then assign 4 to Pth length.
 - During firing constructor all data members will be initialized
 - call the pwdCheck constructor and pass it the Pth lenght
----------------------------------------------------------------------------------------------------
IMPLEMENTATION INVARIANTS:
ValidatePassword()
- Determine if object is ON/OFF
- If ON call helper function IsPasswordValid(). Password validation will be on
these conditions:
1. Password contains an integer
2. Password contains mixedcase
3. Password contains dollar sign
Return true if all conditions are met
- If OFF, then call base.ValidatePassword(). Password validation will depend on
base validation conditions.
Return result from base validation to calling function

IsPasswordValid()
- invoke this function when object status is ON
- this function will call three helper functions to validate if password is valid
- called helper functions in the following orders:
1. IsInteger()
2. IsStringMixedCase()
3. IsDollarSign

IsInteger()
- helper function to determine if password contain an integer
- if true, update isInteger variable


IsStringMixedCase()
- helper function to determine if password has mixed case
- if true, update isMixedCase variable

IsDollarSign()
- helper to determine if password contains $ sign

GetIsMixedCase()
- accessor return password has mixed case

----------------------------------------------------------------------------------
CLASS INVARIANTS:
Return true when password meets following requirements:
1. Object is not LOCKED
2. Password has at least one repeating charcter
3. Password pass pwdCheck.ValidatePassword()

----------------------------------------------------------------------------------
-- WHEN     WHO     WHAT
	 5/11/19	DD      Ported excessC.cs to excessC.cpp
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
