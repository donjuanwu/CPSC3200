/*
-- Developer    : Don Dang
-- Project      : Project 4
-- Instructor   : Dr. Dingle
-- File Name    : flipPwdCheck.cpp
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
 * IMPLEMENTATION INVARIANTS:
 *  1 - Multiple Inheritance: pwdCheck class and flip class
 *  This is a derived class of pwdCheck and flip classes
 *  This class used flipChar() to flip the stored password characters.
 *  The flipped password will be passed to the ValidationPassword() (see PwdCheck) to validate the password.
 *  A true will be returned if the flipped password meets PwdCheck requirements
 *  A false will be returned if the flipped password doesn't meet PwdCheck requirements
 *
 * 2 - Reference pwdCheck and Flip for additional details
 * ---------------------------------------------------------------------------------------------------------------------------------
 * CLASS INVARIANTS:
 *
 *  2 - CONSTRUCTORS:
 *
 * One constructor takes in 2 parameter which are the minimum password length for PwdCheck and password for Flip.
 * The other constructor is a default constructor that calls the default constructor in pwdCheck and Flip classes.
 *
 *  2 - flipPwdCheckCharacter:
 *
 * Take an unsigned integer that can be any value which will be used to flip the password initialized when firing the constructor
 * If 0 is passed in then the password doesnt get flipped.
 * If a value passed in equals or greater than the password length, the whole encapsulated string will be flipped (password get reverse)
 * (see Flip for further information). Afterwards, the method will password the flipped password to pwdCheck ValidatePassword to
 * validate against PwdCheck reguirements
 * ---------------------------------------------------------------------------------------------------------------------------------
 */

#include "flipPwdCheck.h"

flipPwdCheck::flipPwdCheck() : pwdCheck(), flip() { }
flipPwdCheck::flipPwdCheck(unsigned int length, string password) : pwdCheck(length), flip(password) { }

bool flipPwdCheck::flipPwdCheckCharacter(unsigned int uIndex)
{
	string flippedPwd = flipChar(uIndex);
	return ValidatePassword(flippedPwd);
}



