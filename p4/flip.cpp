/*
-- Developer    : Don Dang
-- Project      : Project 4
-- Instructor   : Dr. Dingle
-- File Name    : flipp.cpp
-- File Version : 1.0
-- Due Date	    : 5/15/2019
-- Course Name  : CPSC 3200
*/

#include "flip.h"


flip::flip(string password) 
{
	strPhrase = password;
}

string flip::flipChar(unsigned int flipIndex)
{
	unsigned int strLen = (unsigned int)strPhrase.length();

	if (flipIndex > strLen)
	{
		flipIndex = strLen;
	}

	char* cArray = new char[strLen];

	for (unsigned int i = 0; i < strLen; i++)
	{
		if (flipIndex > 0)
		{
			cArray[i] = strPhrase[flipIndex - 1];
			flipIndex--;
		}
		else
		{
			cArray[i] = strPhrase[i];
		}
	}
	string strFlipped = string(cArray);
	delete[] cArray;
	return strFlipped;

}


