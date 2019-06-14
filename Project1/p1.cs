/*
-- Developer     : Don Dang
-- Project       : Project 1
-- Instructor    : Dr. Dingle
-- File Name     : p1.cs
-- File Version  : 1.0
-- Due Date	     : 4/8/2019
-- Course Name   : CPSC 3200
-- Global        : 
--                 const int RAND_MIN = 1;
--                 const int RAND_MAX = 1000;
--                 const int MIN_FACTOR = 2;
--                 const int MAX_FACTOR = 20;
--                 const int ARR_SIZE= 5;
-- Methods       : Private
--                   N/A
--                 Public 
--                   void InitializeFactorObject(factor[] objArr, 
--                     int[] factorArr, Random rand)
--                   void ProgramIntro()
--                   void ResetObjects(factor[] objArr)
--                   void TestObjectWithRandomNumber(factor[] objArr, 
--                     int[] factorArr, Random rand)
--                   void TestInactiveObject(factor[] objArr, 
--                     int[] factorArr, Random rand)
--
-- Driver Design:
--                All generated numbers will be positive integers
--                Five factor objects will be declared and initialized for test
--                factor[] objArray = new factor[ARR_SIZE];
--                  hold factor objects
--                int[] factorArray = new int[ARR_SIZE];
--                  hold factor value for each factor object
--                All functions are public static void
--                InitializeFactorObject(factor[] objArr, int[] factorArr)
--                  declared and initialized factor objects
--                  factor value will be randoly generated between 2 - 20
--                ProgramIntro()
--                  briefly display project 1 description
--                ResetFactorObject(objArray)
--                  reset class private data members to initial value/status
--                TestObjectWithRandomNumber(objArray, factorArray, rand)
--                  loop through each factor object array
--                  display each object factor value
--                  determine if object status is active
--                  no
--                     display object status & multiple count
--                     terminate current object testing
--                  generate random number
--                  check if random number is multiple of object factor value
--                  display generated number & multiple count
--                                 			
-- Notes      : 
--               All factor initialization will have a factor value 
--                 greater than 0
--               All comments followed 80 characters line rule

-- Test Cases :
--              1. TestInactiveObject(factor[] objArr, int[] factorArr, Random rand)
--                  Generate a static number
--                  Determine static number is a multiple of factor value
--                  Passed it to the Div() 3 consecutive times
--                  By desgin factor object will be set to inactive
--                  Multiple max count = 2.
--                  PRE: 
--                    Factor object & factor value already intialized
--                  POST: 
--                    Display factor value and total multiple count
--              2. TestObjectWithRandomNumber(factor[] objArr, int[] factorArr, Random rand)	
--                  Generate random number from 1 - 10000
--                  Pass the random number to Div()
--                  Any passed in random number multiple of factor value
--                    will increment multiples count by 1
--                  If two consecutive passed in number is the same the same
--                    factor object will be set to inactive and 
--                    multiple count will no longer be incremented
--                  PRE:
--                    Factor object and factor value already initialized
--                  POST:
--                    Display factor value and the multiple count
--             3. TestQueryCount(factor[] objArr, int[] factorArr)
--                  Call the GetDiv() method to get current factor object
--                    multiple count
--                PRE:
--                  Factor object and factor value already initialized
--                POST:
--                  Display factor object, factor value and total multiple
--                    count for each factor value
--             4. ResetObjects(factor[] objArr)
--                Display factor value and its multiple counts
--                  all multiple count value should be equals 0
--                PRE:
--                  All factor class private members already initialized
--                POST:
--                  Reset multiple count, lastNumber & isObject variables
--                  in the class to their initial values.
----------------------------------------------------------------
-- WHEN		WHO		WHAT
-- 4/4/19	DD  	Design and model p1.cs
-- 4/5/19   DD      Created p1.cs         
-- 4/6/19   DD      Created ProgramIntro(), Reset()
--                    TestObjectWithRandomNumber()
--                  Added new test case, TestInactiveObject()
-- 4/7/19   DD      Added documentation comments
*/

using System;
namespace Project1
{
    class p1
    {
        const int RAND_MIN = 1;
        const int RAND_MAX = 1000;
        const int MIN_FACTOR = 2;
        const int MAX_FACTOR = 20;
        const int ARR_SIZE= 5;

        static void Main(string[] args)
        {
            Random rand = new Random();

            ProgramIntro();
            factor[] objArray = new factor[ARR_SIZE];
            int[] factorArray = new int[ARR_SIZE];
            InitializeFactorObject(objArray,factorArray, rand);
            TestObjectWithRandomNumber(objArray, factorArray, rand);
            TestQueryCount(objArray, factorArray);
            ResetObjects(objArray);
            TestInactiveObject(objArray, factorArray, rand);
            TestQueryCount(objArray, factorArray);
            ResetObjects(objArray);
            Console.Write("\n");
            Console.Write("Press any key to terminate program... ");
            Console.ReadKey();
        }

