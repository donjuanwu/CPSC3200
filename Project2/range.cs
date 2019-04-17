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
   The factor object encapsulates its private data members 
   A postive integer value passed into the Div() is check to
   see if it's a multiple of the divFactor value.
   If it's then increment the multipleCount

Design Decisions and Assumptions:
   Parameter to initialize the Factor Constructor must be positive integer
   Parameter to Div() must be positive integer
   If two consecutive passed in numbers are the same then the Factor
     object will be set to inactive
     a -1 will be returned
   Reset() can be called regardless of Factor object state
------------------------------------------------------------------------------
Interface Invariants 
    Minimal    : illegal calls (unspecified behavior)
     - Cannot Ping() with a non positive integer
     - 
   Problematic:
   Unncessary :
				
			
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
    
  
        public range(uint factorValue1 = 2, uint factorValue2 = 4)
        {
            factorObjOne = new factor(factorValue1);
            factorObjTwo = new factor(factorValue2);
            min_Ping = 0;
            max_Ping = 0;
            ping_Count = 0;
        }

        //PRE : Factor object must be active
        //POST: N/A
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

        //PRE : Factor object must be active
        //POST: N/A
        public uint GetMaxPing()
        {
            return max_Ping;
        }

        //PRE : Factor object must be active
        //POST: N/A
        public uint GetMinPing()
        {
            return min_Ping;
        }

        //PRE : Factor object must be active
        //POST: N/A
        public uint GetPingCount()
        {
            return ping_Count;
        }
 
        //PRE : Factor object must be active
        //POST: N/A
        public void Replace(uint factorValue1, uint factorValue2)
        {
            factorObjOne = new factor(factorValue1);
            factorObjTwo = new factor(factorValue2);
            min_Ping = 0;
            max_Ping = 0;
            ping_Count = 0;
        }

        //PRE : Factor object must be active
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
