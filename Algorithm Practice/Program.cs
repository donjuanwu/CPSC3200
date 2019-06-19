using System;

namespace Algorithm_Practice
{
    class Program
    {
        const string ASTERISK = "****************";
        static void Main(string[] args)
        {
            Console.WriteLine(ASTERISK + "Interview Preparation" + ASTERISK);
           // PracticeAlgorithm();
          //  TestBoxing();
          //  TestUnBoxing();
          //  TestBitWiseShift();
            TestParity();

           

            Console.ReadKey();
        }

        public static void Intro()
        {
            Console.WriteLine("");
            Console.WriteLine(ASTERISK + "Begin Display Topics To Be Covered" + ASTERISK);


            Console.WriteLine("");
            Console.WriteLine(ASTERISK + "End Display Topics To Be Covered" + ASTERISK);
        }


        public static void PracticeAlgorithm()
        {
            Console.WriteLine("");
            Console.WriteLine(ASTERISK + "Begin Sorting Algorithm" + ASTERISK);
            int[] arrUnsorted = new int[] { 6, 4, 3, 2, 1 };

            int[] arrSelectionSorted = SelectionSort(arrUnsorted);
            PrintArray(arrUnsorted, "unsorted array");
            PrintArray(arrSelectionSorted, "selection sort");

            Console.WriteLine(ASTERISK + "End Sorting Algorithm" + ASTERISK);
        }

        //Selection sort is a simple sorting algorithm
        //This sorting algorithm is an in-place comparison-based algorithm in which 
        //the list is divided into two parts, the sorted part at the left end and the
        //unsorted part at the right end.
        //The smallest element is selected from the unsorted array and 
        //swapped with the leftmost element, and that element becomes a part of the sorted array.
        //Cons:
        //this algorithm is not suitable for large data
        //Time Complexity (average and worst case)
        //O (n^2), where n is the number of item
        public static int[] SelectionSort(int[] arr)
        {
            int[] arrLoc = new int[arr.Length];
            for (int i = 0; i < arr.Length; i++) //transfer ownership, avoid copy by bitwise. 
            {                                    //arrLoc = arr
                arrLoc[i] = arr[i];
            }

            int smallest;
            int temp;
            for (int i = 0; i < arrLoc.Length - 1; i++) //get 
            {
                smallest = arrLoc[i];
                for (int j = i + 1; j < arrLoc.Length; j++)
                {
                    if (arrLoc[j] < arrLoc[i])
                    {
                        temp = arrLoc[i];
                        arrLoc[i] = arrLoc[j];
                        arrLoc[j] = temp;
                    }
                }
            }

            return arrLoc;
        }

        //Print values from array
        public static void PrintArray(int[] arr, string strType)
        {
            Console.WriteLine("");
            Console.WriteLine("-printing values from a {0}: ", strType);
            Console.Write(" ");
            for (int i = 0; i < arr.Length; i++)
            {
                if (arr.Length - i > 1)
                {
                    Console.Write(arr[i] + ",");
                }
                else
                {
                    Console.WriteLine(arr[i]);
                }
            }
        }

        //The process of Converting a Value Type (char, int, etc.) to a Reference Type (object) is called Boxing
        //Boxing is implicit conversion process in which object type (super type) is used
        //The Value type is always stored in Stack. 
        //The Referenced Type is stored in Heap
        public static void TestBoxing()
        {
            Console.WriteLine("");
            Console.WriteLine(ASTERISK + "Begin display Boxing" + ASTERISK);

            int num = 23; //declare on the stack
            Object obj = num; //Boxing: assigned a value type (int) to a reference type (object)

          //  num = 50; //assign 50 to num
            
            Console.WriteLine("Value type - value {0}", num);
            Console.WriteLine("Reference type - value {0}", obj);

            Console.WriteLine("");
            Console.WriteLine(ASTERISK + "End display Boxing" + ASTERISK);

        }

        public static void TestUnBoxing()
        {
            Console.WriteLine("");
            Console.WriteLine(ASTERISK + "Begin display Unboxing" + ASTERISK);
            int num = 23;
            Object obj = num;   //Boxing - converting a Value Type to a Reference Type
            Console.WriteLine("Value type - value {0}", num);
            Console.WriteLine("Reference type - value {0} through Boxing", obj);
            obj = 50;
            int num2 = (int)obj; //Unboxing - converting a Reference Type (object) to a Value Type (int, char etc)
            Console.WriteLine("Reference type - new value {0} through assignment", obj);
            Console.WriteLine("Value type - value {0} through Unboxing", obj);

            Console.WriteLine("");
            Console.WriteLine(ASTERISK + "End display Unboxing" + ASTERISK);

        }

        //Left operands value is moved left by the number of bits specified by the right operand
        // x << y is equivalent to x multiply 2^y
        //Left operands value is moved right by the number of bits specified by the rigth operand
        // x >> y is equivalent to x divide by 2^y

        public static void TestBitWiseShift()
        {
            Console.WriteLine("");
            Console.WriteLine(ASTERISK + "Begin display Left Shift/Rigth Shift" + ASTERISK);

            int leftOperand = 60; // 0 0 1 1 1 1 0 0
            int c = 0;

            c = leftOperand >> 2; //shift right, expect c --> 13

            Console.WriteLine("Left operand value: {0}", leftOperand);
            Console.WriteLine("Left shift - shift by 2. Operand new value: {0}", c);

            c = leftOperand << 2; //shift left, expect c--> 240
            Console.WriteLine("Right operand value: {0}", leftOperand);
            Console.WriteLine("Right shift - shift by 2. Operand new value: {0}", c);

            Console.WriteLine("");
            Console.WriteLine(ASTERISK + "End display Left Shift/Rigth Shift" + ASTERISK);

        }


        public static void TestParity()
        {
            Random rand = new Random();
            //int num = 13;
            int num = rand.Next(2, 100);
            bool isOdd = ParityCheck(num);

            Console.WriteLine("");
            Console.WriteLine("Random number - value: {0}, contain odd/even number of 1-bits '{1}'", num, (isOdd ? "odd" : "even"));


        }

        //Parity: Parity of a number refers to whether it contains an odd or even number of 1-bits.
        //The number has "odd parity", if it contains odd number of 1-bits and is "even parity" if it contains
        //even number of 1-bits.
        //Main idea of the below solutions is - loop while n is not 0 and in loop unset one of
        //the set bits and invert parity
        public static bool ParityCheck(int n)
        {
            bool parity = false;
            while (n != 0)
            {
                parity = !parity; //invert parity
                n = n & (n - 1);
            }

            return parity;

        }

    }
}
