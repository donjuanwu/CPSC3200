/*
-- Developer    : Don Dang
-- Project      : Project 4
-- Instructor   : Dr. Dingle
-- File Name    : flipp.cpp
-- File Version : 1.0
-- Due Date	    : 5/15/2019
-- Course Name  : CPSC 3200

 * OVERVIEW:
 *  FlipChar encapsulated a string password, flip the first 'xth length' number of characters in the string, and then
 *  pass the flipped password to the calling function
 *
 * ---------------------------------------------------------------------------------------------------------------------------------
 * DESIGN DECISIONS AND ASSUMPTIONS:
 *  1 - FlipChar:
 *
 *      This method will flip the beginning characters until the passed index of the string. It will return the flipped password back
 *		  to the calling function
 * ---------------------------------------------------------------------------------------------------------------------------------
 * IMPLEMENTATION INVARIANTS:
 *  1 - FlipChar
 *
 * Take in an unsigned int including from 0 to the size of the unsigned int value
 * Use the unsigned int lenght to flipped the characters of the string.
 * The characters will be flipped starting at the index (length) of the password
 * If the number of the characters to be flipped is longer than the string, then the whole string get flipped.
 * The flipped string get return back to the calling function
 * ---------------------------------------------------------------------------------------------------------------------------------
 * CLASS INVARIANTS:
 *  2 - CONSTRUCTORS: Encapsulate the password
 *
 * One constructor takes in an alphanumeric password at any length
 * The other constructor is a default constructor. It will provide a default password name "password"
 *
 * ---------------------------------------------------------------------------------------------------------------------------------
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


