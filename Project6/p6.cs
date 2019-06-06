/*
-- Developer    : Don Dang
-- Project      : Project 6
-- Instructor   : Dr. Dingle
-- File Name    : p6.cs
-- File Version : 1.0
-- Due Date	    : 6/7/2019
-- Course Name  : CPSC 3200
----------------------------------------------------------------------------
OVERVIEW: 
   This driver will sequentially perform the following test cases:
   1) InitPwdObject(rand)
      - Create a heterogenous array and initialized PwdCheck, CompundC and ExcessC objects
      - Return the heterogenous arary back to the calling function
   2) TestPasswordLength(arrPwdObj, rand)
      - Specific test to see if password meet the minimum password length defined during 
        firing each object constructor
   3) TestPwdClassWithInValidPassword(arrPwdObj, rand)
      - Specific test to see if password has invalid characters. These invalid characters
        were initialized during firing constructor of the PwdCheck 
   4) TestCheckPassword(arrPwdObj, rand)
      - General password test to determine if password meet each class specific password conditions
   5) TestForbiddenCharsInPwd(arrPwdObj, rand, NON_ASCII)
      - Update the initialized forbidden characters during firing PwdCheck constructor with new 
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
  First third is reserved for PwdCheck object
  Second third is reserved for CompundC object
  Third third is reserved for ExcessC object
- Down cast was used when need access to CompundC and ExcessC object's public functions
- Every invalid password validation will be displayed with failed reasons
- This design applies to CompundC
  Each toggle = K cycle * 2
  Max validation = password length * K cycle * 2
- Initialization of ExcessC object status is inactive.


DATA MEMBERS DICTIONARY:
 enum ObjectName                       -- Use to display objet name
        {
            pwdClass = 0,
            CompundC = 1,
            ExcessC = 2
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
    WHEN     WHO		WHAT
    5/29/19  DD         Copied p3.cs from project3 to p6.cs  
*/


using System;


namespace Project6
{
    class P6
    {
        enum ObjectName
        {
            PwdClass = 0,
            CompundC = 1,
            ExcessC = 2,
            FLIP = 3,
            FlipPwdCheck = 4
        };
        const int RAND_MIN = 10;
        const int RAND_MAX = 20;
        const int ARR_SIZE = 4;
        const int ARR_MULTIPLIER = 3;
        const int REDUCED_LENGTH = 1;
        const string ASTERISK = "***************";
        const string VALID_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijkl" +
            "mnopqrstuvwxyz0123456789#_<>!+*&@^=.?|\\";
        const string INVALID_CHARS = " ~(){}[]Æ»ØøÅåß¶";
        const int ONECYLE = 2;
        const string NON_ASCII = "ÆæØøÅåß¶";
        const int INDEX_ZERO = 0;
        const int INDEX_ONE = 1;
        const int INDEX_TWO = 2;


        static void Main(string[] args)
        {
            Random rand = new Random();
            ProgramIntro();

            PwdCheck[] arrPwdObj = InitPwdHeterogeneousObjects(rand);
            Flip[] arrFlipObj = InitFlipHeterogeneousObjects(rand, arrPwdObj);


           // IPwdCheck[] arrPwdObj = InitIPwdHeterogeneousObjects(rand);
            //TestPasswordLength(arrPwdObj, rand);
            //TestPwdClassWithInValidPassword(arrPwdObj, rand);
            //TestCheckPassword(arrPwdObj, rand);
            //TestForbiddenCharsInPwd(arrPwdObj, rand, NON_ASCII);
            //TestToggleObject(arrPwdObj, rand);

            Console.WriteLine("");
            Console.WriteLine("Press any key to terminate...");
            Console.ReadKey();
        }

