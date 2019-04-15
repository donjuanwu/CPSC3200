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
        private const int INITIAL_FACTOR_INDEX = -1;

        public multiQ()
        {
            arrFactorObject = new factor[INITIAL_ARRAY_SIZE];
            isObjActive = true;
            arrFactorSize = INITIAL_ARRAY_SIZE;
            factorIndex = INITIAL_FACTOR_INDEX;
            queryCount = INITIAL_QUERYCOUNT;
        }

        public bool AddFactorObj(factor obj)
        {
           if (isObjActive)
            {
                if (factorIndex < arrFactorSize)
                {
                    factorIndex++;
                    arrFactorObject[factorIndex] = obj;
                    return true;
                }
                else
                {
                    ResizeFactorArray((uint)factorIndex);
                    factorIndex++;
                    arrFactorObject[factorIndex] = obj;
                    return true;
                }
            }
            return false;
        }

        public bool IsEmpty()
        {
            if (factorIndex < 0)
            {
                return true;
            }
            return false;
        }

        public uint Query(uint num)
        {
            if (isObjActive)
            {
                if (!IsEmpty())
                {
                    for (int i = 0; i <= factorIndex; i++)
                    {
                        int retDivCount = arrFactorObject[i].Div(num);
                        if (retDivCount == -1)
                        {
                            isObjActive = false;
                            break;
                        }
                        else
                        {
                            int prevDivCount = arrFactorObject[i].GetDivCount();
                            if (retDivCount > prevDivCount)
                            {
                                queryCount++;

                            }
                        }

                    }
                }
            }
            return queryCount;
        }

        public bool RemoveLastFactorObject()
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

        private void ResizeFactorArray(uint index)
        {
            factor[] temp = arrFactorObject;
            arrFactorSize *= 2;
            arrFactorObject = new factor[arrFactorSize];
            for (int i = 0; i <= index; i++)
            {
                arrFactorObject[i] = temp[i];
            }

        }
    }
}
