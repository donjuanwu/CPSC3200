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
 The MultiQ class will accept two factor values and use them to initial two 
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
PushFactorObj()
 Only operate when MultiQ object is active
 Accept a Factor object 
 Return true when push operation is sucessful.
 Else, return false.

PopFactorObject()
 Only operate when MultiQ object is active
 Return true if pop is successful.
 Else, return false.

Query()
 Only operate when MultiQ object is active
  Return total successful query count

GetQueryCount()
 Accessor to return total successful queried count

GetAvgQuery()
 Accessor to return average queried count

GetMaxQuery()
 Accessor to return max successful queried count

GetMinQuery()
 Accessor to return min successful queried count
       
IsEmpty()
 Accessor to return true when stack is emptied
 Stack emptied implied Factor objects can not be pop

GetQueriedNumberList()
 Accessor to return an array of successful queried numbers

Reset()
 Reset all MultiQ private data members EXCEPT factor values.


---------------------------------------------------------------------------------
IMPLEMENTATION INVARIANTS:
 This is a Holds-a relationship between the MultiQ class and the Factor class.
 The Driver can initialize both a MultiQ and a Factor object
 Allow Default Constructor for MultiQ
 Firing MultiQ's constructor will set all private data members to initial value
 An array will be used to hold Factor objects. Array will be implemented like
   a Stack.
 The array can only hold 5 Factor objects. 
 If more than 5 Factor objects pushed into the array then it will get resize
   by 2 times the current size. 
 Query number must be greater than 0.
 All accessors can be called regardless of MultiQ object status.
 Have a counter variable (factorIndex) to keep track of how large the Factor 
  object array grow.
 Each successful push will increment factorIndex by 1.
 Each successful pop will decrement factorIndex by 1.


PushFactorObj()
 Only operate when MultiQ object is active
 Accept a Factor object that is already initialized and met the 
   Factor class requirement.
 Push the Factor object into an array (simulated as a stack).
 Increment the factorIndex by 1 before using it as a placeholder to insert the 
   Factor object into the array.
 By default the Factor array has length 5
 Resize the array if the next available index (factorIndex base 0) is equals to the current array size
 Return true when push operation is sucessful.
 Else, return false.

PopFactorObject()
 Only operate when MultiQ object is active
 Pop is enable when the stack is not empty
 Simulate pop by decrementing 1 from a counter variable (factorIndex).
 Return true if pop is successful.
 Else, return false.

Query()
 Only operate when MultiQ object is active
 Iterate through the Factor object array and call the Div function
  and pass it the query number. 
  Capture the prev divCount by calling the Factor class's accessor
  Capture the current divCount returned by the Div()
  If the current divCount = -1, set MultiQ object to inactive
  Else, determine if current divCount is greater than prev divCount.
    If yes, 1. update the summation of query
            2. update the total successful query count
            3. update the array that keep track of successful queried number
 Return total successful query count

GetQueryCount()
 Accessor to return total successful queried count

GetAvgQuery()
 Accessor to return average queried count

GetMaxQuery()
 Accessor to return max successful queried count

GetMinQuery()
 Accessor to return min successful queried count
       
IsEmpty()
 Accessor to return true when stack is emptied
 Stack emptied implied Factor objects can not be pop

GetQueriedNumberList()
 Accessor to return an array of successful queried numbers

IsDuplicate()
 Private utility to GetQueriedNumberList(), check if 
  number already existed in the array
  
ResizeArray()
 Private utility to resize the Factor object.
 Array new size is 2 times the current array size

UpdateMinMaxQuery()
 Private utility to update private member min & max queried number

Reset()
 Reset all MultiQ private data members EXCEPT factor values.
 Call the Factor class's Reset() to  reset all Factor private data members
   EXCEPT divCount

        
----------------------------------------------------------------------------------     
CLASS INVARIANTS:
 Only operate when MultiQ object is active.
 Return true when the queried number is a multiple of all the factor values
  initialized by each Factor object.

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
        //POST: Stack may not be empty
        //      Stack may get resize
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

        //PRE : N/A
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
        //POST: MultiQ object status may changed
        //      Factor object status may changed
        public uint Query(uint num)
        {
            if (isObjActive)
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
                                if (!IsDuplicate(arrQueriedNumbers, (int)num))
                                {
                                    arrQueriedNumbers[i] = (int)num;
                                }
                            }
                        }

                    }
            }
            return query_Count;
        }

        //PRE : Factor object must be active
        //      Stack can not be emptied
        //POST: Stack may be emptied
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

        //PRE : N/A
        //POST: MultiQ object status is active
        //      Factor object status may changed
        public void Reset()
        {
            if (factorIndex > 0)
            {
                for (int i = 0; i <= factorIndex; i++)
                {
                    arrFactorObject[i].Reset();
                    
                }
            }

            if (array_Size > 0)
            {
                for (int i = 0; i < array_Size; i++)
                {
                    arrQueriedNumbers[i] = 0;
                }
            }
           
            min_Query = INITIAL_COUNT;
            max_Query = INITIAL_COUNT;
            query_Count = INITIAL_COUNT;
            sum_Query = INITIAL_COUNT;
            isObjActive = true;
           
        }

        //PRE : N/A
        //POST: N/A
        public int GetQueryCount()
        {
            return (int)query_Count;
        }

        //PRE : N/A
        //POST: N/A
        public int GetAvgQuery()
        {
            if (query_Count > 0)
            {
              return (int)sum_Query / (int)query_Count;
            }
            return 0;
        }

        //PRE : N/A
        //POST: N/A
        public uint GetMaxQuery()
        {
            return max_Query;
        }

        //PRE : N/A
        //POST: N/A
        public uint GetMinQuery()
        {
            return min_Query;
        }

        //PRE : N/A
        //POST: N/A
        public int[] GetQueriedNumberList()
        {
            return arrQueriedNumbers;
        }

        //PRE : Stack can not be emptied
        //POST: N/A
        private bool IsDuplicate(int[] arr, int num)
        {
                for (int i = 0; i < array_Size; i++)
                {
                    if (arr[i] == num)
                    {
                        return true;
                    }
                }
            return false;
        }

        //PRE : Factor object must be active (validate by calling function)
        //      Stack can not be emptied
        //POST: Stack size will be larger
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

        //PRE : N/A
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
