/*
-- Developer    : Don Dang
-- Project      : Project 5
-- Instructor   : Dr. Dingle
-- File Name    : range.cpp
-- File Version : 1.1
-- Due Date	    : 5/24/2019
-- Course Name  : CPSC 3200
---------------------------------------------------------------------------------------------------------------------------------
 * IMPLEMENTATION INVARIANTS:
 *  1 - All range objects are kept active internally by calling reset after each pinged comparison.
 *
 *  2 - The factor objects are initialized either through client input, or through the default values already assigned.
 *
 *  3 - The Ping() method calls methods Div() to determine if the input value was a ping.
 * ---------------------------------------------------------------------------------------------------------------------------------
 * CLASS INVARIANTS:
 *  1 - Constructor initializes two factor objects & all other data members to keep track
 *      of statistics.
 *
 *	2 - Overloaded Operators:
 *
 *		Arithmetic operators (+, -) add and subtract from the encapsulated_factor value within the encapsulated_factor
 *		values located in the range object. Support of mixed mode with integers is implemented. In mixed mode, the integer is added or
 * 		subtracted both encapsulated_factor values in the range object.
 *
 *		Relational operators (==, !=, <, <=, >, >=) are implemented & will compare  encapsulated_factor
 *		values within the range object. Range objects can be compared to other range objects, range objects
 *		can be compared to integers, and integers can be compared to range objects. The result returned a boolean
 *		from the comparison. The comparison is only true is both encapsulated_factor values in the range object
 *		pass the relational check with what it is compared against.
 *
 *		Unary operators (++, --) increments or decrements both encapsulated_factor values of a range object by one.
 *		Pre and post increment and decrement are supported. These operators are destructive.
 *
 *		Assignment operators (+=, -=) are destructive, meaning they will alter the state of an existing factor
 *		objects encapsulated_factor rather than creating and returning a new factor object. These operators are
 *		supported for factor objects with other factor objects, factor objects with integers, and integers with
 *		factor objects. The encapsulated_factor values are what is used for addition and subtraction and += adds
 * 		a value on the RHS and assigns it to the LHS and the -= does the same but with subtraction instead. Same
 * 		as (+, -) but destructive. Supported for range and range operation
 * 		and range and integer operation.
 *
 *		Bitwise operator (<<) will output the encapsulated_factors ONLY for testing.
 * 		Example: cout << range; will return both encapsulated_factor values of object range seperated by a comma.
 *
 *		NOTES:
 *
 *		Subtraction operators (-, --, -=) the encapsulated values will not subtract a value if the
 *		resulting encapsulated factor values will be less than 1. 

-------------------------------------------------------------------------------
Range Feedback: Range Class Design - 4
	- 1 redundant boolean evualations in update min and max
	- 1 not self - documenting names
	- 2 factor values should not be allowed to be 1
----------------------------------------------------------------------------------
-- WHEN     WHO		WHAT
  5/20/19   DD      Ported range.cs to range.cpp
									Updated range.cpp from feedback (See above Range Feedback section)
*/

#include "range.h"

range::range(unsigned int factor1, unsigned int factor2) //: factObject1(factor1), factObject2(factor2)
{
	if (factor1 <= 1) factor1 = DEFAULT_FACTOR_VALUE;
	if (factor2 <= 1) factor2 = DEFAULT_FACTOR_VALUE;

	factObject1 = factor(factor1);
	factObject2 = factor(factor2);
	min_Ping = DEFAULT_PING_VALUE;
	max_Ping = DEFAULT_PING_VALUE;
	pingsCount = DEFAULT_PING_VALUE;
}

range::~range()
{
}

unsigned int range::Ping(unsigned int pNumber)
{
	bool isMultiple1 = factObject1.Div(pNumber);
	bool isMultiple2 = factObject2.Div(pNumber);
	factObject1.Reset();
	factObject2.Reset();
	if ((isMultiple1) && (isMultiple2))
	{
		pingsCount++;
		UpdateMinMaxPingValue(pNumber);
	}

	return pingsCount;
}

void range::UpdateMinMaxPingValue(unsigned int number)
{
		if (number >= max_Ping)
		{
			max_Ping = number;
		}
		else
		{
			if (number <= min_Ping)
			{
				min_Ping = number;
			}
		}
}

unsigned int range::GetMaxPingNumber() {return max_Ping;}

unsigned int range::GetMinPingNumber() {return min_Ping;}

