/*
-- Developer    : Don Dang
-- Project      : Project 5
-- Instructor   : Dr. Dingle
-- File Name    : range.h
-- File Version : 1.1
-- Due Date	    : 5/24/2019
-- Course Name  : CPSC 3200
----------------------------------------------------------------------------------
-- WHEN     WHO		WHAT
	 5/20/19  DD    Ported range.cs to range.h
								  Updated range.h from feedback (See range Feeback in range.cpp file)
*/


#ifndef RANGE_H
#define RANGE_H
#include <iostream>
#include <stdlib.h>
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

	/////////////////Stream I/O/////////////////////////
	friend ostream& operator<<(ostream& os, const range & r); //completed





	/////////////////Mathematical//////////////////////
	//range operator+(const factor & rhs); //completed
	//factor operator+(unsigned int x); //completed
	//friend factor operator+(unsigned int x, const factor & rhs);


	//factor operator-(const factor & rhs); //completed
	//factor operator-(unsigned int x); //complete
	//friend factor operator-(unsigned int x, const factor & rhs);

	//factor operator*(const factor & rhs);//complete
	//factor operator*(unsigned int x);//complete
	//friend factor operator*(unsigned int x, const factor & rhs);

	//factor operator/(const factor & rhs);//complete
	//factor operator/(unsigned int x);//complete
	//friend factor operator/(unsigned int x, const factor & rhs);

	//factor operator%(const factor & rhs);//complete
	//factor operator%(unsigned int x);//complete
	//friend factor operator%(unsigned int x, const factor & rhs);

	///////////////////RELATION OPERATOR////////////////////////////
	bool operator == (const range & rhs);
	bool operator<(const range & rhs); 
	bool operator>(const range & rhs);
	bool operator!=(const range & rhs);
	bool operator<=(const range & rhs);

	/*bool factor::operator>=(const factor & rhs) { return (divFactor >= rhs.divFactor); }*/

};


#endif


