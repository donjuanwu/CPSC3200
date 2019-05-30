using System;

namespace Project6
{
    class Flip
    {
        private string strPhrase;
        private const string DEFAULT_PASSWORD = "password";

        public Flip(string password = DEFAULT_PASSWORD)
        {
            strPhrase = password;
        }

        public string FlipChar(uint index)
        {
            string strFlipped ="";
            if (index > strPhrase.Length)
            {
                index = (uint)strPhrase.Length;
            }

            for (int i = 0; i <strPhrase.Length; i++)
            {
                if (index > 0)
                {
                    strFlipped += strPhrase[(int)index - 1];
                }
                strFlipped += strPhrase[i];
            }

            return strFlipped;
        }


    }
}
