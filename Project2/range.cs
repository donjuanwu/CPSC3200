/*
-- Developer    : Don Dang
-- Project      : Project 2
-- Instructor   : Dr. Dingle
-- File Name    : range.cs
-- File Version : 1.0
-- Due Date	    : 4/17/2019
-- Course Name  : CPSC 3200
-- Data Members : 
--                Private
--                 int divFactor;      - passed in divisible factor
--                 int multiplesCount; - keep track of multiple count
--                 int lastNumber;     - use to compare current number
--                 bool isObjActive;   - keep track of object status
--                 const int INITIAL_FACTOR = 1;
--                 const int INITIAL_LAST_NUMBER = -1;
--                 const int INITIAL_MULTIPLESCOUNT = 0;
--                Public: 
--                  N/A
-- Methods      :  
--                Helper Utilities
--                  N/A
--                Private
--                  N/A
--                Public
--                  factor(int initialFactor)
--                  Div(int number)
--                  Reset()
--                  Accessors
--                    GetDivCount() 
--                  Mutators
--                    N/A
--                
-- Class Design :
--                 No Default Constructor, a factor value must be 
--                   provided
--                 Parameterized Constructor, factor value less 
--                   than 1 will be initialized to 1
--                 Constructor will initialized all private members
--                 Incoming number must be positive integer,
--                  number > 0
--                Div() 
--                  increment multiplescount variable by 1 ONLY when 
--                    object status is 'true' and the current incoming 
--                    number doesnt equals the lastNumber
--                  set isObjStatus to 'false', when lastNumber equals
--                    incoming number
--                  assign number to lastNumber
--                  return multiplescount
--                 Reset()
--                   reset all private members:
--                     isObjective, lastNumber and multiplesCount to initial value
--                 GetDivCount()
--                   return multiplescount
--
-- Interface Invariants 
     Minimal    : illegal calls (unspecified behavior)
     - Cannot Ping() with a non positive integer
     - 
   Problematic:
   Unncessary :
--				
--				
----------------------------------------------------------------
-- WHEN		WHO		WHAT
-- 4/11/19	DD  	Added comments for Interface Invariants, 
--                    Implementation Invariants, Class Invariants
--
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

        public uint Ping(uint pNumber)
        {
             int retDivCount1 = factorObjOne.Div(pNumber);
             int retDivCount2 = factorObjTwo.Div(pNumber);

              //reset the factor objects
              factorObjOne.Reset();
              factorObjTwo.Reset();
              if ((retDivCount1 == 1) && (retDivCount2 == 1))
              {
                //increment ping count
                //update min/max ping value
                ping_Count++;
                UpdateMinMaxPingRange(pNumber);
              }
             
            return ping_Count;
        }

        public uint GetMaxPing()
        {
            return max_Ping;
        }

        public uint GetMinPing()
        {
            return min_Ping;
        }

        public uint GetPingCount()
        {
            return ping_Count;
        }

       

        public void Replace(uint factorValue1, uint factorValue2)
        {
            factorObjOne = new factor(factorValue1);
            factorObjTwo = new factor(factorValue2);
            min_Ping = 0;
            max_Ping = 0;
            ping_Count = 0;
        }

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
                    max_Ping = number; //set max Ping
                }
                else
                {
                    if ((min_Ping == 0) || (number < min_Ping))
                    {
                        min_Ping = number; //set min Ping
                    }
                }
            }
        }
    }
}
