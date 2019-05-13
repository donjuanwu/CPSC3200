/*
-- Developer    : Don Dang
-- Project      : Project 4
-- Instructor   : Dr. Dingle
-- File Name    : flipCompundC.h
-- File Version : 1.0
-- Due Date	    : 5/15/2019
-- Course Name  : CPSC 3200
*/


#ifndef FLIPCOMPUNDC_H
#define FLIPCOMPUNDC_H
#include "compundC.h"
#include "flip.h"

using namespace std;
class flipCompundC: public compundC, public flip
{
public:
	flipCompundC(unsigned int len, unsigned int toggleNum, string password);
	bool flipCompundCCharacter(unsigned int uIndex);
};
#endif 



