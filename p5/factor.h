/*
-- Developer    : Don Dang
-- Project      : Project 5
-- Instructor   : Dr. Dingle
-- File Name    : factor.h
-- File Version : 1.1
-- Due Date	    : 5/24/2019
-- Course Name  : CPSC 3200
----------------------------------------------------------------------------------
-- WHEN     WHO		WHAT
	 5/17/19  DD    Ported factor.cs to factor.h
									Updated factor.h from feedback (See Factor Feeback in factor.cpp file)
   5/20/19  DD   Completed with most overloaded operators
*/



#ifndef FACTOR_H
#define FACTOR_H
#include <iostream>
#include <cmath>



using namespace std;
class factor
{

private:
	unsigned int divFactor;
	unsigned int multiplesCount;
	int lastNumber;
	bool isObjectActive;
	static const int INITIAL_LAST_NUMBER = -1;
	static const int INITIAL_MULTIPLESCOUNT = 0;
	static const int INITIAL_FACTOR_VALUE = 2;
	static const int RETURN_INACTIVE = -1;


public:
	factor(unsigned int initFactor = INITIAL_FACTOR_VALUE);
	~factor();

	unsigned int GetMultiplesCount();
	bool Div(unsigned int number);
	void Reset();
	bool GetFactorStatus();

	
	/////////////////Stream I/O/////////////////////////
	friend ostream& operator<<(ostream& os, const factor & f); //completed
	

	////////////////////////////MATHEMATICAL/////////////////////////////////
	factor operator+(const factor & rhs); //completed
	factor operator+(unsigned int x); //completed
	friend factor operator+(unsigned int x, const factor & rhs);

	factor operator-(const factor & rhs); //completed
	factor operator-(unsigned int x); //complete
	friend factor operator-(unsigned int x, const factor & rhs);

	factor operator*(const factor & rhs);//complete
	factor operator*(unsigned int x);
	friend factor operator*(unsigned int x, const factor & rhs);

	//factor operator/(const factor & rhs);//complete
	//factor operator/(unsigned int x);//complete
	//friend factor operator/(unsigned int x, const factor & rhs);

	//factor operator%(const factor & rhs);//complete
	//factor operator%(unsigned int x);//complete
	//friend factor operator%(unsigned int x, const factor & rhs);


	
	//////////////////////////////Compound Assignments///////////////////////////////
	//=, +=, *=, -=, /=
  void operator+=(const factor & rhs);
	void operator+=(unsigned int x);

	void operator-=(const factor & rhs);
	void operator-=(unsigned int x);

	void operator*=(const factor & rhs);
	void operator*=(unsigned int x);

	void operator/=(const factor & rhs);
	void operator/=(unsigned int x);

	void operator%=(const factor & rhs);
	void operator%=(unsigned int x);

	///////////////////////////////Shortcuts////////////////////////////////////////
	//++, --
	//factor operator++();
	//factor operator++(int x);

	//factor operator--();
	//factor operator--(int x);

/**************************Modified Shortcuts*****************************/
 int operator++();
 int operator++(int x);
 int operator--();
 int operator--(int x);

/**************************************************************************/

	//////////////////////////RELATIONAL/////////////////////////////////////
	bool operator== (const factor & rhs); //completed
	bool operator== (unsigned int x); //completed
	friend bool operator== (unsigned int x, const factor& rhs);

	bool operator<(const factor & rhs); //completed
	bool operator<(unsigned int x); 
	friend bool operator<(unsigned int x, const factor& rhs);

	bool operator>(const factor & rhs); //completed
	bool operator> (unsigned int x);
	friend bool operator>(unsigned int x, const factor& rhs);
	
	bool operator!=(const factor & rhs); //completed
	bool operator!=(unsigned int x);
	friend bool operator!=(unsigned int x, const factor& rhs);


	bool operator<=(const factor & rhs); //completed



	bool operator>=(const factor & rhs); //completed

};

#endif 



