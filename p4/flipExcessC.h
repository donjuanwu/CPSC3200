/*
-- Developer    : Don Dang
-- Project      : Project 4
-- Instructor   : Dr. Dingle
-- File Name    : flipExcessC.h
-- File Version : 1.0
-- Due Date	    : 5/15/2019
-- Course Name  : CPSC 3200
*/


#ifndef FLIPEXCESSC_H
#define FLIPEXCESSC_H

#include <stdlib.h>
#include "excessC.h"
#include "flip.h"

using namespace std;
class flipExcessC: public excessC, public flip
{
public:
	flipExcessC(unsigned int len, bool isOn, string password);
	bool flipExcessCCharacter(unsigned int uIndex);
};

#endif



