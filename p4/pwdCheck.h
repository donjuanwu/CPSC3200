/*
-- Developer    : Don Dang
-- Project      : Project 4
-- Instructor   : Dr. Dingle
-- File Name    : pwdCheck.h
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
INTERFACE INVARIANTS:
 Virtual ValidatePassword()
- return true if password is valid
- return false if password is invalid

IsForbiddenCharacter()
- return true if passed in password equals password minimum length
- else, return false

IsPasswordLength()
- return if passed in password meets minimum password length


GetPasswordLength()
- return password length

IsObjectActive()
- return object status

GetASCIINumber()
- only type descendant can get current ASCII max value

GetIsCharForbidden()
- return true/false if password contains forbidden character

SetForbiddenCharacters()
- update forbidden characters


---------------------------------------------------------------------------------

CLASS INVARIANTS:
Return true when password meets following requirements:
1. Object is status is active
2. Password length meets minimum password length
3. Password doesn't contain forbidden character(s)

----------------------------------------------------------------------------------
-- WHEN     WHO		WHAT
	 5/10/19  DD    Ported pwdCheck.cs to pwdCheck.h
*/
#ifndef PWDCHECK_H
#define PWDCHECK_H
#include <stdlib.h>
#include <string>

using namespace std;

class pwdCheck
{

private:
	static const int ASCII_NUM = 127;
	unsigned int pwdLength;
	bool isActive;
	bool isCharForbidden;
	unsigned int countValidation;
	static const unsigned int DEFAULT_PWD_LENGTH = 4;
	string strForBidden;

	void ToggleObject();
	bool IsForbiddenCharacter(string strPwd);

protected:
	int GetASCIINumber();

public:
	pwdCheck();
	pwdCheck(unsigned int length);

	bool virtual ValidatePassword(string strAlphaNumeric);
	bool IsPasswordLength(string word);
	int GetPasswordLength();
	bool GetObjectStatus();
	bool GetIsCharForbidden();
	void SetForbiddenCharacters(string newCharacters);
};

#endif 



