/*
-- Developer    : Don Dang
-- Project      : Project 5
-- Instructor   : Dr. Dingle
-- File Name    : multiQ.h
-- File Version : 1.1
-- Due Date	    : 5/24/2019
-- Course Name  : CPSC 3200
----------------------------------------------------------------------------------
-- WHEN     WHO		WHAT
	 5/22/19  DD    Ported multiQ.cs to mltiQ.h
									Updated range.h from feedback (See range Feeback in range.cpp file)
*/

#ifndef MULTIQ_H
#define MULTIQ_H
#include <iostream>
#include "factor.h"

using namespace std;
class multiQ
{

private:
	unsigned int array_Size;
	unsigned int factorIndex;
	factor* arrFactor;
	bool isObjectActive;
	static const int INIT_COUNT = 0;
	static const int MIN_QUERY_VALUE = 0;
	static const int INIT_ARRAY_SIZE = 5;
	static const int INIT_FACTOR_INDEX = -1;
	static const unsigned int ARR_RESIZE_MULTIPLIER = 2;
	unsigned int query_Count;
	unsigned int min_Query;
	unsigned int max_Query;
	unsigned int sum_Query;

	void ResizeArray();
	void UpdateMinMaxQuery(unsigned int number);
	bool IsDuplicate(factor* arr, int num);


public:
	multiQ(unsigned int arrSize = INIT_ARRAY_SIZE);
	~multiQ();
	multiQ & operator=(const multiQ & src);
	multiQ(const multiQ& src);

	bool PushFactorObj(factor obj);
	bool PopFactorObject();
	unsigned int Query(unsigned int x);
	unsigned int GetMinQuery();
	unsigned int GetMaxQuery();
	unsigned int GetAvgQuery();
	unsigned int GetTotalQueryCount();
	void Reset();
	bool IsEmpty();


	bool operator!=(const multiQ & rhs);
};
#endif 



