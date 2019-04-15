/*
-- Developer    : Don Dang
-- Project      : Project 2
-- Instructor   : Dr. Dingle
-- File Name    : factor.cs
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
-- Notes        : 
--                 This class will be used again in P2	
--                   All initial and default values will be 
--                   defined as constant
--                 All comments followed 80 characters line rule
--				
--				
----------------------------------------------------------------
-- WHEN		WHO		WHAT
-- 4/3/19	DD  	Design and model factor.cs
-- 4/4/19   DD      Created factor.cs         
-- 4/7/19   DD      Removed Default Constructor()
--                  Removed helper utility, IsDuplicate()
--                  Updated private member & passed in variables 
--                    name to be self documenting
--                  Added documentation comments for factor.cs
-- 4/8/19   DD      Removed GetObjectStatus()
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
            if (initialFactor == 0)
            {
               divFactor = INITIAL_FACTOR;
            }
            divFactor = initialFactor;
            multiplesCount = INITIAL_MULTIPLESCOUNT;
            isObjActive = true;
            lastNumber = INITIAL_LAST_NUMBER;
        }

        public int GetDivCount()
        {
            return multiplesCount;
        }

        public int Div(uint number)
        {
            if (isObjActive)
            {
                if (lastNumber == number)
                {
                    isObjActive = false;
                    //4/11/19 
                    //duplicate return -1
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

        public void Reset()
        {
            multiplesCount = INITIAL_MULTIPLESCOUNT;
            lastNumber = INITIAL_LAST_NUMBER;
            isObjActive = true;
        }
    }
}
