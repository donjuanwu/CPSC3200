/*
-- Developer    : Don Dang
-- Project      : Project 5
-- Instructor   : Dr. Dingle
-- File Name    : multiQ.cpp
-- File Version : 1.1
-- Due Date	    : 5/24/2019
-- Course Name  : CPSC 3200

-------------------------------------------------------------------------------
MultiQ Feedback: MultiQ Class Design - 15
 - 1 mishandling of booleans in IsEmpty.directly return result of comparison, no need for if - else
- 1 not self - documenting names
- 1 redundant boolean evaulations in update min and max
- 1 do not pass data members as parameters, access them directly
- 5 do not store query values
- 1 check for duplicate query unnecessary
- 5 control of encapsulated factor states should be internalized
----------------------------------------------------------------------------------
-- WHEN     WHO		WHAT
	 5/22/19  DD    Ported multiQ.cs to multiQ.cpp
					Updated multiQ.cpp from feedback (See above MultiQ Feedback section)
*/


#include "multiQ.h"

multiQ::multiQ()
{
	arrFactor = new factor*[INIT_ARRAY_SIZE];
	isObjectActive = true;
	array_Size = INIT_ARRAY_SIZE;
	factorIndex = 0;
	query_Count = INIT_COUNT;
	min_Query = MIN_QUERY_VALUE;
	max_Query = MIN_QUERY_VALUE;
	sum_Query = INIT_COUNT;
}

multiQ::~multiQ() {delete[] arrFactor;}


multiQ::multiQ(const multiQ& src)
{
	factorIndex = src.factorIndex;
	array_Size = src.array_Size;
	arrFactor = new factor*[array_Size];
	min_Query = src.min_Query;
	max_Query = src.max_Query;
	query_Count = src.query_Count;
	sum_Query = src.sum_Query;
	isObjectActive = src.isObjectActive;
	for (unsigned int i = 0; i < array_Size; i++)
	{
		arrFactor[i] = src.arrFactor[i];
	}
}



multiQ& multiQ::operator=(const multiQ& src)
{
	if (this != &src)
	{
		delete[] arrFactor;
		factorIndex = src.factorIndex;
		array_Size = src.array_Size;
		min_Query = src.min_Query;
		max_Query = src.max_Query;
		query_Count = src.query_Count;
		sum_Query = src.sum_Query;
		isObjectActive = src.isObjectActive;
		arrFactor = new factor*[array_Size];

		for (unsigned int i = 0; i < array_Size; i++)
		{
			arrFactor[i] = src.arrFactor[i]; 
		}
	}

	return *this;
}


void multiQ::PushFactorObj(int fValue)
{
	if (isObjectActive)
	{
		if (factorIndex >= array_Size)
		{
			ResizeArray();
		}
		arrFactor[factorIndex] = new factor(fValue);
		factorIndex++;
	}
	
}

void multiQ::ResizeArray()
{
	int tempSize = array_Size * ARR_RESIZE_MULTIPLIER;
	factor** temp = new factor*[tempSize];
	for (unsigned int i = 0; i < factorIndex; i++)
	{
		temp[i] = arrFactor[i];
	}

	delete[] arrFactor;
	arrFactor = temp;
	array_Size = tempSize;
	delete[] temp;
}

bool multiQ::PopFactorObject()
{
	if (isObjectActive && !IsEmpty())
	{
			factorIndex--;
			return true;
	}
	return false;
}

bool multiQ::IsEmpty(){ return ((int)factorIndex <= INIT_FACTOR_INDEX);}

 int multiQ::Query(unsigned int num)
{
	 if (!isObjectActive || (int)factorIndex == INIT_FACTOR_INDEX)
	 {
		 return -1;
	 }

	 for (unsigned int i = 0; i <= factorIndex; i++)
	 {
		 if (arrFactor[i]->GetFactorStatus())
		 {
			 if (arrFactor[i]->Div(num))
			 {
				 query_Count += 1;
			 }
			 else
			 {
				 isObjectActive = false;
				 return -1;
			 }
		 }
	 }

	 if (query_Count > 0)
	 {
		 UpdateMinMaxQuery(num);
	 }

	 sum_Query += num;
	 return query_Count;
}

 unsigned int multiQ::GetMaxQuery() { return max_Query; }
 unsigned int multiQ::GetMinQuery() {return min_Query;}
 unsigned int multiQ::GetSumQuery() { return sum_Query;}
 unsigned int multiQ::GetAvgQuery() { return sum_Query / query_Count;} 
