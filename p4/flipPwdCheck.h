/*
-- Developer    : Don Dang
-- Project      : Project 4
-- Instructor   : Dr. Dingle
-- File Name    : flipPwdCheck.h
-- File Version : 1.0
-- Due Date	    : 5/15/2019
-- Course Name  : CPSC 3200

 * OVERVIEW:
 *  FlipPwdCheck encapsulated a string password, flip the first 'xth length' number of characters in the string, and then
 *  pass it back to PwdCheck ValidationPassword(). It will return a true/false
 *  
 * ---------------------------------------------------------------------------------------------------------------------------------
 * DESIGN DECISIONS AND ASSUMPTIONS:
 *  1 - flipPwdCheckCharacter:
 *
 *      This method will flip first and then validate the flipped password and return a boolean to the calling function
 * ---------------------------------------------------------------------------------------------------------------------------------
 * INTERFACE INVARIANTS:
 *  1 - flipPwdCheckCharacter
 *
 * Enter a length into the flipPwdCheckCharacter() then characters will be flipped from the beginning of
 * the string to the length entered into the method. 
 * A return of true indicates the password is valid
 * A return of false indicates the password is invalid.
 * Reference: pwdCheck and flip
 *
 * 2 - Reference pwdCheck and Flip for additional details
 * ---------------------------------------------------------------------------------------------------------------------------------
 * CLASS INVARIANTS:
 *  1 - CONSTRUCTORS:
 *
 * One constructor takes in 2 parameter which are the minimum password length for PwdCheck and password for Flip. 
 * The other constructor is a default constructor that calls the default constructor in pwdCheck and Flip classes. 
 *
 *  2 - flipPwdCheckCharacter:
 *
 * Take an unsigned integer that can be any value which will be used to flip the password initialized when calling the constructor
 * If 0 is passed in then the password doesnt get flipped.
 * If a value passed in equals or greater than the password length, the whole encapsulated string will be flipped (password get reverse)
 * (see Flip for further information). Afterwards, the method will password the flipped password to pwdCheck ValidatePassword to 
 * validate against PwdCheck reguirements
 * ---------------------------------------------------------------------------------------------------------------------------------
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
	flipPwdCheck();
	flipPwdCheck(unsigned int len, string password);
	bool flipPwdCheckCharacter(unsigned int index);
};

#endif 




