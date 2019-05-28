/*
-- Developer    : Don Dang
-- Project      : Project 5
-- Instructor   : Dr. Dingle
-- File Name    : range.h
-- File Version : 1.1
-- Due Date	    : 5/24/2019
-- Course Name  : CPSC 3200

 * OVERVIEW:
 *  Range class initializes two factor objects. Passed in parameters can be zero, one, or two by the client. These factors will be compare to
 *  pinge value client sent into Ping(). Ping value will be compared to two factor objects
 *  and validate to see if it is a ping. A successful ping occurs when both factor objects are factors of the pinged value entered by the
 *  client. Example, two factor objects have factor values of 3 and 6 and the client passes in a pinged value of 6. This is
 *  not a ping, however, the pinged value of 12 is a ping.
 * ---------------------------------------------------------------------------------------------------------------------------------
 * DESIGN DECISIONS AND ASSUMPTIONS:
 *  1 - Only non-negative numbers for the factor objects upon construction, and for the pinged value.
 *
 *  2 - Reset() is called during every Ping() the client does to ensure all range objects remain active indefinitely.
 *
 *	3 - Overloaded operators are not allowed to decrement to a resulting value of
 *		less than 2.
 * ---------------------------------------------------------------------------------------------------------------------------------
 * INTERFACE INVARIANTS:
 *  1 - range objects are always active.
 *
 *  2 - Client should not pass in more than 2 factor values into the constructor. These values are to be positive numbers and
 *      preferably not zero since zero is a factor to all other numbers.
 *
 *  3 - Ping():
 *
 *      The client can input a non-negative number and it will compare that input value to the factor object values. This will return
 *      whether or not the value was a ping. An input value is a ping if it is a multiple of both factor values.
 *
 *  4 - Statistics - Max, Min, Mean, & Ping_Num:
 *
 *      The statistics have been implemented such that the client can access the information via an accessor at any point. They may use
 *      Max to determine the largest value that was a ping. Min will determine the smallest value that was a ping. Mean will return the
 *      average of all the values that were succefful pings. Ping_Num will return the number of pings that have occured. All the stats
 *      will be 0 if the object never receives a ping value from the client or if there are no successful pings.
 * ---------------------------------------------------------------------------------------------------------------------------------
 * CLASS INVARIANTS:
 *  1 - Constructor initializes two factor objects & other data members to keep track
 *      of statistics.
 *
 *	2 - Overloaded Operators:
 *
 *		Arithmetic operators (+, -) add and subtract from the encapsulated_factor value within the encapsulated_factor
 *		values located in the range object. Support of mixed mode with integers is implemented. The same goes for the second encapsulated_factor values. 
 *      In mixed mode, the integer is added or
 * 		subtracted both encapsulated_factor values in the range object.
 *
 *		Relational operators (==, !=, <, <=, >, >=) are implemented and will compare the encapsulated_factor
 *		values within the range object. Range objects can be compared to other range objects, range objects
 *		can be compared to integers, and integers can be compared to range objects. Each will return a boolean
 *		from the comparison. The comparison is only true is both encapsulated_factor values in the range object
 *		pass the relational check with what it is compared against.
 *
 *		Unary operators (++, --) increments or decrements both encapsulated_factor values of a range object by one.
 *		Pre and post increment and decrement are supported. These operators are destructive.
 *
 *		Assignment operators (+=, -=) are destructive. These operators are
 *		supported for factor objects with other factor objects, factor objects with integers. 
       The encapsulated_factor values are what is used for addition and subtraction and += adds
 * 		a value on the RHS and assigns it to the LHS and the -= does the same but with subtraction instead. Same
 * 		as (+, -) but destructive. Supported for range and range operation
 * 		and range and integer operation.
 *
 *		Bitwise operator (<<) will output the encapsulated_factors ONLy because of testing
 * 		Example: cout << range; will return both encapsulated_factor values seperated by a comma
 *
 *		NOTES:
 *
 *		Subtraction operators (-, --, -=) the encapsulated values will not subtract a value if the
 *		resulting encapsulated factor values will be less than 1. 

----------------------------------------------------------------------------------
-- WHEN     WHO		WHAT
   5/20/19  DD      Ported range.cs to range.h
					Updated range.h from feedback (See range Feeback in range.cpp file)
*/


#ifndef RANGE_H
#define RANGE_H
#include <iostream>
#include "factor.h"

using namespace std;

class range
{

private:
	factor factObject1;
	factor factObject2;
	unsigned int pingsCount;
	unsigned int min_Ping;
	unsigned int max_Ping;
	static const int DEFAULT_PING_VALUE = 0;
	static const int DEFAULT_FACTOR_VALUE = 2;


	void UpdateMinMaxPingValue(unsigned int number);


public:
	range(unsigned int factor1 = DEFAULT_FACTOR_VALUE, unsigned int factor2 = DEFAULT_FACTOR_VALUE);
	~range();
	unsigned int Ping(unsigned int pNumber);
	unsigned int GetMaxPingNumber();
	unsigned int GetMinPingNumber();
	unsigned int GetTotalPingCount();
	void Replace(unsigned int factor1, unsigned int factor2);

	
	friend ostream& operator<<(ostream& os, const range & r); 
	range operator+(unsigned int x); 


	range operator-(unsigned int x); 
	
	bool operator == (const range & rhs); 
	bool operator== (unsigned int x); 
	friend bool operator== (unsigned int x, const range& rhs); 

	bool operator<(const range & rhs); 
	bool operator<(unsigned int x);  
	friend bool operator<(unsigned int x, const range& rhs); 

	bool operator>(const range & rhs);
	bool operator>(unsigned int x);
	friend bool operator>(unsigned int x, const range& rhs);

	bool operator!=(const range & rhs);
	bool operator!=(unsigned int x);
	friend bool operator!=(unsigned int x, const range& rhs);

	bool operator<=(const range & rhs);
	bool operator<=(unsigned int x);
	friend bool operator<=(unsigned int x, const range& rhs);



	bool operator>=(const range & rhs); 
	bool operator>=(unsigned int x);
	friend bool operator>=(unsigned int x, const range& rhs);

	range operator++();
	range operator++(int x);

	range operator--();
	range operator--(int x);

	void operator+=(unsigned int x);
	void operator-=(unsigned int x);

};

#endif


