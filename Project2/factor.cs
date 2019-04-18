/*
-- Developer    : Don Dang
-- Project      : Project 2
-- Instructor   : Dr. Dingle
-- File Name    : factor.cs
-- File Version : 1.1
-- Due Date	    : 4/17/2019
-- Course Name  : CPSC 3200

----------------------------------------------------------------------------
OVERVIEW: 
 The factor class encapsulates its private data members 
 A postive integer value (greater than 0) passed into the Div() is check to
  see if it's a multiple of the divFactor value.
 If it's then increment the multipleCount
 A return of -1 indicate the factor object is inactive.

Design Decisions and Assumptions:
 Constructor initialized all private data memebers to initial values
 Constructor needs to be initialized with a factor value.
 Factor value can not be equals to 0
 If no factor value get passed when firing constructor an INITIAL_DEFAULT_VALUE will be
  assigned to the factor value
 If passed-in factor value equals 0 then it will get assigned to an INITIAL_DEFAULT_VALUE.
 Number passed to Div() must be positive integer value (greater than 0)
 Set factor object to inactive if prev passed-in number equals current 
  passed-in number
 A return of Return_InActive  (value -1 ) to indicate factor object is inactive. 
 Reset() can be called regardless of Factor object status state
------------------------------------------------------------------------------
INTERFACE INVARIANTS:
 GetDivCount() (return a count of successful number that is multiple of divFactor)
 Can be called regardless of factor object state
 Return
  0   = no number that is multiple of divFactor
  > 0 = quantity of number that is multiple of divFactor
  -1  = Factor object is inactive
  
 Div() (increment multipleCount when passed in number is multiple of divFactor)
  Should only be called when the factor object is active
  Return multiple count
   -1 = Factor object is inactive
   
 Reset()
 Can be called regardless of factor object state
  Reset all private data members EXCEPT divFactor to initial value

---------------------------------------------------------------------------------
IMPLEMENTATION INVARIANTS:
 Only has Parameterized Constructor
 Div()
  Factor object must be active for mutliplecount to be incremented
  Set factor object to inactive if prev passed-in number equals current 
   passed-in number. 
   Return -1
  Assign current passed-in number to prev passed-in number 
  Check current passed-in number is divisible by divFactor
   If yes, increment multiplescount by 1
   Return multiplescount
 Reset()
  Reset all private data members EXCEPT divFactor to initial values
  DivFactor will be changed when calling Parameterized Constructor

 GetDivCount()
  Return current multiple count
  Multiplecount is incremented by Div()
----------------------------------------------------------------------------------     
CLASS INVARIANTS:
 Set factor object to inactive if prev passed-in number equals current 
  passed-in number
----------------------------------------------------------------------------------
-- WHEN		WHO		WHAT
-- 4/15/19  DD      Set DivCount() to return a RETURN_INACTIVE when 
                      previous passed in number equals current passed in number
-- 4/16/19  DD      Remove test to determine if passed in factor value is greater
                      than 0 in Constructor. Passed in factor value should be positive integer.
*/

using System;
namespace Project2
{
    class factor
    {
        private uint divFactor;
        private int multiplesCount;
        private int lastNumber;
        private bool isObjActive;
        private const int INITIAL_LAST_NUMBER = -1;
        private const int INITIAL_MULTIPLESCOUNT = 0;
        private const int INITIAL_FACTOR_VALUE = 1;
        private const int RETURN_INACTIVE = -1;
        
        public factor(uint initFactor = INITIAL_FACTOR_VALUE)
        {
            if (initFactor == 0)
            {
                divFactor = INITIAL_FACTOR_VALUE;
            }
            divFactor = initFactor;
            multiplesCount = INITIAL_MULTIPLESCOUNT;
            isObjActive = true;
            lastNumber = INITIAL_LAST_NUMBER;
        }
        //PRE : N/A
        //POST: N/A
        public int GetDivCount()
        {
            return multiplesCount;
        }

        //PRE : Factor object must be active
        //      Passed in number should be positive integer
        //POST: Factor object status may changed
        public int Div(uint number)
        {
            if (isObjActive)
            {
                if (lastNumber == number)
                {
                    isObjActive = false;
                    return RETURN_INACTIVE;
                }
                lastNumber = (int)number;
                if (number % divFactor == 0)
                {
                    multiplesCount++;
                }
            }
            return multiplesCount;
        }
        //PRE : N/A
        //POST: Factor object is active
        public void Reset()
        {
            multiplesCount = INITIAL_MULTIPLESCOUNT;
            lastNumber = INITIAL_LAST_NUMBER;
            isObjActive = true;
        }
    }
}