        //Display Project 3 descriptions
        //PRE : N/A
        //POST: N/A
        public static void ProgramIntro()
        {
            Console.WriteLine("P3's goal is to design C# 'PwdCheck' classess");
            Console.WriteLine("that share a common interface but vary output");
            Console.WriteLine("and state transitions.  ");
            Console.WriteLine("");
            Console.WriteLine("Part I: Class Design");
            Console.WriteLine("Design a class hierarchy of PwdChecks, where");
            Console.WriteLine("each PwdCheck object accepts or rejects offered");
            Console.WriteLine("passwords.");
            Console.WriteLine("If 'on', an PwdCheck object accepts a password");
            Console.WriteLine("of length at least p (where p is a stable value");
            Console.WriteLine("that varies from object to object) UNLESS the");
            Console.WriteLine("password contains a forbidden symbol (a small");
            Console.WriteLine("internal set of characters); its on/off state");
            Console.WriteLine("is toggled with every 'pth' request.");
            Console.WriteLine("");
            Console.WriteLine("If 'off', an ExcessC acts exactly like a PwdCheck;");
            Console.WriteLine("otherwise, it requires that the pth character be");
            Console.WriteLine("a digit, that case is mixed and that '$' appears");
            Console.WriteLine("in the password. A CompundC acts like a PwdCheck,");
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


        // Create and initialize a heterogenous array with PwdCheck, CompundC and ExcessC
        // Return heterogenous array back to calling function
        // PRE : a random object is already created
        //       a PwdCheck[] variable is declared
        // POST: state of PwdCheck obj, CompundC object and ExcessC are initialized and set
        public static PwdCheck[] InitPwdHeterogeneousObjects(Random rand)
        {
            Console.WriteLine("");
            Console.WriteLine(ASTERISK + "BEGIN INITIALIZE PWDCLASS HETEROGENOUS OBJECTS" + ASTERISK);
            int augmentedArraySize = ARR_SIZE * ARR_MULTIPLIER;
            Console.WriteLine("Initialize " + (augmentedArraySize/ARR_MULTIPLIER) + " PwdCheck, CompundC & Excess");
            uint randPwdLength;
            PwdCheck[] arr_PwdObj = new PwdCheck[augmentedArraySize];
            for (int i = 0; i < augmentedArraySize; i++) // 0 - 4
            {
                if (i < (augmentedArraySize) / ARR_MULTIPLIER)
                {

                    randPwdLength = (uint)rand.Next(RAND_MIN, RAND_MAX);
                    arr_PwdObj[i] = new PwdCheck(randPwdLength);
                    Console.WriteLine(" {0} object [{1}], password length = {2}, status = {3}", ObjectName.PwdClass, i, arr_PwdObj[i].GetPasswordLength(), arr_PwdObj[i].IsObjectActive() ? "active" : "inactive");

                }
                else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize) - (augmentedArraySize / ARR_MULTIPLIER)) // 4 - 8
                {
                    if (i == augmentedArraySize / ARR_MULTIPLIER){Console.WriteLine("");}

                    randPwdLength = (uint)rand.Next(RAND_MIN, RAND_MAX);
                    uint toggleCycle = (uint)rand.Next(RAND_MIN, RAND_MAX);
                    arr_PwdObj[i] = new CompundC(randPwdLength, toggleCycle);
                    Console.WriteLine(" {0} object [{1}], password length = {2}, toggle cycle = {3}, toggle limit = {4}, status = {5} ", ObjectName.CompundC, i, randPwdLength, toggleCycle, toggleCycle * ONECYLE * randPwdLength, (arr_PwdObj[i].IsObjectActive() ? "active" : "inactive"));
                }
                else //8 - 12
                {
                  
                    if (i == augmentedArraySize - ARR_SIZE){Console.WriteLine("");}

                    bool objStatus = false;
                    randPwdLength = (uint)rand.Next(RAND_MIN, RAND_MAX);
                    arr_PwdObj[i] = new ExcessC(randPwdLength, objStatus);
                    Console.WriteLine(" {0} object[{1}], password length = {2}, status = {3} ", ObjectName.ExcessC, i, randPwdLength, (objStatus ? "active" : "inactive"));
                }
                
            }
            Console.WriteLine(ASTERISK + "END INITIALIZE PWDCLASS HETEROGENOUS OBJECTS" + ASTERISK);
            return arr_PwdObj;
        }