        public static void TestInactiveObject(factor[] objArr, int[] factorArr, Random rand)
        {
            Console.WriteLine("\n");
            Console.WriteLine("Begin test inactive object.");
            Console.WriteLine(" Count number of multiples per factor value.");
            int staticNumber = rand.Next(RAND_MAX, RAND_MAX);
            int objNumber = 1;
            for (int i = 0; i < ARR_SIZE; i++)
            {
                Console.WriteLine("  Object {0} - factor value: " +
                    "{1}", objNumber, factorArr[i]);
                Console.WriteLine("    static number: {0}, " +
                    "multiples count: " +
                    "{1}", staticNumber, objArr[i].Div((uint)staticNumber));
                Console.WriteLine("    static number: {0}, " +
                    "multiples count: " +
                    "{1}", staticNumber, objArr[i].Div((uint)staticNumber));
                Console.WriteLine("    static number: {0}, " +
                    "multiples count: " +
                    "{1}", staticNumber, objArr[i].Div((uint)staticNumber));
                objNumber++;
                Console.WriteLine("\n");
            }
        }


        public static void TestObjectWithRandomNumber(factor[] objArr, 
            int[] factorArr, Random rand)
        {
            Console.WriteLine("\n");
            Console.WriteLine("Begin test object with random number.");
            Console.WriteLine(" Count number of multiples per factor value.");
            int randNumber;
            int objNumber = 1;
            for (int i = 0; i < ARR_SIZE; i++)
            {
                Console.WriteLine(" Object {0} - factor value: " +
                    "{1}",objNumber, factorArr[i]);
                for (int j = 0; j < ARR_SIZE; j++)
                {
                    randNumber = rand.Next(RAND_MIN, RAND_MAX);
                    Console.WriteLine("    generated number: {0}, " +
                        "multiples count: " +
                        "{1}", randNumber, objArr[i].Div((uint)randNumber));
                }
                objNumber++;
                Console.WriteLine("\n");
            }
        }

        public static void TestQueryCount(factor[] objArr, int[] factorArr)
        {

            Console.WriteLine("Begin test query count.");
            Console.WriteLine("  Display total count per factor value.");
            int objNumber = 1;
            for (int i = 0; i < ARR_SIZE; i++)
            {
                Console.WriteLine("   Object {0}, factor value: {1}, " +
                    "total count: {2}", objNumber, factorArr[i], objArr[i].GetDivCount());
                objNumber++;
            }
            Console.WriteLine("\n");
        }

        public static void ProgramIntro()
        {
            Console.WriteLine("This program encapsulate a factor class.");
            Console.WriteLine("Each factor object encapsulate a 'factor'");
            Console.WriteLine("value and, if active, identifies whether");
            Console.WriteLine("an incoming value is a multiple of this");
            Console.WriteLine("factor value AND keeps a count of all");
            Console.WriteLine("incoming values that are multiples.");
            Console.WriteLine("Every factor object is initially active");
            Console.WriteLine("but transmission to inactive if two");
            Console.WriteLine("successive IsMultiple queries are made");
            Console.WriteLine("with the same value.");
            Console.WriteLine("\n");
            Console.WriteLine("A factor value for each object will be");
            Console.WriteLine("generated using a random().");
            Console.WriteLine("In addition incoming value to test");
            Console.WriteLine("whether it is a multiple of the factor");
            Console.WriteLine("will also be randomly generated.");
            Console.WriteLine("The range of these generated values will be");
            Console.WriteLine("from " + RAND_MIN + " - " + RAND_MAX);
        }

        public static void InitializeFactorObject(factor[] objArr, 
            int[] factorArr, Random rand)
        {
            Console.WriteLine("\n");
            Console.WriteLine("Initialize " + ARR_SIZE+ " factor objects class.");
            int factorValue;
            for (int i = 0; i < ARR_SIZE; i++)
            {
                factorValue = rand.Next(MIN_FACTOR, MAX_FACTOR);
                factorArr[i] = factorValue;
                objArr[i] = new factor((uint)factorValue);
            }
        }

        public static void ResetObjects(factor[] objArr)
        {
            Console.WriteLine("Reset Factor objects.");
            int objNum = 1;
            for (int i = 0; i < ARR_SIZE; i++)
            {
                objArr[i].Reset();
                Console.WriteLine("   Object {0}, multiples count: {1}", objNum, 
                    objArr[i].GetDivCount());
                objNum++;
            }
        }
    }
}
