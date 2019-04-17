/*
-- Developer    : Don Dang
-- Project      : Project 2
-- Instructor   : Dr. Dingle
-- File Name    : p2.cs
-- File Version : 1.0
-- Due Date	    : 4/17/2019
-- Course Name  : CPSC 3200
----------------------------------------------------------------------------
OVERVIEW: 
   This driver will sequentially test each class: 1) range.cs 2)multiQ.cs
   The first test will be the range.cs
   Range's Class Test Cases:
   1. Initialize Range objects
      Generate two random factor values and use them to initial Range object. 
      The range of the factor value is from 2 - 10 (inclusive)
      

Design Decisions and Assumptions:
 

----------------------------------------------------------------------------------
-- WHEN     WHO		WHAT
   4/14/19	DD  	Created p2.cs
                    Create function signatures for the range.cs
                    Develop test cases for range.cs
   4/15/19  DD      Create function signatures for the multiQ.cs
                    Develop test cases for multiQ.cs
   4/16/19  DD      Added comments for p2.cs

                 
*/		

using System;

namespace Project2
{
    class p2
    {
        const int RAND_MIN = 1;
        const int RAND_MAX = 1000;
        const int MIN_FACTOR = 2;
        const int MAX_FACTOR = 20;
        const int MIN_FACTOR_IDX = 0;
        const int MAX_FACTOR_IDX = 1;
        const int ARR_SIZE = 7;
        const int ARR_RESIZE_VALUE = 2;

