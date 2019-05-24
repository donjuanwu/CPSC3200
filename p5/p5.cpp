#include "factor.h"
#include "range.h"
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
	range arrRange[DEFAULT_ARR_SIZE];

};

void InitArrays(Arrays& obj);
void TestNumberIsMultiplierFactor(Arrays& arr);
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
	TestNumberIsMultiplierFactor(p5Arr);
	TestOverloaded_StreamIO_Operators(p5Arr); 
	TestOverloadedMathematicalOperators(p5Arr);
	//TestOverloaded_StreamIO_Operators(p5Arr);
	//TestOverloadedRelationalOperators(p5Arr);
	//TestOverloadedShortcutOperators(p5Arr);
	//TestOverloadedCompounAssignmentOperators(p5Arr);


	return 0;
}

void InitArrays(Arrays& arr)
{
	srand(static_cast<unsigned>(time(0)));
	cout << endl;
	cout << ASTERISK + "Begin initialize P5 arrays" + ASTERISK << endl;
	cout << " - Initialized each factor, range and multiQ object " << DEFAULT_ARR_SIZE << " times" << endl;

	int num;
	int num2;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		arr.arrFactor[i] = factor(num);
		cout << i + 1 << ") factor object " << i << " initialized value " << num << endl;
		
		
		num = rand() % RAN_MAX + RAN_MIN;
		num2 = rand() % RAN_MAX + RAN_MIN;

		arr.arrRange[i] = range(num, num2);
		cout << i + 1 << ") range object " << i  << " initialized values [" << num << "," << num2 << "]" << endl;
		cout << "- display factor object " << i << " encapsulated value = " << arr.arrFactor[i] << endl;
		cout << "- display range object " << i << " encapsulated values = [" << arr.arrRange[i] << "]"  << endl;
		cout << endl;
	}
	cout << ASTERISK + "End initialize P5 arrays" + ASTERISK << endl;

}

void TestNumberIsMultiplierFactor(Arrays& arr)
{
	cout << endl;
	cout << ASTERISK + "Begin test number is a multiplier of encapsulated factor" + ASTERISK << endl;
	cout << " - Passed in " << DEFAULT_ARR_SIZE << " random numbers " << endl;
	int num;

	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % (RAN_MAX * RAN_MAX * MULTIPLIER) + RAN_MIN;
		cout << i + 1 << ") Passed in number " << num << endl;
		if (arr.arrFactor[i].Div(num))
		{
			cout << " - " << num << " is a multiplier of factor [" << arr.arrFactor[i] << "]" << endl;
		}
		else
		{
			cout << " - " << num << " is NOT a multiplier of factor [" << arr.arrFactor[i] << "]" << endl;
		}

		if (arr.arrRange[i].Ping(num))
		{
			cout << " - " << num << " is a multiplier of range [" << arr.arrRange[i] << "]" << endl;
		}
		else
		{
			cout << " - " << num << " is NOT a multiplier of range [" << arr.arrRange[i] << "]" << endl;
		}


	}
	cout << ASTERISK + "End test number is a multiplier of factor value" + ASTERISK << endl;
}

void TestOverloaded_StreamIO_Operators(Arrays arr)
{
	cout << endl;
	cout << ASTERISK + "Begin Test Overloaded Stream I/O Operators " + ASTERISK << endl;
	cout << " - Print encapsulated values" << endl;

	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		cout << i + 1 << ") factor object[" << i << "] encapsulated factor = " << arr.arrFactor[i] << endl;
		cout << i + 1 << ") range object[" << i << "] encapsulated factors = [" << arr.arrRange[i] <<"]" << endl;

		cout << endl;
	}

	cout << ASTERISK + "End Test Overloaded Stream I/O Operators" + ASTERISK << endl;
}

