#include <stdlib.h>
#include "pwdCheck.h"
#include "flip.h"
#ifndef FLIPPWDCHECK_H
#define FLIPPWDCHECK_H
using namespace std;

class flipPwdCheck: public pwdCheck, public flip
{

private:



public:
	flipPwdCheck(unsigned int length, string password);

	~flipPwdCheck();




};

#endif 




