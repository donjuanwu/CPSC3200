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
        const int A_SIZE = 16;
        const string ASTERISK = "***************************";
        const string VALID_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789#_<>!+*&@^=.?|\\";
        const string INVALID_CHARS = " ~(){}[]#_<>!+*&@^=.?|";
        const int ONECYLE = 2;
        const int QUARTER = 4;


        static void Main(string[] args)
        {
            Random rand = new Random();
            ProgramIntro();
            Flip[] arrFlipObj = InitFlipHeterogeneousArray(rand);
            TestFlipObjects(arrFlipObj,rand);
            TestFlipPwdCheckObjects(arrFlipObj,rand);

            Console.WriteLine("");
            Console.WriteLine("Press any key to terminate...");
            Console.ReadKey();
        }

        //Display Project 3 descriptions
        //PRE : N/A
        //POST: N/A
        public static void ProgramIntro()
        {
            Console.WriteLine("P6’s objective is to redo P4 in C#.");
            Console.WriteLine("P4 used multiple inheritance in C++ to support");
            Console.WriteLine("type definitions that encompassed pwdCheck and Flip types.");
            Console.WriteLine("C# does not support multiple inheritance=> design P6 using simulated multiple inheritance.");
            Console.WriteLine("");
            Console.WriteLine("Part I: Class Design");
            Console.WriteLine("pwdChecks are as defined in P3 (a class hierarchy of pwdChecks – pwdCheck, excess, compundC).");
            Console.WriteLine("Flip is as defined in P5");
            Console.WriteLine("You must decide how to effectively and consistently redesign the classes from P4,");
            Console.WriteLine("integrating the notions of state change, and functionality");
            Console.WriteLine("You must simulate multiple inheritance.");
            Console.WriteLine("Make reasonable design decisions so that your classes satisfy the stated goals,");
            Console.WriteLine("communicate assumptions and use, and yield clear and maintainable software.");
            Console.WriteLine("Use ProgrammingByContract to specify pre and post conditions; interface,");
            Console.WriteLine("implementation and class invariants. Relationships should be noted in the appropriate");
            Console.WriteLine("invariants.");
            Console.WriteLine("");
            Console.WriteLine("Part II: Driver");
            Console.WriteLine("Design a driver to demonstrate program requirements: ");
            Console.WriteLine("Do not skimp on your driver’s design");
            Console.WriteLine("Clearly specify the intent and structure of your driver");
            Console.WriteLine("You should have arrays (do NOT use vectors, Lists,…) ");
            Console.WriteLine("of distinct objects, initialized appropriately.");
            Console.WriteLine("Use of random number generator and/or file IO is appropriate.");
            Console.WriteLine("Use C#, the interface construct AND PROGRAMMING BY CONTRACT. ");
        }

        public static Flip[] InitFlipHeterogeneousArray(Random rand)
        {
            Console.WriteLine("");
            Console.WriteLine(ASTERISK + "BEGIN INITIALIZE FLIP HETEROGENOUS ARRAY" + ASTERISK);
            Console.WriteLine("Initialize " + (A_SIZE / QUARTER) + " FLIP & " + (A_SIZE - A_SIZE / QUARTER) + " FLIPPWDCHECK OBJECTS");

            Flip[] flipObj = new Flip[A_SIZE];
            uint randPwdLength;
            string psdWord;
            PwdCheck pObj;
            CompundC cObj;
            ExcessC eObj;
         

            for (int i = 0; i < A_SIZE; i++)
            {
                psdWord = GenerateRandomValidPassword(rand);

                if (i <  QUARTER) 
                {
                    Console.WriteLine("{0} object [{1}], password = {2}", ObjectName.FLIP, i, psdWord);
                    flipObj[i] = new Flip(psdWord);
                }
                else if (i >= QUARTER && i < QUARTER + QUARTER) 
                {
                    if (i == QUARTER) { Console.WriteLine(""); }

                    randPwdLength = (uint)rand.Next(RAND_MIN, RAND_MAX);
                    pObj = new PwdCheck(randPwdLength);
                    flipObj[i] = new FlipPwdCheck(pObj, psdWord);
                    Console.WriteLine(" {0} object [{1}], password length = {2}, status = {3}", ObjectName.PwdClass, i, randPwdLength, pObj.GetObjectActive() ? "active" : "inactive");
                }
                else if (i >= QUARTER + QUARTER && i < A_SIZE - QUARTER) 
                {
                    if (i == QUARTER + QUARTER) { Console.WriteLine(""); }

                    randPwdLength = (uint)rand.Next(RAND_MIN, RAND_MAX);
                    uint toggleCycle = (uint)rand.Next(RAND_MIN, RAND_MAX);
                    cObj = new CompundC(randPwdLength, toggleCycle);
                    flipObj[i] = new FlipPwdCheck(cObj, psdWord);              
                    Console.WriteLine(" {0} object [{1}], password length = {2}, toggle cycle = {3}, toggle limit = {4}, status = {5} ", ObjectName.CompundC, i, randPwdLength, toggleCycle, toggleCycle * ONECYLE * randPwdLength, (cObj.GetObjectActive() ? "active" : "inactive"));
                }
                else
                {
                    if (i == A_SIZE - QUARTER) { Console.WriteLine(""); }
                    bool objStatus = true;
                    randPwdLength = (uint)rand.Next(RAND_MIN, RAND_MAX);
                    eObj = new ExcessC(randPwdLength, objStatus);
                    flipObj[i] = new FlipPwdCheck(eObj, psdWord);
                    Console.WriteLine(" {0} object[{1}], password length = {2}, status = {3} ", ObjectName.ExcessC, i, randPwdLength, (objStatus ? "active" : "inactive"));
                }

            }
            Console.WriteLine(ASTERISK + "END INITIALIZE FLIP HETEROGENOUS ARRAY" + ASTERISK);
            return flipObj;
        }


        public static void TestFlipObjects(Flip[] obj, Random rand)
        {
            Console.WriteLine("");
            Console.WriteLine(ASTERISK + "BEGIN TEST FLIP OBJECTS" + ASTERISK);
            Console.WriteLine("Create random index and flip the encapsulated password");
            uint index;
            string modStr;
            for (int i = 0; i < A_SIZE; i++)
            {
                index = (uint)rand.Next(RAND_MIN, RAND_MAX);  

                if (i < QUARTER)
                {
                    modStr = obj[i].FlipChar(index);
                    Console.WriteLine("- {0} object [{1}], index to flip password = {2}, flipped passsword = {3}", ObjectName.FLIP, i, index, modStr);
                }
                else
                {
                    if (i == QUARTER) { Console.WriteLine(""); }
                    modStr = obj[i].FlipChar(index);
                    Console.WriteLine("- {0} object [{1}], index to flip password = {2}, flipped passsword = {3}", ObjectName.FlipPwdCheck, i, index, modStr);
                }
            }
            Console.WriteLine("");
            Console.WriteLine(ASTERISK + "END TEST FLIP OBJECTS" + ASTERISK);

        }

        public static void TestFlipPwdCheckObjects(Flip[] obj, Random rand)
        {
            Console.WriteLine("");
            Console.WriteLine(ASTERISK + "BEGIN TEST FLIPPWDCHECK OBJECTS" + ASTERISK);
            Console.WriteLine("Test Implementation of Interface Methods");
            HelperTestFlipAndValidatePassword(obj, rand);
            HelperDisplayPwdLength(obj);
            HelperTestValidatePassword(obj, rand);
            HelperDisplayPwdLength(obj);
           // HelperUpdateForbiddenCharacters(obj);
           // HelperTestForbiddenCharacters(obj);

            HelperDisplayFlipPwdObjectStatus(obj);
            HelperForceFlipPwdObjectStateChange(obj, rand);

            Console.WriteLine("");
            Console.WriteLine(ASTERISK + "TEST FLIPPWDCHECK OBJECTS AGAIN IN OFF STATE" + ASTERISK);
            HelperTestFlipAndValidatePassword(obj, rand);
            HelperDisplayPwdLength(obj);
            HelperTestValidatePassword(obj, rand);
            HelperDisplayPwdLength(obj);
            HelperDisplayFlipPwdObjectStatus(obj);
            HelperForceFlipPwdObjectStateChange(obj, rand);

            Console.WriteLine("");
            Console.WriteLine(ASTERISK + "END FLIPPWDCHECK OBJECTS" + ASTERISK);

        }


        public static void HelperTestFlipAndValidatePassword(Flip[] obj, Random rand)
        {
            Console.WriteLine("");
            Console.WriteLine("Begin flip then validate password using FlipAndValidatePassword()");
            Console.WriteLine("Only execute objects of type FlipPwdCheck");
            FlipPwdCheck flipO;
            uint index;
            string valid = "invalid";
            for (int i = 0; i < A_SIZE; i++)
            {
                index = (uint)rand.Next(RAND_MIN, RAND_MAX);
                if (obj[i] is FlipPwdCheck)
                {
                    flipO = (FlipPwdCheck)obj[i];
                   
                    if (flipO.FlipAndValidatePassword(index))
                    {
                        valid = "valid";
                        Console.WriteLine("- {0} object [{1}], index to flip password = {2}, password is '{3}'", ObjectName.FlipPwdCheck, i, index, valid);
                    }
                    else
                    {
                        Console.WriteLine("- {0} object [{1}], index to flip password = {2}, password is '{3}'", ObjectName.FlipPwdCheck, i, index, valid);
                    }
                }
            }
            Console.WriteLine("End validate password using FlipAndValidatePassword()");

        }

        public static void HelperDisplayPwdLength(Flip[] obj)
        {
            Console.WriteLine("");
            Console.WriteLine("Begin display FlipPwdCheck objects required password length");
            Console.WriteLine("Only execute objects of type FlipPwdCheck");
            FlipPwdCheck flipO;
            for (int i = 0; i < A_SIZE; i++)
            {
                if ( obj[i] is FlipPwdCheck)
                {
                    flipO = (FlipPwdCheck)obj[i]; 
                    Console.WriteLine("- {0} object [{1}], password length = {2},", ObjectName.FlipPwdCheck, i, flipO.GetPasswordLength());
                }
            }
            Console.WriteLine("End display FlipPwdCheck objects password length");
        }

        public static void HelperDisplayFlipPwdObjectStatus(Flip[] obj)
        {
            Console.WriteLine("");
            Console.WriteLine("Begin display FlipPwdCheck objects state");
            Console.WriteLine("Only execute objects of type FlipPwdCheck");
            FlipPwdCheck flipO;
            for (int i = 0; i < A_SIZE; i++)
            {
                if (obj[i] is FlipPwdCheck)
                {
                    flipO = (FlipPwdCheck)obj[i];
                    Console.WriteLine("- {0} object [{1}], object status '{2}'", ObjectName.FlipPwdCheck, i, flipO.GetObjectActive()? "Active" : "Inactive");
                }
            }
            Console.WriteLine("End display FlipPwdCheck objects state");
        }

        public static void HelperForceFlipPwdObjectStateChange(Flip[] obj, Random rand)
        {
            Console.WriteLine("");
            Console.WriteLine("Begin force FlipPwdCheck objects state change");
            Console.WriteLine("Only execute objects of type FlipPwdCheck");
            FlipPwdCheck flipO;
            uint rNum;
            for (int i = 0; i < A_SIZE; i++)
            {
                if (obj[i] is FlipPwdCheck)
                {
                    flipO = (FlipPwdCheck)obj[i];
                    Console.WriteLine(" Force object state change by calling FlipAndVaildatePassword() pth time = {0}", flipO.GetPasswordLength());
                    for (int j = 0; j < flipO.GetPasswordLength(); j++)
                    {
                        rNum = (uint)rand.Next(RAND_MIN, RAND_MAX);
                        flipO.FlipAndValidatePassword(rNum);
                    }

                    Console.WriteLine(" - {0} object [{1}], updated status '{2}'", ObjectName.FlipPwdCheck, i, flipO.GetObjectActive() ? "Active" : "Inactive");
                }
            }
            Console.WriteLine("End force FlipPwdCheck objects state change");
        }

        public static void HelperTestValidatePassword(Flip[] obj, Random rand)
        {
            Console.WriteLine("");
            Console.WriteLine("Begin validate password using ValidatePassword()");
            Console.WriteLine("Only execute objects of type FlipPwdCheck");
            FlipPwdCheck flipO;
            string pWord;
            string valid = "invalid";
            for (int i = 0; i < A_SIZE; i++)
            {
                pWord = GenerateRandomValidPassword(rand);
                if (obj[i] is FlipPwdCheck)
                {
                    flipO = (FlipPwdCheck)obj[i]; 

                    if (flipO.ValidatePassword(pWord))
                    {
                        valid = "valid";
                        Console.WriteLine("- {0} object [{1}], password to validate = {2}, password is'{3}'", ObjectName.FlipPwdCheck, i, pWord, valid);
                    }
                    else
                    {
                        Console.WriteLine("- {0} object [{1}], password to validate = {2}, password is'{3}'", ObjectName.FlipPwdCheck, i, pWord, valid);
                    }
                }
            }
            Console.WriteLine("End validate password using ValidatePassword()");
        }

        public static void HelperUpdateForbiddenCharacters(Flip[] obj)
        {
            char[] charForbidden = INVALID_CHARS.ToCharArray();
            Console.WriteLine("");
            Console.WriteLine("Begin Update Forbidden Charcters");
            Console.WriteLine("Only execute objects of type FlipPwdCheck");
            FlipPwdCheck flipO;
            for (int i = 0; i < A_SIZE; i++)
            {
                if (obj[i] is FlipPwdCheck)
                {
                    flipO = (FlipPwdCheck)obj[i]; 
                    flipO.SetForbiddenCharacters(charForbidden);
                    Console.WriteLine("- {0} object [{1}], forbidden characters updated", ObjectName.FlipPwdCheck, i);
                }
            }
            Console.WriteLine("End  Update Forbidden Charcters");
        }


        public static void HelperTestForbiddenCharacters(Flip[] obj)
        {
            Console.WriteLine("");
            Console.WriteLine("Begin test FlipPwdCheck password has forbidden character(s)");
            Console.WriteLine("Only execute objects of type FlipPwdCheck");
            FlipPwdCheck flipO;
            for (int i = 0; i < A_SIZE; i++)
            {
                if (obj[i] is FlipPwdCheck)
                {
                    flipO = (FlipPwdCheck)obj[i]; 
                    Console.WriteLine("- {0} object [{1}], password has forbidden character(s) '{2}'", ObjectName.FlipPwdCheck, i, flipO.GetIsCharForbidden() ? "yes" : "no");
                }
            }
            Console.WriteLine("End test FlipPwdCheck password has forbidden character(s)");
        }

        
        //Return a random password that contains valid characters
        //PRE : A random already declare and initialized
        //POST: N/A
        public static string GenerateRandomValidPassword(Random rand)
        {
            string str = "";
            int length = rand.Next(RAND_MIN, RAND_MAX);
            string mixedString = VALID_CHARS;
            for (int i = 0; i < length; i++)
            {
                str += mixedString[rand.Next(mixedString.Length)];
            }
            return str;
        }

        //Return a random password that contains valid & invalid characters
        //PRE : A random already declare and initialized
        //POST: N/A
        public static string GenerateRandomMixedPassword(Random rand)
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
    }
}
