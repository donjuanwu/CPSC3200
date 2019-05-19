/*
-- Developer    : Don Dang
-- Project      : Project 5
-- Instructor   : Dr. Dingle
-- File Name    : factor.cpp
-- File Version : 1.1
-- Due Date	    : 5/24/2019
-- Course Name  : CPSC 3200


-------------------------------------------------------------------------------
FACTOR Feedback:
  -2 number passed to div is an uint but it is stored in an int.  Uints may not fit in an int.
	-2 confusingly similar variable names.  initialFactor and INITIAL_FACTOR
	-5 no way to check if factor is active
	-3 div should return whether or not the value was a multiple not the div count
	-1 GetDivCount not descriptive of actual value returned.  Try GetMultiplesCount

----------------------------------------------------------------------------------
-- WHEN     WHO		WHAT
	 5/17/19  DD    Ported factor.cs to factor.cpp
	                Updated factor.cpp from feedback (See above Factor Feedback section)
*/


#include "factor.h"


factor::factor(unsigned int uFactor)
{ 
	if (uFactor <= 1)
	{
		divFactor = INITIAL_FACTOR_VALUE;
	}
	divFactor = uFactor;
	multiplesCount = INITIAL_MULTIPLESCOUNT;
	isObjectActive = true;
	lastNumber = INITIAL_LAST_NUMBER;
}
factor::~factor() { }

unsigned factor::GetMultiplesCount()
{
	return multiplesCount;
}

bool factor::Div(unsigned int number)
{
	if (isObjectActive)
	{

		if (number != lastNumber) 
		{
			lastNumber = number;
			if (number % divFactor == 0)
			{
				return true;
			}
		}
		else
		{
			isObjectActive = false;
		}

	}
	return false;
}

void factor::Reset()
{
	multiplesCount = INITIAL_MULTIPLESCOUNT;
	lastNumber = INITIAL_LAST_NUMBER;
	isObjectActive = true;
}

bool factor::GetFactorStatus()
{
	return isObjectActive;
}

ostream& operator<<(ostream& os, const factor & f) 
{
	os << f.divFactor;	
	return os;
}


///////////////MATHEMATICAL////////////////////
factor factor::operator+(const factor & rhs)
{
	divFactor += rhs.divFactor;
	return *this;
}

factor factor::operator+(unsigned int x)
{
	divFactor += x;
	return *this;
}

factor factor::operator-(const factor & rhs)
{
	int temp = divFactor - rhs.divFactor;
	int div = abs(temp);
	if (div == 0)
	{
		div += 2;
	}
	
	if (div == 1)
	{
		div += 1;
	
	}
	divFactor = div;
	return *this;

}


factor factor::operator-(unsigned int x)
{
	int temp;
	if (x > divFactor) temp = x - divFactor;
	else temp = divFactor - x;

	if (temp == 0) temp += 2;
	if (temp == 1) temp += 1;

	divFactor = temp;
	return *this;
}


factor factor::operator*(const factor & rhs)
{
	divFactor *= rhs.divFactor;
	return *this;
}

factor factor::operator*(unsigned int x)
{
	if (x <= 0) x += 1;

	divFactor *= x;
	return *this;
}

factor factor::operator/(const factor & rhs)
{
	int remainder = divFactor / rhs.divFactor;
	if ( remainder == 1) remainder += 1;
	if (remainder == 0) remainder += 2;

	divFactor = remainder;
	return *this;

}


factor factor::operator/(unsigned int x)
{
	if (x <= 0) x += 1;

	int remainder = divFactor / x;
	if (remainder == 1) remainder += 1;
	if (remainder == 0) remainder += 2;

	divFactor = remainder;
	return *this;

}

factor factor::operator%(const factor & rhs)
{
	int quotient = divFactor % rhs.divFactor;
	if (quotient == 0) quotient += 2;
	if (quotient == 1) quotient += 1;
	divFactor = quotient;
	return *this;
}

factor factor::operator%(unsigned int x)
{
	if (x <= 0) x += 1;
	int quotient = divFactor % x;
	if (quotient == 0) quotient += 2;
	if (quotient == 1) quotient += 1;
	divFactor = quotient;
	return *this;
}

/////////////////////////SHORTCUT OPERATORS/////////////////
factor factor::operator++()
{
	divFactor += 1;
	return *this;
}

int factor::operator++(int x)
{
	int local = divFactor;
	divFactor += 1;
	return local;
}

factor factor::operator--()
{
	int temp = divFactor - 1;
	if (temp <= 1) temp = 2;
	divFactor = temp;

	return *this;
}

int factor::operator--(int x)
{
	int local = divFactor - 1;
	if (local <= 1) local = 2;
	else
	{
		local = divFactor;
		divFactor -= 1;
	}
	
	return local;
}

/////////////////LOGICAL OPERATORS//////////////////////////
//bool factor::operator&&()
//{
//	/*if (a == b) return true;
//	else return false;*/
//}



/////////////////COMPOUND ASSIGNMENT OPERATORS//////////////////////
	//=, +=, *=, -=, /=
factor factor::operator+=(const factor & rhs)
{
	divFactor = divFactor + rhs.divFactor;
	return *this;
}

factor factor::operator+=(unsigned int x)
{
	divFactor = divFactor + x;
	return *this;
}

factor factor::operator-=(const factor & rhs)
{
	int temp = divFactor - rhs.divFactor;
	int local = abs(temp);
	if (local <= 1) local = 2;
	divFactor = local;

	return *this;
}

factor factor::operator-=(unsigned int x)
{
	
	int temp = divFactor - x;
	int local = abs(temp);
	if (local <= 1) local = 2;
	divFactor = local;

	return *this;
}

factor factor::operator*=(const factor & rhs)
{
	divFactor = divFactor * rhs.divFactor;
	return *this;
}

factor factor::operator*=(unsigned int x)
{
	divFactor = divFactor * x;
	return *this;
}

factor factor::operator/=(const factor & rhs)
{
	int remainder = divFactor / rhs.divFactor;
	if (remainder == 1) remainder += 1;
	if (remainder == 0) remainder += 2;

	divFactor = remainder;
	return *this;
}

factor factor::operator/=(unsigned int x)
{
	if (x <= 0) x = 1;
	int remainder = divFactor / x;
	if (remainder == 1) remainder += 1;
	if (remainder == 0) remainder += 2;

	divFactor = remainder;
	return *this;
}

factor factor::operator%=(const factor & rhs)
{
	
	int quotient = divFactor % rhs.divFactor;
	if (quotient == 0) quotient += 2;
	if (quotient == 1) quotient += 1;
	divFactor = quotient;
	return *this;
}

factor factor::operator%=(unsigned int x)
{

	if (x <= 0) x += 1;
	int quotient = divFactor % x;
	if (quotient == 0) quotient += 2;
	if (quotient == 1) quotient += 1;
	divFactor = quotient;
	return *this;
}


///////////////RELATIONAL OPERATORS////////////////////////
bool factor::operator == (const factor & rhs) { return (divFactor == rhs.divFactor);} 
bool factor::operator<(const factor & rhs){ return (divFactor < rhs.divFactor);}
bool factor::operator>(const factor & rhs){ return (divFactor > rhs.divFactor);}
bool factor::operator!=(const factor & rhs){return (divFactor != rhs.divFactor);}
bool factor::operator<=(const factor & rhs) {return (divFactor <= rhs.divFactor);}
bool factor::operator>=(const factor & rhs){return (divFactor >= rhs.divFactor);}




