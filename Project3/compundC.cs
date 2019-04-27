using System;


namespace Project3
{
    class compundC: pwdCheck
    {
        private uint countCompCRequest;   //keep track of number of password request
        private uint cycleToggledMax;  //number of cycle toggled max
        private int isOneCycle;           //keep track of a complete cyle; odd = complete a cyle, even = half cycle
        private bool isCharRepeated;
        private bool isCompCActive;  //keep track of compundC status
        private bool isCompCLocked; //indicate object is maxed out at toggle on/off limit
        private const int INIT_TOGGLE_LIMIT = 3;
        private const int INIT_PASSWORD_LENGTH = 4;
        private const int INIT_CYCLE_POS = -1;
        private const int DEFAULT_MOD_DIVISOR = 2;

        //public compundC(uint pwdLength = INIT_PASSWORD_LENGTH): base(pwdLength)
        //{
        //    toggledMax = INIT_TOGGLE_LIMIT;
        //    countRequest = 0;
        //    allowedReqest = INIT_TOGGLE_LIMIT;
        //    countStateChanged = 0;
        //}

        public compundC (uint pwdLength = INIT_PASSWORD_LENGTH, uint toggleMax = INIT_TOGGLE_LIMIT) : base(pwdLength)
        {
            if (toggleMax < INIT_TOGGLE_LIMIT)
            {
                toggleMax = INIT_TOGGLE_LIMIT;
            }

            countCompCRequest = 0;
            cycleToggledMax = toggleMax;
            isOneCycle = INIT_CYCLE_POS;
            isCompCActive = true;
            isCompCLocked = false;
            isCharRepeated = false;
        }

        //PRE :
        //POST: Password object status may changed
        public override bool ValidatePassword(string strPwd)
        {
            return base.ValidatePassword(strPwd) && IsObjectLocked() && IsRepeatedChar(strPwd);
           // return base.ValidatePassword(strPwd) && CheckToggleStatus() && IsRepeatedChar(strPwd);
        }

       private bool IsObjectLocked()
        {
            if (!isCompCLocked)
            {
                //increment count compC request
                countCompCRequest++;

                if (countCompCRequest == base.GetPasswordLength())
                {
                    if (isCompCActive ? false : true)

                    isOneCycle++;
                    countCompCRequest = 0;
                    if (isOneCycle % DEFAULT_MOD_DIVISOR != 0)
                    {
                        cycleToggledMax--;
                        if (cycleToggledMax == 0)
                        {
                            isCompCLocked = true;
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                            
                    }
                    return false;
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
                    isCharRepeated = true;
                    return true;
                }
            }
            return false;
        }

        public bool GetIsCharRepeated()
        {
            return isCharRepeated;
        }

        public bool GetLockedStatus()
        {
            return isCompCLocked;
        }

        public bool GetCompCStatus()
        {
            return isCompCActive;
        }

    }
   
}
