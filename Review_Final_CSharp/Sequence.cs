/*
 Individual Design Quiz

 Write the code C# for a class taht encapsulates a sequence of numbers x, x + 1, x + 2, .... x + y
 and count how often each number in sequence is "pinged"

 1. x and y are passed to the constructor and thereafter do not change
 2. key functionality
    a. pinging a number
    b. identify the number pinged most often
    c. identify the number pinged least often
    d. reset()
3. Copying must be fully supported (this is mostly for C++)
4. You may not use vectors or list

Time Start = 7:00
Time End = 
 */


using System;


namespace Review_Final_CSharp
{
    class Sequence
    {
        private int[] array;
        private uint y;
        private uint x;
        private uint aIndex;
        private uint arr_SIZE;

        uint maxPing;
        uint minPing;
        uint countPing;
        uint sumPing;

        const uint INIT_VAL = 2;
        const uint MULTIPLIER = 2;

        //constructor
        public Sequence(int[] arr, uint num1 = INIT_VAL, uint num2 = INIT_VAL)
        {
            x = num1;
            y = num2;
            arr_SIZE = (uint)arr.Length;
            maxPing = 0;
            minPing = 0;
            sumPing = 0;
            aIndex = 0;
            countPing = 0;
            aIndex = 0;

            array = arr;
            //array = new int[arr_SIZE];
        }

        public void Ping (int k)
        {
            countPing++; //increment countPing by 1
            if (IsFound(k))
            {
                SetMaxPing(k);
                SetMinPing(k);
            }
            else
            {
                aIndex++;
                if (aIndex == arr_SIZE)
                {
                    Resize();
                }
                array[aIndex] = k;
                SetMaxPing(k);
                SetMinPing(k);
            }
            sumPing += (maxPing + minPing);

        }


        public uint GetMaxPing()
        {
            return maxPing;
        }

        public uint GetMinPing()
        {
           
            return minPing;
        }

        public uint GetSumPing()
        {
            return sumPing;
        }

        public uint GetPingCount()
        {
            return countPing;
        }

        public void Reset()
        {
            maxPing = 0;
            minPing = 0;
            countPing = 0;
            sumPing = 0;
        }

        //public uint[] GetPingStat()
        //{
        //    uint[] stat = { minPing, maxPing, countPing, sumPing };

        //    return stat;
        //}

        private void Resize()
        {
            int[] temp = new int[arr_SIZE * MULTIPLIER];
            for (int i = 0; i < arr_SIZE; i++)
            {
                temp[i] = array[i];

            }

            array = new int[arr_SIZE * MULTIPLIER];
            array = temp; //assign one array to another array

            arr_SIZE *= 2;

        }

        private bool IsFound(int k)
        {
            bool found = false;

            for (int i = 0; i < arr_SIZE; i++)
            {
                if (array[i] == k)
                {
                    found = true;
                    continue;
                }
            }
            return found;
        }

        private void SetMaxPing(int k)
        {
            if (k >= maxPing)
            {
                maxPing = (uint)k;
            }
        }

        private void SetMinPing(int k)
        {
            if (k <= minPing)
            {
                minPing = (uint)k;
            }
        }
    }
}
