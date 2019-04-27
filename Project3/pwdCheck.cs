/*
-- Developer    : Don Dang
-- Project      : Project 3
-- Instructor   : Dr. Dingle
-- File Name    : pwdCheck.cs
-- File Version : 1.0
-- Due Date	    : 4/29/2019
-- Course Name  : CPSC 3200
----------------------------------------------------------------------------
OVERVIEW: 
   This driver will sequentially test each class: 1) range.cs 2)multiQ.cs & factor.cs
   The first test will be the range.cs
Range's Class Test Cases:
   1. Initialize Range objects
      Generate two random factor values and use them to initial Range object. 
      Factor values will be tracked on Driver class to be used later for 
        context
   2. Test Ping function with random numbers
      A succcessful pinged is when the random number is a multiple of
       two factor values
      There wil be 7 random generated numbers to test
      After pinging each random number, a stat will be provided by the Range class:
      - Successful minimum pinged value
      - Successful maximum pinged value
      - Total successful pinged count
   3. Test replace current factor values with two new factor values
      A successful test will show current factor values and replaced factor values.
      Test Ping function again with new factor values.
      New stats will be displayed base on new factor values.

MultiQ & Factor Class's Test Cases:
    1. Initialize MultiQ object with no parameters.
    2. Initialize Factor objects 
       Expect to created 7 Factor objects and initialized each Factor object
        with a factor. These factor values are randomly generated. There may e
        duplicate factor values. The Factor objects will be added into an array.
       All factor values are stored in an array in the Driver to be used for
         context when display stats from MutliQ.
    3. Test PushFactorObject()
       By design MultiQ class can only store 5 Factor objects. 
       Push 7 Factor objects to MultiQ which will invoke the private
         ResizeArray() to resize the Factor array in MultiQ.
       Expect all 7 Factor object are saved in the MultiQ.
       
    4. Test QueryMutliQ()
       Query 7 randomly generated numbers. Determine how many randomly
         generated numbers are multiples of the factor value belong to 7 Factor object
       Display the following stats from MultiQ for all of them:
       - List of successfully queried numbers
       - Maximum successful queried number
       - Minimum successful queried number
       - Average successful queried value
       - Total successful queried count
   5. PopFactorObjectFromMultiQ()
      There are 7 Factor objects saved from TestPushFactor Object.
      Expect 7 successful pop to display on Driver's console.
   6. ResetMultiQObject()
      All private data members of MultiQ should be reset to initial value
      Stats from MultiQ should all be display 0
       
---------------------------------------------------------------------------------
Design Decisions and Assumptions:
 The range of the factor value is randomly generated between 2 - 10 (inclusive).
 The ping/query number is randomly generated between 1 - 10000 (inclusive).
 All generated numbers are greater than 0.
 Two factor values will be passed to the Range parameterized constructor
 Seven Factor objects and seven factor values will be initialized for 
   the Factor object.
 Range object will be initialized by the InitRangeObject().
 MultiQ object will be initialized by the InitMultiQObject().
 Factor object will be initialized by the InitFactorObject().
 All pinged and queried numbers will be tracked from the Driver to .
  give context to the Stats returned from the Range and the MultiQ classes.
 Range and MultiQ along with Factor will be tested separately.
 The Range class will be tested first.
 The MultiQ and Factor classes will follow.
 Reset MultiQObject ONLY reset all MultiQ private data memebers to initial value.

----------------------------------------------------------------------------------
-- WHEN     WHO		WHAT
   4/19/19	DD  	Created pwdCheck.cs  
   4/25/19  DD      Added IsPasswordLength()
                    - Check for password length requirement
*/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project3
{
    class pwdCheck
    {
        private char[] strForbiddenChar;
        private const int ASCII_NUM = 127;
        protected readonly uint pwdLength;
        protected bool isObjectActive;
        protected uint countValidation;
        protected const uint DEFAULT_PWD_Length = 4;
      
        public pwdCheck(uint length)
        {
            if (length < DEFAULT_PWD_Length)
            {
                length = DEFAULT_PWD_Length;
            }
            isObjectActive = true;
            countValidation = 0;
            pwdLength = length;
            strForbiddenChar = new char[] { ' ', '~', '(', ')', '{', '}', '[', ']' };
        }

        public virtual bool ValidatePassword(string strAlphaNumeric)
        {
            if (TogglePwdObjectState())
            {
                if (IsPasswordLength(strAlphaNumeric))
                {
                    return !IsForbiddenCharacter(strAlphaNumeric);
                }
                
            }
            return false;
        }

        private bool IsForbiddenCharacter(string strPwd)
        {
            for (int i = 0; i < strPwd.Length; i++)
            {
                foreach (char c in strForbiddenChar)
                {
                    if ((int)strPwd[i] > ASCII_NUM || c.Equals(strPwd[i]))
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        public virtual bool IsPasswordLength(string pWord)
        {
            return (pWord.Length >= pwdLength);
        }

        public bool TogglePwdObjectState()
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
        
        public int GetPasswordLength()
        {
            return (int)pwdLength;
        }

        public bool IsObjectActive()
        {
            return isObjectActive;
        }

        protected int GetASCIINumber()
        {
            return ASCII_NUM;
        }
    }
}
