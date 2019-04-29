using System;


namespace Project3
{
    class compundC: pwdCheck
    {
        private uint countCompCRequest;   //keep track of number of password request
        private uint toggleMax;          //max toggle limit
       
      //  private bool isCharRepeated;
        private bool isCompCLocked; //indicate object is maxed out at toggle on/off limit
        private const int INIT_TOGGLE_MAX = 3;
        private const int INIT_PASSWORD_LENGTH = 4;
        private const uint ONECYCLE = 2;  //cycle per toggle
        public compundC (uint pwdLength = INIT_PASSWORD_LENGTH, uint toggleNum = INIT_TOGGLE_MAX) : base(pwdLength)
        {
            if (toggleNum < INIT_TOGGLE_MAX)
            {
                toggleNum = INIT_TOGGLE_MAX;
            }

            countCompCRequest = 0;
            toggleMax = toggleNum;
            isCompCLocked = false;
          //  isCharRepeated = false;
        }

        //PRE :
        //POST: Password object status may changed
        public override bool ValidatePassword(string strPwd)
        {
            return !IsObjectLocked() && base.ValidatePassword(strPwd) && IsRepeatedChar(strPwd);
           // return base.ValidatePassword(strPwd) && CheckToggleStatus() && IsRepeatedChar(strPwd);
        }

       private bool IsObjectLocked()
        {
            if (!isCompCLocked)
            {
               if (++countCompCRequest == (base.GetPasswordLength() * toggleMax * ONECYCLE))
                {
                    isCompCLocked = true;
                }
                return false;
            }
            return true;
        }

        private bool IsRepeatedChar(string str)
        {
             int[] arrChar = new int[base.GetASCIINumber()];
            for (int i = 0; i < str.Length; i++)
            {
                int index = (int)str[i];
                if (++arrChar[index] > 1)
                {
                   // isCharRepeated = true;
                    return true;
                }
            }
            return false;
        }

        //public bool GetIsCharRepeated()
        //{
        //    return isCharRepeated;
        //}

        public bool GetLockedStatus()
        {
            return isCompCLocked;
        }
    }
   
}
