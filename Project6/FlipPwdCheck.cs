using System;

namespace Project6
{
    interface IPwdCheck
    {
        bool ValidatePassword(string strAlphaNumeric);
        int GetPasswordLength(); 
        bool GetObjectActive();
        bool GetIsCharForbidden();
        void SetForbiddenCharacters(char[] cForBidden);
    }

    class FlipPwdCheck: Flip, IPwdCheck
    {
        IPwdCheck pObj; //delay instantiation

        public FlipPwdCheck(PwdCheck obj, string pd) : base(pd)
        {
            pObj = obj;
            obj = null; 
        }

        public bool ValidatePassword(string strAlphaNumeric)
        {
            return pObj.ValidatePassword(strAlphaNumeric);
        }

        public bool GetIsCharForbidden()
        {
            return pObj.GetIsCharForbidden();
        }

        public int GetPasswordLength()
        {
            return pObj.GetPasswordLength();
        }

        public bool GetObjectActive()
        {
            return pObj.GetObjectActive();
        }

        public void SetForbiddenCharacters(char[] cForBidden)
        {
            pObj.SetForbiddenCharacters(cForBidden);
        }

        public bool FlipAndValidatePassword(uint index)
        {
            return ValidatePassword(base.FlipChar(index));
        }
    }
}
