/*
Developers: Don Dang


*/


#include "factor.h"
#include "range.h"
#include <iostream>
#include <cstdlib>

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
	cout << ASTERISK + "Begin test number is a multiplier of encapsulated value" + ASTERISK << endl;
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
	cout << ASTERISK + "test number is a multiplier of encapsulated value" + ASTERISK << endl;
}

void TestOverloaded_StreamIO_Operators(Arrays arr)
{
	cout << endl;
	cout << ASTERISK + "Begin Test Overloaded Stream I/O Operators " + ASTERISK << endl;
	cout << " - Print encapsulated values" << endl;

	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		cout << i + 1 << ") factor object[" << i << "] encapsulated value = " << arr.arrFactor[i] << endl;
		cout << i + 1 << ") range object[" << i << "] encapsulated values = [" << arr.arrRange[i] <<"]" << endl;

		cout << endl;
	}

	cout << ASTERISK + "End Test Overloaded Stream I/O Operators" + ASTERISK << endl;
}

void TestOverloadedMathematicalOperators(Arrays arr)
{
	srand(static_cast<unsigned>(time(0)));
	int num;
	factor fObject;
	range rObject;

	cout << endl;
	cout << ASTERISK + "Begin Test Overloaded Mathematical Operators " + ASTERISK << endl;

	cout << "Adding two factor objects" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- object [" << i << "] + object[" << i + 1 << "] --> " << arr.arrFactor[i] << " + " << arr.arrFactor[i + 1] << endl;
			fObject = arr.arrFactor[i] + arr.arrFactor[i + 1];
			cout << "  in scope encapsulated value = " << fObject << endl;
		}
		else
		{
			cout << "- object [" << i << "] + object[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrFactor[i] << " + " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			
			fObject = arr.arrFactor[i] + arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
			cout << "  in scope encapsulated value = " << fObject << endl;
		}
	}

		cout << endl;
		cout << "Adding a factor object to a random unsigned integer" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- object [" << i << "] encapsulated value +  random integer --> " << arr.arrFactor[i] << " + " << num << endl;
			fObject = arr.arrFactor[i] + num;
			cout << "  in scope encapsulated value = " << fObject << endl;
		}

		cout << endl;
		cout << "Adding a range object to a random unsigned integer" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- object [" << i << "] encapsulated values +  random integer --> " << "[" << arr.arrRange[i] << "]" << " + " << num << endl;
			rObject = arr.arrRange[i] + num;
			cout << "  in scope encapsulated values = " << "[" << rObject << "]" << endl;
		}


		/*cout << endl;
		cout << "Adding a random unsigned integer to a factor object" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- random integer + " << "object [" << i << "] encapsulated value --> " << num << " + " << arr.arrFactor[i] << endl;
			fObject = num + arr.arrFactor[i];
			cout << "  in scope encapsulated value = " << fObject << endl;
		}*/


		/*cout << endl;
		cout << "Adding a random unsigned integer to a range object" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- random integer + " << "object [" << i << "] encapsulated values --> " << num << " + [" << arr.arrRange[i] <<"]" << endl;
			rObject = num + arr.arrRange[i];
			cout << "  in scope encapsulated values = " << "[" << rObject << "]" << endl;
		}*/

		cout << endl;
		cout << "Subtracting two factor objects" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			if (i < DEFAULT_ARR_SIZE - 1)
			{
				cout << "- object [" << i << "] - object[" << i + 1 << "] --> " << arr.arrFactor[i] << " - " << arr.arrFactor[i + 1] << endl;
				fObject = arr.arrFactor[i] - arr.arrFactor[i + 1];
				cout << "  in scope encapsulated value = " << fObject << endl;
			}
			else
			{
				cout << "- object [" << i << "] - object[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrFactor[i] << " - " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
				fObject =	arr.arrFactor[i] - arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
				cout << "  in scope encapsulated value = " << fObject << endl;
			}
		}

		cout << endl;
		cout << "Subtracting an unsigned int from a factor object" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- object [" << i << "] encapsulated value - random integer --> " << arr.arrFactor[i] << " - " << num << endl;
			fObject = arr.arrFactor[i] - num;
			cout << "  in scope encapsulated value = " << fObject << endl;
		
		}

		cout << endl;
		cout << "Subtracting an unsigned int from a range object" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- object [" << i << "] encapsulated values - random integer --> [" << arr.arrRange[i] << "] - " << num << endl;
			rObject = arr.arrRange[i] - num;
			cout << "  in scope encapsulated values = " << "[" << rObject << "]" << endl;
		}


		/*cout << endl;
		cout << "Subtract a factor object from an unsigned int" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- random integer - " << "object [" << i << "] encapsulated value --> " << num << " - " << arr.arrFactor[i] << endl;
			fObject = num - arr.arrFactor[i];
			cout << "  in scope encapsulated value = " << fObject << endl;
		}*/

		//cout << endl;
		//cout << "Subtract a range object from an unsigned int" << endl;
		//for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		//{
		//	num = rand() % RAN_MAX + RAN_MIN;
		//	cout << "- random integer - " << "object [" << i << "] encapsulated values --> " << num << " - [" << arr.arrRange[i] <<"]" << endl;
		//	rObject = num - arr.arrRange[i];
		//	cout << "  in scope encapsulated values = " << "[" << rObject << "]" << endl;
		//}


		cout << endl;
		cout << "Multiply two factor objects" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			if (i < DEFAULT_ARR_SIZE - 1)
			{
				cout << "- object [" << i << "] * object[" << i + 1 << "] --> " << arr.arrFactor[i] << " * " << arr.arrFactor[i + 1] << endl;
				fObject = arr.arrFactor[i] * arr.arrFactor[i + 1];
				cout << "  in scope encapsulated value = " << fObject << endl;
			}
			else
			{
				cout << "- object [" << i << "] * object[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrFactor[i] << " * " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
				fObject = arr.arrFactor[i] * arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
				cout << "  in scope encapsulated value = " << fObject << endl;
			}
		}

		cout << endl;
		cout << "Multiply a factor object to an unsigned int" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- object [" << i << "] encapsulated value * random integer --> " << arr.arrFactor[i] << " * " << num << endl;
			fObject =	arr.arrFactor[i] * num;
			cout << "  in scope encapsulated value = " << fObject << endl;
		}

		/*cout << endl;
		cout << "Multiply an unsigned int to a factor object" << endl;
		for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
		{
			num = rand() % RAN_MAX + RAN_MIN;
			cout << "- random integer * " << "object [" << i << "] encapsulated value --> " << num << " * " << arr.arrFactor[i] << endl;
			fObject = num * arr.arrFactor[i];
			cout << "  in scope encapsulated value = " << fObject << endl;
		}*/

	cout << ASTERISK + "End Test Overloaded Mathematical Operators" + ASTERISK << endl;
}

