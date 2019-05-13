/*
-- Developer    : Don Dang
-- Project      : Project 4
-- Instructor   : Dr. Dingle
-- File Name    : pwdCheck.h
-- File Version : 1.0
-- Due Date	    : 5/15/2019
-- Course Name  : CPSC 3200
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

	pwdCheck(unsigned int length = DEFAULT_PWD_LENGTH);

	bool virtual ValidatePassword(string strAlphaNumeric);
	bool IsPasswordLength(string word);
	int GetPasswordLength();
	bool GetObjectStatus();
	bool GetIsCharForbidden();
	void SetForbiddenCharacters(string newCharacters);
};

#endif 



