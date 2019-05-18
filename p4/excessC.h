/*
-- Developer    : Don Dang
-- Project      : Project 4
-- Instructor   : Dr. Dingle
-- File Name    : excessC.h
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



---------------------------------------------------------------------------------------------
Design Decisions and Assumptions:
 - Pth character is the required minimum length for a password defined during firing constructor
 - If Pth length is less than 4, then assign 4 to Pth length.
 - During firing constructor all data members will be initialized
 - call the pwdCheck constructor and pass it the Pth lenght

----------------------------------------------------------------------------------
INTERFACE INVARIANTS:
override ValidatePassword()
- Determine if password meet requirements
- If yes, return true
- Else, return false

GetExObjectStatus()
- accessor return object status

GetIsInteger()
- accessor return is password contain an integer

GetIsMixedCase()
- accessor return is password contains mixed case

----------------------------------------------------------------------------------

CLASS INVARIANTS:
Return true when password meets following requirements:
1. Object is not LOCKED
2. Password has at least one repeating charcter
3. Password pass pwdCheck.ValidatePassword()

----------------------------------------------------------------------------------
-- WHEN     WHO     WHAT
	 5/11/19	DD      Ported excessC.cs to excessC.h
*/

#ifndef EXCESSC_H
#define EXCESSC_H
#include <ctype.h>
#include "pwdCheck.h"

using namespace std;


class excessC: public pwdCheck
{

private:
	unsigned exPwdLength;
	bool exActiveStatus;
	bool isInteger;
	bool isMixedCase;
	const static unsigned int INIT_PASSWORD_LENGTH = 4;
	const static unsigned int ASCII_ZERO = 0;
  const static unsigned int ASCII_NINE = 9;
	const static char DOLLAR_SIGN = '$';

	bool IsInteger(string str);
	bool IsPasswordValid(string str);
	bool IsStringMixedCase(string str);
	bool IsDollarSign(string str);

public:
	excessC();
	excessC(unsigned int len, bool isOn);
	//excessC(unsigned int len = INIT_PASSWORD_LENGTH, bool isOn = false);
	bool ValidatePassword(string pwd);
	bool GetExObjectStatus();
	bool GetIsInteger();
	bool GetIsMixedCase();

};

#endif


