#include <stdlib.h>
#include <string>


#ifndef PWDCHECK_H
#define PWDCHECK_H
using namespace std;

class pwdCheck
{

private:
	const int ASCII_NUM = 127;
	unsigned int pwdLength;
	bool isActive;
	bool isCharForbidden;
	unsigned int countValidation;
	const unsigned int DEFAULT_PWD_LENGTH = 4;
	string strForBidden;

	void ToggleObject();
	bool IsForbiddenCharacter(string strPwd);

protected:
	int GetASCIINumber();

public:
	pwdCheck(unsigned int length);
	~pwdCheck();

	bool virtual ValidatePassword(string strAlphaNumeric);
	bool IsPasswordLength(string word);
	int GetPasswordLength();
	bool GetObjectStatus();
	bool GetIsCharForbidden();
	void SetForbiddenCharacters(string newCharacters);

};



#endif 



