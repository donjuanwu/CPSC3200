using System;

namespace Project6
{
    interface IPwdCheck
    {
        bool ValidatePassword(string strAlphaNumeric);
    }

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
    }
}
