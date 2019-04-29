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


namespace Project3
{
    class p3
    {
        enum ObjectName
        {
            pwdClass = 0,
            compundC = 1,
            excessC = 2
        };
        const int RAND_MIN = 10;
        const int RAND_MAX = 20;
        const int ARR_SIZE = 1;
        const int ARR_MULTIPLIER = 3;
        const int REDUCED_LENGTH = 1;
        const string ASTERISK = "***************";
        const string VALID_CHARS ="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijkl" +
            "mnopqrstuvwxyz0123456789#_<>!+*&@^=.?|\\";
        const string INVALID_CHARS = " ~(){}[]";
        const int ONECYLE = 2;
     
        static void Main(string[] args)
        {
            Random rand = new Random();
            ProgramIntro();

            pwdCheck[] arrPwdObj = InitPwdObject(rand);
           // TestPasswordLength(arrPwdObj, rand);
           // TestForbiddenCharactersInPassword(arrPwdObj, rand);
 
            TestToggleObject(arrPwdObj,rand);
          //  TestToggleObject(arrPwdObj, rand);
            //TestToggleObject(arrPwdObj, rand);
             TestCheckPassword2(arrPwdObj, rand);

            // TestToggleObject(arrPwdObj, rand);
            //TestPwdClassWithValidPassword(arrPwdObj, rand);

            // TestPwdClassWithInValidPassword(arrPwdObj, rand);


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
            Console.WriteLine(ASTERISK + "BEGIN INITIALIZED PWDCLASS OBJECTS" + ASTERISK);
            int augmentedArraySize = ARR_SIZE * ARR_MULTIPLIER;
            uint randPwdLength;
            pwdCheck[] arr_PwdObj = new pwdCheck[augmentedArraySize];
            for (int i = 0; i < augmentedArraySize; i++)
            {
                if (i < (augmentedArraySize) / ARR_MULTIPLIER)
                {

                    randPwdLength = (uint)rand.Next(RAND_MIN, RAND_MAX);
                    arr_PwdObj[i] = new pwdCheck(randPwdLength);
                    Console.WriteLine(" Initialized {0} object at index: {1} ", ObjectName.pwdClass, i);
                    Console.WriteLine(" -password length = {0}", arr_PwdObj[i].GetPasswordLength());
                    Console.WriteLine(" -object status: {0}", (arr_PwdObj[i].IsObjectActive() ? "active" : "inactive"));
                    
                }
                else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize - ARR_SIZE))
                {
                    Console.WriteLine("");
                    randPwdLength = (uint)rand.Next(RAND_MIN, RAND_MAX);
                    uint toggleCycle = (uint)rand.Next(RAND_MIN, RAND_MAX);
                    arr_PwdObj[i] = new compundC(randPwdLength, toggleCycle);
                    Console.WriteLine(" Initialized {0} object at index: {1} ", ObjectName.compundC, i);
                    Console.WriteLine(" -password length = {0}", randPwdLength);
                    Console.WriteLine(" -toggle cycle = {0}", toggleCycle);
                    Console.WriteLine(" -toggle max = {0}", toggleCycle * ONECYLE * randPwdLength);
                    Console.WriteLine(" -object status: {0}", (arr_PwdObj[i].IsObjectActive() ? "active" : "inactive"));
                }
                else
                {
                    Console.WriteLine("");
                    bool objStatus = true;
                    randPwdLength = (uint)rand.Next(RAND_MIN, RAND_MAX);
                    arr_PwdObj[i] = new excessC(randPwdLength, objStatus);
                    Console.WriteLine(" Initialized {0} object at index: {1} ", ObjectName.excessC, i);
                    Console.WriteLine(" -password length = {0}", randPwdLength);
                    Console.WriteLine(" -object status: {0}", (objStatus ? "active" : "inactive"));
                }
            }
            Console.WriteLine(ASTERISK + "END INITIALIZED PWDCLASS OBJECTS" + ASTERISK);
            return arr_PwdObj;
        }

        public static string GenerateRandomMixedString(Random rand)
        {
            string str = "";
            int length = rand.Next(RAND_MIN, RAND_MAX);
            string mixedString = VALID_CHARS + INVALID_CHARS;

            for (int i = 0; i < length; i++)
            {
                str += mixedString[rand.Next(mixedString.Length)];
            }
            return str;
        }

        public static string GenRandStrWithPredefinedLen(Random rand, int staticLength)
        {
            string str = "";
            string mixedString = VALID_CHARS + INVALID_CHARS;

            for (int i = 0; i < staticLength; i++)
            {
                str += mixedString[rand.Next(mixedString.Length)];
            }
            return str;
        }

        public static string GenerateRandomValidString(Random rand)
        {
            string str = "";
            int length = rand.Next(RAND_MIN, RAND_MAX);

            for (int i = 0; i < length; i++)
            {
                str += VALID_CHARS[rand.Next(VALID_CHARS.Length)];
            }
            return str;
        }

        public static string GenerateRandomInValidString(Random rand)
        {
            int length = rand.Next(RAND_MIN, RAND_MAX);
            string str = "";

            for (int i = 0; i < length; i++)
            {
                str += VALID_CHARS[rand.Next(VALID_CHARS.Length)];
                str += INVALID_CHARS[rand.Next(INVALID_CHARS.Length)];

            }
            return str;
        }

        public static void TestCheckPassword(pwdCheck[] obj, Random rand)
        {
            Console.WriteLine(" ");
            Console.WriteLine(ASTERISK + "BEGIN TEST PASSWORD" + ASTERISK);
            int augmentedArraySize = ARR_SIZE * ARR_MULTIPLIER;
            for (int i = 0; i < augmentedArraySize; i++)
            {
                string pWord = GenerateRandomMixedString(rand);
                if (!obj[i].ValidatePassword(pWord)) //password is false
                {
                    if (obj[i].IsObjectActive())
                    {
                        if (pWord.Length >= obj[i].GetPasswordLength()) //Has forbidden characters
                        {

                            if (i < (augmentedArraySize) / ARR_MULTIPLIER)
                            {
                                Console.WriteLine(" Object {0} at index: {1}'s has forbidden character(s) ", ObjectName.pwdClass, i);
                                Console.WriteLine(" -rejected password:{0}", pWord);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                            }
                            else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize - ARR_SIZE))
                            {
                                
                                if (obj[i].GetIsCharForbidden())
                                {
                                    Console.WriteLine(" Object {0} at index: {1}'s has forbidden character(s) ", ObjectName.compundC, i);
                                    Console.WriteLine(" -rejected password:{0}", pWord);
                                    Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                                }
                                else
                                {
                                    //check isrepeated, istoggle
                                    Console.WriteLine(" Object {0} at index: {1} is invalid ", ObjectName.compundC, i);
                                    Console.WriteLine(" -there is no repeated character", pWord);
                                    Console.WriteLine(" -rejected password:{0}", pWord);
                                    Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                                }

                            }
                            else
                            {
                                Console.WriteLine(" Object {0} at index: {1}'s has forbidden character(s)", ObjectName.excessC, i);
                                Console.WriteLine(" -rejected password:{0}", pWord);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                            }
                        }
                        else //object active, failed length
                        {
                            if (i < (augmentedArraySize) / ARR_MULTIPLIER)
                            {
                                Console.WriteLine(" {0} object at index: {1} password is invalid ", ObjectName.pwdClass, i);
                                Console.WriteLine(" -password:{0} doesn't meet length requirement", pWord);
                                Console.WriteLine(" -required length = {0}, password length = {1}", obj[i].GetPasswordLength(), pWord.Length);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");

                            }
                            else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize - ARR_SIZE))
                            {
                                Console.WriteLine(" {0} object at index: {1} is invalid ", ObjectName.compundC, i);
                                Console.WriteLine(" -password:{0} doesn't meet length requirement", pWord);
                                Console.WriteLine(" -required length = {0}, password length = {1}", obj[i].GetPasswordLength(), pWord.Length);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                            }
                            else
                            {
                                Console.WriteLine(" {0} object at index: {1} is invalid ", ObjectName.excessC, i);
                                Console.WriteLine(" -password:{0} doesn't meet length requirement", pWord);
                                Console.WriteLine(" -required length = {0}, password length = {1}", obj[i].GetPasswordLength(), pWord.Length);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                            }
                        }
                    }
                    else
                    {
                        //object is not active
                        if (i < (augmentedArraySize) / ARR_MULTIPLIER)
                        {
                            Console.WriteLine(" {0} object at index: {1} is not active ", ObjectName.pwdClass, i);
                        }
                        else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize - ARR_SIZE))
                        {
                            Console.WriteLine(" {0} object at index: {1} is not active ", ObjectName.compundC, i);
                        }
                        else
                        {
                            Console.WriteLine(" {0} object at index: {1} is not active", ObjectName.excessC, i);
                        }
                    }
                } 
                else //password is valid
                {

                    if (i < (augmentedArraySize) / ARR_MULTIPLIER)
                    {
                        Console.WriteLine(" {0} object at index: {1} password is valid ", ObjectName.pwdClass, i);
                        Console.WriteLine(" -password:{0} meet requirements", pWord);
                        Console.WriteLine(" -required length = {0}, password length = {1}", obj[i].GetPasswordLength(), pWord.Length);
                        Console.WriteLine(" -contains no forbidden character(s)");
                        Console.WriteLine(" -object is {0}", obj[i].IsObjectActive() ? "active" : "inactive");

                    }
                    else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize - ARR_SIZE))
                    {

                        Console.WriteLine(" {0} object at index: {1} password is valid ", ObjectName.compundC, i);
                        Console.WriteLine(" -password:{0} meet requirements", pWord);
                        Console.WriteLine(" -required length = {0}, password length = {1}", obj[i].GetPasswordLength(), pWord.Length);
                        Console.WriteLine(" -contains no forbidden character(s)");
                        Console.WriteLine(" -contains repeated character(s)");
                        Console.WriteLine(" -object is {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                    }
                    else
                    {
                        Console.WriteLine(" {0} object at index: {1} is invalid ", ObjectName.excessC, i);
                        Console.WriteLine(" -password:{0} doesn't meet length requirement", pWord);
                        Console.WriteLine(" -required length = {0}, password length = {1}", obj[i].GetPasswordLength(), pWord.Length);
                    }

                }
               
            } 
            
            Console.WriteLine(ASTERISK + "END TEST PASSWORD" + ASTERISK);
        }

        public static void TestCheckPassword2(pwdCheck[] obj, Random rand)
        {
            Console.WriteLine(" ");
            Console.WriteLine(ASTERISK + "BEGIN TEST PASSWORD" + ASTERISK);
            int augmentedArraySize = ARR_SIZE * ARR_MULTIPLIER;
            for (int i = 0; i < augmentedArraySize; i++)
            {
                string pWord = GenerateRandomMixedString(rand);
                if (obj[i] is excessC)
                {
                    excessC cObj = (excessC)obj[i];
                    bool exStatus = cObj.exActiveStatus;
                    if (exStatus)
                    {
                        if (cObj.ValidatePassword(pWord))
                        {
                            Console.WriteLine(" {0} object at index: {1} is valid ", ObjectName.excessC, i);
                            Console.WriteLine(" -password:{0} has an integer at location {1}, " +
                                "has mixed case and has $", pWord, cObj.GetPasswordLength());
                            Console.WriteLine(" -object status: {0}", exStatus ? "active" : "inactive");
                            continue;
                        }
                        else
                        {
                            if (pWord.Length >= cObj.GetPasswordLength())
                            {
                                //check is integer
                                if (cObj.GetIsInteger())
                                {
                                    //check is MixedCase
                                    if (cObj.GetIsMixedCase())
                                    {
                                        Console.WriteLine(" {0} object at index: {1} is invalid ", ObjectName.excessC, i);
                                        Console.WriteLine(" -password:{0} doesn't contain dollar sign symbol", pWord);
                                        Console.WriteLine(" -object status: {0}", exStatus ? "active" : "inactive");
                                        continue;
                                    }
                                    else
                                    {
                                        Console.WriteLine(" {0} object at index: {1} is invalid ", ObjectName.excessC, i);
                                        Console.WriteLine(" -password:{0} doesn't contain mixed case", pWord);
                                        Console.WriteLine(" -object status: {0}", exStatus ? "active" : "inactive");
                                        continue;
                                    }
                                }
                                else
                                {
                                    Console.WriteLine(" {0} object at index: {1} is invalid ", ObjectName.excessC, i);
                                    Console.WriteLine(" -password:{0} doesn't contain an integer at location {1}",pWord, cObj.GetPasswordLength());
                                    Console.WriteLine(" -object status: {0}", exStatus ? "active" : "inactive");
                                    continue;
                                }
                            }
                            else
                            {
                                Console.WriteLine(" {0} object at index: {1} is invalid ", ObjectName.excessC, i);
                                Console.WriteLine(" -password:{0} doesn't meet length requirement", pWord);
                                Console.WriteLine(" -required length = {0}, password length = {1}", cObj.GetPasswordLength(), pWord.Length);
                                Console.WriteLine(" -object status: {0}", exStatus ? "active" : "inactive");
                                continue;
                            }
                        }
                    }
                }


                if (!obj[i].ValidatePassword(pWord)) //password is false
                {

                    if (obj[i] is compundC)
                    {
                        compundC cObj = (compundC)obj[i];
                        if (cObj.GetLockedStatus())
                        {
                            Console.WriteLine(" Object {0} at index: {1} is LOCKED ", ObjectName.compundC, i);
                            continue;
                        }
                       
                    }
                   
                    if (obj[i].IsObjectActive())
                    {
                        if (pWord.Length >= obj[i].GetPasswordLength()) //Has forbidden characters
                        {

                            if (i < (augmentedArraySize) / ARR_MULTIPLIER)
                            {
                                Console.WriteLine(" Object {0} at index: {1}'s has forbidden character(s) ", ObjectName.pwdClass, i);
                                Console.WriteLine(" -rejected password:{0}", pWord);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                            }
                            else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize - ARR_SIZE))
                            {

                                if (obj[i].GetIsCharForbidden())
                                {
                                    Console.WriteLine(" Object {0} at index: {1}'s has forbidden character(s) ", ObjectName.compundC, i);
                                    Console.WriteLine(" -rejected password:{0}", pWord);
                                    Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                                }
                                else
                                {
                                    //check isrepeated, istoggle
                                    Console.WriteLine(" Object {0} at index: {1} is invalid ", ObjectName.compundC, i);
                                    Console.WriteLine(" -there is no repeated character", pWord);
                                    Console.WriteLine(" -rejected password:{0}", pWord);
                                    Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                                }

                            }
                            else
                            {
                                Console.WriteLine(" Object {0} at index: {1}'s has forbidden character(s)", ObjectName.excessC, i);
                                Console.WriteLine(" -rejected password:{0}", pWord);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                            }
                        }
                        else //object active, failed length
                        {
                            if (i < (augmentedArraySize) / ARR_MULTIPLIER)
                            {
                                Console.WriteLine(" {0} object at index: {1} password is invalid ", ObjectName.pwdClass, i);
                                Console.WriteLine(" -password:{0} doesn't meet length requirement", pWord);
                                Console.WriteLine(" -required length = {0}, password length = {1}", obj[i].GetPasswordLength(), pWord.Length);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");

                            }
                            else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize - ARR_SIZE))
                            {
                                Console.WriteLine(" {0} object at index: {1} is invalid ", ObjectName.compundC, i);
                                Console.WriteLine(" -password:{0} doesn't meet length requirement", pWord);
                                Console.WriteLine(" -required length = {0}, password length = {1}", obj[i].GetPasswordLength(), pWord.Length);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                            }
                            else
                            {

                                Console.WriteLine(" {0} object at index: {1} is invalid ", ObjectName.excessC, i);
                                Console.WriteLine(" -password:{0} doesn't meet length requirement", pWord);
                                Console.WriteLine(" -required length = {0}, password length = {1}", obj[i].GetPasswordLength(), pWord.Length);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                            }
                        }
                    }
                    else
                    {
                        //object is not active
                        if (i < (augmentedArraySize) / ARR_MULTIPLIER)
                        {
                            Console.WriteLine(" {0} object at index: {1} is not active ", ObjectName.pwdClass, i);
                        }
                        else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize - ARR_SIZE))
                        {
                            Console.WriteLine(" {0} object at index: {1} is not active ", ObjectName.compundC, i);
                        }
                        else
                        {
                            Console.WriteLine(" {0} object at index: {1} is not active", ObjectName.excessC, i);
                        }
                    }
                }
                else //password is valid
                {

                    if (i < (augmentedArraySize) / ARR_MULTIPLIER)
                    {
                        Console.WriteLine(" {0} object at index: {1} password is valid ", ObjectName.pwdClass, i);
                        Console.WriteLine(" -password:{0} meet requirements", pWord);
                        Console.WriteLine(" -required length = {0}, password length = {1}", obj[i].GetPasswordLength(), pWord.Length);
                        Console.WriteLine(" -contains no forbidden character(s)");
                        Console.WriteLine(" -object is {0}", obj[i].IsObjectActive() ? "active" : "inactive");

                    }
                    else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize - ARR_SIZE))
                    {

                        Console.WriteLine(" {0} object at index: {1} password is valid ", ObjectName.compundC, i);
                        Console.WriteLine(" -password:{0} meet requirements", pWord);
                        Console.WriteLine(" -required length = {0}, password length = {1}", obj[i].GetPasswordLength(), pWord.Length);
                        Console.WriteLine(" -contains no forbidden character(s)");
                        Console.WriteLine(" -contains repeated character(s)");
                        Console.WriteLine(" -object is {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                    }
                    else
                    {
                        Console.WriteLine(" {0} object at index: {1} is invalid ", ObjectName.excessC, i);
                        Console.WriteLine(" -password:{0} doesn't meet length requirement", pWord);
                        Console.WriteLine(" -required length = {0}, password length = {1}", obj[i].GetPasswordLength(), pWord.Length);
                    }

                }

            }

            Console.WriteLine(ASTERISK + "END TEST PASSWORD" + ASTERISK);
        }

        public static void TestForbiddenCharactersInPassword(pwdCheck[] obj, Random rand)
        {
            Console.WriteLine(" ");
            Console.WriteLine(ASTERISK + "BEGIN TEST FORBIDDEN CHARACTERS" + ASTERISK);
            int augmentedArraySize = ARR_SIZE * ARR_MULTIPLIER;
            for (int i = 0; i < augmentedArraySize; i++)
            {
                int pwdLength = obj[i].GetPasswordLength();
                string pWord = GenRandStrWithPredefinedLen(rand, pwdLength);
                if (!obj[i].ValidatePassword(pWord))
                {
                    if (obj[i].IsObjectActive())
                    {
                        if (pWord.Length >= obj[i].GetPasswordLength())
                        {

                            if (i < (augmentedArraySize) / ARR_MULTIPLIER)
                            {
                                Console.WriteLine(" Object {0} at index: {1}'s has forbidden character(s) ", ObjectName.pwdClass, i);
                                Console.WriteLine(" -rejected password: {0}", pWord);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                            }
                            else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize - ARR_SIZE))
                            {
                                Console.WriteLine(" Object {0} at index: {1}'s has forbidden character(s) ", ObjectName.compundC, i);
                                Console.WriteLine(" -rejected password: {0}", pWord);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                            }
                            else
                            {
                                if (obj[i] is excessC)
                                {
                                    excessC  c = (excessC)obj[i];
                                    Console.WriteLine(" Object {0} at index: {1}'s has forbidden character(s)", ObjectName.excessC, i);
                                    Console.WriteLine(" -rejected password: {0}", pWord);
                                    Console.WriteLine(" -object status: {0}", c.GetExObjectStatus() ? "active" : "inactive");
                                }
                            }
                        }
                    }
                }
            }
            Console.WriteLine(ASTERISK + "END TEST FORBIDDEN CHARACTERS" + ASTERISK);
         
        }

        public static void TestToggleObject(pwdCheck[] obj, Random rand)
        {
            Console.WriteLine(" ");
            Console.WriteLine(ASTERISK + "BEGIN TEST TOGGLE OBJECTS" + ASTERISK);
            int augmentedArraySize = ARR_SIZE * ARR_MULTIPLIER;
            string pWord;
            for (int i = 0; i < augmentedArraySize; i++)
            {


                if (i < (augmentedArraySize) / ARR_MULTIPLIER)
                {
                    bool pStatus = obj[i].IsObjectActive();
                    int pToggledMax = obj[i].GetPasswordLength();
                    while (pStatus == obj[i].IsObjectActive())
                    {
                        pWord = GenerateRandomValidString(rand);
                        obj[i].ValidatePassword(pWord);
                       
                    }

                    Console.WriteLine(" Object {0} at index {1} was toggled ", ObjectName.pwdClass, i);
                    Console.WriteLine(" -toggled at {0} requests.", pToggledMax);
                    Console.WriteLine(" -updated status: {0}.", (obj[i].IsObjectActive() ? "active" : "inactive"));
                }
                else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize - ARR_SIZE))
                {

                    if (obj[i] is compundC)
                    {
                        compundC cObj = (compundC)obj[i];
                        int countToggle = 0;
                        if (cObj.GetLockedStatus())
                        {
                            Console.WriteLine(" Object {0} at index  {1} have been LOCKED", ObjectName.compundC, i);
                            continue;
                        }
                        else
                        {
                            while (!cObj.GetLockedStatus())
                            {
                                countToggle++;
                                pWord = GenerateRandomValidString(rand);
                                obj[i].ValidatePassword(pWord);
                            }
                            Console.WriteLine(" Object {0} at index {1} is LOCKED", ObjectName.compundC, i);
                            Console.WriteLine(" -locked at {0} toggles", countToggle);
                            continue;
                        }
                    }
                }
                else
                {
                    if (obj[i] is excessC)
                    {
                        excessC cObj = (excessC)obj[i];
                        bool exStatusOn = cObj.GetExObjectStatus();
                        if (exStatusOn)
                        {
                            Console.WriteLine(" Object {0} at index {1} is {2} ", ObjectName.excessC, i,
                                (cObj.GetExObjectStatus() ? "active" : "inactive"));
                            Console.WriteLine(" -by design when object status is {0}", (exStatusOn ? "active" : "inactive"));
                            Console.WriteLine(" -object state can't be toggled");

                        }
                        else
                        {
                            bool exStatusOff = obj[i].IsObjectActive();
                            int cToggledMax = obj[i].GetPasswordLength();
                            while (exStatusOff == obj[i].IsObjectActive())
                            {
                                pWord = GenerateRandomValidString(rand);
                                obj[i].ValidatePassword(pWord);
                                // Console.WriteLine("asd");
                            }

                            Console.WriteLine(" Object {0} at index: {1} was toggled ", ObjectName.excessC, i);
                            Console.WriteLine(" -toggled at {0} requests.", cToggledMax);
                            Console.WriteLine(" -status: {0}.", (exStatusOn ? "active" : "inactive"));
                        }
                    }

                }





                //if (obj[i] is pwdCheck)
                //{
                //    bool pStatus = obj[i].IsObjectActive();
                //    int pToggledMax = obj[i].GetPasswordLength();
                //    while (pStatus == obj[i].IsObjectActive())
                //    {
                //        pWord = GenerateRandomValidString(rand);
                //        obj[i].ValidatePassword(pWord);
                //        Console.WriteLine("infinite loop. Index value: {0}", i);
                //    }

                //    Console.WriteLine(" Object {0} at index: {1} was toggled ", ObjectName.pwdClass, i);
                //    Console.WriteLine(" -toggled at {0} requests.", pToggledMax);
                //    Console.WriteLine(" -updated status: {0}.", (obj[i].IsObjectActive() ? "active" : "inactive"));

                //}


                //if (obj[i] is compundC)
                //{
                //    compundC cObj = (compundC)obj[i];
                //    int countToggle = 0;
                //    if (cObj.GetLockedStatus())
                //    {
                //        Console.WriteLine(" Object {0} at index: {1} have been LOCKED", ObjectName.compundC, i);
                //        continue;
                //    }
                //    else
                //    {
                //        while (!cObj.GetLockedStatus())
                //        {
                //            countToggle++;
                //            pWord = GenerateRandomValidString(rand);
                //            obj[i].ValidatePassword(pWord);
                //        }
                //        Console.WriteLine(" Object {0} at index: {1} is LOCKED", ObjectName.compundC, i);
                //        Console.WriteLine(" -locked at {0} toggles", countToggle);
                //        continue;
                //    }
                //}

                //if (obj[i] is excessC)
                //{
                //    excessC cObj = (excessC)obj[i];
                //   bool exStatusOn = cObj.GetExObjectStatus();
                //    if (exStatusOn)
                //    {
                //        Console.WriteLine(" Object {0} at index: {1} state is: {2} ", ObjectName.excessC, i, 
                //            (cObj.GetExObjectStatus() ? "active" : "inactive"));
                //        Console.WriteLine(" -by design when object status is: {0}", (exStatusOn ? "active" : "inactive"));
                //        Console.WriteLine(" -object state can't be toggled");

                //    }
                //    else
                //    {
                //        bool exStatusOff = obj[i].IsObjectActive();
                //        int cToggledMax = obj[i].GetPasswordLength();
                //        while (exStatusOff == obj[i].IsObjectActive())
                //        {
                //            pWord = GenerateRandomValidString(rand);
                //            obj[i].ValidatePassword(pWord);
                //            // Console.WriteLine("asd");
                //        }

                //        Console.WriteLine(" Object {0} at index: {1} was toggled ", ObjectName.excessC, i);
                //        Console.WriteLine(" -toggled at {0} requests.", cToggledMax);
                //        Console.WriteLine(" -updated status: {0}.", (exStatusOn ? "active" : "inactive"));
                //    }
                //}

              

                //bool currentStatus = obj[i].IsObjectActive();
                //int toggleReached = obj[i].GetPasswordLength();
                //while (currentStatus == obj[i].IsObjectActive())
                //{
                //    pWord = GenerateRandomValidString(rand);
                //    obj[i].ValidatePassword(pWord);
                //    Console.WriteLine("infinite loop. Index value: {0}",i);
                //}
              
                //if (i < (augmentedArraySize) / ARR_MULTIPLIER)
                //{
                //    Console.WriteLine(" Object {0} at index: {1} was toggled ", ObjectName.pwdClass, i);
                //    Console.WriteLine(" -toggled at {0} requests.", toggleReached);
                //    Console.WriteLine(" -updated status: {0}.", (obj[i].IsObjectActive() ? "active" : "inactive"));
                //}
                //else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize - ARR_SIZE))
                //{
                
                //    Console.WriteLine(" Object {0} at index: {1} was toggled ", ObjectName.compundC, i);
                //    Console.WriteLine(" -toggled at {0} requests.", toggleReached);
                //    Console.WriteLine(" -updated status: {0}.", (obj[i].IsObjectActive() ? "active" : "inactive"));
                //}
                //else
                //{
                //    Console.WriteLine(" Object {0} at index: {1} was toggled ", ObjectName.excessC, i);
                //    Console.WriteLine(" -toggled at {0} requests.", toggleReached);
                //    Console.WriteLine(" -updated status: {0}.", (exStatus ? "active" : "inactive"));
                //}
            }

            Console.WriteLine(ASTERISK + "END TEST TOGGLE OBJECTS" + ASTERISK);
        }

        public static void TestPwdClassWithInValidPassword(pwdCheck[] obj, Random rand)
        {
            Console.WriteLine(" ");
            Console.WriteLine("Begin test PwdCheck class with invalid password.");
            for (int i = 0; i < ARR_SIZE; i++)
            {
                string pWord = GenerateRandomInValidString(rand);
                if (!obj[i].ValidatePassword(pWord))
                {
                    if (obj[i].IsObjectActive())
                    {
                        if (pWord.Length >= obj[i].GetPasswordLength())
                        {
                            Console.WriteLine(" Object at index {0}'s password is invalid", i);
                            Console.WriteLine("  password contains invalid character(s): {0}", pWord);
                        }
                        
                    }
                }
            }
            Console.WriteLine("End test PwdCheck class with invalid password.");
        }

        public static void TestPasswordLength(pwdCheck[] obj, Random rand)
        {
            Console.WriteLine(" ");
            Console.WriteLine(ASTERISK + "BEGIN TEST PASSWORD LENGTH" + ASTERISK);

            int augmentedArraySize = ARR_SIZE * ARR_MULTIPLIER;
            for (int i = 0; i < augmentedArraySize; i++)
            {
                int pwdLength = obj[i].GetPasswordLength();
                string str = GenRandStrWithPredefinedLen(rand, pwdLength - REDUCED_LENGTH);

                if (!obj[i].ValidatePassword(str))
                {
                    if (obj[i].IsObjectActive())
                    {
                        if (str.Length < pwdLength)
                        {
                            if (i < (augmentedArraySize) / ARR_MULTIPLIER)
                            {
                                Console.WriteLine(" {0} object at index: {1} password is invalid ", ObjectName.pwdClass, i);
                                Console.WriteLine(" -password:{0} doesn't meet length requirement", str);
                                Console.WriteLine(" -required length = {0}, password length = {1}", pwdLength, str.Length);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");

                            }
                            else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize - ARR_SIZE))
                            {
                                Console.WriteLine(" {0} object at index: {1} is invalid ", ObjectName.compundC, i);
                                Console.WriteLine(" -password:{0} doesn't meet length requirement", str);
                                Console.WriteLine(" -required length = {0}, password length = {1}", pwdLength, str.Length);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                            }
                            else
                            {
                                excessC c;
                                if (obj[i] is excessC)
                                {
                                    c = (excessC)obj[i];
                                    Console.WriteLine(" {0} object at index: {1} is invalid ", ObjectName.excessC, i);
                                    Console.WriteLine(" -password:{0} doesn't meet length requirement", str);
                                    Console.WriteLine(" -required length = {0}, password length = {1}", pwdLength, str.Length);
                                    Console.WriteLine(" -object status: {0}", c.GetExObjectStatus() ? "active" : "inactive");
                                }
                                //Console.WriteLine(" {0} object at index: {1} is invalid ", ObjectName.excessC, i);
                                //Console.WriteLine(" -password:{0} doesn't meet length requirement", str);
                                //Console.WriteLine(" -required length = {0}, password length = {1}", pwdLength, str.Length);
                                //Console.WriteLine(" -object status: {0}", c.GetExObjectStatus() ? "active" : "inactive");
                            }
                        }
                    }
                }
            }
            Console.WriteLine(ASTERISK + "END TEST PASSWORD LENGTH" + ASTERISK);
        }
    }
}