         /// <summary>
         /// 
         /// </summary>
         /// <param name="args"></param>
        static void Main(string[] args)
        {
            Random rand = new Random();

            ProgramIntro();
            int[] arrFactorValues = new int[ARR_SIZE];
            range rangeObj = InitRangeObject(rand, arrFactorValues);
            TestPingWithRandomNumber(rangeObj, arrFactorValues, rand);
            ReplaceRangeFactor(rangeObj, arrFactorValues, rand);
            TestPingWithRandomNumber(rangeObj, arrFactorValues, rand);

            multiQ multiQObj = InitMultiQObject();
            
            factor[] arrFactorObj = InitFactorObject(rand, multiQObj, arrFactorValues);
            PushFactorObjectsToMultiQ(multiQObj, arrFactorObj, arrFactorValues);
          
            QueryMultiQ(multiQObj, rand, arrFactorValues);
            PopFactorObjectFromMultiQ(multiQObj);
            ResetFactorObjects(multiQObj);

            Console.Write("Press any key to terminate program... ");
            Console.ReadKey(); 
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="rand"></param>
        /// <param name="arrFactorValues"></param>
        /// <returns></returns>
        public static range InitRangeObject(Random rand, int[] arrFactorValues)
        {
            Console.WriteLine("\n");
            Console.WriteLine("----------------------------------------------------");
            Console.WriteLine("Initialize Range objects.");
            int factorValue1 = rand.Next(MIN_FACTOR, MAX_FACTOR);
            int factorValue2 = rand.Next(MIN_FACTOR, MAX_FACTOR);
            arrFactorValues[MIN_FACTOR_IDX] = factorValue1;
            arrFactorValues[MAX_FACTOR_IDX] = factorValue2;
            range rangeObj = new range((uint)factorValue1, (uint)factorValue2);
            return rangeObj;
        }

        //SUMMARY:
        public static multiQ InitMultiQObject()
        {
            Console.WriteLine("----------------------------------------------------");
            Console.WriteLine("Initialize MultiQ object.");
            multiQ mObj = new multiQ();
            return mObj;
        }

        //SUMMARY:
        public static factor[] InitFactorObject(Random rand, multiQ obj, int[] factors)
        {
            Console.WriteLine("Initialize Factor objects.");
            factor[] fObj = new factor[ARR_SIZE];
            int randNum;
            for (int i = 0; i < ARR_SIZE; i++)
            {
                randNum = rand.Next(MIN_FACTOR, MAX_FACTOR);
                factors[i] = (randNum);
                fObj[i] = new factor((uint)randNum);
            }
            return fObj;
        }

        //SUMMARY:
        public static void PushFactorObjectsToMultiQ(multiQ qObj, factor[] arrFactorObj, int[] factors)
        {
            Console.WriteLine(" Begin push Factor objects to MultiQ.");
            for (int i = 0; i < ARR_SIZE; i++)
            {
                qObj.PushFactorObj(arrFactorObj[i]);
            }
            string strFactorValues = ConvertArrayToString(factors);
            Console.WriteLine(" Factor values: {0}", strFactorValues);
            Console.WriteLine(" End push Factor objects to MultiQ.");
        }

        //SUMMARY:
        public static string ConvertArrayToString(int[] arr)
        {
            string strValues = "";
            if (arr.Length > 0)
            {
                strValues = Convert.ToString(arr[0]);
                for (int i = 1; i < arr.Length; i++)
                {
                    strValues += "," + Convert.ToString(arr[i]);
                }
            }
            return strValues;
        }

        //SUMMARY:
        public static string ParseArrayValuesToString(int[] arr)
        {
            string strValues = "";
            if (arr.Length > 0)
            {
                if (arr[0] > 0)
                {
                    strValues = Convert.ToString(arr[0]);
                    for (int i = 1; i < arr.Length; i++)
                    {
                        if (arr[i] > 0)
                        {
                            strValues += " " + Convert.ToString(arr[i]);
                        }
                    }
                }
                else
                {
                    for (int i = 1; i < arr.Length; i++)
                    {
                        if (arr[i] > 0)
                        {
                            strValues += Convert.ToString(arr[i]) + " ";
                        }
                    }
                }
            }
            return strValues;
        }

        //SUMMARY:
        public static void InitStaticFactorObject(Random rand, multiQ obj, int[] factors, int arraySize = ARR_SIZE)
        {
            Console.WriteLine("Initialize Static Factor objects.");

            int randNum = 2;
            for (int i = 0; i < arraySize; i++)
            {
                factors[i] = (randNum + i);
                factor factorObj = new factor((uint)(randNum + i));
                obj.PushFactorObj(factorObj);
            }
            Console.WriteLine(" Begin push Factor objects to MutliQ.");
            string strFactorValues = ConvertArrayToString(factors);
            Console.WriteLine(" Factor values: {0}", strFactorValues);
        }

        //SUMMARY:
        public static void QueryMultiQ(multiQ obj, Random rand, int[] factors, int arraySize = ARR_SIZE)
        {
            Console.WriteLine("\n");
            Console.WriteLine(" Begin query MultiQ.");
            int randNum;
            uint queryCount;
            int[] arrQueryNumbers = new int[arraySize];
            for (int i = 0; i < arraySize; i++)
            {
                randNum = rand.Next(RAND_MIN, RAND_MAX);
                arrQueryNumbers[i] = randNum;
                queryCount = obj.Query((uint)randNum);
            }
            DisplayMultiQStat(obj, arrQueryNumbers, factors);
            Console.WriteLine(" End query MultiQ.");
        }

        //SUMMARY:
        public static void PopFactorObjectFromMultiQ(multiQ obj)
        {
            Console.WriteLine("\n");
            Console.WriteLine(" Begin pop Factor objects from MutliQ.");
            bool isPopped = true;
            while(isPopped)
            {
                isPopped = obj.PopFactorObject();
            }
            Console.WriteLine(" End pop Factor objects from MutliQ.");

        }

        //SUMMARY:
        public static void DisplayMultiQStat(multiQ obj, int[] queriedNumbers, int[] factors)
        {
            string strFactorValues = ConvertArrayToString(factors);
            string strQueryNumbers = ConvertArrayToString(queriedNumbers);
            int[] arrSuccessQueriedNumbers = obj.GetQueriedNumberList();
            string strSuccessQueriedNumbers = ParseArrayValuesToString(arrSuccessQueriedNumbers);
           
            Console.WriteLine("  Total queried numbers: {0}", strQueryNumbers);
            Console.WriteLine("  Factor values: {0}", strFactorValues);
            Console.WriteLine("  Stats from MultiQ class");
            Console.WriteLine("    Successful queried numbers: {0}", strSuccessQueriedNumbers);
            Console.WriteLine("    Max queried number: {0}", obj.GetMaxQuery());
            Console.WriteLine("    Min queried number: {0}", obj.GetMinQuery());
            Console.WriteLine("    Average queried number: {0}", obj.GetAvgQuery());
            Console.WriteLine("    Total successful queried count: {0}", obj.GetQueryCount());
           
        }

        //SUMMARY:
        public static void ProgramIntro()
        {
            Console.WriteLine("P2's goal is to design and implement");
            Console.WriteLine("two classes, each of which encapsulate");
            Console.WriteLine("distinct factor objects. The first type, ");
            Console.WriteLine("'range', uses 2 factor objects to identify");
            Console.WriteLine("all pinged values that have exactly two");
            Console.WriteLine("factors (grater than one) in common.");
            Console.WriteLine("For example, if a range object encapsulated");
            Console.WriteLine("factor objects with factors 5 and 7 then a");
            Console.WriteLine("pinged value of 735 would satisfy this criterion");
            Console.WriteLine("while a pinged value of 78 would not.");
            Console.WriteLine("Cumulative statistics should also be released.");
            Console.WriteLine("\n");
            Console.WriteLine("The second type, multiQ, tracks some number of");
            Console.WriteLine("factor objects at a given time and.");
            Console.WriteLine("1. returns a count reflecting the divisibility");
            Console.WriteLine("of the factors thus encapsulated. For example,");
            Console.WriteLine("an active multiQ object tracking factor objects");
            Console.WriteLine("with thresholds 4, 7, and 102 would return 2");
            Console.WriteLine("if queried with 84 and 0 if queried with 311.");
            Console.WriteLine("\n");
            Console.WriteLine("The factor,ping and query values will randomly be");
            Console.WriteLine("generated using a random().");
            Console.WriteLine("Factor value range: " + MIN_FACTOR + "-" + MAX_FACTOR);
            Console.WriteLine("Ping value range: " + RAND_MIN + "-" + RAND_MAX);
            Console.WriteLine("Query value range: " + RAND_MIN + "-" + RAND_MAX);

        }

        //SUMMARY:
        public static void ReplaceRangeFactor(range obj, int[] arrFactorValues, Random rand)
        {
            int cFactorValue1 = arrFactorValues[MIN_FACTOR_IDX];
            int cFactorValue2 = arrFactorValues[MAX_FACTOR_IDX];
            int newFactor1 = rand.Next(MIN_FACTOR, MAX_FACTOR);
            int newFactor2 = rand.Next(MIN_FACTOR, MAX_FACTOR);
            arrFactorValues[MIN_FACTOR_IDX] = newFactor1;
            arrFactorValues[MAX_FACTOR_IDX] = newFactor2;
            obj.Replace((uint)newFactor1, (uint)newFactor2);
        
            Console.WriteLine("\n");
            Console.WriteLine("Begin replace currrent factor values with " +
                "new factor values.");
            Console.WriteLine(" Current factor values: {0},{1}", cFactorValue1,
                cFactorValue2);
            Console.WriteLine(" Replaced factor values: {0},{1}", newFactor1,
                newFactor2);
        }

        //SUMMARY:
        public static void ResetFactorObjects(multiQ qObj)
        {
            Console.WriteLine("\n");
            Console.WriteLine(" Begin reset MultiQ object");
            qObj.Reset();
            Console.WriteLine(" End reset MultiQ object");
        }

        //SUMMARY:
        public static void TestPingWithRandomNumber(range obj,
            int[] factorArr, Random rand)
        {
            Console.WriteLine("\n");
            Console.WriteLine("Begin test Ping() with random number.");
            Console.WriteLine(" Count number of multiples that have exactly" +
                " two factors.");
            int randPing; 
            uint count;
            int factor1 = factorArr[MIN_FACTOR_IDX];
            int factor2 = factorArr[MAX_FACTOR_IDX];

            for (int i = 0; i < ARR_SIZE; i++)
            {
                randPing = rand.Next(RAND_MIN, RAND_MAX);
                count = obj.Ping((uint)randPing);
               
                Console.WriteLine("  Pinged number: {0}", randPing);
                Console.WriteLine("  Factor values: {0}, {1}", factor1, factor2);
                Console.WriteLine("  Stats From Range Class");
                Console.WriteLine("   Minimum ping value: {0}", obj.GetMinPing());
                Console.WriteLine("   Maximum ping value: {0}", obj.GetMaxPing());
                Console.WriteLine("   Successful pinged count: {0}", count);
                Console.WriteLine("\n");
            }
        }
    }
    
}
