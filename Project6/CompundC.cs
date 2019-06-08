/*
-- Developer    : Don Dang
-- Project      : Project 6
-- Instructor   : Dr. Dingle
-- File Name    : compundC.cs
-- File Version : 1.3
-- Due Date	    : 6/7/2019
-- Course Name  : CPSC 3200
--------------------------------------------------------------------------------------------

OVERVIEW: 
 - This class inherit from pwdCheck class
 - This class acts like pwdCheck
 - Except it requires the password to have at least one repeating character
 - Except it cannot be toggled ON/OFF more than k cycle time
 - Return true if the password meets all requirement
 - Return false if failed requirement
 
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

DATA MEMBERS DICTIONARY:
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
    WHEN        WHO     WHAT
    5/29/19     DD      Added CompundC from project3
 
*/

using System;
namespace Project6
{
    class CompundC: PwdCheck
    {
        private uint countCompCRequest;  
        private uint toggleMax;          
        private bool isCompCLocked; 
        private const int INIT_TOGGLE_MAX = 3;
        private const int INIT_PASSWORD_LENGTH = 4;
        private const uint ONECYCLE = 2;  


        public CompundC (uint pwdLength = INIT_PASSWORD_LENGTH, uint toggleNum = INIT_TOGGLE_MAX) : base(pwdLength)
        {
            if (toggleNum < INIT_TOGGLE_MAX)
            {
                toggleNum = INIT_TOGGLE_MAX;
            }

            countCompCRequest = 0;
            toggleMax = toggleNum;
            isCompCLocked = false;
        }

        //PRE : password is already created
        //POST: Object maybe LOCKED
        public override bool ValidatePassword(string strPwd)
        {
            return !IsObjectLocked() && base.ValidatePassword(strPwd) && IsRepeatedChar(strPwd);
        }

        //PRE : Object locked status is already assigned. 
        //      countCompundC is already assigned.
        //      toggledMax is already assigned
        //POST: Object maybe LOCKED
        private bool IsObjectLocked()
        {
            if (!isCompCLocked)
            {
               if (++countCompCRequest == (base.GetPasswordLength() * toggleMax * ONECYCLE))
                {
                    isCompCLocked = true;
                }
                return false;
            }
            return true;
        }

        //PRE : password is already created
        //      ASCII value is already created
        //POST: N/A
        private bool IsRepeatedChar(string str)
        {
             int[] arrChar = new int[base.GetASCIINumber()];
            for (int i = 0; i < str.Length; i++)
            {
                int index = (int)str[i];
                if (++arrChar[index] > 1)
                {
                    return true;
                }
            }
            return false;
        }

        //PRE : N/A
        //POST: N/A
        public bool GetLockedStatus()
        {
            return isCompCLocked;
        }
    }
   
}
