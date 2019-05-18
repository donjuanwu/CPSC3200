#include "factor.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void InitFactorObject(factor* obj);
void TestNumberIsMultiplierFactor(factor* obj);

const int RAN_MIN = 1;
const int RAN_MAX = 20;
const int DEFAULT_ARR_SIZE = 2;
const int MULTIPLIER = 2;
const string ASTERISK = "******";


int main()
{
	srand(static_cast<unsigned>(time(0)));
	cout << "Welcome to p5" << endl;
	factor arrFObj[DEFAULT_ARR_SIZE];
	InitFactorObject(arrFObj);
	TestNumberIsMultiplierFactor(arrFObj);

	return 0;
}


void InitFactorObject(factor* obj)
{
	cout << endl;
	cout << ASTERISK + "Begin initialize Factor objects" + ASTERISK << endl;
	cout << " - Fired factor constructor " << DEFAULT_ARR_SIZE << " times" << endl;

	int num;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		obj[i] = num;
		cout << i + 1 << ") factor object " << i + 1 << " random encapsulated number is " << num << endl;
		
	}
	cout << ASTERISK + "End initialize Factor objects" + ASTERISK << endl;

}

void TestNumberIsMultiplierFactor(factor* obj)
{
	cout << endl;
	cout << ASTERISK + "Begin test number is a multiplier of encapsulated factor" + ASTERISK << endl;
	cout << " - Passed in " << DEFAULT_ARR_SIZE << " random numbers " << endl;
	int num;

	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % (RAN_MAX * MULTIPLIER) + RAN_MIN;
		cout << i + 1 << ") Generated random number is " << num << endl;
		if (obj[i].Div(num))
		{
			cout << " - Number " << num << " is a multiplier of the encapsulated factor" << endl;
		}
		else
		{
			cout << " - Number " << num << " is NOT a multiplier of the encapsulated factor" << endl;
		}
	}
	cout << ASTERISK + "End test number is a multiplier of factor value" + ASTERISK << endl;
}