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

const string flip::DEFAULT_PASSWORD = "password";

flip::flip() 
{ 
	strPhrase = DEFAULT_PASSWORD;
}
flip::flip(string password = DEFAULT_PASSWORD)
{
	strPhrase = password;
}

string flip::flipChar(unsigned int flipIndex)
{
	unsigned int strLen = (unsigned int)strPhrase.length();
	string strFlipped;
	if (flipIndex > strLen)
	{
		flipIndex = strLen;
	}

	for (unsigned int i = 0; i < strLen; i++)
	{
		if (flipIndex > 0)
		{
			strFlipped += strPhrase[flipIndex - 1];
			flipIndex--;
		}
		else
		{
			strFlipped += strPhrase[i];
		}
	}


	return strFlipped;

}


