/*
-- Developer    : Don Dang
-- Project      : Project 4
-- Instructor   : Dr. Dingle
-- File Name    : flip.h
-- File Version : 1.0
-- Due Date	    : 5/15/2019
-- Course Name  : CPSC 3200
*/
#ifndef FLIP_H
#define FLIP_H
#include <stdlib.h>
#include <string>

using namespace std;

class flip
{

private:
	string strPhrase;
public:

	flip(string password);
	string flipChar(unsigned int index);

};

#endif



