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
   This driver will sequentially test each class: 1) range.cs 2)multiQ.cs & factor.cs
   The first test will be the range.cs
Range's Class Test Cases:
   1. Initialize Range objects
      Generate two random factor values and use them to initial Range object. 
      Factor values will be tracked on Driver class to be used later for 
        context
   2. Test Ping function with random numbers
      A succcessful pinged is when the random number is a multiple of
       two factor values
      There wil be 7 random generated numbers to test
      After pinging each random number, a stat will be provided by the Range class:
      - Successful minimum pinged value
      - Successful maximum pinged value
      - Total successful pinged count
   3. Test replace current factor values with two new factor values
      A successful test will show current factor values and replaced factor values.
      Test Ping function again with new factor values.
      New stats will be displayed base on new factor values.

MultiQ & Factor Class's Test Cases:
    1. Initialize MultiQ object with no parameters.
    2. Initialize Factor objects 
       Expect to created 7 Factor objects and initialized each Factor object
        with a factor. These factor values are randomly generated. There may e
        duplicate factor values. The Factor objects will be added into an array.
       All factor values are stored in an array in the Driver to be used for
         context when display stats from MutliQ.
    3. Test PushFactorObject()
       By design MultiQ class can only store 5 Factor objects. 
       Push 7 Factor objects to MultiQ which will invoke the private
         ResizeArray() to resize the Factor array in MultiQ.
       Expect all 7 Factor object are saved in the MultiQ.
       
    4. Test QueryMutliQ()
       Query 7 randomly generated numbers. Determine how many randomly
         generated numbers are multiples of the factor value belong to 7 Factor object
       Display the following stats from MultiQ for all of them:
       - List of successfully queried numbers
       - Maximum successful queried number
       - Minimum successful queried number
       - Average successful queried value
       - Total successful queried count
   5. PopFactorObjectFromMultiQ()
      There are 7 Factor objects saved from TestPushFactor Object.
      Expect 7 successful pop to display on Driver's console.
   6. ResetMultiQObject()
      All private data members of MultiQ should be reset to initial value
      Stats from MultiQ should all be display 0
       
---------------------------------------------------------------------------------
Design Decisions and Assumptions:
 The range of the factor value is randomly generated between 2 - 10 (inclusive).
 The ping/query number is randomly generated between 1 - 10000 (inclusive).
 All generated numbers are greater than 0.
 Two factor values will be passed to the Range parameterized constructor
 Seven Factor objects and seven factor values will be initialized for 
   the Factor object.
 Range object will be initialized by the InitRangeObject().
 MultiQ object will be initialized by the InitMultiQObject().
 Factor object will be initialized by the InitFactorObject().
 All pinged and queried numbers will be tracked from the Driver to .
  give context to the Stats returned from the Range and the MultiQ classes.
 Range and MultiQ along with Factor will be tested separately.
 The Range class will be tested first.
 The MultiQ and Factor classes will follow.
 Reset MultiQObject ONLY reset all MultiQ private data memebers to initial value.

