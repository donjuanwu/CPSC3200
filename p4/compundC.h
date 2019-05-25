/*
-- Developer    : Don Dang
-- Project      : Project 4
-- Instructor   : Dr. Dingle
-- File Name    : compundC.h
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
INTERFACE INVARIANTS:
IsObjectLocked()
 - Validate a password
 - If return true if object is not locked and password meets all requirements

GetLockedStatus()
- accessor to return object locked status

---------------------------------------------------------------------------------
CLASS INVARIANTS:
Return true when password meets following requirements:
1. Object is not LOCKED
2. Password has at least one repeating charcter
3. Password pass pwdCheck.ValidatePassword()

----------------------------------------------------------------------------------
-- WHEN     WHO     WHAT
   5/12/19  DD			Ported compundC.cs to compundC.h
*/

#ifndef COMPUNDC
#define COMPUNDC
#include "pwdCheck.h"
using namespace std;

class compundC: public pwdCheck
{
private:
	unsigned int countCompCRequest;
	unsigned int toggleMax;
	bool isCompCLocked;
	const static int INIT_TOGGLE_MAX = 3;
	const static int INIT_PASSWORD_LENGTH = 4;
	const static unsigned int ONECYCLE = 2;

public:
	compundC();
	compundC(unsigned int len, unsigned int toggleNum);

	bool ValidatePassword(string strPwd);
	bool IsObjectLocked();
	bool IsRepeatedChar(string str);
	bool GetLockedStatus();


};


#endif



