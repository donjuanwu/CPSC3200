/*
-- Developer    : Don Dang
-- Project      : Project 4
-- Instructor   : Dr. Dingle
-- File Name    : flipPwdCheck.h
-- File Version : 1.0
-- Due Date	    : 5/15/2019
-- Course Name  : CPSC 3200
*/
#ifndef FLIPPWDCHECK_H
#define FLIPPWDCHECK_H
#include <stdlib.h>
#include "pwdCheck.h"
#include "flip.h"



using namespace std;

class flipPwdCheck: public pwdCheck, public flip
{
public:

	flipPwdCheck(unsigned int len, string password);
	bool flipPwdCheckCharacter(unsigned int index);
};

#endif 




