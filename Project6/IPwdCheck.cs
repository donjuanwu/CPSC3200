using System;

namespace Project6
{
    interface IPwdCheck
    {
        bool ValidatePassword(string strAlphaNumeric);
        bool IsPasswordLength(string pWord);
        int GetPasswordLength();
        bool IsObjectActive();
        bool GetIsCharForbidden();
        void SetForbiddenCharacters(char[] cForBidden);
    }
}
