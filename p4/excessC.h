/*
-- Developer    : Don Dang
-- Project      : Project 4
-- Instructor   : Dr. Dingle
-- File Name    : excessC.h
-- File Version : 1.0
-- Due Date	    : 5/15/2019
-- Course Name  : CPSC 3200
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


