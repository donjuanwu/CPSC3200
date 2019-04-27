using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project3
{
    class compundC: pwdCheck
    {
        private uint countRequest;
        private uint allowedReqest;
        private int countStateChanged;
        private int toggledMax;
        private const int INIT_TOGGLE_LIMIT = 3;
        private const int INIT_PASSWORD_LENGTH = 4;

        //public compundC(uint pwdLength = INIT_PASSWORD_LENGTH): base(pwdLength)
        //{
        //    toggledMax = INIT_TOGGLE_LIMIT;
        //    countRequest = 0;
        //    allowedReqest = INIT_TOGGLE_LIMIT;
        //    countStateChanged = 0;
        //}

        public compundC (uint pwdLength = INIT_PASSWORD_LENGTH, uint reqMax = INIT_TOGGLE_LIMIT) : base(pwdLength)
        {
            if (reqMax < INIT_TOGGLE_LIMIT)
            {
                reqMax = INIT_TOGGLE_LIMIT;
            }

            toggledMax = INIT_TOGGLE_LIMIT;
            countRequest = 0;
            allowedReqest = reqMax;
            countStateChanged = 0;
        }

        //PRE :
        //POST: Password object status may changed
        public override bool ValidatePassword(string strPwd)
        {
            return base.ValidatePassword(strPwd) && CheckToggleStatus() && IsRepeatedChar(strPwd);
        }

        public int GetToggledCount()
        {
            return countStateChanged;
        }

       private bool CheckToggleStatus()
        {
            if (GetToggledCount() < (int)toggledMax)
            {
                if (base.IsObjectActive())
                {
                    if (++countRequest == allowedReqest)
                    {
                        countStateChanged++; 
                    }
                }
                else
                {
                   if (allowedReqest - (--countRequest) == allowedReqest)
                    {
                        countRequest++;
                    }
                }
                return true;
            }
            return false;
        }

        private bool IsRepeatedChar(string str)
        {
            int[] arrChar = new int[base.GetASCIINumber()];
            for (int i = 0; i < str.Length; i++)
            {
                if (++arrChar[i] > 1)
                {
                    return true;
                }
            }
            return false;
        }
    }
}
