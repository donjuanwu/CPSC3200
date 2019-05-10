#include "flip.h"

flip::flip(string password) 
{
	if (password == " ")
	{
		password = DEFAULT_PASSWORD;
	}
	strPhrase = password;
}

string flip::flipChar(unsigned int flipIndex)
{
	int strLen = strPhrase.length();
	string modPassword;

	if (flipIndex > strLen)
	{
		return strPhrase;
	}

	char* cArray = new char[strLen];

	for (int i = 0; i < strLen; i++)
	{
		if (flipIndex > 0)
		{
			cArray[i] = strPhrase[flipIndex - 1];
			flipIndex--;
		}
		else
		{
			cArray[i] = strPhrase[i];
		}
	}
	string strFlipped = string(cArray);
	delete[] cArray;
	return strFlipped;


}

flip::~flip()
{

}
