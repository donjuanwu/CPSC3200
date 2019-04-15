/*
-- Developer    : Don Dang
-- Project      : Project 2
-- Instructor   : Dr. Dingle
-- File Name    : p2.cs
-- File Version : 1.0
-- Due Date	    : 4/17/2019
-- Course Name  : CPSC 3200
-- Data Members : 
--                Private
--                 int divFactor;      - passed in divisible factor
--                 int multiplesCount; - keep track of multiple count
--                 int lastNumber;     - use to compare current number
--                 bool isObjActive;   - keep track of object status
--                 const int INITIAL_FACTOR = 1;
--                 const int INITIAL_LAST_NUMBER = -1;
--                 const int INITIAL_MULTIPLESCOUNT = 0;
--                Public: 
--                  N/A
-- Methods      :  
--                Helper Utilities
--                  N/A
--                Private
--                  N/A
--                Public
--                  factor(int initialFactor)
--                  Div(int number)
--                  Reset()
--                  Accessors
--                    GetDivCount() 
--                  Mutators
--                    N/A
--                
-- Class Design :
--                 No Default Constructor, a factor value must be 
--                   provided
--                 Parameterized Constructor, factor value less 
--                   than 1 will be initialized to 1
--                 Constructor will initialized all private members
--                 Incoming number must be positive integer,
--                  number > 0
--                Div() 
--                  increment multiplescount variable by 1 ONLY when 
--                    object status is 'true' and the current incoming 
--                    number doesnt equals the lastNumber
--                  set isObjStatus to 'false', when lastNumber equals
--                    incoming number
--                  assign number to lastNumber
--                  return multiplescount
--                 Reset()
--                   reset all private members:
--                     isObjective, lastNumber and multiplesCount to initial value
--                 GetDivCount()
--                   return multiplescount
--
-- Interface Invariants 
     Minimal    : illegal calls (unspecified behavior)
     - Cannot Ping() with a non positive integer
     - 
   Problematic:
   Unncessary :
--				
--				
----------------------------------------------------------------
-- WHEN		WHO		WHAT
   4/14/19	DD  	Created p2.cs
                      develop test cases for the range.cs

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
        const int ARR_RANGE_SIZE = 2;
        const int MIN_FACTOR_IDX = 0;
        const int MAX_FACTOR_IDX = 1;
        const int ARR_MULTIQ_SIZE = 5;

        static void Main(string[] args)
        {
            Random rand = new Random();

            ProgramIntro();
            int[] factorArray = new int[ARR_RANGE_SIZE];
            range rangeObj = InitRangeObject(rand, factorArray);
            TestPingWithRandomNumber(rangeObj, factorArray, rand);
            ReplaceRangeFactor(rangeObj, factorArray, rand);
            TestPingWithRandomNumber(rangeObj, factorArray, rand);

            multiQ multiQObj = InitMultiQObject();
            InitFactorObject(rand, multiQObj);
            TestQueryMultiQ(multiQObj, rand);


            Console.Write("Press any key to terminate program... ");
            Console.ReadKey(); 
        }
        public static range InitRangeObject(Random rand, int[] factorArray)
        {
            Console.WriteLine("\n");
            Console.WriteLine("Initialize Range objects.");
            int factorValue1 = rand.Next(MIN_FACTOR, MAX_FACTOR);
            int factorValue2 = rand.Next(MIN_FACTOR, MAX_FACTOR);
            factorArray[MIN_FACTOR_IDX] = factorValue1;
            factorArray[MAX_FACTOR_IDX] = factorValue2;
            range rangeObj = new range((uint)factorValue1, (uint)factorValue2);
            return rangeObj;
        }

        public static multiQ InitMultiQObject()
        {
            Console.WriteLine("----------------------------------------------------");
            Console.WriteLine("Initialize MultiQ objects.");
            multiQ mObj = new multiQ();
            return mObj;
        }

        public static void InitFactorObject(Random rand, multiQ obj)
        {
            Console.WriteLine("Initialize Factor objects.");

            int randNum;
            for (int i = 0; i < ARR_MULTIQ_SIZE; i++)
            {
                randNum = rand.Next(MIN_FACTOR, MAX_FACTOR);
                factor factorObj = new factor((uint)randNum);
                obj.AddFactorObj(factorObj);
            }
            Console.WriteLine(" Add Factor objects to MutliQ array.");
        }

        public static void TestQueryMultiQ(multiQ obj, Random rand)
        {
            Console.WriteLine("  Initialize test Query().");

            int randNum;
            uint queryCount;
            for (int i = 0; i < ARR_MULTIQ_SIZE; i++)
            {
                randNum = rand.Next(RAND_MIN, RAND_MAX);
                queryCount = obj.Query((uint)randNum);
                Console.WriteLine("  Queried number: {0}", randNum);
                Console.WriteLine("   Successful query count: {0}", queryCount);
            }
            
        }


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
        public static void ReplaceRangeFactor(range obj, int[] factorArray, Random rand)
        {
            int cFactorValue1 = factorArray[MIN_FACTOR_IDX];
            int cFactorValue2 = factorArray[MAX_FACTOR_IDX];
            int newFactor1 = rand.Next(MIN_FACTOR, MAX_FACTOR);
            int newFactor2 = rand.Next(MIN_FACTOR, MAX_FACTOR);
            factorArray[MIN_FACTOR_IDX] = newFactor1;
            factorArray[MAX_FACTOR_IDX] = newFactor2;
            obj.Replace((uint)newFactor1, (uint)newFactor2);
        
            Console.WriteLine("\n");
            Console.WriteLine("Begin replace currrent factor values with " +
                "new factor values.");
            Console.WriteLine(" Current factor values: {0},{1}", cFactorValue1,
                cFactorValue2);
            Console.WriteLine(" Replaced factor values: {0},{1}", newFactor1,
                newFactor2);
        }

        public static void TestPingWithRandomNumber(range obj,
            int[] factorArr, Random rand)
        {
            Console.WriteLine("\n");
            Console.WriteLine("Begin test ping with random number.");
            Console.WriteLine(" Count number of multiples that have exactly" +
                " two factors.");
            int randPing; 
            uint count;
            int factor1;
            int factor2;

            for (int i = 0; i < ARR_RANGE_SIZE; i++)
            {
                randPing = rand.Next(RAND_MIN, RAND_MAX);
                count = obj.Ping((uint)randPing);
                factor1 = factorArr[MIN_FACTOR_IDX];
                factor2 = factorArr[MAX_FACTOR_IDX];

                Console.WriteLine("  Pinged number: {0}", randPing);
                Console.WriteLine("  Factor values: {0}, {1}", factor1, factor2);
                Console.WriteLine("  Minimum ping value: {0}", obj.GetMinPing());
                Console.WriteLine("  Maximum ping value: {0}", obj.GetMaxPing());
                Console.WriteLine("  Total ping count: {0}", count);
                Console.WriteLine("\n");
            }
        }
    }
    
}
