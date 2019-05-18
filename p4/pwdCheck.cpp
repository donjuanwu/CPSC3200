/*
-- Developer    : Don Dang
-- Project      : Project 4
-- Instructor   : Dr. Dingle
-- File Name    : pwdCheck.cpp
-- File Version : 1.1
-- Due Date	    : 5/15/2019
-- Course Name  : CPSC 3200
--------------------------------------------------------------------------------------------
OVERVIEW:
 - This class accepts a password of length at least P (where p is a stable
		value tha varies from object to object).
 - A password is not acceptable if it contains a forbidden symbol.
 - This class object is toggled when the number of password validation equals P.

---------------------------------------------------------------------------------------------
Design Decisions and Assumptions:
 - P is given when the class constructor fired.
 - P length must be at least 4. If P doesn't = 4 then it get assign a default value of 4
 - A default forbidden characters array will be initialized during constructor firing
 - The forbidden characters can be changed with a mutator
 - Private data members are exposed with accessors/mutators

DATA MEMBERS DICTIONARY:
char[] charForBidden      - hold forbidden characters
const int ASCII_NUM = 127 - indicate max value of ASCII
readonly uint pwdLength   - hold P value
bool isObjectActive       - indicate object active status
bool isCharForbidden      - indicate if forbidden character found in password
uint countValidation      - indicate number of validation request
const int DEFAULT_PWD_Length = 4

------------------------------------------------------------------------------
IMPLEMENTATION INVARIANTS:
pwdCheck()
- intialized private data members to their default value

Virtual ValidatePassword()
- return true when object status is true, password meet length requirement
	and password doesn't contain forbidden character
- return false, if any of the above condition failed
- invoking this function may object state
- this function can be override by it children

IsForbiddenCharacter()
- helper function to validate password
- determine if password contain forbidden characters
- return true, contain forbidden character(s)
- return false, no forbidden character(s)

IsPasswordLength()
- helper function to validate password
- determine if password length meet the set password length in the constructor
- return true, if password meet length requirement
- return false, if password doesn't meet length requirement

IsObjectStateChanged()
- helper function to determine if object state needs to be toggled
- when this function get invoked, determine object status
- if object is active, then increment count of password
	determine if count of password request equals request limit
	if yes, toggle object state then return true
- if object is inactive, then decrement count of password
	determine if count of password request equals 0
	if yes, toggle object state then return true

GetPasswordLength()
- accessor function to return predefined set password

IsObjectActive()
- accessor function to return object status

GetASCIINumber()
- protected function to return const ASCII max value

GetIsCharForbidden()
- accessor to return password contain forbidden characters status

SetForbiddenCharacters()
- mutator to set forbidden characters
----------------------------------------------------------------------------------
CLASS INVARIANTS:
Return true when password meets following requirements:
1. Object is status is active
2. Password length meets minimum password length
3. Password doesn't contain forbidden character(s)

----------------------------------------------------------------------------------
-- WHEN     WHO		WHAT
   5/11/19  DD		Ported pwdCheck.cs to pwdCheck.cpp
*/

#include "pwdCheck.h"
pwdCheck::pwdCheck()
{
	isActive = true;
	pwdLength = DEFAULT_PWD_LENGTH;
	countValidation = 0;
	isCharForbidden = 0;
	strForBidden = " ~(){}[]";
}
pwdCheck::pwdCheck(unsigned int length = DEFAULT_PWD_LENGTH) //: pwdLength(DEFAULT_PWD_LENGTH)
{
	if (length < DEFAULT_PWD_LENGTH)
	{
		length = DEFAULT_PWD_LENGTH;
	}

	isActive = true;
	pwdLength = length;
	countValidation = 0;
	isCharForbidden = 0;
	strForBidden = " ~(){}[]"; 
	
}

bool pwdCheck::ValidatePassword(string strAlphaNumeric) 
{
	ToggleObject();
	if (isActive)
	{
		if (IsPasswordLength(strAlphaNumeric))
		{
			return !IsForbiddenCharacter(strAlphaNumeric);
		}
	}
	return false;
}


//PRE :Object state is already assigned
//POST:Object state may be toggled
//Update count of password requested
//Determine if number of password validation equals request limit
void pwdCheck::ToggleObject()
{
	if (isActive)
	{
		if (++countValidation == pwdLength)
		{
			isActive = false;
		}

	}
	else
	{
		if (countValidation > 0)
		{
			countValidation--;
			if (pwdLength - countValidation == pwdLength)
			{
				isActive = true;
			}
		}
	}
}


bool pwdCheck::IsPasswordLength(string word)
{
	int count = (int)word.length();
	return (count >= (int) pwdLength);
}

bool pwdCheck::IsForbiddenCharacter(string strPwd)
{
	for (int i = 0; i < (int)strPwd.length(); i++)
	{
		for (int j = 0; j < (int)strForBidden.length(); j++)
		{
			if (((int)strPwd[i] == (int)strForBidden[j]) || ((int)strPwd[i] > ASCII_NUM))
			{
				isCharForbidden = true;
				return true;
			}
		}
	}
	return false;
}

int pwdCheck::GetPasswordLength()
{
	return (int)pwdLength;
}

bool pwdCheck::GetObjectStatus()
{
	return isActive;
}

bool pwdCheck::GetIsCharForbidden()
{
	return isCharForbidden;
}

void pwdCheck::SetForbiddenCharacters(string newCharacters)
{
	strForBidden = newCharacters;
}

int pwdCheck::GetASCIINumber()
{
	return ASCII_NUM;
}


