#include "factor.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
const int RAN_MIN = 1;
const int RAN_MAX = 20;
const int DEFAULT_ARR_SIZE = 4;
const int MULTIPLIER = 2;
const string ASTERISK = "******";
const int MIN_ARRAYS_IDX = 0;
const int MAX_ARRAYS_IDX = 1;

struct Arrays {
	factor arrFactor[DEFAULT_ARR_SIZE];

};

void InitArrays(Arrays& obj);
void TestNumberIsMultiplierFactor(Arrays arr);
void TestOverloaded_StreamIO_Operators(Arrays arr);
void TestOverloadedMathematicalOperators(Arrays arr);
void TestOverloadedRelationalOperators(Arrays arr);
void TestOverloadedShortcutOperators(Arrays arr);
void TestOverloadedCompounAssignmentOperators(Arrays arr);



int main()
{
	cout << "Welcome to p5" << endl;
	Arrays p5Arr;
	InitArrays(p5Arr);
	//TestNumberIsMultiplierFactor(p5Arr);
	TestOverloaded_StreamIO_Operators(p5Arr); 
	TestOverloadedMathematicalOperators(p5Arr);
	TestOverloaded_StreamIO_Operators(p5Arr);
	TestOverloadedRelationalOperators(p5Arr);
	TestOverloadedShortcutOperators(p5Arr);
	TestOverloadedCompounAssignmentOperators(p5Arr);


	return 0;
}

void InitArrays(Arrays& arr)
{
	srand(static_cast<unsigned>(time(0)));
	cout << endl;
	cout << ASTERISK + "Begin initialize P5 arrays" + ASTERISK << endl;
	cout << " - Initialized each factor, range and multiQ object " << DEFAULT_ARR_SIZE << " times" << endl;

	int num;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		arr.arrFactor[i] = num;
		cout << i + 1 << ") factor object " << i + 1 << " encapsulated factor is " << num << endl;

	}
	cout << ASTERISK + "End initialize P5 arrays" + ASTERISK << endl;

}

void TestNumberIsMultiplierFactor(Arrays arr)
{
	cout << endl;
	cout << ASTERISK + "Begin test number is a multiplier of encapsulated factor" + ASTERISK << endl;
	cout << " - Passed in " << DEFAULT_ARR_SIZE << " random numbers " << endl;
	int num;

	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % (RAN_MAX * MULTIPLIER) + RAN_MIN;
		cout << i + 1 << ") Generated random number is " << num << endl;
		if (arr.arrFactor[i].Div(num))
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

void TestOverloaded_StreamIO_Operators(Arrays arr)
{
	cout << endl;
	cout << ASTERISK + "Begin Test Overloaded Stream I/O Operators " + ASTERISK << endl;
	cout << " - Print factor objects" << endl;

	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		cout << " object[" << i << "] div factor = " << arr.arrFactor[i] << endl;
	}

	cout << ASTERISK + "End Test Overloaded Stream I/O Operators" + ASTERISK << endl;
}