void multiQ::Reset()
{
	if (!isObjectActive)
	{
		for (unsigned int i = 0; i <= factorIndex; i++)
		{
			arrFactor[i]->Reset();
		}
	}
	isObjectActive = true;
	query_Count = INIT_COUNT;
	min_Query = MIN_QUERY_VALUE;
	max_Query = MIN_QUERY_VALUE;
	sum_Query = INIT_COUNT;
}

void multiQ::UpdateMinMaxQuery(unsigned int number)
{
	if (max_Query == MIN_QUERY_VALUE && min_Query == MIN_QUERY_VALUE)
	{
		max_Query = number;
		min_Query = number;
	}

	if (number > max_Query)
	{
		max_Query = number;
	}
	else
	{
		if (number < min_Query)
		{
			min_Query = number;
		}
	}
}


multiQ& multiQ::operator+=(unsigned int x)
{
	for (unsigned int i = 0; i < factorIndex; i++)
	{
		*arrFactor[i] += x;
	}

	return *this;
}

multiQ multiQ::operator+(const multiQ& rhs) const
{
	multiQ local(*this);
	int min = factorIndex < rhs.factorIndex ? factorIndex : rhs.factorIndex;
	for (int i = 0; i < min; i++) 
	{
		*local.arrFactor[i] += *rhs.arrFactor[i];
	}
	return local;
}
multiQ& multiQ::operator+=(factor& rhs) 
{
	for (unsigned int i = 0; i < factorIndex; i++) 
	{
		*arrFactor[i] += rhs;
	}
	return *this;
}

multiQ multiQ::operator+(const factor& rhs) const {
	multiQ local(*this);
	for (unsigned int i = 0; i < local.factorIndex; i++) {
		*(local.arrFactor[i]) = *(local.arrFactor[i]) + rhs;
	}
	return local;
}

multiQ&  multiQ::operator+=(multiQ& rhs) {
	unsigned int min = factorIndex < rhs.factorIndex ? factorIndex : rhs.factorIndex;
	for (unsigned int i = 0; i < min; i++) {
		*arrFactor[i] += *rhs.arrFactor[i];
	}
	return *this;
}

multiQ multiQ::operator+(int x) const {
	multiQ local(*this);
	for (unsigned int i = 0; i < local.factorIndex; i++) {
		*(local.arrFactor[i]) += x;
	}
	return local;
}
multiQ& multiQ::operator++() {
	return (AddByOne());
}

multiQ& multiQ::AddByOne() {
	for (unsigned int i = 0; i < factorIndex; i++) {
		*arrFactor[i] += 1;
	}
	return *this;
}

multiQ multiQ::operator++(int) {
	multiQ local(*this);
	AddByOne();
	return local;
}

bool multiQ::operator==(const multiQ& b) const {
	bool isEqual = true;
	if (factorIndex == b.factorIndex) {
		for (unsigned int i = 0; i < factorIndex; i++) {
			if (*arrFactor[i] != *b.arrFactor[i]) {
				isEqual = false;
			}
		}
	}
	else {
		isEqual = false;
	}
	return isEqual;
}

bool multiQ::operator!=(const multiQ& rhs)
{ 
	return (*this != rhs);
}


ostream& operator<<(ostream& os, const multiQ& m) {
	for (unsigned int i = 0; i < m.factorIndex; i++) {
		os << *m.arrFactor[i] << ",";
	}
	return os;
}

multiQ operator+(int x, const multiQ& m) {
	multiQ local(m);
	for (unsigned int i = 0; i < local.factorIndex; i++) {
		*(local.arrFactor[i]) += x;
	}
	return local;
}