----------------------------------------------------------------------------------
-- WHEN     WHO		WHAT
   4/14/19	DD  	Created p2.cs
                    Create function signatures for the range.cs
                    Develop test cases for range.cs
   4/15/19  DD      Create function signatures for the multiQ.cs
                    Develop test cases for multiQ.cs
   4/16/19  DD      Added comments for p2.cs
   4/17/19  DD      Added comments for range.cs, mutliQ.cs and factor.cs
                 
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
            ResetMultiQObject(multiQObj);

            Console.Write("Press any key to terminate program... ");
            Console.ReadKey(); 
        }

        /// <summary>
        /// Initialize a range object and return the range object 
        /// to the calling function
        /// </summary>
        /// <param name="rand">initialized random object</param>
        /// <param name="arrFactorValues">empty array to hold two factor values</param>
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

        /// <summary>
        /// Initialize and return multiQ object
        /// </summary>
        /// <returns></returns>
        public static multiQ InitMultiQObject()
        {
            Console.WriteLine("----------------------------------------------------");
            Console.WriteLine("Initialize MultiQ object.");
            multiQ mObj = new multiQ();
            return mObj;
        }

        /// <summary>
        /// Create, intialize and return factor object array
        /// </summary>
        /// <param name="rand">intialize random object</param>
        /// <param name="obj">initialized mutliQ object</param>
        /// <param name="factors">int array to hold factor values</param>
        /// <returns></returns>
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

        /// <summary>
        /// Push Factor objects to multiQ class
        /// </summary>
        /// <param name="qObj">initialized mutliQ object</param>
        /// <param name="arrFactorObj">array contains Factor objects</param>
        /// <param name="factors">array contains factor values</param>
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

        /// <summary>
        /// Convert values in array and assign it to string
        /// Return string
        /// </summary>
        /// <param name="arr">contain numbers</param>
        /// <returns></returns>
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

        /// <summary>
        /// Convert numbers in array to string
        /// Return string
        /// </summary>
        /// <param name="arr">contains numbers</param>
        /// <returns></returns>
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

        /// <summary>
        /// Determine if number is multiple of factor value
        /// </summary>
        /// <param name="obj">multiQ object</param>
        /// <param name="rand">Random object</param>
        /// <param name="factors">contain factor values</param>
        /// <param name="arraySize">array size</param>
        public static void QueryMultiQ(multiQ obj, Random rand, int[] factors)
        {
            Console.WriteLine("\n");
            Console.WriteLine(" Begin query MultiQ.");
            int randNum;
            uint queryCount;
            int[] arrQueryNumbers = new int[ARR_SIZE];
            for (int i = 0; i < ARR_SIZE; i++)
            {
                randNum = rand.Next(RAND_MIN, RAND_MAX);
                arrQueryNumbers[i] = randNum;
                queryCount = obj.Query((uint)randNum);
            }
            DisplayMultiQStat(obj, arrQueryNumbers, factors);
            Console.WriteLine(" End query MultiQ.");
        }

        /// <summary>
        /// Pop Factor objects from MultiQ
        /// </summary>
        /// <param name="obj">multiQ object</param>
        public static void PopFactorObjectFromMultiQ(multiQ obj)
        {
            Console.WriteLine("\n");
            Console.WriteLine(" Begin pop Factor objects from MutliQ.");
            while(obj.PopFactorObject())
            {
                Console.WriteLine("   Factor object popped.");
            }
            Console.WriteLine(" End pop Factor objects from MutliQ.");

        }

       /// <summary>
       /// Display MultiQ stats
       /// </summary>
       /// <param name="obj">multiQ object</param>
       /// <param name="queriedNumbers">contain list of queried numbers</param>
       /// <param name="factors">factor values</param>
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

        /// <summary>
        /// Display Project 2 descriptions
        /// </summary>
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

        /// <summary>
        /// Replace factor values in Range class
        /// </summary>
        /// <param name="obj"></param>
        /// <param name="arrFactorValues"></param>
        /// <param name="rand"></param>
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
            Console.WriteLine("Begin replace current factor values with " +
                "new factor values.");
            Console.WriteLine(" Current factor values: {0},{1}", cFactorValue1,
                cFactorValue2);
            Console.WriteLine(" Replaced factor values: {0},{1}", newFactor1,
                newFactor2);
            Console.WriteLine("End replace current factor values with " +
                "new factor values.");
        }

        /// <summary>
        /// Reset MultiQ private data members to initial value
        /// </summary>
        /// <param name="qObj"></param>
        public static void ResetMultiQObject(multiQ qObj)
        {
           
            Console.WriteLine("\n");
            Console.WriteLine(" Begin reset MultiQ object");
            qObj.Reset();
            int[] arrSuccessQueriedNumbers = qObj.GetQueriedNumberList();
            string strSuccessQueriedNumbers = ParseArrayValuesToString(arrSuccessQueriedNumbers);
            Console.WriteLine("  Reset MultiQ object");

            Console.WriteLine("  Stats from MultiQ class");
            Console.WriteLine("    Successful queried numbers: {0}", strSuccessQueriedNumbers);
            Console.WriteLine("    Max queried number: {0}", qObj.GetMaxQuery());
            Console.WriteLine("    Min queried number: {0}", qObj.GetMinQuery());
            Console.WriteLine("    Average queried number: {0}", qObj.GetAvgQuery());
            Console.WriteLine("    Total successful queried count: {0}", qObj.GetQueryCount());

            Console.WriteLine(" End reset MultiQ object");
            Console.WriteLine("\n");
        }

        /// <summary>
        /// Determine if random number if multiple of factor values in range
        /// </summary>
        /// <param name="obj"></param>
        /// <param name="factorArr"></param>
        /// <param name="rand"></param>
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
            Console.WriteLine("End test Ping() with random number.");
        }
    }
    
}
