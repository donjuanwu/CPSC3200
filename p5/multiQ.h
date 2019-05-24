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
	int factorIndex;
	factor* arrFactorObject;
	int* arrQueriedNumbers;
	bool isObjActive;
	unsigned int query_Count;
	static const int INITIAL_COUNT = 0;
	static const int INITIAL_ARRAY_SIZE = 5;
	static const int INITIAL_FACTOR_INDEX = -1;
	static unsigned int ARR_RESIZE_VALUE;
	unsigned int min_Query;
	unsigned int max_Query;
	unsigned int sum_Query;


public:
	multiQ();
	~multiQ();
};
#endif 



