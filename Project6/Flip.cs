/*
-- Developer    : Don Dang
-- Project      : Project 6
-- Instructor   : Dr. Dingle
-- File Name    : flipp.cs
-- File Version : 1.0
-- Due Date	    : 6/7/2019
-- Course Name  : CPSC 3200

 * OVERVIEW:
 *  FlipChar encapsulated a string password, flip the first 'xth length' number of characters in the string, and then
 *  pass the flipped password to the calling function
 *
 * ---------------------------------------------------------------------------------------------------------------------------------
 * DESIGN DECISIONS AND ASSUMPTIONS:
 *  1 - FlipChar():
 *
 *      This method will flip the beginning characters until the passed index of the string. It will return the flipped password back
 *		  to the calling function
 * ---------------------------------------------------------------------------------------------------------------------------------
 * IMPLEMENTATION INVARIANTS:
 *  1 - FlipChar()
 * Take in an unsigned int including from 0 to the size of the unsigned int value
 * Use the unsigned int lenght to flipped the characters of the string.
 * The characters will be flipped starting at the index (length) of the password
 * If the number of the characters to be flipped is longer than the string, then the whole string get flipped.
 * The flipped string get return back to the calling function
 * ---------------------------------------------------------------------------------------------------------------------------------
 * CLASS INVARIANTS:
 *  2 - CONSTRUCTORS: Encapsulate the password
 *
 * One constructor takes in an alphanumeric password at any length
 * The other constructor is a default constructor. It will provide a default password name "password"
 *
---------------------------------------------------------------------------------------------------------------------------------------
    WHEN     WHO		WHAT
    5/29/19  DD         Copied p4.cs from project3 to p6.cs  
*/

using System;

namespace Project6
{
    class Flip
    {
        private string strPhrase;
        private const string DEFAULT_PASSWORD = "password";

        public Flip(string password = DEFAULT_PASSWORD)
        {
            strPhrase = password;
        }

        public string FlipChar(uint index)
        {
            string strFlipped ="";
            if (index > strPhrase.Length)
            {
                index = (uint)strPhrase.Length;
            }

            for (int i = 0; i <strPhrase.Length; i++)
            {
                if (index > 0)
                {
                    strFlipped += strPhrase[(int)index - 1];
                    index--;
                }
                else
                {
                    strFlipped += strPhrase[i];
                }
                
            }

            return strFlipped;
        }


    }
}
