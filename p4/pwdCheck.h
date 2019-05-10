#include <stdlib.h>
#include <string>


#ifndef PWDCHECK_H
#define PWDCHECK_H


class pwdCheck
{
public:
	pwdCheck(unsigned int length);

	bool ValidatePassword(string strAlphaNumeric);
	bool IsPasswordLength(string word);
	

	~pwdCheck();



private:
	char* charForbidden;
	const int ASCII_NUM = 127;
	unsigned int pwdLength;
	bool isActive;
	bool isCharForbidden;
	unsigned int countValidation;
	const unsigned int DEFAULT_PWD_LENGTH = 4;
	const unsigned int DEFAULT_ARRAY_CHAR_LENGTH = 8;
	string strForBidden;

	void ToggleObject();
	bool IsForbiddenCharacter(string strPwd);
	void InitForBiddenChar();

};



#endif 



