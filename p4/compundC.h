/*
-- Developer    : Don Dang
-- Project      : Project 4
-- Instructor   : Dr. Dingle
-- File Name    : compundC.h
-- File Version : 1.0
-- Due Date	    : 5/15/2019
-- Course Name  : CPSC 3200
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