void TestOverloadedMathematicalOperators(Arrays arr)
{
	srand(static_cast<unsigned>(time(0)));
	int num;

	cout << endl;
	cout << ASTERISK + "Begin Test Overloaded Mathematical Operators " + ASTERISK << endl;

	cout << "Adding two factor objects" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- object [" << i << "] + object[" << i + 1 << "] --> " << arr.arrFactor[i] << " + " << arr.arrFactor[i + 1] << endl;
			arr.arrFactor[i] + arr.arrFactor[i + 1];
			cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
		}
		else
		{
			cout << "- object [" << i << "] + object[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrFactor[i] << " + " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			arr.arrFactor[i] + arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
			cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
		}
	}
		 
		cout << endl;
		cout << "Adding a factor object to a random unsigned integer" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- object [" << i << "] div factor +  random integer --> " << arr.arrFactor[i] << " + " << num << endl;
			arr.arrFactor[i] + num;
			cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
		}

		cout << endl;
		cout << "Subtracting two factor objects" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			if (i < DEFAULT_ARR_SIZE - 1)
			{
				cout << "- object [" << i << "] - object[" << i + 1 << "] --> " << arr.arrFactor[i] << " - " << arr.arrFactor[i + 1] << endl;
				arr.arrFactor[i] - arr.arrFactor[i + 1];
				cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
			}
			else
			{
				cout << "- object [" << i << "] - object[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrFactor[i] << " - " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
				arr.arrFactor[i] - arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
				cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
			}
		}

		cout << endl;
		cout << "Subtracting an unsigned int from a factor objects" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- object [" << i << "] div factor - random integer --> " << arr.arrFactor[i] << " - " << num << endl;
			arr.arrFactor[i] - num;
			cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
			
			
		}

		cout << endl;
		cout << "Multiply two factor objects" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			if (i < DEFAULT_ARR_SIZE - 1)
			{
				cout << "- object [" << i << "] * object[" << i + 1 << "] --> " << arr.arrFactor[i] << " * " << arr.arrFactor[i + 1] << endl;
				arr.arrFactor[i] * arr.arrFactor[i + 1];
				cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
			}
			else
			{
				cout << "- object [" << i << "] * object[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrFactor[i] << " * " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
				arr.arrFactor[i] * arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
				cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
			}
		}

		cout << endl;
		cout << "Multiply a factor object to an unsigned int" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- object [" << i << "] div factor * random integer --> " << arr.arrFactor[i] << " * " << num << endl;
			arr.arrFactor[i] * num;
			cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
		}

		cout << endl;
		cout << "Integer division with two factor objects" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			if (i < DEFAULT_ARR_SIZE - 1)
			{
				cout << "- object [" << i << "] / object[" << i + 1 << "] --> " << arr.arrFactor[i] << " / " << arr.arrFactor[i + 1] << endl;
				arr.arrFactor[i] / arr.arrFactor[i + 1];
				cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
			}
			else
			{
				cout << "- object [" << i << "] / object[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrFactor[i] << " / " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
				arr.arrFactor[i] / arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
				cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
			}
		}

		cout << endl;
		cout << "Integer division of a factor object by an unsigned int" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- object [" << i << "] div factor / random integer --> " << arr.arrFactor[i] << " / " << num << endl;
			arr.arrFactor[i] / num;
			cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
		}

		cout << endl;
		cout << "Integer modulus with two factor objects" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			if (i < DEFAULT_ARR_SIZE - 1)
			{
				cout << "- object [" << i << "] % object[" << i + 1 << "] --> " << arr.arrFactor[i] << " % " << arr.arrFactor[i + 1] << endl;
				arr.arrFactor[i] % arr.arrFactor[i + 1];
				cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
			}
			else
			{
				cout << "- object [" << i << "] % object[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrFactor[i] << " % " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
				arr.arrFactor[i] % arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
				cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
			}
		}

		cout << endl;
		cout << "Integer modulus of a factor object by an unsigned int" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- object [" << i << "] div factor % random integer --> " << arr.arrFactor[i] << " % " << num << endl;
			arr.arrFactor[i] % num;
			cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
		}

	cout << ASTERISK + "End Test Overloaded Mathematical Operators" + ASTERISK << endl;
}

