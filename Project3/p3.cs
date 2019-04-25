/*
-- Developer    : Don Dang
-- Project      : Project 3
-- Instructor   : Dr. Dingle
-- File Name    : p3.cs
-- File Version : 1.0
-- Due Date	    : 4/29/2019
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
   4/24/19	DD  	Created p3.cs           
*/


using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project3
{
    class p3
    {
        const int RAND_MIN = 2;
        const int RAND_MAX = 5;
        const int ARR_SIZE = 3;
        const int REDUCED_LENGTH = 2;
        const string VALID_CHARS ="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijkl" +
            "mnopqrstuvwxyz0123456789#_<>!+*&@^=.?|\\";
        const string INVALID_CHARS = " ~(){}[]";

        static void Main(string[] args)
        {
            Random rand = new Random();
            ProgramIntro();

            pwdCheck[] arrPwdObj = InitPwdObject(rand);
            TestPwdClassWithValidPassword(arrPwdObj, rand);
            TestToggleObject(arrPwdObj, rand);
           // TestPwdLenReq(arrPwdObj, rand);

            Console.WriteLine("");
            Console.WriteLine("Press any key to terminate...");
            Console.ReadKey();
        }

        /// <summary>
        /// Display Project 3 descriptions
        /// </summary>
        public static void ProgramIntro()
        {
            Console.WriteLine("P3's goal is to design C# 'pwdcheck' classess");
            Console.WriteLine("that share a common interface but vary output");
            Console.WriteLine("and state transitions.  ");
            Console.WriteLine("");
            Console.WriteLine("Part I: Class Design");
            Console.WriteLine("Design a class hierarchy of pwdChecks, where");
            Console.WriteLine("each pwdCheck object accepts or rejects offered");
            Console.WriteLine("passwords.");
            Console.WriteLine("If 'on', an pwdCheck object accepts a password");
            Console.WriteLine("of length at least p (where p is a stable value");
            Console.WriteLine("that varies from object to object) UNLESS the");
            Console.WriteLine("password contains a forbidden symbol (a small");
            Console.WriteLine("internal set of characters); its on/off state");
            Console.WriteLine("is toggled with every 'pth' request.");
            Console.WriteLine("");
            Console.WriteLine("If 'off', an excessC acts exactly like a pwdCheck;");
            Console.WriteLine("otherwise, it requires that the pth character be");
            Console.WriteLine("a digit, that case is mixed and that '$' appears");
            Console.WriteLine("in the password. A compundC acts like a pwdCheck,");
            Console.WriteLine("except that the password must repeat at least one");
            Console.WriteLine("character and it cannot cycle through on/off states");
            Console.WriteLine("more than 'k' times. ");
            Console.WriteLine("");
            Console.WriteLine("Part II: Driver");
            Console.WriteLine("Design a functionally decomposed driver to demonstrate");
            Console.WriteLine("program requirements. Driver should use a heterogeneous");
            Console.WriteLine("array to appropriately test type functionality");
            Console.WriteLine("Test data (object) should:");
            Console.WriteLine("be allocated via a construction routine");
            Console.WriteLine("provide a random distribution of objects with");
            Console.WriteLine("varying initial values.");

        }

        public static pwdCheck[] InitPwdObject(Random rand)
        {
            Console.WriteLine("");
            Console.WriteLine("Initialize PwdCheck objects.");
            pwdCheck[] arr_PwdObj = new pwdCheck[ARR_SIZE];
            for (int i = 0; i < ARR_SIZE; i++)
            {
               // int num = rand.Next(RAND_MIN, RAND_MAX);
               // arr_PwdObj[i] = new pwdCheck((uint)num);

               // Console.WriteLine("Generated number: {0}", num);
              arr_PwdObj[i]= new pwdCheck((uint)rand.Next(RAND_MIN, RAND_MAX));
            }
            return arr_PwdObj;
        }

        public static string CreateRandomValidString(Random rand, int size)
        {
            string str = "";

            for (int i = 0; i < size; i++)
            {
                str += VALID_CHARS[rand.Next(VALID_CHARS.Length)];
                str += INVALID_CHARS[rand.Next(INVALID_CHARS.Length)];

            }
            return str;
        }

        public static string CreateRandomInValidString(Random rand)
        {
            int length = rand.Next(RAND_MIN, RAND_MAX);
            string str = "";

            for (int i = 0; i < length; i++)
            {
                str += VALID_CHARS[rand.Next(VALID_CHARS.Length)];
                str += INVALID_CHARS[rand.Next(INVALID_CHARS.Length)];

            }
            Console.WriteLine("Generate invalid password: {0}", str);
            return str;
        }

        public static void TestPwdClassWithValidPassword(pwdCheck[] obj, Random rand)
        {
            Console.WriteLine("Begin test PwdCheck class with valid password.");
            for (int i = 0; i < ARR_SIZE; i++)
            {
                int size = obj[i].GetPasswordLength();
                //Console.WriteLine("Retrieved password length from pwdCheck class: {0}", size);
                string pWord = CreateRandomValidString(rand, size);
                if (obj[i].RequestPassword(pWord))
                {
                    Console.WriteLine(" Password is valid: {0}", pWord);
                }
            }
            Console.WriteLine("End test PwdCheck class with valid password.");
        }

        public static void TestToggleObject(pwdCheck[] obj, Random rand)
        {
            Console.WriteLine("");
            Console.WriteLine("Begin test toggle object.");
            for (int i = 0; i < ARR_SIZE; i++)
            {
                int length = obj[i].GetPasswordLength();
                Console.WriteLine(" Object {0} will be toggled with {1} requests.",i,length);
                string pWord = CreateRandomValidString(rand, length);
               
                    if (!obj[i].RequestPassword(pWord))
                    {
                        if (!obj[i].IsObjectActive())
                        {
                            Console.WriteLine(" Object at index {0} was toggled.", i);
                            Console.WriteLine(" ");
                        }
                    }
            }
            Console.WriteLine("End test toggle object.");
        }

        public static void TestPwdClassWithInValidPassword(pwdCheck[] obj, Random rand)
        {
            Console.WriteLine("Begin test PwdCheck class with invalid password.");
            for (int i = 0; i < ARR_SIZE; i++)
            {

                string pWord = CreateRandomInValidString(rand);
                if (!obj[i].RequestPassword(pWord))
                {
                    if (obj[i].IsObjectActive())
                    {
                        Console.WriteLine(" Password is invalid: {0}", pWord);
                    }
                    
                }
            }
            Console.WriteLine("End test PwdCheck class with invalid password.");
        }
    }
}
