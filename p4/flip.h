#include <stdlib.h>
#include <string>


#ifndef FLIP_H
using namespace std;

class flip
{

private:
	string strPhrase;
	const string DEFAULT_PASSWORD = "password";
	

public:
	flip(string password);
	~flip();


	string flipChar(unsigned int index);

};


#define FLIP_H
#endif



