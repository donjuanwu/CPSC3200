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
   This driver will sequentially perform the following test cases:
   1) InitPwdObject(rand)
      - Create a heterogenous array and initialized pwdCheck, compundC and excessC objects
      - Return the heterogenous arary back to the calling function
   2) TestPasswordLength(arrPwdObj, rand)
      - Specific test to see if password meet the minimum password length defined during 
        firing each object constructor
   3) TestPwdClassWithInValidPassword(arrPwdObj, rand)
      - Specific test to see if password has invalid characters. These invalid characters
        were initialized during firing constructor of the pwdCheck 
   4) TestCheckPassword(arrPwdObj, rand)
      - General password test to determine if password meet each class specific password conditions
   5) TestForbiddenCharsInPwd(arrPwdObj, rand, NON_ASCII)
      - Update the initialized forbidden characters during firing pwdCheck constructor with new 
        NON ASCII characters
      - Determine if password contains any of these forbidden characters
   6) TestToggleObject(arrPwdObj,rand)
      - Toggle the state of each initialized object in the heterogenous array.

---------------------------------------------------------------------------------
Design Decisions and Assumptions:
- All objects initialized with password length greater than 0
- Password length is randomly generated using RAND_MIN & RAND_MAX values
- Password is randomly generated from a predefined string using random generator
- Objects are added to heterogenous array in group of 1/3. 
  First third is reserved for pwdCheck object
  Second third is reserved for compundC object
  Third third is reserved for excessC object
- Down cast was used when need access to compundC and excessC object's public functions
- Every invalid password validation will be displayed with failed reasons
- This design applies to compundC
  Each toggle = K cycle * 2
  Max validation = password length * K cycle * 2
- Initialization of excessC object status is inactive.


DATA MEMBERS DICTIONARY:
 enum ObjectName                       -- Use to display objet name
        {
            pwdClass = 0,
            compundC = 1,
            excessC = 2
        };
        const int RAND_MIN = 2          -- Minimum random value   
        const int RAND_MAX = 20;        -- Maximum random value
        const int ARR_SIZE = 3;         -- Default array size
        const int ARR_MULTIPLIER = 3;   -- Multiplier to increase array size
        const int REDUCED_LENGTH = 1;   -- Decrement value
        const string ASTERISK = "***************";  -- Prefix and suffix to aling caption
        const string VALID_CHARS ="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijkl" +
            "mnopqrstuvwxyz0123456789#_<>!+*&@^=.?|\\";
        const string INVALID_CHARS = " ~(){}[]Æ»ØøÅåß¶";   -- Mixed invalid character
        const int ONECYLE = 2;                             -- indicate one cycle
        const string NON_ASCII = "ÆæØøÅåß¶";               -- NON-ASCII characters



