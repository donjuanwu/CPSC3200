using System;

namespace Project6
{
   
    class FlipPwdCheck: Flip, IPwdCheck
    {
        PwdCheck pObj; //delay instantiation

        public FlipPwdCheck(PwdCheck obj, string pd) : base(pd)
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


    }
}
