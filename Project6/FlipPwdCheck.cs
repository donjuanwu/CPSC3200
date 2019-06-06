using System;

namespace Project6
{
   
    class FlipPwdCheck: Flip, IPwdCheck
    {
        IPwdCheck pObj; //delay instantiation

        public FlipPwdCheck(IPwdCheck obj, string pd) : base(pd)
        {
            pObj = obj;
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

        public bool IsObjectActive()
        {
            return pObj.IsObjectActive();
        }

        public bool IsPasswordLength(string pWord)
        {
            return pObj.IsPasswordLength(pWord);
        }

        public void SetForbiddenCharacters(char[] cForBidden)
        {
            pObj.SetForbiddenCharacters(cForBidden);
        }

        public bool FlipAndValidatePassword(uint index)
        {
            return ValidatePassword(FlipChar(index));
        }


    }
}
