using System;
using System.Text.RegularExpressions;


namespace Project3
{
    class excessC : pwdCheck
    {
        private uint cPwdLength;
        public bool exActiveStatus { get; set; }
        private bool isInteger;
        private bool isMixedCase;
        private const uint INIT_PASSWORD_LENGTH = 4;
        private const uint ASCII_ZERO = 0;
        private const uint ASCII_NINE = 9;
        private const char DOLLAR_SIGN = '$';

        public excessC(uint length = INIT_PASSWORD_LENGTH, bool isOn = false) : base(length)
        {
            if (length < INIT_PASSWORD_LENGTH)
            {
                length = INIT_PASSWORD_LENGTH;
            }
            cPwdLength = length;
            exActiveStatus = isOn;
            isInteger = false;
            isMixedCase = false;

        }

        public override bool ValidatePassword(string pwd)
        {
           
            if (exActiveStatus)
            {
                return IsPasswordValid(pwd);
                
            }
            return base.ValidatePassword(pwd);
        }

        private bool IsPasswordValid(string str)
        {

            return IsInteger(str) && IsStringMixedCase(str) && IsDollarSign(str);
        }

        private bool IsInteger(string str)
        {
            if (str.Length >= cPwdLength)
            {
              if (char.IsDigit(str[(int)cPwdLength - 1]))
               {
                    isInteger = true;
                    return true;
               }

            }
            return false;
        }

        private bool IsStringMixedCase(string str)
        {
            
            bool isLower = false;
            bool isUpper = false;

            foreach (char c in str)
            {
                if (char.IsLower(c))
                    isLower = true;
                if (char.IsUpper(c))
                    isUpper = true;
                if (isLower && isUpper)
                    return true;

            }

            return false;
        }

        private bool IsDollarSign(string str)
        {
            foreach (char c in str)
            {
                if (c.Equals(DOLLAR_SIGN))
                    return true;
            }
            return false;
        }

        public bool GetExObjectStatus()
        {
            return exActiveStatus;
        }
        public bool GetIsInteger()
        {
            return isInteger;
        }

        public bool GetIsMixedCase()
        {
            return isMixedCase;
        }
    }
}