      public static Flip[] InitFlipHeterogeneousObjects(Random rand, PwdCheck[] arrPwdObj)
        {
            Console.WriteLine("");
            Console.WriteLine(ASTERISK + "BEGIN INITIALIZE FLIP HETEROGENOUS OBJECTS" + ASTERISK);
            Console.WriteLine("Initialize " + (ARR_SIZE/INDEX_TWO) + " FLIP & FLIPPWDCHECK OBJECTS");

            Flip[] flipObj = new Flip[ARR_SIZE];
            uint index;
            string psdWord;

            for (int i = 0; i < ARR_SIZE; i++)
            {
                psdWord = GenerateRandomMixedString(rand);
                if (i < INDEX_TWO)
                {
                    Console.WriteLine("{0} object [{1}], password = {2}", ObjectName.FLIP, i, psdWord);
                    flipObj[i] = new Flip(psdWord);
                }
                else
                {
                    index = (uint)rand.Next(ARR_SIZE * ARR_MULTIPLIER);
                    flipObj[i] = new FlipPwdCheck(arrPwdObj[index], psdWord);
                     //Console.WriteLine("Index {0}", index);
                    if (arrPwdObj[index].GetType() == typeof(PwdCheck))
                    {
                        Console.WriteLine("{0} object [{1}], password = {2}", ObjectName.PwdClass, i, psdWord);
                    }
                    else if (arrPwdObj[index].GetType() == typeof(ExcessC))
                    {
                        Console.WriteLine("{0} object [{1}], password = {2}", ObjectName.ExcessC, i, psdWord);
                    }
                    else if (arrPwdObj[index].GetType() == typeof(CompundC))
                    {
                        Console.WriteLine("{0} object [{1}], password = {2}", ObjectName.CompundC, i, psdWord);
                    }
                    else
                    {
                        Console.WriteLine("Unknown object [{1}], password = {2}", i, psdWord);
                    }
                }
              
            }
            Console.WriteLine(ASTERISK + "END INITIALIZE FLIP HETEROGENOUS OBJECTS" + ASTERISK);
            return flipObj;
        }