void TestOverloadedRelationalOperators(Arrays arr)
{

	cout << endl;
	cout << ASTERISK + "Begin Test Overloaded Relational Operators " + ASTERISK << endl;

	cout << "Determine two factor objects div factor are equals to each other using '==' operator" << endl;

	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- object [" << i << "] div factor = " << arr.arrFactor[i] << endl;
			cout << "- object [" << i + 1 << "] div factor = " << arr.arrFactor[i + 1] << endl;
			if (arr.arrFactor[i] == arr.arrFactor[i + 1])
			{
				cout << " object div factor are the same" << endl;
			}
			else
			{
				cout << " object div factor are not the same" << endl;
			}
		}
		else
		{
			cout << "- object [" << i << "] div factor = " << arr.arrFactor[i] << endl;
			cout << "- object [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div factor = " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			if (arr.arrFactor[i] == arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " object div factor are the same" << endl;
			}
			else
			{
				cout << " object div factor are not the same" << endl;
			}
		}
	}
	cout << endl;
	cout << "Determine one object div factor is less than another div factor using '<' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- object [" << i << "] div factor = " << arr.arrFactor[i] << endl;
			cout << "- object [" << i + 1 << "] div factor = " << arr.arrFactor[i + 1] << endl;
			if (arr.arrFactor[i] < arr.arrFactor[i + 1])
			{
				cout << " object [" << i << "] div factor is less than object [" << i + 1 << "] div factor" << endl;
			}
			else
			{
				cout << " object [" << i << "] div factor is NOT less than object [" << i + 1 << "] div factor" << endl;
			}
		
		}
		else
		{
			cout << "- object [" << i << "] div factor = " << arr.arrFactor[i] << endl;
			cout << "- object [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div factor = " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			if (arr.arrFactor[i] < arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " object [" << i << "] div factor is less than object [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div factor" << endl;
			}
			else
			{
				cout << " object [" << i << "] div factor is NOT less than object [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div factor" << endl;
			}
		
		}
	}

	cout << endl;
	cout << "Determine one object div factor is greater than another div factor using '>' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- object [" << i << "] div factor = " << arr.arrFactor[i] << endl;
			cout << "- object [" << i + 1 << "] div factor = " << arr.arrFactor[i + 1] << endl;
			if (arr.arrFactor[i] > arr.arrFactor[i + 1])
			{
				cout << " object [" << i << "] div factor is greater than object [" << i + 1 << "] div factor" << endl;
			}
			else
			{
				cout << " object [" << i << "] div factor is NOT greater than object [" << i + 1 << "] div factor" << endl;
			}

		}
		else
		{
			cout << "- object [" << i << "] div factor = " << arr.arrFactor[i] << endl;
			cout << "- object [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div factor = " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			if (arr.arrFactor[i] > arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " object [" << i << "] div factor is greater than object [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div factor" << endl;
			}
			else
			{
				cout << " object [" << i << "] div factor is NOT greater than object [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div factor" << endl;
			}

		}
	}

	cout << endl;
	cout << "Determine two objects div factor are not equals to each other using '!=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- object [" << i << "] div factor = " << arr.arrFactor[i] << endl;
			cout << "- object [" << i + 1 << "] div factor = " << arr.arrFactor[i + 1] << endl;
			if (arr.arrFactor[i] != arr.arrFactor[i + 1])
			{
				cout << " object [" << i << "] div factor is NOT equals to object [" << i + 1 << "] div factor" << endl;
			}
			else
			{
				cout << " object [" << i << "] div factor is equals object [" << i + 1 << "] div factor" << endl;
			}

		}
		else
		{
			cout << "- object [" << i << "] div factor = " << arr.arrFactor[i] << endl;
			cout << "- object [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div factor = " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			if (arr.arrFactor[i] != arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " object [" << i << "] div factor is NOT equals to object [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div factor" << endl;
			}
			else
			{
				cout << " object [" << i << "] div factor is equals to object [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div factor" << endl;
			}

		}
	}

	cout << endl;
	cout << "Determine one object div factor is less than or equals to the other using '<=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- object [" << i << "] div factor = " << arr.arrFactor[i] << endl;
			cout << "- object [" << i + 1 << "] div factor = " << arr.arrFactor[i + 1] << endl;
			if (arr.arrFactor[i] <= arr.arrFactor[i + 1])
			{
				cout << " object [" << i << "] div factor is less than or equals to object [" << i + 1 << "] div factor" << endl;
			}
			else
			{
				cout << " object [" << i << "] div factor is NOT less than or equals to object [" << i + 1 << "] div factor" << endl;
			}

		}
		else
		{
			cout << "- object [" << i << "] div factor = " << arr.arrFactor[i] << endl;
			cout << "- object [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div factor = " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			if (arr.arrFactor[i] <= arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " object [" << i << "] div factor is less than or equals to object [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div factor" << endl;
			}
			else
			{
				cout << " object [" << i << "] div factor is NOT less than or equals to object [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div factor" << endl;
			}
		}
	}

	cout << endl;
	cout << "Determine one object div factor is greater than or equals to the other using '>=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- object [" << i << "] div factor = " << arr.arrFactor[i] << endl;
			cout << "- object [" << i + 1 << "] div factor = " << arr.arrFactor[i + 1] << endl;
			if (arr.arrFactor[i] >= arr.arrFactor[i + 1])
			{
				cout << " object [" << i << "] div factor is greater than or equals to object [" << i + 1 << "] div factor" << endl;
			}
			else
			{
				cout << " object [" << i << "] div factor is NOT greater than or equals to object [" << i + 1 << "] div factor" << endl;
			}

		}
		else
		{
			cout << "- object [" << i << "] div factor = " << arr.arrFactor[i] << endl;
			cout << "- object [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div factor = " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			if (arr.arrFactor[i] >= arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " object [" << i << "] div factor is greater than or equals to object [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div factor" << endl;
			}
			else
			{
				cout << " object [" << i << "] div factor is NOT greater than or equals to object [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div factor" << endl;
			}
		}
	}

	cout << ASTERISK + "End Test Overloaded Relational Operators " + ASTERISK << endl;
}

void TestOverloadedShortcutOperators(Arrays arr)
{
	cout << endl;
	cout << ASTERISK + "Begin Test Overloaded Shortcut Operators " + ASTERISK << endl;

	cout << "Pre increment factor objects using '++object' operator" << endl;

	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		cout << "- object [" << i << "] current div factor = " << arr.arrFactor[i];
		cout << ", call ++object[" << i <<"]" << endl;
		cout << "  in scope returned div factor = " << ++arr.arrFactor[i] << endl;
	}
	cout << endl;
	cout << "Post increment factor objects using 'object++' operator" << endl;

	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		cout << "- object [" << i << "] current div factor = " << arr.arrFactor[i];
		cout << ", call object[" << i << "]++" << endl;
		cout << "  in scope returned div factor = " << arr.arrFactor[i]++ << endl;
	}

	cout << endl;
	cout << "Pre decrement factor objects using '--object' operator" << endl;

	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		cout << "- object [" << i << "] current div factor = " << arr.arrFactor[i];
		cout << ", call --object[" << i << "]" << endl;
		cout << "  in scope returned div factor = " << --arr.arrFactor[i] << endl;
	}

	cout << endl;
	cout << "Post decrement factor objects using 'object--' operator" << endl;

	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		cout << "- object [" << i << "] current div factor = " << arr.arrFactor[i];
		cout << ", call object[" << i << "]--" << endl;
		cout << "  in scope returned div factor = " << arr.arrFactor[i]-- << endl;
	}

	cout << ASTERISK + "End Test Overloaded Shortcut Operators " + ASTERISK << endl;
}

