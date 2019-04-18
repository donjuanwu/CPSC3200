/*
-- Developer    : Don Dang
-- Project      : Project 2
-- Instructor   : Dr. Dingle
-- File Name    : range.cs
-- File Version : 1.0
-- Due Date	    : 4/17/2019
-- Course Name  : CPSC 3200
----------------------------------------------------------------------------
OVERVIEW: 
 The Range class will accept two factor values and use them to initial two 
  different Factor objects.
 A passed-in ping number will be checked if it's a multiple of the factor
  value. If Diverized then increment ping count
 Every successful Div() called will invoke setting the min & max ping stats.

Design Decisions and Assumptions:
 The range class encapsulates its private data members.
 There is no Default Constructor, a DEFALUT CONSTRUCTOR VALUE will be provided
 Factor value can not be zero.
   If factor values = 0, then they will get assign to DEFAULT CONSTRUCTOR VALUE.
 DEFAULT CONSTRUCTOR VALUE will be postive integer greater than 1.
 Factor values passed to constructors can be duplicated.
 All public methods can be called regardless of Factor object status.
 After every called to the Factor class's Div(), all Factor object will 
  be set to active.
------------------------------------------------------------------------------
Interface Invariants 
 Ping() 
  Increment and return the ping count when the passed-in number is a multiple
    of two factor values

 GetMaxPing()
  Return the greatest successful pinged number.
  It could be a 0 if there is no successful pinged number

 GetMinPing()
  Return the lowest successful pinged number.
  It could be a 0 if there is no successful pinged number
 
 GetPingCount()
  Return a count of successful pinged number.
  It could be a 0 if there is no successful pinged number

 Replace()
  Replace the current two factor values with two new factor values

---------------------------------------------------------------------------------
IMPLEMENTATION INVARIANTS:
 Allow max two factor values can be passed into Range Constructor.
 Allow factor values to be changed after firing constructor.

 Ping() 
  Determine if the passed-in number is a multiple of two factor values.
  Validation is checked by comparing the returned value of divCount 
   for each factor object.
  If it is a successful multiple then, 
   1. Increment ping count.
   2. Update the min & max stats.
  After every called to the Factor class's Div(), the Factor object get reset. This
   means the Factor object will never be inactive.
  Return ping count.

 GetMaxPing()
  Accessor to return max successful pinged value

 GetMinPing()
   Accessor to return min successful pinged value
 
 GetPingCount()
   Accessor to return total successful pinged count

 Replace()
  Accept two factor values
  Separately used each passed-in factor value to initialize a new Factor object 
   with passed-in factor value
  Current Factor object's factor values will be replaced by new factor values
  Reset all private stats data members to initial values
----------------------------------------------------------------------------------     
CLASS INVARIANTS:
  Increment and return the ping count when the passed-in number is a multiple
    of two factor values
----------------------------------------------------------------------------------
-- WHEN		WHO		WHAT
-- 4/11/19	DD  	Added comments for Interface Invariants, 
--                    Implementation Invariants, Class Invariants
*/


using System;

namespace Project2
{
    class range
    {
        private factor factorObjOne;
        private factor factorObjTwo;
        private uint ping_Count;
        private uint min_Ping;
        private uint max_Ping;
        const int INITIAL_VALUE = 0;
        const int DEFAULT_CONSTRUCTOR_FACTOR1 = 2;
        const int DEFAULT_CONSTRUCTOR_FACTOR2 = 4;

   
        public range(uint factorValue1 = DEFAULT_CONSTRUCTOR_FACTOR1, 
            uint factorValue2 = DEFAULT_CONSTRUCTOR_FACTOR2)
        {
            if (factorValue1 == 0)
            {
                factorValue1 = DEFAULT_CONSTRUCTOR_FACTOR1;
            }

            if (factorValue2 == 0)
            {
                factorValue2 = DEFAULT_CONSTRUCTOR_FACTOR2;
            }

            factorObjOne = new factor(factorValue1);
            factorObjTwo = new factor(factorValue2);
            min_Ping = INITIAL_VALUE;
            max_Ping = INITIAL_VALUE;
            ping_Count = INITIAL_VALUE;
        }

        //PRE : N/A
        //POST: Factor object will be active
        public uint Ping(uint pNumber)
        {
             int retDivCount1 = factorObjOne.Div(pNumber);
             int retDivCount2 = factorObjTwo.Div(pNumber);
              factorObjOne.Reset();
              factorObjTwo.Reset();
              if ((retDivCount1 == 1) && (retDivCount2 == 1))
              {
                ping_Count++;
                UpdateMinMaxPingRange(pNumber);
              }
             
            return ping_Count;
        }

        //PRE : N/A
        //POST: N/A
        public uint GetMaxPing()
        {
            return max_Ping;
        }

        //PRE : N/A
        //POST: N/A
        public uint GetMinPing()
        {
            return min_Ping;
        }

        //PRE : N/A
        //POST: N/A
        public uint GetPingCount()
        {
            return ping_Count;
        }
 
        //PRE : N/A
        //POST: Factor object will be active
        public void Replace(uint factorValue1, uint factorValue2)
        {
            factorObjOne = new factor(factorValue1);
            factorObjTwo = new factor(factorValue2);
            min_Ping = INITIAL_VALUE;
            max_Ping = INITIAL_VALUE;
            ping_Count = INITIAL_VALUE;
        }

        //PRE : N/A
        //POST: N/A
        private void UpdateMinMaxPingRange(uint number)
        {
            if (max_Ping == 0 && min_Ping == 0)
            {
                max_Ping = number;
                min_Ping = number;
            }
            else
            {
                if (number > max_Ping)
                {
                    max_Ping = number; 
                }
                else
                {
                    if ((min_Ping == 0) || (number < min_Ping))
                    {
                        min_Ping = number; 
                    }
                }
            }
        }
    }
}
