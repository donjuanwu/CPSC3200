/*
-- Developer    : Don Dang
-- Project      : Project 6
-- Instructor   : Dr. Dingle
-- File Name    : FlipPwdCheck.cs
-- File Version : 1.0
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
 - Take ownership of passed in FlipPwdCheck object
 - Create a IPwdCheck delegate
 - Delay the IPwdCheck delegate instatiation

---------------------------------------------------------------------------------------------
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
-Implement all public methods from IPwdCheck Interface
-Transfer ownership of FlipPwdCheck object during constructor

bool pwdCheck()
- intialized private data members to their default value

bool Virtual ValidatePassword()
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
1. Object status is active
2. Password length meets minimum password length
3. Password doesn't contain forbidden character(s)


------------------------------------------------------------------------------------
   WHEN    WHO	WHAT
   5/29/19  DD      Created FlipPwdCheck.cs
*/



using System;

namespace Project6
{
    interface IPwdCheck
    {
        bool ValidatePassword(string strAlphaNumeric);
        int GetPasswordLength(); 
        bool GetObjectActive();
        bool GetIsCharForbidden();
        void SetForbiddenCharacters(char[] cForBidden);
    }

    class FlipPwdCheck: Flip, IPwdCheck
    {
        IPwdCheck pObj;

        public FlipPwdCheck(PwdCheck obj, string pd) : base(pd)
        {
            pObj = obj;
            obj = null; 
        }

        //Pre : Each object password is already encapsulated
        //Post: May change state of object
        public bool ValidatePassword(string strAlphaNumeric)
        {
            return pObj.ValidatePassword(strAlphaNumeric);
        }

        //Pre : Encapsulated password is already validated
        //Post: Return true/false if password contains forbidden character
        public bool GetIsCharForbidden()
        {
            return pObj.GetIsCharForbidden();
        }

        //Pre : Password length is already set
        //Post: Return encapsulated password length
        public int GetPasswordLength()
        {
            return pObj.GetPasswordLength();
        }

        //Pre : Object status is already set
        //Post: Return encapsulated password object status
        public bool GetObjectActive()
        {
            return pObj.GetObjectActive();
        }

        //Pre : N/A
        //Post: Update forbidden characters
        public void SetForbiddenCharacters(char[] cForBidden)
        {
            pObj.SetForbiddenCharacters(cForBidden);
        }

        //Pre : Each object password is already encapsulated
        //Post: May change object state
        public bool FlipAndValidatePassword(uint index)
        {
            return ValidatePassword(base.FlipChar(index));
        }
    }
}
