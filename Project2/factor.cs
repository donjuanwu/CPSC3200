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
   The factor object encapsulates its private data members 
   A postive integer value passed into the Div() is check to
   see if it's a multiple of the divFactor value.
   If it's then increment the multipleCount

------------------------------------------------------------------------------
INTERFACE INVARIANTS:
   Constructor expected a factor value of positive integer value
   Constructor will initial all private data member to defaul values
   GetDivCount() return a count of successful number that is multiple
    of divFactor. 
   Div() 
     should only be called when the factor object is active
     return -1 to indicate factor object is inactive
     factor object status is set to inactive when previous passed in number
       equals current passed in number

     return 0 if passed in number is not a multiple of the divFactor
     return > 0 could mean the passed in number is a multiple of the divFactor
   Reset()
     reset multiplesCount, lastNumber, and factor object status to default value
     divFactor doesn't need to get reset as calling the factor constructor
     will reset it. 
---------------------------------------------------------------------------------
IMPLEMENTATION INVARIANTS:
   Div()
     Set factor object to inactive if prev passed in number equals current 
      passed in number
     Assign current passed in number to lastNumber
     Check current passed in number is divisible by factor value
     If yes, increment multiplescount by 1
     Return multiplescount
   Reset()
     Reset factor object to initial values
----------------------------------------------------------------------------------     
CLASS INVARIANTS:
   See below PRE & POST conditions 
----------------------------------------------------------------------------------
-- WHEN		WHO		WHAT
-- 4/15/19  DD      set DivCount() to return a RETURN_INACTIVE when 
                      previous passed in number equals current passed in number
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
        private const int INITIAL_FACTOR = 1;
        private const int INITIAL_LAST_NUMBER = -1;
        private const int INITIAL_MULTIPLESCOUNT = 0;
        private const int RETURN_INACTIVE = -1;


        public factor(uint initialFactor)
        {
            divFactor = initialFactor;
            multiplesCount = INITIAL_MULTIPLESCOUNT;
            isObjActive = true;
            lastNumber = INITIAL_LAST_NUMBER;
        }

        //PRE : Factor object must be active
        //POST: N/A
        public int GetDivCount()
        {
            return multiplesCount;
        }

        //PRE : Factor object should be active
        //      Passed in number should be positive integer value
        //POST: Factor object will be set to inactive if two consecutive 
        //      passed in number is the same
        //      Multiplecount will increment by one if passed in number is
        //      a multiple of the divFactor
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
        //      MultipleCount is reset to initial value
        //      LastNumber is reset to initial value
        public void Reset()
        {
            multiplesCount = INITIAL_MULTIPLESCOUNT;
            lastNumber = INITIAL_LAST_NUMBER;
            isObjActive = true;
        }
    }
}
