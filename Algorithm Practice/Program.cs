using System;

namespace Algorithm_Practice
{
    class Program
    {
        const string ASTERISK = "****************";
        static void Main(string[] args)
        {
            Console.WriteLine(ASTERISK + "Interview Preparation" + ASTERISK);
            PracticeAlgorithm();

           

            Console.ReadKey();
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
    }
}