unsigned int range::GetTotalPingCount() { return pingsCount; }

void range::Replace(unsigned int rFactor1, unsigned int rFactor2)
{
	factObject1 = factor(rFactor1);
	factObject2 = factor(rFactor2);
	min_Ping = DEFAULT_PING_VALUE;
	max_Ping = DEFAULT_PING_VALUE;
	pingsCount = DEFAULT_PING_VALUE;
}

/////////////////Stream I/O/////////////////////////
ostream& operator<<(ostream& os, const range & r)
{
	os << r.factObject1 << "," << r.factObject2;
	return os;
}


/////////////////////////////////RELATION OPERATORS/////////////////////////////////////

bool range::operator== (const range & rhs) { return factObject1 == rhs.factObject1 && factObject2 == rhs.factObject2;}
bool range::operator== (unsigned int x){ return (factObject1 == x && factObject2 == x);}
bool operator== (unsigned int x, const range& rhs) { return (x == rhs.factObject1 && x == rhs.factObject2);}

bool range::operator<(const range & rhs) { return (factObject1 < rhs.factObject1 && factObject2 < rhs.factObject2); }
bool range::operator<(unsigned int x) {return (factObject1 < x && factObject2 < x);}
bool operator<(unsigned int x, const range& rhs) { return (x < rhs.factObject1 && x < rhs.factObject2); }

bool range::operator>(const range & rhs) { return (factObject1 > rhs.factObject1 && factObject2 > rhs.factObject2); }
bool range::operator>(unsigned int x) { return (factObject1 > x && factObject2 > x); }
bool operator>(unsigned int x, const range& rhs) { return (x > rhs.factObject1 && x > rhs.factObject2); }


bool range::operator!=(const range & rhs){return (factObject1 != rhs.factObject1 && factObject2 != rhs.factObject2);}
bool range::operator!=(unsigned int x) { return (factObject1 != x && factObject2 != x); }
bool operator!=(unsigned int x, const range& rhs) { return (x != rhs.factObject1 && x != rhs.factObject2); }


bool range::operator<=(const range & rhs){return (factObject1 <= rhs.factObject1 && factObject2 <= rhs.factObject2);}
bool range::operator<=(unsigned int x) { return (factObject1 <= x && factObject2 <= x); }
bool operator<=(unsigned int x, const range& rhs) { return (x <= rhs.factObject1 && x <= rhs.factObject2); }


bool range::operator>=(const range & rhs){return (factObject1 >= rhs.factObject1 && factObject2 >= rhs.factObject2);}
bool range::operator>=(unsigned int x) { return (factObject1 >= x && factObject2 >= x); }
bool operator>=(unsigned int x, const range& rhs) { return (x >= rhs.factObject1 && x >= rhs.factObject2); }

///////////////////////////////MATHEMATICAL OPERATORS//////////////////////////////////

range range::operator+(unsigned int x)
{
	range local(*this);
	local.factObject1 += x;
	local.factObject2 += x;
	
	return local;
}

//range operator+(unsigned int x, const range & rhs)
//{
//	range local(rhs);
//	local.factObject1 += x;
//	local.factObject2 += x;
//	return local;
//}


range range::operator-(unsigned int x)
{

	range local(*this);
	local.factObject1 -= x;
	local.factObject2 -= x;
	return local;
}

//range operator-(unsigned int x, const range & rhs)
//{
//	range local(rhs);
//	local.factObject1 -= x;
//	local.factObject2 -= x;
//
//	return local;
//}

////////////////////////////////SHORTCUT OPERATORS////////////////////////////////////////////
range range::operator++()
{

	range local(*this);
	++local.factObject1;
	++local.factObject2;
	return local;
}

range range::operator++(int x)
{
	range temp(*this);
	range local(*this);
	local.factObject1++;
	local.factObject2++;
	return temp;
}

range range::operator--()
{
	range local(*this);
	--local.factObject1;
	--local.factObject2;
	return local;
}

range range::operator--(int x)
{
	range temp(*this);
	range local(*this);
	local.factObject1--;
	local.factObject2--;
	return temp;
}

/////////////////////////////////COMPOUNDED ASSIGNMENT///////////////////////////
void range::operator+=(unsigned int x)
{
	factObject1 += x;
	factObject2 += x;
}

void range::operator-=(unsigned int x)
{
	factObject1 -= x;
	factObject2 -= x;
}