void TestOverloadedCompounAssignmentOperators(Arrays arr)
{
	srand(static_cast<unsigned>(time(0)));
	int num;

	cout << endl;
	cout << ASTERISK + "Begin Test Overloaded Compound Assignment Operators " + ASTERISK << endl;

	cout << "Add two factor objects using '+=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- object [" << i << "] += object[" << i + 1 << "] --> " << arr.arrFactor[i] << " += " << arr.arrFactor[i + 1] << endl;
			arr.arrFactor[i] += arr.arrFactor[i + 1];
			cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
		}
		else
		{
			cout << "- object [" << i << "] += object[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrFactor[i] << " += " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			arr.arrFactor[i] += arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
			cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
		}
	}

	cout << endl;
	cout << "Add a factor object with an unsigned int using '+=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- object [" << i << "] div factor +=  random integer --> " << arr.arrFactor[i] << " += " << num << endl;
		arr.arrFactor[i] += num;
		cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
	}

	cout << endl;
	cout << "Subtract two factor objects using '-=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- object [" << i << "] -= object[" << i + 1 << "] --> " << arr.arrFactor[i] << " -= " << arr.arrFactor[i + 1] << endl;
			arr.arrFactor[i] -= arr.arrFactor[i + 1];
			cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
		}
		else
		{
			cout << "- object [" << i << "] -= object[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrFactor[i] << " -= " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			arr.arrFactor[i] -= arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
			cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
		}
	}

	cout << endl;
	cout << "Subtract an unsigned int from a factor object using '-=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- object [" << i << "] div factor -=  random integer --> " << arr.arrFactor[i] << " -= " << num << endl;
		arr.arrFactor[i] -= num;
		cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
	}


	cout << endl;
	cout << "Multiply two factor objects using '*=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- object [" << i << "] *= object[" << i + 1 << "] --> " << arr.arrFactor[i] << " *= " << arr.arrFactor[i + 1] << endl;
			arr.arrFactor[i] *= arr.arrFactor[i + 1];
			cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
		}
		else
		{
			cout << "- object [" << i << "] *= object[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrFactor[i] << " *= " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			arr.arrFactor[i] *= arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
			cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
		}
	}

	cout << endl;
	cout << "Multiply a factor object with an unsigned int using '*=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- object [" << i << "] div factor *=  random integer --> " << arr.arrFactor[i] << " *= " << num << endl;
		arr.arrFactor[i] *= num;
		cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
	}

	cout << endl;
	cout << "Integer division with two factor objects using '/=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- object [" << i << "] /= object[" << i + 1 << "] --> " << arr.arrFactor[i] << " /= " << arr.arrFactor[i + 1] << endl;
			arr.arrFactor[i] /= arr.arrFactor[i + 1];
			cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
		}
		else
		{
			cout << "- object [" << i << "] /= object[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrFactor[i] << " /= " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			arr.arrFactor[i] /= arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
			cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
		}
	}


	cout << endl;
	cout << "Integer division of a factor object by an unsigned int using '/=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- object [" << i << "] div factor /=  random integer --> " << arr.arrFactor[i] << " /= " << num << endl;
		arr.arrFactor[i] /= num;
		cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
	}

	cout << endl;
	cout << "Integer modulus with two factor objects using '%=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- object [" << i << "] %= object[" << i + 1 << "] --> " << arr.arrFactor[i] << " %= " << arr.arrFactor[i + 1] << endl;
			arr.arrFactor[i] %= arr.arrFactor[i + 1];
			cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
		}
		else
		{
			cout << "- object [" << i << "] %= object[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrFactor[i] << " %= " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			arr.arrFactor[i] %= arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
			cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
		}
	}

	cout << endl;
	cout << "Integer modulus of a factor object by an unsigned int using '%=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- object [" << i << "] div factor %=  random integer --> " << arr.arrFactor[i] << " %= " << num << endl;
		arr.arrFactor[i] %= num;
		cout << "  in scope object [" << i << "] updated div factor = " << arr.arrFactor[i] << endl;
	}

	cout << ASTERISK + "End Test Overloaded Compound Assignment Operators " + ASTERISK << endl;
}