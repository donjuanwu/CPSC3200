/*
-- Developer    : Don Dang
-- Project      : Project 4
-- Instructor   : Dr. Dingle
-- File Name    : pwdCheck.cpp
-- File Version : 1.0
-- Due Date	    : 5/15/2019
-- Course Name  : CPSC 3200
*/

#include "pwdCheck.h"

pwdCheck::pwdCheck(unsigned int length)
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


