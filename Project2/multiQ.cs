/*
-- Developer    : Don Dang
-- Project      : Project 2
-- Instructor   : Dr. Dingle
-- File Name    : multiQ.cs
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
using System.Collections;

namespace Project2
{
    class multiQ
    {
        private uint array_Size;
        private int factorIndex;
        private factor[] arrFactorObject;
        private int[] arrQueriedNumbers;
        private bool isObjActive;
        private uint query_Count;
        private const int INITIAL_COUNT = 0;
        private const int INITIAL_ARRAY_SIZE = 5;
        private const int INITIAL_FACTOR_INDEX = -1;
        readonly uint ARR_RESIZE_VALUE;
        private uint min_Query;
        private uint max_Query;
        private uint sum_Query;

        public multiQ()
        {
            arrFactorObject = new factor[INITIAL_ARRAY_SIZE];
            arrQueriedNumbers = new int[INITIAL_ARRAY_SIZE];
            isObjActive = true;
            array_Size = INITIAL_ARRAY_SIZE;
            factorIndex = INITIAL_FACTOR_INDEX;
            query_Count = INITIAL_COUNT;
            min_Query = INITIAL_COUNT;
            max_Query = INITIAL_COUNT;
            sum_Query = INITIAL_COUNT;
            ARR_RESIZE_VALUE = 2;
        }

        //PRE : Factor object must be active
        //POST: N/A
        public bool PushFactorObj(factor obj)
        {
           if (isObjActive)
            {
                if ((factorIndex + 1) < array_Size)
                {
                    factorIndex++;
                    arrFactorObject[factorIndex] = obj;
                    return true;
                }
                else
                {
                    ResizeArray((uint)factorIndex);
                    factorIndex++;
                    arrFactorObject[factorIndex] = obj;
                    return true;
                }
            }
            return false;
        }

        //PRE : Factor object must be active
        //POST: N/A
        public bool IsEmpty()
        {
            if (factorIndex < 0)
            {
                return true;
            }
            return false;
        }

        //PRE : Factor object must be active
        //POST: N/A
        public uint Query(uint num)
        {
            if (isObjActive)
            {
                if (!IsEmpty())
                {
                    for (int i = 0; i <= factorIndex; i++)
                    {
                        int prevDivCount = arrFactorObject[i].GetDivCount();
                        int retDivCount = arrFactorObject[i].Div(num);
                        if (retDivCount == -1)
                        {
                            isObjActive = false;
                            break;
                        }
                        else
                        {
                            if (retDivCount > prevDivCount)
                            {
                                sum_Query += num;
                                query_Count++;
                                UpdateMinMaxQuery((uint)num);
                                if (!IsDuplicate(arrQueriedNumbers, i, (int)num))
                                {
                                    arrQueriedNumbers[i] = (int)num;
                                }
                            }
                        }

                    }
                }
            }
            return query_Count;
        }

        //PRE : Factor object must be active
        //POST: N/A
        public bool PopFactorObject()
        {
            if (isObjActive)
            {
                if (!IsEmpty())
                {
                    arrFactorObject[factorIndex] = null;
                    factorIndex--;
                    return true;
                }
            }
            return false;
        }

        //PRE : Factor object must be active
        //POST: N/A
        public void Reset()
        {
            if (factorIndex > 0)
            {
                for (int i = 0; i <= factorIndex; i++)
                {
                    arrFactorObject[i].Reset();
                }
            }
            min_Query = INITIAL_COUNT;
            max_Query = INITIAL_COUNT;
            query_Count = INITIAL_COUNT;
            sum_Query = INITIAL_COUNT;
            isObjActive = true;
           
        }

        //PRE : Factor object must be active
        //POST: N/A
        public int GetQueryCount()
        {
            if (isObjActive)
            {
                return (int)query_Count;
            }

            return -1;
        }

        //PRE : Factor object must be active
        //POST: N/A
        public int GetAvgQuery()
        {
            if (query_Count > 0)
            {
              return (int)sum_Query / (int)query_Count;
            }
            return 0;
        }

        //PRE : Factor object must be active
        //POST: N/A
        public uint GetMaxQuery()
        {
            return max_Query;
        }

        //PRE : Factor object must be active
        //POST: N/A
        public uint GetMinQuery()
        {
            return min_Query;
        }

        //PRE : Factor object must be active
        //POST: N/A
        public int[] GetQueriedNumberList()
        {
            return arrQueriedNumbers;
        }

        //PRE : Factor object must be active
        //POST: N/A
        private bool IsDuplicate(int[] arr, int count, int num)
        {
            if (count != 0)
            {
                for (int i = 0; i <= count; i++)
                {
                    if (arr[i] == num)
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        //PRE : Factor object must be active
        //POST: N/A
        private void ResizeArray(uint index)
        {
            factor[] temp = arrFactorObject;
            int[] temp2 = arrQueriedNumbers;
            array_Size *= ARR_RESIZE_VALUE;
            arrFactorObject = new factor[array_Size];
            arrQueriedNumbers = new int[array_Size];
            for (int i = 0; i <= index; i++)
            {
                arrFactorObject[i] = temp[i];
                arrQueriedNumbers[i] = temp2[i];
            }

        }

        //PRE : Factor object must be active
        //POST: N/A
        private void UpdateMinMaxQuery(uint number)
        {
            if (max_Query == 0 && min_Query == 0)
            {
                max_Query = number;
                min_Query = number;
            }
            else
            {
                if (number > max_Query)
                {
                    max_Query = number; 
                }
                else
                {
                    if ((min_Query == 0) || (number < min_Query))
                    {
                        min_Query = number; 
                    }
                }
            }
        }

    }
}
