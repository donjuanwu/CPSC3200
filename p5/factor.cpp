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

		if ((int)number != lastNumber) 
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


///////////////////////////////MATHEMATICAL////////////////////////////////////////
factor factor::operator+(const factor & rhs)
{
	factor local(divFactor);
	local.divFactor += rhs.divFactor;
	return local;
}


factor factor::operator+(unsigned int x)
{
	factor local(*this);
	local.divFactor += x;
	return local;

}

//factor operator+(unsigned int x, const factor & rhs)
//{
//	factor local(x);
//	local.divFactor += rhs.divFactor;
//	return local;
//}


factor factor::operator-(const factor & rhs)
{
	factor local(divFactor);
	if (local.divFactor <= rhs.divFactor + 1) {
		local.divFactor = 2;
	}
	else {
		local.divFactor -= rhs.divFactor;
	}
	return local;
}

factor factor::operator-(unsigned int x)
{
	factor local(divFactor);
	if (local.divFactor <= x + 1) { local.divFactor = 2; }
	else { local.divFactor -= x; }

	return local;
}


//factor operator-(unsigned int x, const factor & rhs)
//{
//	factor local(x);
//	if (local.divFactor <= rhs.divFactor + 1) { local.divFactor = 2; }
//	else { local.divFactor -= rhs.divFactor; }
//	return local;
//}


factor factor::operator*(const factor & rhs)
{
	factor local(rhs.divFactor);
	local.divFactor *= divFactor;
	return local;
}


factor factor::operator*(unsigned int x)
{
	factor local(x);
	local.divFactor *= divFactor;
	if (local.divFactor <= 1) local.divFactor = 2;
	return local;
}

//factor operator*(unsigned int x, const factor & rhs)
//{
//	factor local(x);
//	local.divFactor *= rhs.divFactor;
//	return local;
//}

/////////////////////////SHORTCUT OPERATORS/////////////////
factor factor::operator++()
{
	divFactor += 1;
	return *this;
}

factor factor::operator++(int x)
{
	factor local = *this;
	divFactor++;
	return local;
}

factor factor::operator--()
{
	if (divFactor > 2) divFactor--;
	return *this;
}

factor factor::operator--(int x)
{
	factor local = *this;
	if (divFactor > 2) divFactor--;
	return local;
}


/////////////////COMPOUND ASSIGNMENT OPERATORS//////////////////////
	//=, +=, *=, -=, /=
void factor::operator+=(const factor & rhs)
{
	divFactor += rhs.divFactor;

}

void factor::operator+=(unsigned int x){ divFactor += x;}

void factor::operator-=(const factor & rhs)
{
	if (divFactor <= rhs.divFactor + 1) divFactor = 2;
	else divFactor -= rhs.divFactor;
}

void factor::operator-=(unsigned int x)
{
	if (divFactor <= x + 1) divFactor = 2;
	else divFactor -= x;
	
}

void factor::operator*=(const factor & rhs)
{
	divFactor *= rhs.divFactor;
	
}

void factor::operator*=(unsigned int x)
{
	divFactor *= x;
	if (divFactor <= 1) divFactor = 2;
	
}


///////////////RELATIONAL OPERATORS////////////////////////
bool factor::operator == (const factor & rhs) { return (divFactor == rhs.divFactor);} 
bool factor::operator== (unsigned int x){ return (divFactor == x);}
bool operator== (unsigned int x, const factor& rhs) { return (x == rhs.divFactor);}

bool factor::operator<(const factor & rhs){ return (divFactor < rhs.divFactor);}
bool factor::operator<(unsigned int x) { return (divFactor < x); }
bool operator<(unsigned int x, const factor& rhs) { return (x < rhs.divFactor); }

bool factor::operator>(const factor & rhs){ return (divFactor > rhs.divFactor);}
bool factor::operator> (unsigned int x) { return (divFactor > x); }
bool operator>(unsigned int x, const factor& rhs) { return (x > rhs.divFactor); }

bool factor::operator!=(const factor & rhs){return (divFactor != rhs.divFactor);}
bool factor::operator!=(unsigned int x) {return (divFactor != x);}
bool operator!=(unsigned int x, const factor& rhs) { return (x != rhs.divFactor); }

bool factor::operator<=(const factor & rhs) {return (divFactor <= rhs.divFactor);}
bool factor::operator<=(unsigned int x){ return (divFactor <= x);}
bool operator<=(unsigned int x, const factor& rhs){ return (x <= rhs.divFactor);}

bool factor::operator>=(const factor & rhs){return (divFactor >= rhs.divFactor);}
bool factor::operator>=(unsigned int x){ return (divFactor >= x);}
bool operator>=(unsigned int x, const factor& rhs) { return (x >= rhs.divFactor); }