        public static IPwdCheck[] InitIPwdHeterogeneousObjects(Random rand)
        {
            Console.WriteLine("");
            Console.WriteLine(ASTERISK + "BEGIN INITIALIZED IPWDCLASS HETEROGENOUS OBJECTS" + ASTERISK);
            Console.WriteLine("Initialize " + (ARR_SIZE) + " PwdCheck, CompundC & Excess");
            uint randPwdLength;
            IPwdCheck[] arr_IPwdObj = new IPwdCheck[ARR_SIZE];
            for (int i = 0; i < ARR_SIZE; i++) // 
            {
                
                if (i == INDEX_ZERO) //0
                {

                    randPwdLength = (uint)rand.Next(RAND_MIN, RAND_MAX);
                    arr_IPwdObj[i] = new PwdCheck(randPwdLength);
                    Console.WriteLine(" {0} object [{1}], password length = {2}, status = {3}", ObjectName.PwdClass, i, arr_IPwdObj[i].GetPasswordLength(), arr_IPwdObj[i].IsObjectActive() ? "active" : "inactive");

                }
                else if (i == INDEX_ONE) // 1
                {

                    randPwdLength = (uint)rand.Next(RAND_MIN, RAND_MAX);
                    uint toggleCycle = (uint)rand.Next(RAND_MIN, RAND_MAX);
                    arr_IPwdObj[i] = new CompundC(randPwdLength, toggleCycle);
                    Console.WriteLine(" {0} object [{1}], password length = {2}, toggle cycle = {3}, toggle limit = {4}, status = {5} ", ObjectName.CompundC, i, randPwdLength, toggleCycle, toggleCycle * ONECYLE * randPwdLength, (arr_IPwdObj[i].IsObjectActive() ? "active" : "inactive"));
                }
                else if (i == INDEX_TWO) //2
                {
                    bool objStatus = false;
                    randPwdLength = (uint)rand.Next(RAND_MIN, RAND_MAX);
                    arr_IPwdObj[i] = new ExcessC(randPwdLength, objStatus);
                    Console.WriteLine(" {0} object[{1}], password length = {2}, status = {3} ", ObjectName.ExcessC, i, randPwdLength, (objStatus ? "active" : "inactive"));
                }
                else
                {
                    string pWord = GenerateRandomMixedString(rand);
                    string obj = "none";
                    uint index = (uint)rand.Next(INDEX_TWO + INDEX_ONE);
                    if (arr_IPwdObj[index] is PwdCheck)
                    {
                        obj = "PwdCheck";
                    }
                    else if (arr_IPwdObj[index] is ExcessC)
                    {
                        obj = "ExcessC";
                    }
                    else if (arr_IPwdObj[index] is CompundC)
                    {
                        obj = "CompundC";
                    }


                    //if (arr_IPwdObj[index] is ExcessC)
                    //{
                    //    obj = "PwdCheck"; 
                    //}
                    //else if (arr_IPwdObj[index] is PwdCheck)
                    //{
                    //    obj = "ExcessC";
                    //}
                    //else if (arr_IPwdObj[index] is CompundC)
                    //{
                    //    obj = "CompundC";
                    //}

                    arr_IPwdObj[i] = new FlipPwdCheck(arr_IPwdObj[index], pWord);
                    Console.WriteLine(" {0} object[{1}], initialized with object = {2}, status = {3} ", ObjectName.FlipPwdCheck, i, obj, (arr_IPwdObj[index].IsObjectActive() ? "active" : "inactive"));
                }

            }
            Console.WriteLine(ASTERISK + "END INITIALIZED IPWDCLASS HETEROGENOUS OBJECTS" + ASTERISK);
            return arr_IPwdObj;
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
        //PRE : PwdCheck, CompundC and ExcessC are already initialized
        //      All data members are initialized
        //POST: PwdCheck, CompundC and ExcessC objects may changed state
        public static void TestCheckPassword(PwdCheck[] obj, Random rand)
        {
            Console.WriteLine(" ");
            Console.WriteLine(ASTERISK + "BEGIN TEST PASSWORD" + ASTERISK);
            int augmentedArraySize = ARR_SIZE * ARR_MULTIPLIER;
            for (int i = 0; i < augmentedArraySize; i++)
            {
                string pWord = GenerateRandomMixedString(rand);
                if (obj[i] is ExcessC)
                {
                    ExcessC cObj = (ExcessC)obj[i];
                    bool exStatus = cObj.exActiveStatus;
                    if (exStatus)
                    {
                        if (cObj.ValidatePassword(pWord))
                        {
                            Console.WriteLine(" {0} object at index {1} is valid ", ObjectName.ExcessC, i);
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
                                        Console.WriteLine(" {0} object at index {1} is invalid ", ObjectName.ExcessC, i);
                                        Console.WriteLine(" -password '{0}' doesn't contain dollar sign symbol", pWord);
                                        Console.WriteLine(" -object status: {0}", exStatus ? "active" : "inactive");
                                        continue;
                                    }
                                    else
                                    {
                                        Console.WriteLine(" {0} object at index {1} is invalid ", ObjectName.ExcessC, i);
                                        Console.WriteLine(" -password '{0}' doesn't contain mixed case", pWord);
                                        Console.WriteLine(" -object status: {0}", exStatus ? "active" : "inactive");
                                        continue;
                                    }
                                }
                                else
                                {
                                    Console.WriteLine(" {0} object at index {1} is invalid ", ObjectName.ExcessC, i);
                                    Console.WriteLine(" -password '{0}' doesn't contain an integer at location {1}", pWord, cObj.GetPasswordLength());
                                    Console.WriteLine(" -object status: {0}", exStatus ? "active" : "inactive");
                                    continue;
                                }
                            }
                            else
                            {
                                Console.WriteLine(" {0} object at index {1} is invalid ", ObjectName.ExcessC, i);
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
                    if (obj[i] is CompundC)
                    {
                        CompundC cObj = (CompundC)obj[i];
                        if (cObj.GetLockedStatus())
                        {
                            Console.WriteLine(" Object {0} at index {1} is LOCKED ", ObjectName.CompundC, i);
                            continue;
                        }
                    }

                    if (obj[i].IsObjectActive())
                    {
                        if (pWord.Length >= obj[i].GetPasswordLength())
                        {
                            if (i < (augmentedArraySize) / ARR_MULTIPLIER)
                            {
                                Console.WriteLine(" Object {0} at index {1}'s has forbidden character(s) ", ObjectName.PwdClass, i);
                                Console.WriteLine(" -rejected password '{0}'", pWord);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                            }
                            else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize - ARR_SIZE))
                            {

                                if (obj[i].GetIsCharForbidden())
                                {
                                    Console.WriteLine(" Object {0} at index {1}'s has forbidden character(s) ", ObjectName.CompundC, i);
                                    Console.WriteLine(" -rejected password '{0}'", pWord);
                                    Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                                }
                                else
                                {
                                    Console.WriteLine(" Object {0} at index {1} is invalid ", ObjectName.CompundC, i);
                                    Console.WriteLine(" -there is no repeated character", pWord);
                                    Console.WriteLine(" -rejected password '{0}'", pWord);
                                    Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                                }
                            }
                            else
                            {
                                Console.WriteLine(" Object {0} at index {1}'s has forbidden character(s)", ObjectName.ExcessC, i);
                                Console.WriteLine(" -rejected password '{0}'", pWord);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                            }
                        }
                        else
                        {
                            if (i < (augmentedArraySize) / ARR_MULTIPLIER)
                            {
                                Console.WriteLine(" {0} object at index {1} password is invalid ", ObjectName.PwdClass, i);
                                Console.WriteLine(" -password '{0}' doesn't meet length requirement", pWord);
                                Console.WriteLine(" -required length = {0}, password length = {1}", obj[i].GetPasswordLength(), pWord.Length);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                            }
                            else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize - ARR_SIZE))
                            {
                                Console.WriteLine(" {0} object at index {1} is invalid ", ObjectName.CompundC, i);
                                Console.WriteLine(" -password '{0}' doesn't meet length requirement", pWord);
                                Console.WriteLine(" -required length = {0}, password length = {1}", obj[i].GetPasswordLength(), pWord.Length);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                            }
                            else
                            {
                                Console.WriteLine(" {0} object at index {1} is invalid ", ObjectName.ExcessC, i);
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
                            Console.WriteLine(" {0} object at index {1} is not active ", ObjectName.PwdClass, i);
                        }
                        else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize - ARR_SIZE))
                        {
                            Console.WriteLine(" {0} object at index {1} is not active ", ObjectName.CompundC, i);
                        }
                        else
                        {
                            Console.WriteLine(" {0} object at index {1} is not active", ObjectName.ExcessC, i);
                        }
                    }
                }
                else
                {
                    if (i < (augmentedArraySize) / ARR_MULTIPLIER)
                    {
                        Console.WriteLine(" {0} object at index {1} password is valid ", ObjectName.PwdClass, i);
                        Console.WriteLine(" -password '{0}' meet requirements", pWord);
                        Console.WriteLine(" -required length = {0}, password length = {1}", obj[i].GetPasswordLength(), pWord.Length);
                        Console.WriteLine(" -contains no forbidden character(s)");
                        Console.WriteLine(" -object is {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                    }
                    else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize - ARR_SIZE))
                    {

                        Console.WriteLine(" {0} object at index {1} password is valid ", ObjectName.CompundC, i);
                        Console.WriteLine(" -password '{0}' meet requirements", pWord);
                        Console.WriteLine(" -required length = {0}, password length = {1}", obj[i].GetPasswordLength(), pWord.Length);
                        Console.WriteLine(" -contains no forbidden character(s)");
                        Console.WriteLine(" -contains repeated character(s)");
                        Console.WriteLine(" -object is {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                    }
                    else
                    {
                        Console.WriteLine(" {0} object at index {1} is invalid ", ObjectName.ExcessC, i);
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
        //PRE : PwdCheck, CompundC and ExcessC are already initialized
        //      All data members are initialized
        //POST: PwdCheck, CompundC and ExcessC objects may changed state
        public static void TestForbiddenCharsInPwd(PwdCheck[] obj, Random rand, string strForbidden)
        {
            char[] cForbidden = strForbidden.ToCharArray();
            Console.WriteLine(" ");
            Console.WriteLine(ASTERISK + "BEGIN TEST PASSWORD WITH UPDATED FORBIDDEN CHARACTERS" + ASTERISK);
            Console.WriteLine("Non ASCII forbidden characters = {0}", strForbidden);

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
                                Console.WriteLine(" {0} object at index {1} has forbidden character(s) ", ObjectName.PwdClass, i);
                                Console.WriteLine(" -rejected password '{0}'", pWord);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                            }
                            else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize - ARR_SIZE))
                            {
                                Console.WriteLine(" {0} object at index {1} has forbidden character(s) ", ObjectName.CompundC, i);
                                Console.WriteLine(" -rejected password '{0}'", pWord);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                            }
                            else
                            {
                                if (obj[i] is ExcessC)
                                {
                                    ExcessC c = (ExcessC)obj[i];
                                    Console.WriteLine(" {0} object at index {1} has forbidden character(s)", ObjectName.ExcessC, i);
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

        //Toggled CompundC state until it's LOCKED
        //Toggled PwdCheck and execessC objects
        //PRE : PwdCheck, CompundC and ExcessC are already initialized
        //      All data members are initialized
        //      Some of the object may have already changed state
        //      CompundC may already been LOCKED
        //POST: PwdCheck will changed state
        //      CompundC state will be changed to LOCKed if it hasn't already
        //      ExcessC will be toggled if it's state is 'OFF'
        public static void TestToggleObject(PwdCheck[] obj, Random rand)
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

                    Console.WriteLine(" Object {0} at index {1} was toggled ", ObjectName.PwdClass, i);
                    Console.WriteLine(" -toggled at {0} requests.", pToggledMax);
                    Console.WriteLine(" -updated status: {0}.", (obj[i].IsObjectActive() ? "active" : "inactive"));
                }
                else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize - ARR_SIZE))
                {

                    if (obj[i] is CompundC)
                    {
                        CompundC cObj = (CompundC)obj[i];
                        int countToggle = 0;
                        if (cObj.GetLockedStatus())
                        {
                            Console.WriteLine(" Object {0} at index  {1} have been LOCKED", ObjectName.CompundC, i);
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
                            Console.WriteLine(" Object {0} at index {1} is LOCKED", ObjectName.CompundC, i);
                            Console.WriteLine(" -locked at {0} toggles", countToggle);
                            continue;
                        }
                    }
                }
                else
                {
                    if (obj[i] is ExcessC)
                    {
                        ExcessC cObj = (ExcessC)obj[i];
                        bool exStatusOn = cObj.GetExObjectStatus();
                        if (exStatusOn)
                        {
                            Console.WriteLine(" Object {0} at index {1} is {2} ", ObjectName.ExcessC, i,
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
                            Console.WriteLine(" Object {0} at index: {1} was toggled ", ObjectName.ExcessC, i);
                            Console.WriteLine(" -toggled at {0} requests.", cToggledMax);
                            Console.WriteLine(" -status: {0}.", (exStatusOn ? "active" : "inactive"));
                        }
                    }

                }
            }

            Console.WriteLine(ASTERISK + "END TEST TOGGLE OBJECTS" + ASTERISK);
        }

        //Check for invalid characters in password. The invalid characters were initialized
        //during firing of the PwdCheck constructors.
        //PRE : PwdCheck, CompundC and ExcessC objects already initialized with default value
        //POST: PwdCheck, CompundC and ExcessC objects may change state
        public static void TestPwdClassWithInValidPassword(PwdCheck[] obj, Random rand)
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
        //PRE : PwdCheck, CompundC and ExcessC objects already initialized with default value
        //POST: PwdCheck, CompundC and ExcessC objects may change state
        public static void TestPasswordLength(IPwdCheck[] obj, Random rand)
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
                                Console.WriteLine(" {0} object at index: {1} password is invalid ", ObjectName.PwdClass, i);
                                Console.WriteLine(" -password '{0}' doesn't meet length requirement", str);
                                Console.WriteLine(" -required length = {0}, password length = {1}", pwdLength, str.Length);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");

                            }
                            else if (i >= (augmentedArraySize / ARR_MULTIPLIER) && i < (augmentedArraySize - ARR_SIZE))
                            {
                                Console.WriteLine(" {0} object at index: {1} is invalid ", ObjectName.CompundC, i);
                                Console.WriteLine(" -password '{0}' doesn't meet length requirement", str);
                                Console.WriteLine(" -required length = {0}, password length = {1}", pwdLength, str.Length);
                                Console.WriteLine(" -object status: {0}", obj[i].IsObjectActive() ? "active" : "inactive");
                            }
                            else
                            {
                                ExcessC c;
                                if (obj[i] is ExcessC)
                                {
                                    c = (ExcessC)obj[i];
                                    Console.WriteLine(" {0} object at index: {1} is invalid ", ObjectName.ExcessC, i);
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
