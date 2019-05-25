/*
-- Developer    : Don Dang
-- Project      : Project 4
-- Instructor   : Dr. Dingle
-- File Name    : flip.h
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
 * INTERFACE INVARIANTS:
 *  1 - FlipChar
 *
 * Enter a length of characters to be flipped to the FlipChar() 
 * Method flipped the string and return it back to the calling function
 *
 * ---------------------------------------------------------------------------------------------------------------------------------
 * CLASS INVARIANTS:
 *  2 - CONSTRUCTORS: Encapsulate the password
 *
 * One constructor takes in an alphanumeric password at any length
 * The other constructor is a default constructor. It will provide a default password name "password"
 *
 * ---------------------------------------------------------------------------------------------------------------------------------
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
	static const string DEFAULT_PASSWORD;
public:
	flip();
	flip(string password);
	string flipChar(unsigned int index);

};

#endif



