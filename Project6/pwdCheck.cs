/*
-- Developer    : Don Dang
-- Project      : Project 6
-- Instructor   : Dr. Dingle
-- File Name    : pwdCheck.cs
-- File Version : 1.3
-- Due Date	    : 6/7/2019
-- Course Name  : CPSC 3200
--------------------------------------------------------------------------------------------
OVERVIEW: 
 - This class accepts a password of length at least P (where p is a stable 
    value tha varies from object to object). 
 - A password is not acceptable if it contains a forbidden symbol.
 - This class object is toggled when the number of password validation equals P.
 
---------------------------------------------------------------------------------------------
Design Decisions and Assumptions:
 - P is given when the class constructor fired.
 - P length must be at least 4. If P doesn't = 4 then it get assign a default value of 4
 - A default forbidden characters array will be initialized during constructor firing
 - The forbidden characters can be changed with a mutator
 - Private data members are exposed with accessors/mutators

DATA MEMBERS DICTIONARY:
char[] charForBidden      - hold forbidden characters
const int ASCII_NUM = 127 - indicate max value of ASCII
readonly uint pwdLength   - hold P value
bool isObjectActive       - indicate object active status
bool isCharForbidden      - indicate if forbidden character found in password
uint countValidation      - indicate number of validation request
const int DEFAULT_PWD_Length = 4  

------------------------------------------------------------------------------
INTERFACE INVARIANTS:
 Virtual ValidatePassword()
- return true if password is valid
- return false if password is invalid
 
IsForbiddenCharacter()
- return true if passed in password equals password minimum length
- else, return false

IsPasswordLength()
- return if passed in password meets minimum password length


GetPasswordLength()
- return password length

IsObjectActive()
- return object status

GetASCIINumber()
- only type descendant can get current ASCII max value

GetIsCharForbidden()
- return true/false if password contains forbidden character

SetForbiddenCharacters()
- update forbidden characters


---------------------------------------------------------------------------------
IMPLEMENTATION INVARIANTS:

-IPwdCheck Interface

pwdCheck()
- intialized private data members to their default value

Virtual ValidatePassword()
- return true when object status is true, password meet length requirement
  and password doesn't contain forbidden character
- return false, if any of the above condition failed
- invoking this function may object state
- this function can be override by it children
 
IsForbiddenCharacter()
- helper function to validate password
- determine if password contain forbidden characters
- return true, contain forbidden character(s)
- return false, no forbidden character(s)

IsPasswordLength()
- helper function to validate password
- determine if password length meet the set password length in the constructor
- return true, if password meet length requirement
- return false, if password doesn't meet length requirement

IsObjectStateChanged()
- helper function to determine if object state needs to be toggled
- when this function get invoked, determine object status
- if object is active, then increment count of password
  determine if count of password request equals request limit
  if yes, toggle object state then return true
- if object is inactive, then decrement count of password
  determine if count of password request equals 0
  if yes, toggle object state then return true

GetPasswordLength()
- accessor function to return predefined set password

GetObjectActive()
- accessor function to return object status


GetIsCharForbidden()
- accessor to return password contain forbidden characters status

SetForbiddenCharacters()
- mutator to set forbidden characters
----------------------------------------------------------------------------------     
CLASS INVARIANTS:
Return true when password meets following requirements:
1. Object is status is active
2. Password length meets minimum password length
3. Password doesn't contain forbidden character(s)


------------------------------------------------------------------------------------
   WHEN    WHO	WHAT
   5/29/19  DD      Created p6
                    Added pwdCheck.cs from project3
*/

using System;

namespace Project6
{

    class PwdCheck: IPwdCheck
    {
        private char[] charForBidden;
        private const int ASCII_NUM = 127;
        private readonly uint pwdLength;
        private bool isObjectActive;
        private bool isCharForbidden; 
        private uint countValidation;
        private const uint DEFAULT_PWD_Length = 4;
      
        public PwdCheck(uint length = DEFAULT_PWD_Length)
        {
            if (length < DEFAULT_PWD_Length)
            {
                length = DEFAULT_PWD_Length;
            }
            isObjectActive = true;
            countValidation = 0;
            pwdLength = length;
            charForBidden = new char[] { ' ', '~', '(', ')', '{', '}', '[', ']' };
            isCharForbidden = false; 
        }


        // PRE : Length password is known, forbidden characters are defined
        // POST: Object state may changed depending on the count of password requested
        public virtual bool ValidatePassword(string strAlphaNumeric)
        {
            if (IsObjectStateChanged())
            {
                if (IsValidPasswordLength(strAlphaNumeric))
                {
                    return !IsForbiddenCharacter(strAlphaNumeric);
                }
                
            }
            return false;
        }


        // PRE : Forbidden characters already defined
        // POST : N/A
        private bool IsForbiddenCharacter(string strPwd)
        {
            for (int i = 0; i < strPwd.Length; i++)
            {
                foreach (char c in charForBidden)
                {
                    if ((int)strPwd[i] > ASCII_NUM || c.Equals(strPwd[i]))
                    {
                        isCharForbidden = true;
                        return true;
                    }
                }
            }
            return false;
        }

        // PRE : Minimum password length already defined
        // POST : N/A
        private bool IsValidPasswordLength(string pWord)
        {
            return (pWord.Length >= pwdLength);
        }

        //PRE :Object state is already assigned
        //POST:Object state may be toggled
        //Update count of password requested
        //Determine if count of password requested equals request limit
        private bool IsObjectStateChanged()
        {
            if (isObjectActive)
            {
                if (++countValidation == pwdLength)
                {
                    isObjectActive = false;
                    return false;
                }
                return true;
            }
            else
            {
                if (countValidation > 0)
                {
                    if (pwdLength - (--countValidation) == pwdLength)
                    {
                        isObjectActive = true;
                        return true;
                    }
                    else
                    return false;
                }          
            }
           return true;
        }
        
        //PRE :Password length is set
        //POST:N/A
        public int GetPasswordLength()
        {
            return (int)pwdLength;
        }

        //PRE :Object status is assigned and known
        //POST:N/A
        public virtual bool GetObjectActive()
        {
            return isObjectActive;
        }

        //PRE :Cons ASCII_NUM must be set
        //POST:N/A
        protected int GetASCIINumber()
        {
            return ASCII_NUM;
        }

        //PRE : Forbidden status is set
        //POST: N/A
        public bool GetIsCharForbidden()
        {
            return isCharForbidden;
        }

        //PRE : N/A
        //POST: N/A
        public void SetForbiddenCharacters(char[] cForBidden)
        {
            charForBidden = cForBidden;
        }
    }
}
