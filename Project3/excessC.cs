/*
-- Developer    : Don Dang
-- Project      : Project 3
-- Instructor   : Dr. Dingle
-- File Name    : excessC.cs
-- File Version : 1.0
-- Due Date	    : 4/29/2019
-- Course Name  : CPSC 3200
--------------------------------------------------------------------------------------------

OVERVIEW: 
 - This class inherit from pwdCheck class
 - When this object is in the 'Off' state, it will acts like pwdCheck class
 - When this object is 'ON':
   1. it requires the Pth character in the password to be a digit
   2. password is mixed case
   3. password contains a '$'
- If these three conditions are valid then return true
- Else, return false


 
---------------------------------------------------------------------------------------------
Design Decisions and Assumptions:
 - Pth character is the required minimum length for a password defined during firing constructor
 - If Pth length is less than 4, then assign 4 to Pth length.
 - During firing constructor all data members will be initialized
 - call the pwdCheck constructor and pass it the Pth lenght
     


DATA MEMBERS DICTIONARY:
private uint exPwdLength;         - keep track of excessC object length
bool exActiveStatus { get; set; } - keept rack of excessC object status
bool isInteger;                   - keep track of password contains a digit
bool isMixedCase;                 - keep track of password contains mixed case
const uint INIT_PASSWORD_LENGTH = 4;
const uint ASCII_ZERO = 0;
const uint ASCII_NINE = 9;
const char DOLLAR_SIGN = '$'; 

----------------------------------------------------------------------------------
INTERFACE INVARIANTS:
override ValidatePassword()
- Determine if password meet requirements
- If yes, return true
- Else, return false

GetExObjectStatus()
- accessor return object status

GetIsInteger()
- accessor return is password contain an integer

GetIsMixedCase()
- accessor return is password contains mixed case

----------------------------------------------------------------------------------
IMPLEMENTATION INVARIANTS:
ValidatePassword()
- Determine if object is ON/OFF
- If ON call helper function IsPasswordValid(). Password validation will be on 
these conditions:
1. Password contains an integer
2. Password contains mixedcase
3. Password contains dollar sign
Return true if all conditions are met
- If OFF, then call base.ValidatePassword(). Password validation will depend on 
base validation conditions.
Return result from base validation to calling function

IsPasswordValid()
- invoke this function when object status is ON
- this function will call three helper functions to validate if password is valid
- called helper functions in the following orders:
1. IsInteger()
2. IsStringMixedCase()
3. IsDollarSign

IsInteger()
- helper function to determine if password contain an integer
- if true, update isInteger variable


IsStringMixedCase()
- helper function to determine if password has mixed case
- if true, update isMixedCase variable

IsDollarSign()
- helper to determine if password contains $ sign

GetIsMixedCase()
- accessor return password has mixed case

----------------------------------------------------------------------------------     
CLASS INVARIANTS:
Return true when password meets following requirements:
1. Object is not LOCKED
2. Password has at least one repeating charcter
3. Password pass pwdCheck.ValidatePassword()

----------------------------------------------------------------------------------
-- WHEN     WHO     WHAT
   4/25/19	DD      Created excessC.cs  
   4/26/19  DD      Added IsInteger(), IsMixedCase (), IsDollarSign()
   4/29/19  DD      Added comments
*/


using System;
using System.Text.RegularExpressions;


namespace Project3
{
    class excessC : pwdCheck
    {
        private uint exPwdLength;
        public bool exActiveStatus { get; set; }
        private bool isInteger;
        private bool isMixedCase;
        private const uint INIT_PASSWORD_LENGTH = 4;
        private const uint ASCII_ZERO = 0;
        private const uint ASCII_NINE = 9;
        private const char DOLLAR_SIGN = '$';

        public excessC(uint length = INIT_PASSWORD_LENGTH, bool isOn = false) : base(length)
        {
            if (length < INIT_PASSWORD_LENGTH)
            {
                length = INIT_PASSWORD_LENGTH;
            }
            exPwdLength = length;
            exActiveStatus = isOn;
            isInteger = false;
            isMixedCase = false;

        }

        //PRE : Object status is assigned
        //POST: N/A
        public override bool ValidatePassword(string pwd)
        {
           
            if (exActiveStatus)
            {
                return IsPasswordValid(pwd);
                
            }
            return base.ValidatePassword(pwd);
        }

        //PRE : N/A
        //POST: N/A
        private bool IsPasswordValid(string str)
        {

            return IsInteger(str) && IsStringMixedCase(str) && IsDollarSign(str);
        }

        //PRE : N/A
        //POST: N/A
        private bool IsInteger(string str)
        {
            if (str.Length >= exPwdLength)
            {
              if (char.IsDigit(str[(int)exPwdLength - 1]))
               {
                    isInteger = true;
                    return true;
               }

            }
            return false;
        }

        //PRE : N/A
        //POST: N/A
        private bool IsStringMixedCase(string str)
        {
            
            bool isLower = false;
            bool isUpper = false;

            foreach (char c in str)
            {
                if (char.IsLower(c))
                    isLower = true;
                if (char.IsUpper(c))
                    isUpper = true;
                if (isLower && isUpper)
                    return true;

            }

            return false;
        }

        //PRE : N/A
        //POST: N/A
        private bool IsDollarSign(string str)
        {
            foreach (char c in str)
            {
                if (c.Equals(DOLLAR_SIGN))
                    return true;
            }
            return false;
        }

        //PRE : Object status is assigned
        //POST: N/A
        public bool GetExObjectStatus()
        {
            return exActiveStatus;
        }

        //PRE : isInteger variable is already assigned
        //POST: N/A
        public bool GetIsInteger()
        {
            return isInteger;
        }

        //PRE : isMixedCase variable is already assigned
        //POST: N/A
        public bool GetIsMixedCase()
        {
            return isMixedCase;
        }
    }
}
