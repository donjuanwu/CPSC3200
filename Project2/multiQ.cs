using System;
using System.Collections;

namespace Project2
{
    class multiQ
    {
        private uint arrFactorSize;
        private int factorIndex;
        private factor[] arrFactorObject;
        private bool isObjActive;
        private uint queryCount;
        private const int INITIAL_QUERYCOUNT = 0;
        private const int INITIAL_ARRAY_SIZE = 5;

        public multiQ()
        {
            arrFactorObject = new factor[INITIAL_ARRAY_SIZE];
            isObjActive = true;
            arrFactorSize = INITIAL_ARRAY_SIZE;
            factorIndex = 0;
        }

        public bool AddFactorObj(factor obj)
        {
           if (isObjActive)
            {
                if (factorIndex < arrFactorSize)
                {
                    arrFactorObject[factorIndex] = obj;
                    factorIndex++;
                    return true;
                }
                else
                {
                    ResizeArray(factorIndex);
                    arrFactorObject[factorIndex] = obj;
                    factorIndex++;
                    return true;
                }
            }
            return false;
        }

        private int FindEmptyIndexInArray()
        {
            
            return -1;
        }

        private bool IsNumberDuplicate(uint number)
        {
           
            return false;
        }

        public void Query(uint num)
        {
            
        }

        public bool RemoveLastFactorObject()
        {
            if (factorIndex >= 0)
            return false;
        }

        private void ResizeArray(uint counter)
        {
            factor[] temp = arrFactorObject;
            arrFactorSize *= 2;
            arrFactorObject = new factor[arrFactorSize];
            for (int i = 0; i < counter; i++)
            {
                arrFactorObject[i] = temp[i];
            }

        }
    }
}