----------------------------------------------------------------------------------
-- WHEN     WHO		WHAT
   4/22/19	DD  	Created p3.cs   
   4/23/19  DD      Test InitPassword()
                    Test PasswordLength()
                    Test ValidPassword()
                    Test InValidPassword()
   4/26/19 DD       Test excessC.cs
   4/29/19 DD       Added comments
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
        const int ARR_SIZE = 3;
        const int ARR_MULTIPLIER = 3;
        const int REDUCED_LENGTH = 1;
        const string ASTERISK = "***************";
        const string VALID_CHARS ="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijkl" +
            "mnopqrstuvwxyz0123456789#_<>!+*&@^=.?|\\";
        const string INVALID_CHARS = " ~(){}[]Æ»ØøÅåß¶";
        const int ONECYLE = 2;
        const string NON_ASCII = "ÆæØøÅåß¶";
     

    static void Main(string[] args)
        {
            Random rand = new Random();
            ProgramIntro();

            pwdCheck[] arrPwdObj = InitPwdObject(rand);
            TestPasswordLength(arrPwdObj, rand);
            TestPwdClassWithInValidPassword(arrPwdObj, rand);
            TestCheckPassword(arrPwdObj, rand);
            TestForbiddenCharsInPwd(arrPwdObj, rand, NON_ASCII);
            TestToggleObject(arrPwdObj,rand);
       
            Console.WriteLine("");
            Console.WriteLine("Press any key to terminate...");
            Console.ReadKey();
        }

        //Display Project 3 descriptions
        //PRE : N/A
        //POST: N/A
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


        // Create and initialize a heterogenous array with pwdCheck, compundC and excessC
        // Return heterogenous array back to calling function
        // PRE : a random object is already created
        //       a pwdCheck[] variable is declared
        // POST: state of pwdCheck obj, compundC object and excessC are initialized and set
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
                    bool objStatus = false;
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

        // Return a random string that contains both valid and invalid strings
        //PRE : A random already declare and initialized
        //POST: N/A
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

        // Return a random string of both valid and invalid strings with a predefined length
        //PRE : A random already declare and initialized
        //POST: N/A
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


        //Passed a new random generated password for every object in the heterogenous array
        //Display if the password is valid.
        //If the password is not valid then state the reason why it failed.
        //PRE : pwdCheck, compundC and excessC are already initialized
        //      All data members are initialized
        //POST: pwdCheck, compundC and excessC objects may changed state
        public static void TestCheckPassword(pwdCheck[] obj, Random rand)
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
                            Console.WriteLine(" {0} object at index {1} is valid ", ObjectName.excessC, i);
                            Console.WriteLine(" -password '{0}' has an integer at location {1}, " +
                                "has mixed case and has $", pWord, cObj.GetPasswordLength());
                            Console.WriteLine(" -object status: {0}", exStatus ? "active" : "inactive");
                            continue;
                        }
                        else
                        {
                            if (pWord.Length >= cObj.GetPasswordLength())
                            {
                                if (cObj.GetIsInteger())
                                {
                                    if (cObj.GetIsMixedCase())
                                    {
                                        Console.WriteLine(" {0} object at index {1} is invalid ", ObjectName.excessC, i);
                                        Console.WriteLine(" -password '{0}' doesn't contain dollar sign symbol", pWord);
                                        Console.WriteLine(" -object status: {0}", exStatus ? "active" : "inactive");
                                        continue;
                                    }
                                    else
                                    {
                                        Console.WriteLine(" {0} object at index {1} is invalid ", ObjectName.excessC, i);
                                        Console.WriteLine(" -password '{0}' doesn't contain mixed case", pWord);
                                        Console.WriteLine(" -object status: {0}", exStatus ? "active" : "inactive");
                                        continue;
                                    }
                                }
                                else
                                {
                                    Console.WriteLine(" {0} object at index {1} is invalid ", ObjectName.excessC, i);
                                    Console.WriteLine(" -password '{0}' doesn't contain an integer at location {1}",pWord, cObj.GetPasswordLength());
                                    Console.WriteLine(" -object status: {0}", exStatus ? "active" : "inactive");
                                    continue;
                                }
                            }
                            else
                            {
                                Console.WriteLine(" {0} object at index {1} is invalid ", ObjectName.excessC, i);
                                Console.WriteLine(" -password '{0}' doesn't meet length requirement", pWord);
                                Console.WriteLine(" -required length = {0}, password length = {1}", cObj.GetPasswordLength(), pWord.Length);
                                Console.WriteLine(" -object status: {0}", exStatus ? "active" : "inactive");
                                continue;
                            }
                        }
                    }
                }


                if (!obj[i].ValidatePassword(pWord))
                {
                    if (obj[i] is compundC)
                    {
                        compundC cObj = (compundC)obj[i];
                        if (cObj.GetLockedStatus())
                        {
                            Console.WriteLine(" Object {0} at index {1} is LOCKED ", ObjectName.compundC, i);
                            continue;
                        }
                    }
                   
                    if (obj[i].IsObjectActive())
                    {
                        if (pWord.Length >= obj[i].GetPasswordLength()) 
                        {
                            if (i < (augmentedArraySize) / ARR_MULTIPLIER)
                            {
                                Console.WriteLine(" Object {0} at index {1}'s has forbidden character(s) ", ObjectName.pwdClass, i);
                                Console.WriteLine(" -rejected password '{0}'", pWord);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                            }
                            else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize - ARR_SIZE))
                            {

                                if (obj[i].GetIsCharForbidden())
                                {
                                    Console.WriteLine(" Object {0} at index {1}'s has forbidden character(s) ", ObjectName.compundC, i);
                                    Console.WriteLine(" -rejected password '{0}'", pWord);
                                    Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                                }
                                else
                                {
                                    Console.WriteLine(" Object {0} at index {1} is invalid ", ObjectName.compundC, i);
                                    Console.WriteLine(" -there is no repeated character", pWord);
                                    Console.WriteLine(" -rejected password '{0}'", pWord);
                                    Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                                }
                            }
                            else
                            {
                                Console.WriteLine(" Object {0} at index {1}'s has forbidden character(s)", ObjectName.excessC, i);
                                Console.WriteLine(" -rejected password '{0}'", pWord);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                            }
                        }
                        else 
                        {
                            if (i < (augmentedArraySize) / ARR_MULTIPLIER)
                            {
                                Console.WriteLine(" {0} object at index {1} password is invalid ", ObjectName.pwdClass, i);
                                Console.WriteLine(" -password '{0}' doesn't meet length requirement", pWord);
                                Console.WriteLine(" -required length = {0}, password length = {1}", obj[i].GetPasswordLength(), pWord.Length);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                            }
                            else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize - ARR_SIZE))
                            {
                                Console.WriteLine(" {0} object at index {1} is invalid ", ObjectName.compundC, i);
                                Console.WriteLine(" -password '{0}' doesn't meet length requirement", pWord);
                                Console.WriteLine(" -required length = {0}, password length = {1}", obj[i].GetPasswordLength(), pWord.Length);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                            }
                            else
                            {
                                Console.WriteLine(" {0} object at index {1} is invalid ", ObjectName.excessC, i);
                                Console.WriteLine(" -password '{0}' doesn't meet length requirement", pWord);
                                Console.WriteLine(" -required length = {0}, password length = {1}", obj[i].GetPasswordLength(), pWord.Length);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                            }
                        }
                    }
                    else
                    {
                        if (i < (augmentedArraySize) / ARR_MULTIPLIER)
                        {
                            Console.WriteLine(" {0} object at index {1} is not active ", ObjectName.pwdClass, i);
                        }
                        else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize - ARR_SIZE))
                        {
                            Console.WriteLine(" {0} object at index {1} is not active ", ObjectName.compundC, i);
                        }
                        else
                        {
                            Console.WriteLine(" {0} object at index {1} is not active", ObjectName.excessC, i);
                        }
                    }
                }
                else 
                {
                    if (i < (augmentedArraySize) / ARR_MULTIPLIER)
                    {
                        Console.WriteLine(" {0} object at index {1} password is valid ", ObjectName.pwdClass, i);
                        Console.WriteLine(" -password '{0}' meet requirements", pWord);
                        Console.WriteLine(" -required length = {0}, password length = {1}", obj[i].GetPasswordLength(), pWord.Length);
                        Console.WriteLine(" -contains no forbidden character(s)");
                        Console.WriteLine(" -object is {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                    }
                    else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize - ARR_SIZE))
                    {

                        Console.WriteLine(" {0} object at index {1} password is valid ", ObjectName.compundC, i);
                        Console.WriteLine(" -password '{0}' meet requirements", pWord);
                        Console.WriteLine(" -required length = {0}, password length = {1}", obj[i].GetPasswordLength(), pWord.Length);
                        Console.WriteLine(" -contains no forbidden character(s)");
                        Console.WriteLine(" -contains repeated character(s)");
                        Console.WriteLine(" -object is {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                    }
                    else
                    {
                        Console.WriteLine(" {0} object at index {1} is invalid ", ObjectName.excessC, i);
                        Console.WriteLine(" -password '{0}' doesn't meet length requirement", pWord);
                        Console.WriteLine(" -required length = {0}, password length = {1}", obj[i].GetPasswordLength(), pWord.Length);
                    }
                }
            }
            Console.WriteLine(ASTERISK + "END TEST PASSWORD" + ASTERISK);
        }


        //Passed a new random generated password for every object in the heterogenous array
        //Update the forbidden characters in the pwdClass.
        //Expected to see password failed validation
        //Display the failed validation reason
        //PRE : pwdCheck, compundC and excessC are already initialized
        //      All data members are initialized
        //POST: pwdCheck, compundC and excessC objects may changed state
        public static void TestForbiddenCharsInPwd(pwdCheck[] obj, Random rand, string strForbidden)
        {
            char[] cForbidden = strForbidden.ToCharArray();
            Console.WriteLine(" ");
            Console.WriteLine(ASTERISK + "BEGIN TEST PASSWORD WITH UPDATED FORBIDDEN CHARACTERS" + ASTERISK);
            Console.WriteLine("Non ASCII forbidden characters = {0}", strForbidden );

            int augmentedArraySize = ARR_SIZE * ARR_MULTIPLIER;
            for (int i = 0; i < augmentedArraySize; i++)
            {
                int pwdLength = obj[i].GetPasswordLength();
                string pWord = GenRandStrWithPredefinedLen(rand, pwdLength);
                obj[i].SetForbiddenCharacters(cForbidden);
                if (!obj[i].ValidatePassword(pWord))
                {
                    if (obj[i].IsObjectActive())
                    {
                        if (pWord.Length >= obj[i].GetPasswordLength())
                        {

                            if (i < (augmentedArraySize) / ARR_MULTIPLIER)
                            {
                                Console.WriteLine(" {0} object at index {1} has forbidden character(s) ", ObjectName.pwdClass, i);
                                Console.WriteLine(" -rejected password '{0}'", pWord);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                            }
                            else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize - ARR_SIZE))
                            {
                                Console.WriteLine(" {0} object at index {1} has forbidden character(s) ", ObjectName.compundC, i);
                                Console.WriteLine(" -rejected password '{0}'", pWord);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                            }
                            else
                            {
                                if (obj[i] is excessC)
                                {
                                    excessC  c = (excessC)obj[i];
                                    Console.WriteLine(" {0} object at index {1} has forbidden character(s)", ObjectName.excessC, i);
                                    Console.WriteLine(" -rejected password '{0}'", pWord);
                                    Console.WriteLine(" -object status: {0}", c.GetExObjectStatus() ? "active" : "inactive");
                                }
                            }
                        }
                    }
                }
            }
            Console.WriteLine(ASTERISK + "END TEST PASSWORD WITH UPDATED FORBIDDEN CHARACTERS" + ASTERISK);
         
        }



        //Toggled compundC state until it's LOCKED
        //Toggled pwdCheck and execessC objects
        //PRE : pwdCheck, compundC and excessC are already initialized
        //      All data members are initialized
        //      Some of the object may have already changed state
        //      compundC may already been LOCKED
        //POST: pwdCheck will changed state
        //      compundC state will be changed to LOCKed if it hasn't already
        //      excessC will be toggled if it's state is 'OFF'
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
                        pWord = GenerateRandomMixedString(rand);
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
                                pWord = GenerateRandomMixedString(rand);
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
                                pWord = GenerateRandomMixedString(rand);
                                obj[i].ValidatePassword(pWord);
                            }
                            Console.WriteLine(" Object {0} at index: {1} was toggled ", ObjectName.excessC, i);
                            Console.WriteLine(" -toggled at {0} requests.", cToggledMax);
                            Console.WriteLine(" -status: {0}.", (exStatusOn ? "active" : "inactive"));
                        }
                    }

                }
            }

            Console.WriteLine(ASTERISK + "END TEST TOGGLE OBJECTS" + ASTERISK);
        }

        //Check for invalid characters in password. The invalid characters were initialized
        //during firing of the pwdCheck constructors.
        //PRE : pwdCheck, compundC and excessC objects already initialized with default value
        //POST: pwdCheck, compundC and excessC objects may change state
        public static void TestPwdClassWithInValidPassword(pwdCheck[] obj, Random rand)
        {
            Console.WriteLine(" ");
            Console.WriteLine(ASTERISK + "BEGIN DETECT INVALID CHARACTERS IN PASSWORD" + ASTERISK);
            for (int i = 0; i < ARR_SIZE; i++)
            {
                string pWord = GenerateRandomMixedString(rand);
                if (!obj[i].ValidatePassword(pWord))
                {
                    if (obj[i].IsObjectActive())
                    {
                        if (pWord.Length >= obj[i].GetPasswordLength())
                        {
                            Console.WriteLine(" Object at index {0} password is invalid", i);
                            Console.WriteLine("  password '{0}' contains invalid character(s)", pWord);
                        }
                    }
                }
            }
            Console.WriteLine(ASTERISK + "END DETECT INVALID CHARACTERS IN PASSWORD" + ASTERISK);
        }

        //Determine if random generated password meet minimum password length defined during
        //firing constructor of each object in the heterogenous array
        //PRE : pwdCheck, compundC and excessC objects already initialized with default value
        //POST: pwdCheck, compundC and excessC objects may change state
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
                                Console.WriteLine(" -password '{0}' doesn't meet length requirement", str);
                                Console.WriteLine(" -required length = {0}, password length = {1}", pwdLength, str.Length);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");

                            }
                            else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize - ARR_SIZE))
                            {
                                Console.WriteLine(" {0} object at index: {1} is invalid ", ObjectName.compundC, i);
                                Console.WriteLine(" -password '{0}' doesn't meet length requirement", str);
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
                                    Console.WriteLine(" -password '{0}' doesn't meet length requirement", str);
                                    Console.WriteLine(" -required length = {0}, password length = {1}", pwdLength, str.Length);
                                    Console.WriteLine(" -object status: {0}", c.GetExObjectStatus() ? "active" : "inactive");
                                }
                              
                            }
                        }
                    }
                }
            }
            Console.WriteLine(ASTERISK + "END TEST PASSWORD LENGTH" + ASTERISK);
        }
    }
}
