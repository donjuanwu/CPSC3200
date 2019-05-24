/*
-- Developer    : Don Dang
-- Project      : Project 5
-- Instructor   : Dr. Dingle
-- File Name    : range.cpp
-- File Version : 1.1
-- Due Date	    : 5/24/2019
-- Course Name  : CPSC 3200


-------------------------------------------------------------------------------
Range Feedback: Range Class Design - 4
	- 1 redundant boolean evualations in update min and max
	- 1 not self - documenting names
	- 2 factor values should not be allowed to be 1
----------------------------------------------------------------------------------
-- WHEN     WHO		WHAT
	 5/20/19  DD    Ported range.cs to range.cpp
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
	//factObject1.Reset();
	//factObject2.Reset();
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

bool range::operator== (const range & rhs)
{
	return factObject1 == rhs.factObject1 && factObject2 == rhs.factObject2;
	
}

bool range::operator<(const range & rhs) 
{ return (factObject1 < rhs.factObject1 && factObject2 < rhs.factObject2); }

bool range::operator>(const range & rhs) 
{ return (factObject1 > rhs.factObject1 && factObject2 > rhs.factObject2); }



bool range::operator!=(const range & rhs)
{
	return (factObject1 != rhs.factObject1 && factObject2 != rhs.factObject2);
}

bool range::operator<=(const range & rhs)
{
	return (factObject1 <= rhs.factObject1 && factObject2 <= rhs.factObject2);
}

bool range::operator>=(const range & rhs)
{
	return (factObject1 >= rhs.factObject1 && factObject2 >= rhs.factObject2);
}

/////////////////////////////////RELATION OPERATOR/////////////////////////////////////

///////////////////////////////MATHEMATICAL OPERATORS//////////////////////////////////
range range::operator+(const range& rhs)
{
	range local(factObject1.operator+(rhs.factObject1), factObject2.operator+(rhs.factObject2));
	return local;
}

range range::operator+(unsigned int x)
{
	range local(factObject1.operator+(x), factObject2.operator+(x));
	return local;
}

range operator+(unsigned int x, const range & rhs)
{
	range local(x + rhs.factObject1, x + rhs.factObject2);
	return local;
}

range range::operator-(const range & rhs)
{
	range local(factObject1.operator-(rhs.factObject1), factObject2.operator-(rhs.factObject2));
	return local;
}

range range::operator-(unsigned int x)
{
	range local(factObject1.operator-(x), factObject2.operator-(x));
	return local;
}

range operator-(unsigned int x, const range & rhs)
{
	range local(x - rhs.factObject1, x - rhs.factObject2);
	return local;
}

//range range::operator*(const range & rhs)
//{
//	range local(factObject1.operator*(rhs.factObject1), factObject2.operator*(rhs.factObject2));
//	return local;
//}

////////////////////////////////SHORTCUT OPERATORS////////////////////////////////////////////
range range::operator++()
{
	range local(++factObject1, ++factObject2);
	return local;
}

