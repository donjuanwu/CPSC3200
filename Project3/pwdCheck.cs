using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project3
{
    class pwdCheck
    {
        private readonly char[] strForbiddenChar = new char[] { ' ', '~', '(', ')', '{', '}', '[', ']' };
        private readonly uint pwdLength;
        private bool isObjectActive;
        private uint countCheck;
        private const uint DEFAULT_PWD_Length = 4;
       // private const int DEFAULT_SIZE = 8;



        public pwdCheck(uint length)
        {
            if (length < DEFAULT_PWD_Length)
            {
                pwdLength = DEFAULT_PWD_Length;
            }
            isObjectActive = true;
            countCheck = 0;
            pwdLength = length;
        }

        public bool CheckPassword(string strAlphaNumeric)
        {
            if (isObjectActive)
            {
                countCheck++;
                if (countCheck == pwdLength)
                {
                    isObjectActive = false;
                    return false;
                }
                else
                {
                    if (IsForbiddenCharacter(strAlphaNumeric))
                    {
                        return false;
                    }
                    else
                    {
                        return true;
                    }
                        
                }
            }
            return false;
        }

        private bool IsForbiddenCharacter(string strPwd)
        {
            for (int i = 0; i < strPwd.Length; i++)
            {
                foreach (char c in strForbiddenChar)
                {
                    if (c.Equals(strPwd[i]))
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        
    }
}