void TestOverloadedMathematicalOperators(Arrays arr)
{
	srand(static_cast<unsigned>(time(0)));
	int num;
	int local;
	factor fTest;
	range rObject;

	cout << endl;
	cout << ASTERISK + "Begin Test Overloaded Mathematical Operators " + ASTERISK << endl;

	cout << "Adding two factor objects" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- object [" << i << "] + object[" << i + 1 << "] --> " << arr.arrFactor[i] << " + " << arr.arrFactor[i + 1] << endl;
			local = arr.arrFactor[i] + arr.arrFactor[i + 1];
			cout << "  in scope object div factor = " << local << endl;
		}
		else
		{
			cout << "- object [" << i << "] + object[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrFactor[i] << " + " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			
			local = arr.arrFactor[i] + arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
			cout << "  in scope object div factor = " << local << endl;
		}
	}

	cout << endl;
	cout << "Adding two range objects" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- object [" << i << "] + object[" << i + 1 << "] --> " << "[" << arr.arrRange[i] <<"]"<< " + " << "[" << arr.arrRange[i + 1] << "]" << endl;
			rObject = arr.arrRange[i] + arr.arrRange[i + 1];
			cout << "  in scope object div factors = " << "[" << rObject << "]" << endl;
			
		}
		else
		{
			cout << "- object [" << i << "] + object[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << "[" << arr.arrRange[i] << "]" << " + " << "[" << arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << "]" << endl;

			rObject = arr.arrRange[i] + arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
			cout << "  in scope object div factors = " << "[" << rObject << "]" << endl;
		}
	}


		cout << endl;
		cout << "Adding a factor object to a random unsigned integer" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- object [" << i << "] div factor +  random integer --> " << arr.arrFactor[i] << " + " << num << endl;
			local = arr.arrFactor[i] + num;
			cout << "  in scope object div factor = " << local << endl;
		}

		cout << endl;
		cout << "Adding a range object to a random unsigned integer" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- object [" << i << "] div factors +  random integer --> " << "[" << arr.arrRange[i] << "]" << " + " << num << endl;
			rObject = arr.arrRange[i] + num;
			cout << "  in scope object div factors = " << "[" << rObject << "]" << endl;
		}


		cout << endl;
		cout << "Adding a random unsigned integer to a factor object" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- random integer + " << "object [" << i << "] div factor --> " << num << " + " << arr.arrFactor[i] << endl;
			local = num + arr.arrFactor[i];
			cout << "  in scope object div factor = " << local << endl;
		}


		cout << endl;
		cout << "Adding a random unsigned integer to a range object" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- random integer + " << "object [" << i << "] div factors --> " << num << " + [" << arr.arrRange[i] <<"]" << endl;
			rObject = num + arr.arrRange[i];
			cout << "  in scope object div factors = " << "[" << rObject << "]" << endl;
		}

		cout << endl;
		cout << "Subtracting two factor objects" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			if (i < DEFAULT_ARR_SIZE - 1)
			{
				cout << "- object [" << i << "] - object[" << i + 1 << "] --> " << arr.arrFactor[i] << " - " << arr.arrFactor[i + 1] << endl;
				local = arr.arrFactor[i] - arr.arrFactor[i + 1];
				cout << "  in scope object div factor = " << local << endl;
			}
			else
			{
				cout << "- object [" << i << "] - object[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrFactor[i] << " - " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
				local =	arr.arrFactor[i] - arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
				cout << "  in scope object div factor = " << local << endl;
			}
		}

		cout << endl;
		cout << "Subtracting two range objects" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			if (i < DEFAULT_ARR_SIZE - 1)
			{
				cout << "- object [" << i << "] - object[" << i + 1 << "] --> " << arr.arrRange[i] << " - " << arr.arrRange[i + 1] << endl;
				rObject = arr.arrRange[i] - arr.arrRange[i + 1];
				cout << "  in scope object div factors = " << "[" << rObject << "]" << endl;
			}
			else
			{
				cout << "- object [" << i << "] - object[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrRange[i] << " - " << arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
				rObject = arr.arrRange[i] - arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
				cout << "  in scope object div factors = " << "[" << rObject << "]" << endl;
			}
		}

		cout << endl;
		cout << "Subtracting an unsigned int from a factor object" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- object [" << i << "] div factor - random integer --> " << arr.arrFactor[i] << " - " << num << endl;
			local = arr.arrFactor[i] - num;
			cout << "  in scope object div factor = " << local << endl;
			
			
		}

		cout << endl;
		cout << "Subtracting an unsigned int from a range object" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- object [" << i << "] div factors - random integer --> [" << arr.arrRange[i] << "] - " << num << endl;
			rObject = arr.arrRange[i] - num;
			cout << "  in scope object div factors = " << "[" << rObject << "]" << endl;


		}


		cout << endl;
		cout << "Subtract a factor object from an unsigned int" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- random integer - " << "object [" << i << "] div factor --> " << num << " - " << arr.arrFactor[i] << endl;
			local = num - arr.arrFactor[i];
			cout << "  in scope object div factor = " << local << endl;
		}

		cout << endl;
		cout << "Subtract a range object from an unsigned int" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- random integer - " << "object [" << i << "] div factors --> " << num << " - [" << arr.arrRange[i] <<"]" << endl;
			rObject = num - arr.arrRange[i];
			cout << "  in scope object div factors = " << "[" << rObject << "]" << endl;
		}



		cout << endl;
		cout << "Multiply two factor objects" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			if (i < DEFAULT_ARR_SIZE - 1)
			{
				cout << "- object [" << i << "] * object[" << i + 1 << "] --> " << arr.arrFactor[i] << " * " << arr.arrFactor[i + 1] << endl;
				local = arr.arrFactor[i] * arr.arrFactor[i + 1];
				cout << "  in scope object div factor = " << local << endl;
			}
			else
			{
				cout << "- object [" << i << "] * object[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrFactor[i] << " * " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
				local = arr.arrFactor[i] * arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
				cout << "  in scope object div factor = " << local << endl;
			}
		}

		cout << endl;
		cout << "Multiply two range objects" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			if (i < DEFAULT_ARR_SIZE - 1)
			{
				cout << "- object [" << i << "] * object[" << i + 1 << "] --> [" << arr.arrRange[i] << "] * [" << arr.arrRange[i + 1] << "]" << endl;
				rObject = arr.arrRange[i] * arr.arrRange[i + 1];
				cout << "  in scope object div factors = " << "[" << rObject << "]" << endl;
			}
			else
			{
				cout << "- object [" << i << "] * object[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> [" << arr.arrRange[i] << "] * [" << arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] <<"]" << endl;
				rObject = arr.arrRange[i] * arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
				cout << "  in scope object div factors = " << "[" << rObject << "]" << endl;
			}
		}



		cout << endl;
		cout << "Multiply a factor object to an unsigned int" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- object [" << i << "] div factor * random integer --> " << arr.arrFactor[i] << " * " << num << endl;
			local =	arr.arrFactor[i] * num;
			cout << "  in scope object div factor = " << local << endl;
		}


		cout << endl;
		cout << "Multiply a range object to an unsigned int" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "random number " << num << endl;
			cout << "range factors " << arr.arrRange[i] << endl;
			cout << "- object [" << i << "] div factors * random integer --> [" << arr.arrRange[i] << "] * " << num << endl;
			rObject = arr.arrRange[i] * num;
			cout << "  in scope object div factors = " << "[" << rObject << "]" << endl;
		}


		cout << endl;
		cout << "Multiply an unsigned int to a factor object" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- random integer * " << "object [" << i << "] div factor --> " << num << " * " << arr.arrFactor[i] << endl;
			fTest = num * arr.arrFactor[i];
			cout << "  in scope returned object div factor = " << fTest << endl;
		}

		cout << endl;
		cout << "Integer division with two factor objects" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			if (i < DEFAULT_ARR_SIZE - 1)
			{
				cout << "- object [" << i << "] / object[" << i + 1 << "] --> " << arr.arrFactor[i] << " / " << arr.arrFactor[i + 1] << endl;
				fTest = arr.arrFactor[i] / arr.arrFactor[i + 1];
				cout << "  in scope object [" << i << "] updated div factor = " << fTest << endl;
			}
			else
			{
				cout << "- object [" << i << "] / object[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrFactor[i] << " / " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			  fTest =	arr.arrFactor[i] / arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
				cout << "  in scope object [" << i << "] updated div factor = " << fTest << endl;
			}
		}

		cout << endl;
		cout << "Integer division of a factor object by an unsigned int" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- object [" << i << "] div factor / random integer --> " << arr.arrFactor[i] << " / " << num << endl;
			fTest = arr.arrFactor[i] / num;
			cout << "  in scope object [" << i << "] updated div factor = " << fTest << endl;
		}

		cout << endl;
		cout << "Integer division of an unsigned int by an object" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- random integer / " << "object [" << i << "] div factor --> " << num << " / " << arr.arrFactor[i] << endl;
			fTest = num / arr.arrFactor[i];
			cout << "  in scope returned object div factor = " << fTest << endl;
		}

		cout << endl;
		cout << "Integer modulus with two factor objects" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			if (i < DEFAULT_ARR_SIZE - 1)
			{
				cout << "- object [" << i << "] % object[" << i + 1 << "] --> " << arr.arrFactor[i] << " % " << arr.arrFactor[i + 1] << endl;
				fTest = arr.arrFactor[i] % arr.arrFactor[i + 1];
				cout << "  in scope object [" << i << "] updated div factor = " << fTest << endl;
			}
			else
			{
				cout << "- object [" << i << "] % object[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrFactor[i] << " % " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
				fTest = arr.arrFactor[i] % arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
				cout << "  in scope object [" << i << "] updated div factor = " << fTest << endl;
			}
		}

		cout << endl;
		cout << "Integer modulus of a factor object by an unsigned int" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- object [" << i << "] div factor % random integer --> " << arr.arrFactor[i] << " % " << num << endl;
			fTest = arr.arrFactor[i] % num;
			cout << "  in scope object [" << i << "] updated div factor = " << fTest << endl;
		}

		cout << endl;
		cout << "Integer modulus of an unsigned int by an object" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- random integer % " << "object [" << i << "] div factor --> " << num << " % " << arr.arrFactor[i] << endl;
			fTest = num % arr.arrFactor[i];
			cout << "  in scope returned object div factor = " << fTest << endl;
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
	cout << "Determine two range objects factor values equal each other using '==' operator" << endl;

	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- range [" << i << "] factor values =  " << arr.arrRange[i] << endl;
			cout << "- range [" << i + 1 << "] factor values = " << arr.arrRange[i + 1] << endl;
			if (arr.arrRange[i] == arr.arrRange[i + 1])
			{
				cout << " range objects have same factor values" << endl;
			}
			else
			{
				cout << " range objects dont have same factor values" << endl;
			}
		}
		else
		{
			cout << "- range [" << i << "] factor values = " << arr.arrRange[i] << endl;
			cout << "- range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] factor values = " << arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			if (arr.arrRange[i] == arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " range objects have same factor values" << endl;
			}
			else
			{
				cout << " range objects dont have same factor values" << endl;
			}
		}
	}




	cout << endl;
	cout << "Determine one range factor values are less than another using '<' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- range [" << i << "] factor values = " << arr.arrRange[i] << endl;
			cout << "- range [" << i + 1 << "] factor values = " << arr.arrRange[i + 1] << endl;
			if (arr.arrRange[i] < arr.arrRange[i + 1])
			{
				cout << " range [" << i << "] both values are less than range [" << i + 1 << "]" << endl;
			}
			else
			{
				cout << " range [" << i << "] both values are NOT less than range [" << i + 1 << "]" << endl;
			}

		}
		else
		{
			cout << "- range [" << i << "] factor values = " << arr.arrRange[i] << endl;
			cout << "- range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] factor values = " << arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			if (arr.arrRange[i] < arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " range [" << i << "] both values are less than range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}
			else
			{
				cout << " range [" << i << "] both values are NOT less than range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}

		}
	}

	cout << endl;
	cout << "Determine one range factor values are greater than another using '>' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- range [" << i << "] factor values = " << arr.arrRange[i] << endl;
			cout << "- range [" << i + 1 << "] factor values = " << arr.arrRange[i + 1] << endl;
			if (arr.arrRange[i] > arr.arrRange[i + 1])
			{
				cout << " range [" << i << "] both values are greater than range [" << i + 1 << "]" << endl;
			}
			else
			{
				cout << " range [" << i << "] both values are NOT greater than range [" << i + 1 << "]" << endl;
			}

		}
		else
		{
			cout << "- range [" << i << "] factor values = " << arr.arrRange[i] << endl;
			cout << "- range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] factor values = " << arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			if (arr.arrRange[i] > arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " range [" << i << "] both values are greater than range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}
			else
			{
				cout << " range [" << i << "] both values are NOT greater than range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}

		}
	}

	cout << endl;
	cout << "Determine two range factor values are not equal using '!=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- range [" << i << "] factor values = " << arr.arrRange[i] << endl;
			cout << "- range [" << i + 1 << "] factor values = " << arr.arrRange[i + 1] << endl;
			if (arr.arrRange[i] != arr.arrRange[i + 1])
			{
				cout << " range [" << i << "] both values are NOT equals to range [" << i + 1 << "]" << endl;
			}
			else
			{
				cout << " range [" << i << "] both values are equals range [" << i + 1 << "]" << endl;
			}

		}
		else
		{
			cout << "- range [" << i << "] factor values = " << arr.arrRange[i] << endl;
			cout << "- range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] factor values = " << arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			if (arr.arrRange[i] != arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " range [" << i << "] both values are NOT equals to range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}
			else
			{
				cout << " range [" << i << "] both values are equals to range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}

		}
	}


	cout << endl;
	cout << "Determine two range factors are less than or equal using '<=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- range [" << i << "] factor values = " << arr.arrRange[i] << endl;
			cout << "- range [" << i + 1 << "] factor values = " << arr.arrRange[i + 1] << endl;
			if (arr.arrRange[i] <= arr.arrRange[i + 1])
			{
				cout << " range [" << i << "] both values are less than or equal to range [" << i + 1 << "]" << endl;
			}
			else
			{
				cout << " range [" << i << "] both values are NOT less than or equals to range [" << i + 1 << "]" << endl;
			}
		}
		else
		{
			cout << "- range [" << i << "] factor values = " << arr.arrRange[i] << endl;
			cout << "- range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] factor values = " << arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			if (arr.arrRange[i] <= arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " range [" << i << "] both values are less than or equal to range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}
			else
			{
				cout << " range [" << i << "] both values are NOT less than or equal to range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}
		}
	}

	cout << endl;
	cout << "Determine two range factors are greater than or equal using '>=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- range [" << i << "] factor values = " << arr.arrRange[i] << endl;
			cout << "- range [" << i + 1 << "] factor values = " << arr.arrRange[i + 1] << endl;
			if (arr.arrRange[i] >= arr.arrRange[i + 1])
			{
				cout << " range [" << i << "] both values are greater than or equal to range [" << i + 1 << "]" << endl;
			}
			else
			{
				cout << " range [" << i << "]  both values are NOT greater than or equal to range [" << i + 1 << "]" << endl;
			}
		}
		else
		{
			cout << "- range [" << i << "] factor values = " << arr.arrRange[i] << endl;
			cout << "- range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] factor values = " << arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			if (arr.arrRange[i] >= arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " range [" << i << "] both values are greater than or equal to range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}
			else
			{
				cout << " range [" << i << "] both values are NOT greater than or equal to range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}
		}
	}

	cout << endl;
	cout << "Determine one div factor is less than another div factor using '<' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- factor [" << i << "] div value = " << arr.arrFactor[i] << endl;
			cout << "- factor [" << i + 1 << "] div value = " << arr.arrFactor[i + 1] << endl;
			if (arr.arrFactor[i] < arr.arrFactor[i + 1])
			{
				cout << " factor [" << i << "] div value is less than factor [" << i + 1 << "] div value" << endl;
			}
			else
			{
				cout << " factor [" << i << "] div value is NOT less than factor [" << i + 1 << "] div value" << endl;
			}
		
		}
		else
		{
			cout << "- factor [" << i << "] div value = " << arr.arrFactor[i] << endl;
			cout << "- factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div value = " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			if (arr.arrFactor[i] < arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " factor [" << i << "] div value is less than factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div value" << endl;
			}
			else
			{
				cout << " factor [" << i << "] div value is NOT less than factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div value" << endl;
			}
		
		}
	}

	cout << endl;
	cout << "Determine one object div factor is greater than another div factor using '>' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- factor [" << i << "] div value = " << arr.arrFactor[i] << endl;
			cout << "- factor [" << i + 1 << "] div value = " << arr.arrFactor[i + 1] << endl;
			if (arr.arrFactor[i] > arr.arrFactor[i + 1])
			{
				cout << " factor [" << i << "] div factor is greater than factor [" << i + 1 << "] div value" << endl;
			}
			else
			{
				cout << " factor [" << i << "] div value is NOT greater than factor [" << i + 1 << "] div value" << endl;
			}

		}
		else
		{
			cout << "- factor [" << i << "] div value = " << arr.arrFactor[i] << endl;
			cout << "- factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div value = " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			if (arr.arrFactor[i] > arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " factor [" << i << "] div value is greater than factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div value" << endl;
			}
			else
			{
				cout << " factor [" << i << "] div value is NOT greater than factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div value" << endl;
			}

		}
	}

	cout << endl;
	cout << "Determine two objects div factor are not equals to each other using '!=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- factor [" << i << "] div value = " << arr.arrFactor[i] << endl;
			cout << "- factor [" << i + 1 << "] div value = " << arr.arrFactor[i + 1] << endl;
			if (arr.arrFactor[i] != arr.arrFactor[i + 1])
			{
				cout << " factor [" << i << "] div factor is NOT equals to factor [" << i + 1 << "] div value" << endl;
			}
			else
			{
				cout << " factor [" << i << "] div factor is equals factor [" << i + 1 << "] div value" << endl;
			}

		}
		else
		{
			cout << "- factor [" << i << "] div value = " << arr.arrFactor[i] << endl;
			cout << "- factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div value = " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			if (arr.arrFactor[i] != arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " factor [" << i << "] div value is NOT equals to factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div value" << endl;
			}
			else
			{
				cout << " factor [" << i << "] div value is equals to factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div value" << endl;
			}

		}
	}

	cout << endl;
	cout << "Determine one object div factor is less than or equals to the other using '<=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- factor [" << i << "] div value = " << arr.arrFactor[i] << endl;
			cout << "- factor [" << i + 1 << "] div value = " << arr.arrFactor[i + 1] << endl;
			if (arr.arrFactor[i] <= arr.arrFactor[i + 1])
			{
				cout << " factor [" << i << "] div value is less than or equals to factor [" << i + 1 << "] div value" << endl;
			}
			else
			{
				cout << " factor [" << i << "] div value is NOT less than or equals to factor [" << i + 1 << "] div value" << endl;
			}

		}
		else
		{
			cout << "- factor [" << i << "] div value = " << arr.arrFactor[i] << endl;
			cout << "- factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div value = " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			if (arr.arrFactor[i] <= arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " factor [" << i << "] div value is less than or equals to factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div value" << endl;
			}
			else
			{
				cout << " factor [" << i << "] div value is NOT less than or equals to factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div value" << endl;
			}
		}
	}

	cout << endl;
	cout << "Determine one object div factor is greater than or equals to the other using '>=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- factor [" << i << "] div value = " << arr.arrFactor[i] << endl;
			cout << "- factor [" << i + 1 << "] div value = " << arr.arrFactor[i + 1] << endl;
			if (arr.arrFactor[i] >= arr.arrFactor[i + 1])
			{
				cout << " factor [" << i << "] div value is greater than or equals to factor [" << i + 1 << "] div value" << endl;
			}
			else
			{
				cout << " factor [" << i << "] div value is NOT greater than or equals to factor [" << i + 1 << "] div value" << endl;
			}

		}
		else
		{
			cout << "- factor [" << i << "] div value = " << arr.arrFactor[i] << endl;
			cout << "- factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div value = " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			if (arr.arrFactor[i] >= arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " factor [" << i << "] div value is greater than or equals to factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div value" << endl;
			}
			else
			{
				cout << " factor [" << i << "] div value is NOT greater than or equals to factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] div value" << endl;
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
		cout << "- factor [" << i << "] current div value = " << arr.arrFactor[i];
		cout << ", call ++object[" << i <<"]" << endl;
		cout << "  in scope returned div factor = " << ++arr.arrFactor[i] << endl;
	}
	cout << endl;
	cout << "Post increment factor objects using 'object++' operator" << endl;

	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		cout << "- factor [" << i << "] current div value = " << arr.arrFactor[i];
		cout << ", call object[" << i << "]++" << endl;
		cout << "  in scope returned div factor = " << arr.arrFactor[i]++ << endl;
	}

	cout << endl;
	cout << "Pre decrement factor objects using '--object' operator" << endl;

	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		cout << "- factor [" << i << "] current div value = " << arr.arrFactor[i];
		cout << ", call --object[" << i << "]" << endl;
		cout << "  in scope returned div factor = " << --arr.arrFactor[i] << endl;
	}

	cout << endl;
	cout << "Post decrement factor objects using 'object--' operator" << endl;

	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		cout << "- factor [" << i << "] current div value = " << arr.arrFactor[i];
		cout << ", call object[" << i << "]--" << endl;
		cout << "  in scope returned div value = " << arr.arrFactor[i]-- << endl;
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
			cout << "- factor [" << i << "] += object[" << i + 1 << "] --> " << arr.arrFactor[i] << " += " << arr.arrFactor[i + 1] << endl;
			arr.arrFactor[i] += arr.arrFactor[i + 1];
			cout << "  in scope factor [" << i << "] updated div value = " << arr.arrFactor[i] << endl;
		}
		else
		{
			cout << "- factor [" << i << "] += factor[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrFactor[i] << " += " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			arr.arrFactor[i] += arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
			cout << "  in scope factor [" << i << "] updated div value = " << arr.arrFactor[i] << endl;
		}
	}

	cout << endl;
	cout << "Add a factor object with an unsigned int using '+=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- factor [" << i << "] div value +=  random integer --> " << arr.arrFactor[i] << " += " << num << endl;
		arr.arrFactor[i] += num;
		cout << "  in scope factor [" << i << "] updated div value = " << arr.arrFactor[i] << endl;
	}

	cout << endl;
	cout << "Subtract two factor objects using '-=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- factor [" << i << "] -= factor[" << i + 1 << "] --> " << arr.arrFactor[i] << " -= " << arr.arrFactor[i + 1] << endl;
			arr.arrFactor[i] -= arr.arrFactor[i + 1];
			cout << "  in scope factor [" << i << "] updated div value = " << arr.arrFactor[i] << endl;
		}
		else
		{
			cout << "- factor [" << i << "] -= factor[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrFactor[i] << " -= " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			arr.arrFactor[i] -= arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
			cout << "  in scope factor [" << i << "] updated div value = " << arr.arrFactor[i] << endl;
		}
	}

	cout << endl;
	cout << "Subtract an unsigned int from a factor object using '-=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- factor [" << i << "] div value -=  random integer --> " << arr.arrFactor[i] << " -= " << num << endl;
		arr.arrFactor[i] -= num;
		cout << "  in scope factor [" << i << "] updated div value = " << arr.arrFactor[i] << endl;
	}


	cout << endl;
	cout << "Multiply two factor objects using '*=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- factor [" << i << "] *= factor[" << i + 1 << "] --> " << arr.arrFactor[i] << " *= " << arr.arrFactor[i + 1] << endl;
			arr.arrFactor[i] *= arr.arrFactor[i + 1];
			cout << "  in scope factor [" << i << "] updated div value = " << arr.arrFactor[i] << endl;
		}
		else
		{
			cout << "- factor [" << i << "] *= factor[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrFactor[i] << " *= " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			arr.arrFactor[i] *= arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
			cout << "  in scope factor [" << i << "] updated div value = " << arr.arrFactor[i] << endl;
		}
	}

	cout << endl;
	cout << "Multiply a factor object with an unsigned int using '*=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- factor [" << i << "] div value *=  random integer --> " << arr.arrFactor[i] << " *= " << num << endl;
		arr.arrFactor[i] *= num;
		cout << "  in scope factor [" << i << "] updated div value = " << arr.arrFactor[i] << endl;
	}

	cout << endl;
	cout << "Integer division with two factor objects using '/=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- factor [" << i << "] /= factor[" << i + 1 << "] --> " << arr.arrFactor[i] << " /= " << arr.arrFactor[i + 1] << endl;
			arr.arrFactor[i] /= arr.arrFactor[i + 1];
			cout << "  in scope factor [" << i << "] updated div value = " << arr.arrFactor[i] << endl;
		}
		else
		{
			cout << "- factor [" << i << "] /= factor[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrFactor[i] << " /= " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			arr.arrFactor[i] /= arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
			cout << "  in scope object [" << i << "] updated div value = " << arr.arrFactor[i] << endl;
		}
	}


	cout << endl;
	cout << "Integer division of a factor object by an unsigned int using '/=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- factor [" << i << "] div value /=  random integer --> " << arr.arrFactor[i] << " /= " << num << endl;
		arr.arrFactor[i] /= num;
		cout << "  in scope object [" << i << "] updated div value = " << arr.arrFactor[i] << endl;
	}

	cout << endl;
	cout << "Integer modulus with two factor objects using '%=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- factor [" << i << "] %= factor[" << i + 1 << "] --> " << arr.arrFactor[i] << " %= " << arr.arrFactor[i + 1] << endl;
			arr.arrFactor[i] %= arr.arrFactor[i + 1];
			cout << "  in scope object [" << i << "] updated div value = " << arr.arrFactor[i] << endl;
		}
		else
		{
			cout << "- factor [" << i << "] %= object[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrFactor[i] << " %= " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			arr.arrFactor[i] %= arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
			cout << "  in scope object [" << i << "] updated div value = " << arr.arrFactor[i] << endl;
		}
	}

	cout << endl;
	cout << "Integer modulus of a factor object by an unsigned int using '%=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- factor [" << i << "] div value %=  random integer --> " << arr.arrFactor[i] << " %= " << num << endl;
		arr.arrFactor[i] %= num;
		cout << "  in scope object [" << i << "] updated div value = " << arr.arrFactor[i] << endl;
	}

	cout << ASTERISK + "End Test Overloaded Compound Assignment Operators " + ASTERISK << endl;
}