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
   1. it requires the password Pth character be a digit
   2. password is mixed case
   3. password contains a '$'

 
---------------------------------------------------------------------------------------------
Design Decisions and Assumptions:
 - K cycle value = pwdCheck pwdLength * toggledMax * 2
 - When toggled = K cycle limit then this class object cannot be toggled
   the object status will be stayed static.
 - Evoking override ValidatePassword() will peform the following steps:
 1.If this object is LOCKED
    if Locked, return true
     
 2.If not, pass the password to pwdCheck.ValidatePassword()
If both steps above are true then return true

Private Data Dictionary
uint countCompCRequest    - keep track of number of password request
uint toggleMax            - max toggle limit
bool isCompCLocked        - indicate object is maxed out at toggle on/off limit
const int INIT_TOGGLE_MAX = 3;
const int INIT_PASSWORD_LENGTH = 4;
const uint ONECYCLE = 2;  

------------------------------------------------------------------------------
INTERFACE INVARIANTS:
IsObjectLocked()
 - Validate a password
 - If return true if object is not locked and password meets all requirements

GetLockedStatus()
- accessor to return object locked status

---------------------------------------------------------------------------------
IMPLEMENTATION INVARIANTS:
IsObjectLocked()
- Invoking this function will increment the countCompundC password request.
- countCompundC will be check agains the max K toggled cycle.
- The max K toggled cycle is derived by (pwdCheck pwdLength * toggledMax * 2)
- If countCompundC eqauls max K toggled cycle, this object will be LOCKED forever
- Once the object is LOCKED, the password will always be returned false
- When object is not LOCKED, then password requirement will follow pwdCheck rules 
  and password must contain a repeated character

IsRepeatedChar()
- helper function to return if password contains a repeated character

GetLockedStatus()
- helpfer function to object locked status
----------------------------------------------------------------------------------     
CLASS INVARIANTS:
Return true when password meets following requirements:
1. Object is not LOCKED
2. Password has at least one repeating charcter
3. Password pass pwdCheck.ValidatePassword()

----------------------------------------------------------------------------------
-- WHEN     WHO     WHAT
   4/20/19	DD      Created compundC.cs  
   4/22/19  DD      Added IsRepeatedChar()
                    - Check repeated characters
   4/29/19  DD      Added comments
*/


using System;
using System.Text.RegularExpressions;


namespace Project3
{
    class excessC : pwdCheck
    {
        private uint cPwdLength;
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
            cPwdLength = length;
            exActiveStatus = isOn;
            isInteger = false;
            isMixedCase = false;

        }

        //PRE :
        //POST: 
        public override bool ValidatePassword(string pwd)
        {
           
            if (exActiveStatus)
            {
                return IsPasswordValid(pwd);
                
            }
            return base.ValidatePassword(pwd);
        }

        private bool IsPasswordValid(string str)
        {

            return IsInteger(str) && IsStringMixedCase(str) && IsDollarSign(str);
        }

        private bool IsInteger(string str)
        {
            if (str.Length >= cPwdLength)
            {
              if (char.IsDigit(str[(int)cPwdLength - 1]))
               {
                    isInteger = true;
                    return true;
               }

            }
            return false;
        }

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

        private bool IsDollarSign(string str)
        {
            foreach (char c in str)
            {
                if (c.Equals(DOLLAR_SIGN))
                    return true;
            }
            return false;
        }

        public bool GetExObjectStatus()
        {
            return exActiveStatus;
        }
        public bool GetIsInteger()
        {
            return isInteger;
        }

        public bool GetIsMixedCase()
        {
            return isMixedCase;
        }
    }
}