void TestOverloadedRelationalOperators(Arrays arr)
{
	int num;

	cout << endl;
	cout << ASTERISK + "Begin Test Overloaded Relational Operators " + ASTERISK << endl;

	cout << "Determine two factor objects are equals to each other using '==' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- object [" << i << "] encapsulated value = " << arr.arrFactor[i] << endl;
			cout << "- object [" << i + 1 << "] encapsulated value = " << arr.arrFactor[i + 1] << endl;
			if (arr.arrFactor[i] == arr.arrFactor[i + 1])
			{
				cout << " object encapsulated values are the same" << endl;
			}
			else
			{
				cout << " object encapsulated values are NOT the same" << endl;
			}
		}
		else
		{
			cout << "- object [" << i << "] encapsulated value = " << arr.arrFactor[i] << endl;
			cout << "- object [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] encapsulated value = " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			if (arr.arrFactor[i] == arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " object encapsulated values are the same" << endl;
			}
			else
			{
				cout << " object encapsulated values are NOT the same" << endl;
			}
		}
	}

	cout << endl;
	cout << "Determine two range objects are equal each other using '==' operator" << endl;

	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- range [" << i << "] encapsulated values =  [" << arr.arrRange[i] << "]" << endl;
			cout << "- range [" << i + 1 << "] encapsulated values = [" << arr.arrRange[i + 1] << "]" << endl;
			if (arr.arrRange[i] == arr.arrRange[i + 1])
			{
				cout << " objects have same encapsulated values" << endl;
			}
			else
			{
				cout << " objects DON'T have same encapsulated values" << endl;
			}
		}
		else
		{
			cout << "- range [" << i << "] encapsulated values = " << arr.arrRange[i] << endl;
			cout << "- range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] encapsulated values = " << arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			if (arr.arrRange[i] == arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " objects have same encapsulated values" << endl;
			}
			else
			{
				cout << " objects DON'T have same encapsulated values" << endl;
			}
		}
	}


	cout << endl;
	cout << "Determine a factor object equals an unsigned int using '==' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- object [" << i << "] encapsulated value == random integer --> " << arr.arrFactor[i] << " == " << num << endl;
		if (arr.arrFactor[i] == num )
		{
			cout << " object encapsulated value equals number" << endl;
		}
		else
		{
			cout << " object encapsulated value doesn't equal number" << endl;
		}
	}

	cout << endl;
	cout << "Determine a range object equals an unsigned int using '==' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- object [" << i << "] encapsulated values == random integer --> [" << arr.arrRange[i] << "] == " << num << endl;
		if (arr.arrRange[i] == num)
		{
			cout << " object encapsulated values equal number" << endl;
		}
		else
		{
			cout << " object encapsulated values don't equal number" << endl;
		}
	}


	cout << endl;
	cout << "Determine an unsigned int equals a factor object using '==' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- random integer == " << " object [" << i << "] encapsulated value --> " << num <<" == " << arr.arrFactor[i] << endl;
		if (num == arr.arrFactor[i])
		{
			cout << " object encapsulated value equals number" << endl;
		}
		else
		{
			cout << " object encapsulated value doesn't equal number" << endl;
		}
	}

	cout << endl;
	cout << "Determine an unsigned int equals a range object using '==' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- random integer == " << " object [" << i << "] encapsulated value --> " << num << " == [" << arr.arrRange[i] << "]" << endl;
		if (num == arr.arrRange[i])
		{
			cout << " number doesn't equal to encapsulated values" << endl;
		}
		else
		{
			cout << " number equals to encapsulated values" << endl;
		}
	}


	cout << endl;
	cout << "Determine one factor object is less than another factor object using '<' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- factor [" << i << "] encapsulated value = " << arr.arrFactor[i] << endl;
			cout << "- factor [" << i + 1 << "] encapsulated value = " << arr.arrFactor[i + 1] << endl;
			if (arr.arrFactor[i] < arr.arrFactor[i + 1])
			{
				cout << " factor [" << i << "] encapsulated value is less than factor [" << i + 1 << "]" << endl;
			}
			else
			{
				cout << " factor [" << i << "] encapsulated value is NOT less than factor [" << i + 1 << "]" << endl;
			}

		}
		else
		{
			cout << "- factor [" << i << "] encapsulated value = " << arr.arrFactor[i] << endl;
			cout << "- factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] encapsulated value = " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			if (arr.arrFactor[i] < arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " factor [" << i << "] encapsulated value is less than factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}
			else
			{
				cout << " factor [" << i << "] encapsulated value is NOT less than factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}

		}
	}

	cout << endl;
	cout << "Determine one range object is less than another range object using '<' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- range [" << i << "] encapsulated values = [" << arr.arrRange[i] <<"]" << endl;
			cout << "- range [" << i + 1 << "] encapsulated values = [" << arr.arrRange[i + 1] <<"]" << endl;
			if (arr.arrRange[i] < arr.arrRange[i + 1])
			{
				cout << " range [" << i << "] encapsulated values are less than range [" << i + 1 << "]" << endl;
			}
			else
			{
				cout << " range [" << i << "] encapsulated values are NOT less than range [" << i + 1 << "]" << endl;
			}

		}
		else
		{
			cout << "- range [" << i << "] factor values = " << arr.arrRange[i] << endl;
			cout << "- range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] encapsulated values = " << arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			if (arr.arrRange[i] < arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " range [" << i << "] encapsulated values are less than range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}
			else
			{
				cout << " range [" << i << "] encapsulated values are NOT less than range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}

		}
	}


	cout << endl;
	cout << "Determine a factor object is less than an unsigned int using '<' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- object [" << i << "] encapsulated value < random integer --> " << arr.arrFactor[i] << " < " << num << endl;
		if (arr.arrFactor[i] < num)
		{
			cout << " encapsulated value is less than number" << endl;
		}
		else
		{
			cout << " encapsulated value is NOT less than number" << endl;
		}
	}


	cout << endl;
	cout << "Determine a range object is less than an unsigned int using '<' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- object [" << i << "] encapsulated value < random integer --> [" << arr.arrRange[i] << "] < " << num << endl;
		if (arr.arrRange[i] < num)
		{
			cout << " encapsulated values are less than number" << endl;
		}
		else
		{
			cout << " encapsulated values are NOT less than number" << endl;
		}
	}

	cout << endl;
	cout << "Determine an unsigned int is less than a factor object using '<' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- random integer < object [" << i << "] encapsulated value--> " << num << " < " << arr.arrFactor[i] << endl;
		if (num < arr.arrFactor[i])
		{
			cout << " number is less than encapsulated value" << endl;
		}
		else
		{
			cout << "number is NOT less than encapsulated value" << endl;
		}
	}

	cout << endl;
	cout << "Determine an unsigned int is less than a range object using '<' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- random integer < object [" << i << "] encapsulated values --> " << num << " < [" << arr.arrRange[i] <<"]" << endl;
		if (num < arr.arrRange[i])
		{
			cout << " number is less than encapsulated values" << endl;
		}
		else
		{
			cout << "number is NOT less than encapsulated values" << endl;
		}
	}
	


	cout << endl;
	cout << "Determine one factor is greater than another factor object using '>' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- factor [" << i << "] encapsulated value = " << arr.arrFactor[i] << endl;
			cout << "- factor [" << i + 1 << "] encapsulated value = " << arr.arrFactor[i + 1] << endl;
			if (arr.arrFactor[i] > arr.arrFactor[i + 1])
			{
				cout << " factor [" << i << "] encapsulated value is greater than factor [" << i + 1 << "]" << endl;
			}
			else
			{
				cout << " factor [" << i << "] encapsulated value is NOT greater than factor [" << i + 1 << "]" << endl;
			}

		}
		else
		{
			cout << "- factor [" << i << "] encapsulated value = " << arr.arrFactor[i] << endl;
			cout << "- factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] encapsulated value = " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			if (arr.arrFactor[i] > arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " factor [" << i << "] encapsulated value is greater than factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}
			else
			{
				cout << " factor [" << i << "] encapsulated value is NOT greater than factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}

		}
	}

	cout << endl;
	cout << "Determine one range object is greater than another range object using '>' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- range [" << i << "] encapsulated values = [" << arr.arrRange[i] <<"]" << endl;
			cout << "- range [" << i + 1 << "] encapsulated values = [" << arr.arrRange[i + 1] <<"]" << endl;
			if (arr.arrRange[i] > arr.arrRange[i + 1])
			{
				cout << " range [" << i << "] encapsulated values are greater than range [" << i + 1 << "]" << endl;
			}
			else
			{
				cout << " range [" << i << "] encapsulated values are NOT greater than range [" << i + 1 << "]" << endl;
			}

		}
		else
		{
			cout << "- range [" << i << "] encapsulated values = [" << arr.arrRange[i] <<"]" << endl;
			cout << "- range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] encapsulated values = [" << arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] <<"]" << endl;
			if (arr.arrRange[i] > arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " range [" << i << "] encapsulated values are greater than range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}
			else
			{
				cout << " range [" << i << "] encapsulated values are NOT greater than range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}

		}
	}

	cout << endl;
	cout << "Determine a factor object is greater than an unsigned int using '>' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- object [" << i << "] encapsulated value > random integer --> " << arr.arrFactor[i] << " > " << num << endl;
		if (arr.arrFactor[i] > num)
		{
			cout << " encapsulated value is greater than number" << endl;
		}
		else
		{
			cout << " encapsulated value is NOT greater than number" << endl;
		}
	}

	cout << endl;
	cout << "Determine a range object is greater than an unsigned int using '>' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- object [" << i << "] encapsulated value > random integer --> [" << arr.arrRange[i] << "] > " << num << endl;
		if (arr.arrRange[i] > num)
		{
			cout << " encapsulated values are greater than number" << endl;
		}
		else
		{
			cout << " encapsulated values are NOT greater than number" << endl;
		}
	}

	cout << endl;
	cout << "Determine an unsigned int is greater than a factor object using '>' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- random integer < object [" << i << "] encapsulated value--> " << num << " > " << arr.arrFactor[i] << endl;
		if (num > arr.arrFactor[i])
		{
			cout << " number is greater than encapsulated value" << endl;
		}
		else
		{
			cout << "number is NOT greater than encapsulated value" << endl;
		}
	}

	cout << endl;
	cout << "Determine an unsigned int is greater than a range object using '>' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- random integer < object [" << i << "] encapsulated values--> " << num << " > [" << arr.arrRange[i] <<"]" << endl;
		if (num > arr.arrRange[i])
		{
			cout << " number is greater than encapsulated values" << endl;
		}
		else
		{
			cout << "number is NOT greater than encapsulated values" << endl;
		}
	}
	

	cout << endl;
	cout << "Determine two factor objects are not equal to each other using '!=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- factor [" << i << "] encapsulated value = " << arr.arrFactor[i] << endl;
			cout << "- factor [" << i + 1 << "] encapsulated value = " << arr.arrFactor[i + 1] << endl;
			if (arr.arrFactor[i] != arr.arrFactor[i + 1])
			{
				cout << " factor [" << i << "] encapsulated value is NOT equals to factor [" << i + 1 << "]" << endl;
			}
			else
			{
				cout << " factor [" << i << "] encapsulated value equals factor [" << i + 1 << "]" << endl;
			}

		}
		else
		{
			cout << "- factor [" << i << "] encapsulated value = " << arr.arrFactor[i] << endl;
			cout << "- factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] encapsulated value = " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			if (arr.arrFactor[i] != arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " factor [" << i << "] encapsulated value is NOT equals to factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}
			else
			{
				cout << " factor [" << i << "] encapsulated value is equal to factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}

		}
	}

	cout << endl;
	cout << "Determine two range objects are not equal to each other using '!=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- range [" << i << "] encapsulated values = [" << arr.arrRange[i] <<"]" << endl;
			cout << "- range [" << i + 1 << "] encapsulated values = [" << arr.arrRange[i + 1] <<"]" << endl;
			if (arr.arrRange[i] != arr.arrRange[i + 1])
			{
				cout << " range [" << i << "] encapsulated values are NOT equals to range [" << i + 1 << "]" << endl;
			}
			else
			{
				cout << " range [" << i << "] encapsulated values are equals range [" << i + 1 << "]" << endl;
			}

		}
		else
		{
			cout << "- range [" << i << "] encapsulated values = [" << arr.arrRange[i] <<"]" << endl;
			cout << "- range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] encapsulated values = [" << arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] <<"]" << endl;
			if (arr.arrRange[i] != arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " range [" << i << "] encapsulated values are NOT equals to range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}
			else
			{
				cout << " range [" << i << "] encapsulated values are equals to range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}

		}
	}


	cout << endl;
	cout << "Determine a factor object is not equal to an unsigned int using '!=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- object [" << i << "] encapsulated value != random integer --> " << arr.arrFactor[i] << " != " << num << endl;
		if (arr.arrFactor[i] != num)
		{
			cout << " encapsulated value is not equals to number" << endl;
		}
		else
		{
			cout << " encapsulated value is equal to number" << endl;
		}
	}

	cout << endl;
	cout << "Determine a range object is not equal to an unsigned int using '!=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- object [" << i << "] encapsulated values != random integer --> [" << arr.arrRange[i] << "] != " << num << endl;
		if (arr.arrRange[i] != num)
		{
			cout << " encapsulated values are not equals to number" << endl;
		}
		else
		{
			cout << " encapsulated values are equal to number" << endl;
		}
	}

	cout << endl;
	cout << "Determine an unsigned int is not equal to a factor object using '!=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- random integer < object [" << i << "] encapsulated value--> " << num << " != " << arr.arrFactor[i] << endl;
		if (num != arr.arrFactor[i])
		{
			cout << " number is not equals to encapsulated value" << endl;
		}
		else
		{
			cout << "number is equal to encapsulated value" << endl;
		}
	}

	cout << endl;
	cout << "Determine an unsigned int is not equal to a range object using '!=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- random integer < object [" << i << "] encapsulated value--> " << num << " != [" << arr.arrRange[i] <<"]" << endl;
		if (num != arr.arrRange[i])
		{
			cout << " number is not equals to encapsulated values" << endl;
		}
		else
		{
			cout << "number is equal to encapsulated values" << endl;
		}
	}

	

	cout << endl;
	cout << "Determine one factor object is less than or equals to another factor object using '<=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- factor [" << i << "] encapsulated value = " << arr.arrFactor[i] << endl;
			cout << "- factor [" << i + 1 << "] encapsulated value = " << arr.arrFactor[i + 1] << endl;
			if (arr.arrFactor[i] <= arr.arrFactor[i + 1])
			{
				cout << " factor [" << i << "] encapsulated valueis less than or equals to factor [" << i + 1 << "]" << endl;
			}
			else
			{
				cout << " factor [" << i << "] encapsulated value is NOT less than or equals to factor [" << i + 1 << "]" << endl;
			}

		}
		else
		{
			cout << "- factor [" << i << "] encapsulated value = " << arr.arrFactor[i] << endl;
			cout << "- factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] encapsulated value = " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			if (arr.arrFactor[i] <= arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " factor [" << i << "] encapsulated value is less than or equals to factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}
			else
			{
				cout << " factor [" << i << "] encapsulated value is NOT less than or equals to factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}
		}
	}

	cout << endl;
	cout << "Determine one range object encapsulated values are less than or equal to another range object using '<=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- range [" << i << "] encapsulated values = [" << arr.arrRange[i] <<"]" << endl;
			cout << "- range [" << i + 1 << "] encapsulated values = [" << arr.arrRange[i + 1] <<"]" << endl;
			if (arr.arrRange[i] <= arr.arrRange[i + 1])
			{
				cout << " range [" << i << "] encapsulated values are less than or equal to range [" << i + 1 << "]" << endl;
			}
			else
			{
				cout << " range [" << i << "] encapsulated values are NOT less than or equals to range [" << i + 1 << "]" << endl;
			}
		}
		else
		{
			cout << "- range [" << i << "] encapsulated values = " << arr.arrRange[i] << endl;
			cout << "- range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] factor values = " << arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			if (arr.arrRange[i] <= arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " range [" << i << "] encapsulated values are less than or equal to range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}
			else
			{
				cout << " range [" << i << "] encapsulated values are NOT less than or equal to range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}
		}
	}

	cout << endl;
	cout << "Determine a factor object encapsulated value is less than or equals to an unsigned int using '<=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- object [" << i << "] encapsulated value <= random integer --> " << arr.arrFactor[i] << " <= " << num << endl;
		if (arr.arrFactor[i] <= num)
		{
			cout << " encapsulated value is less than or equals to number" << endl;
		}
		else
		{
			cout << " encapsulated value is NOT less than or equals to number" << endl;
		}
	}

	cout << endl;
	cout << "Determine a range object encapsulated values are less than or equals to an unsigned int using '<=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- object [" << i << "] encapsulated value <= random integer --> [" << arr.arrRange[i] << "] <= " << num << endl;
		if (arr.arrRange[i] <= num)
		{
			cout << " encapsulated values are less than or equals to number" << endl;
		}
		else
		{
			cout << " encapsulated values are NOT less than or equals to number" << endl;
		}
	}


	cout << endl;
	cout 	<< "Determine an unsigned int is less than or equals to a factor object encapsulated value using '<=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- random integer <= object [" << i << "] encapsulated value--> " << num << " <= " << arr.arrFactor[i] << endl;
		if (num <= arr.arrFactor[i])
		{
			cout << " number is less than or equals to encapsulated value" << endl;
		}
		else
		{
			cout << "number is NOT less than or equals to encapsulated value" << endl;
		}
	}

	cout << endl;
	cout << "Determine an unsigned int is less than or equals to a range object encapsulated values using '<=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- random integer <= object [" << i << "] encapsulated value--> " << num << " <= [" << arr.arrRange[i] <<"]" << endl;
		if (num <= arr.arrRange[i])
		{
			cout << " number is less than or equals to encapsulated values" << endl;
		}
		else
		{
			cout << "number is NOT less than or equals to encapsulated values" << endl;
		}
	}
	
	cout << endl;
	cout << "Determine one factor object encapsulated value is greater than or equal to another factor object using  '>=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- factor [" << i << "] encapsulated value = " << arr.arrFactor[i] << endl;
			cout << "- factor [" << i + 1 << "] encapsulated value = " << arr.arrFactor[i + 1] << endl;
			if (arr.arrRange[i] >= arr.arrRange[i + 1])
			{
				cout << " factor [" << i << "] encapsulated value is greater than or equal to factor [" << i + 1 << "]" << endl;
			}
			else
			{
				cout << " factor [" << i << "] encapsulated value is NOT greater than or equal to factor [" << i + 1 << "]" << endl;
			}
		}
		else
		{
			cout << "- factor  [" << i << "] encapsulated value = " << arr.arrFactor[i] << endl;
			cout << "- factor  [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] encapsulated value = " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			if (arr.arrFactor[i] >= arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " factor  [" << i << "] encapsulated value is greater than or equal to factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}
			else
			{
				cout << " factor  [" << i << "] encapsulated value is NOT greater than or equal to factor [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}
		}
	}

	cout << endl;
	cout << "Determine one range object encapsulated values are greater than or equal to another range object using  '>=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- range [" << i << "] encapsulated values = " << arr.arrRange[i] << endl;
			cout << "- range [" << i + 1 << "] encapsulated values = " << arr.arrRange[i + 1] << endl;
			if (arr.arrRange[i] >= arr.arrRange[i + 1])
			{
				cout << " range [" << i << "] encapsulated values are greater than or equal to range [" << i + 1 << "]" << endl;
			}
			else
			{
				cout << " range [" << i << "] both values are NOT greater than or equal to range [" << i + 1 << "]" << endl;
			}
		}
		else
		{
			cout << "- range [" << i << "] encapsulated values = [" << arr.arrRange[i] <<"]" << endl;
			cout << "- range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] encapsulated values = [" << arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] <<"]" << endl;
			if (arr.arrRange[i] >= arr.arrRange[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE])
			{
				cout << " range [" << i << "] encapsulated values are greater than or equal to range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}
			else
			{
				cout << " range [" << i << "] encapsulated values are NOT greater than or equal to range [" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "]" << endl;
			}
		}
	}


	cout << endl;
	cout << "Determine a factor object encapsulated value is greater than or equals to an unsigned int using '>=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- object [" << i << "] encapsulated value >= random integer --> " << arr.arrFactor[i] << " >= " << num << endl;
		if (arr.arrFactor[i] >= num)
		{
			cout << " encapsulated value is greater than or equals to number" << endl;
		}
		else
		{
			cout << " encapsulated value is NOT greater than or equals to number" << endl;
		}
	}

	cout << endl;
	cout << "Determine a range object encapsulated values are greater than or equals to an unsigned int using '>=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- object [" << i << "] encapsulated values >= random integer --> [" << arr.arrRange[i] << "] >= " << num << endl;
		if (arr.arrRange[i] >= num)
		{
			cout << " encapsulated values are greater than or equals to number" << endl;
		}
		else
		{
			cout << " encapsulated values are NOT greater than or equals to number" << endl;
		}
	}


	cout << endl;
	cout << "Determine an unsigned int is greater than or equals to a factor object encapsulated value using '>=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- random integer >= object [" << i << "] encapsulated value--> " << num << " >= " << arr.arrFactor[i] << endl;
		if (num >= arr.arrFactor[i])
		{
			cout << " number is greater than or equals to encapsulated value" << endl;
		}
		else
		{
			cout << "number is NOT greater than or equals to encapsulated value" << endl;
		}
	}

	cout << endl;
	cout << "Determine an unsigned int is greater than or equals to a range object encapsulated value using '>=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- random integer >= object [" << i << "] encapsulated value--> " << num << " >= [" << arr.arrRange[i] <<"]" << endl;
		if (num >= arr.arrRange[i])
		{
			cout << " number is greater than or equals to encapsulated values" << endl;
		}
		else
		{
			cout << "number is NOT greater than or equals to encapsulated values" << endl;
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
		cout << "- factor [" << i << "] encapsulated value = " << arr.arrFactor[i];
		cout << ", call ++object[" << i <<"]" << endl;
		cout << "  in scope encapsulated value = " << ++arr.arrFactor[i] << endl;
	}

	cout << endl;
	cout << "Pre increment range objects using '++object' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		cout << "- range [" << i << "] encapsulated values = [" << arr.arrRange[i] <<"]";
		cout << ", call ++object[" << i << "]" << endl;
		cout << "  in scope encapsulated values = [" << ++arr.arrRange[i] <<"]" << endl;
	}


	cout << endl;
	cout << "Post increment factor objects using 'object++' operator" << endl;

	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		cout << "- factor [" << i << "] encapsulated value = " << arr.arrFactor[i];
		cout << ", call object[" << i << "]++" << endl;
		cout << "  in scope encapsulated value = " << arr.arrFactor[i]++ << endl;
	}

	cout << endl;
	cout << "Post increment range objects using 'object++' operator" << endl;

	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		cout << "- range [" << i << "] encapsulated values = [" << arr.arrRange[i];
		cout << "], call object[" << i << "]++" << endl;
		cout << "  in scope encapsulated values = [" << arr.arrRange[i]++ << "]" << endl;
	}


	cout << endl;
	cout << "Pre decrement factor objects using '--object' operator" << endl;

	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		cout << "- factor [" << i << "] encapsulated value = " << arr.arrFactor[i];
		cout << ", call --object[" << i << "]" << endl;
		cout << "  in scope encapsulated value = " << --arr.arrFactor[i] << endl;
	}


	cout << endl;
	cout << "Pre decrement range objects using '--object' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		cout << "- range [" << i << "] encapsulated values = [" << arr.arrRange[i];
		cout << "], call --object[" << i << "]" << endl;
		cout << "  in scope encapsulated values = [" << --arr.arrRange[i] << "]" << endl;
	}


	cout << endl;
	cout << "Post decrement factor objects using 'object--' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		cout << "- factor [" << i << "] encapsulated value = " << arr.arrFactor[i];
		cout << ", call object[" << i << "]--" << endl;
		cout << "  in scope encapsulated value = " << arr.arrFactor[i]-- << endl;
	}

	cout << endl;
	cout << "Post decrement range objects using 'object--' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		cout << "- range [" << i << "] encapsulated values = [" << arr.arrRange[i];
		cout << "], call object[" << i << "]--" << endl;
		cout << "  in scope encapsulated values = [" << arr.arrRange[i]-- << "]" << endl;
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
			cout << "  in scope factor [" << i << "] encapsulated value = " << arr.arrFactor[i] << endl;
		}
		else
		{
			cout << "- factor [" << i << "] += factor[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrFactor[i] << " += " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			arr.arrFactor[i] += arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
			cout << "  in scope factor [" << i << "] encapsulated value = " << arr.arrFactor[i] << endl;
		}
	}

	cout << endl;
	cout << "Add a factor object with an unsigned int using '+=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- factor [" << i << "] div value +=  random integer --> " << arr.arrFactor[i] << " += " << num << endl;
		arr.arrFactor[i] += num;
		cout << "  in scope factor [" << i << "] encapsulated value  = " << arr.arrFactor[i] << endl;
	}


	cout << endl;
	cout << "Add a range object with an unsigned int using '+=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- range [" << i << "] encapsulated values +=  random integer --> [" << arr.arrRange[i] << "] += " << num << endl;
		arr.arrRange[i] += num;
		cout << "  in scope encapsulated values  = [" << arr.arrRange[i] <<"]" << endl;
	}


	cout << endl;
	cout << "Subtract two factor objects using '-=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- factor [" << i << "] -= factor[" << i + 1 << "] --> " << arr.arrFactor[i] << " -= " << arr.arrFactor[i + 1] << endl;
			arr.arrFactor[i] -= arr.arrFactor[i + 1];
			cout << "  in scope encapsulated value = " << arr.arrFactor[i] << endl;
		}
		else
		{
			cout << "- factor [" << i << "] -= factor[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrFactor[i] << " -= " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			arr.arrFactor[i] -= arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
			cout << "  in scope encapsulated value = " << arr.arrFactor[i] << endl;
		}
	}

	cout << endl;
	cout << "Subtract an unsigned int from a factor object using '-=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- factor [" << i << "] encapsulated value -=  random integer --> " << arr.arrFactor[i] << " -= " << num << endl;
		arr.arrFactor[i] -= num;
		cout << "  in scope encapsulated value  = " << arr.arrFactor[i] << endl;
	}

	cout << endl;
	cout << "Subtract an unsigned int from a range object using '-=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- range [" << i << "] encapsulated values -=  random integer --> [" << arr.arrRange[i] << "] -= " << num << endl;
		arr.arrRange[i] -= num;
		cout << "  in scope encapsulated values = [" << arr.arrRange[i] <<"]" << endl;
	}


	cout << endl;
	cout << "Multiply two factor objects using '*=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		if (i < DEFAULT_ARR_SIZE - 1)
		{
			cout << "- factor [" << i << "] *= factor[" << i + 1 << "] --> " << arr.arrFactor[i] << " *= " << arr.arrFactor[i + 1] << endl;
			arr.arrFactor[i] *= arr.arrFactor[i + 1];
			cout << "  in scope encapsulated value = " << arr.arrFactor[i] << endl;
		}
		else
		{
			cout << "- factor [" << i << "] *= factor[" << DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE << "] --> " << arr.arrFactor[i] << " *= " << arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE] << endl;
			arr.arrFactor[i] *= arr.arrFactor[DEFAULT_ARR_SIZE - DEFAULT_ARR_SIZE];
			cout << "  in scope encapsulated value = " << arr.arrFactor[i] << endl;
		}
	}

	cout << endl;
	cout << "Multiply a factor object with an unsigned int using '*=' operator" << endl;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << "- factor [" << i << "] div value *=  random integer --> " << arr.arrFactor[i] << " *= " << num << endl;
		arr.arrFactor[i] *= num;
		cout << "  in scope encapsulated value = " << arr.arrFactor[i] << endl;
	}


	cout << ASTERISK + "End Test Overloaded Compound Assignment Operators " + ASTERISK << endl;
}