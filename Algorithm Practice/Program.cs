using System;

namespace Algorithm_Practice
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Algorithm Practice");
            int[] arrUnsorted = new int[] { 6, 4, 3, 2, 1 };
            Console.ReadKey();
        }

        public static void SelectionSort(int[] arr)
        {
            int smallest = arr[0];
            int smallest_index = 0;
            for (int i = 1; i < arr.Length; i++)
            {
                if (arr[i] < smallest)
                {
                    int ptr = smallest;
                }
            }
        }
    }
}
