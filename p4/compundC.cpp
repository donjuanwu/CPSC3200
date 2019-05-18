/*
-- Developer    : Don Dang
-- Project      : Project 4
-- Instructor   : Dr. Dingle
-- File Name    : compundC.cpp
-- File Version : 1.1
-- Due Date	    : 5/15/2019
-- Course Name  : CPSC 3200
--------------------------------------------------------------------------------------------

OVERVIEW:
 - This class inherit from pwdCheck class
 - This class acts like pwdCheck
 - Except it requires the password to have at least one repeating character
 - Except it cannot be toggled ON/OFF more than k cycle time
 - Return true if the password meets all requirement
 - Return false if failed requirement

---------------------------------------------------------------------------------------------
Design Decisions and Assumptions:
 - K cycle value = pwdCheck pwdLength * toggledMax * 2
 - When toggled = K cycle limit then this class object cannot be toggled
	 the object status will be stayed static.
 - Evoking override ValidatePassword() will peform the following steps:
 1.If this object is LOCKED
		if Locked, return true

 2.If not, pass the password to pwdCheck.ValidatePassword()
If both steps above are true then return true

DATA MEMBERS DICTIONARY:
uint countCompCRequest    - keep track of number of password request
uint toggleMax            - max toggle limit
bool isCompCLocked        - indicate object is maxed out at toggle on/off limit
const int INIT_TOGGLE_MAX = 3;
const int INIT_PASSWORD_LENGTH = 4;
const uint ONECYCLE = 2;

------------------------------------------------------------------------------
IMPLEMENTATION INVARIANTS:
IsObjectLocked()
- Invoking this function will increment the countCompundC password request.
- countCompundC will be check agains the max K toggled cycle.
- The max K toggled cycle is derived by (pwdCheck pwdLength * toggledMax * 2)
- If countCompundC eqauls max K toggled cycle, this object will be LOCKED forever
- Once the object is LOCKED, the password will always be returned false
- When object is not LOCKED, then password requirement will follow pwdCheck rules
	and password must contain a repeated character

IsRepeatedChar()
- helper function to return if password contains a repeated character

GetLockedStatus()
- helpfer function to object locked status
----------------------------------------------------------------------------------
CLASS INVARIANTS:
Return true when password meets following requirements:
1. Object is not LOCKED
2. Password has at least one repeating charcter
3. Password pass pwdCheck.ValidatePassword()

----------------------------------------------------------------------------------
-- WHEN     WHO     WHAT
	 5/12/19  DD			Ported compundC.cs to compundC.cpp
*/

#include "compundC.h"

compundC::compundC() : pwdCheck()
{
	countCompCRequest = 0;
	toggleMax = INIT_TOGGLE_MAX;
	isCompCLocked = false;
}

compundC::compundC(unsigned int len, unsigned int toggleNum = INIT_TOGGLE_MAX) : pwdCheck(len)
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