/*
-- Developer    : Don Dang
-- Project      : Project 4
-- Instructor   : Dr. Dingle
-- File Name    : flipCompundC.h
-- File Version : 1.0
-- Due Date	    : 5/15/2019
-- Course Name  : CPSC 3200
* OVERVIEW:
 *  FlipCompundC encapsulated a string password, flip the first 'xth length' number of characters in the string, and then
 *  pass it back to PwdCheck ValidationPassword(). It will return a true/false
 *
 * ---------------------------------------------------------------------------------------------------------------------------------
 * DESIGN DECISIONS AND ASSUMPTIONS:
 *  1 - flipCompundCCharacter:
 *
 *      This method will flip first and then validate the flipped password and return a boolean to the calling function
 * ---------------------------------------------------------------------------------------------------------------------------------
 * INTERFACE INVARIANTS:
 *  1 - flipCompundCCharacter
 *
 * Take an unsigned int length and use it to flip the number of characters from the beginning of
 * the string to the length. 
 * A return of true indicate the password is valid
 * A return of false indicate the password is invalid
 *
 *
 *
 * 2 - Reference pwdCheck, compundC and Flip for additional details
 * ---------------------------------------------------------------------------------------------------------------------------------
 * CLASS INVARIANTS:
 *  1 - CONSTRUCTORS:
 *
 * One constructor takes in 3 parameters which are:
 * 1) unsigned int minimum password length
 * Take an unsigned integer will be used by compundC to validate an encapsulated password minimum length
 * 2) a toggleLimit
 * Unsigned int to determine how many time a compundC object can be turned on/off
 * 3) password
 * Take an alphanumeric password to be flipped. The password no max length
 * The other constructor is a default constructor that calls the default constructor in excessC and Flip classes.
 * (See reference of compundC.cpp, pwdCheck.cpp, flip.cpp)
 *
 *  2 - flipCompundCCharacter:
 * Take an unsigned int value to flip the number of characters in the stored password in the flip class
 * If 0 is passed in then the password doesnt get flipped.
 * If a value passed in equals or greater than the password length, the whole encapsulated string will be flipped (password get reverse)
 * (see Flip for further information). Afterwards, the method will password the flipped password to excessC ValidatePassword to
 * validate against compundC reguirements
 * A return true if the password meet requirements
 * A return false if the password doesn't meet requirements
 * See (compundC.cpp and pwdCheck.cpp)
 * ---------------------------------------------------------------------------------------------------------------------------------
 */


#ifndef FLIPCOMPUNDC_H
#define FLIPCOMPUNDC_H
#include "compundC.h"
#include "flip.h"

using namespace std;
class flipCompundC: public compundC, public flip
{
public:
	flipCompundC();
	flipCompundC(unsigned int len, unsigned int toggleNum, string password);
	bool flipCompundCCharacter(unsigned int uIndex);
};
#endif 



