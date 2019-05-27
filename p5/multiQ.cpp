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

multiQ::multiQ(unsigned int arrSize)
{
	if (arrSize <= 0)
	{
		arrSize = INIT_ARRAY_SIZE;
	}
	arrFactor = new factor[arrSize];
	isObjectActive = true;
	array_Size = INIT_ARRAY_SIZE;
	factorIndex = INIT_FACTOR_INDEX;
	query_Count = INIT_COUNT;
	min_Query = MIN_QUERY_VALUE;
	max_Query = MIN_QUERY_VALUE;
	sum_Query = INIT_COUNT;
}

multiQ::~multiQ() {delete[] arrFactor;}

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


		for (unsigned int i = 0; i < array_Size; i++)
		{
			arrFactor[i] = src.arrFactor[i];
		}
	}

	return *this;
}


multiQ::multiQ(const multiQ& src)
{
	factorIndex = src.factorIndex;
	array_Size = src.array_Size;
	arrFactor = new factor[array_Size];
	for (unsigned int i = 0; i < array_Size; i++)
	{
		arrFactor[i] = src.arrFactor[i];
	}
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

bool multiQ::PushFactorObj(factor obj)
{
	if (isObjectActive)
	{
		if ((factorIndex + 1) < array_Size)
		{
			factorIndex++;
			arrFactor[factorIndex] = obj;
			return true;
		}
		else
		{
			ResizeArray();
			factorIndex++;
			arrFactor[factorIndex] = obj;
			return true;
		}
	}
	return false;
}


void multiQ::ResizeArray()
{
	
	array_Size *= ARR_RESIZE_MULTIPLIER;
	factor* temp = new factor[array_Size];
	for (unsigned int i = 0; i < factorIndex; i++)
	{
		temp[i] = arrFactor[i];
	}

	delete[] arrFactor;
	arrFactor = new factor[array_Size];
	arrFactor = temp;
	delete[] temp;
}

unsigned int multiQ::Query(unsigned int num)
{
	if (isObjectActive)
	{
		for (unsigned int i = 0; i <= factorIndex; i++)
		{
			unsigned int prevDivCount = arrFactor[i].GetMultiplesCount();
			if (arrFactor[i].Div(num))
			{
				isObjectActive = false;
				break;
			}
			else
			{
				unsigned int currentDivCount = arrFactor[i].GetMultiplesCount();
				if (currentDivCount > prevDivCount)
				{
					sum_Query += num;
					query_Count++;
					UpdateMinMaxQuery(num);
				}
			}
		}
	}
	return query_Count;
}


bool multiQ::operator!=(const multiQ& rhs)
{ 
	return (arrFactor != rhs.arrFactor);
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

bool multiQ::IsDuplicate(factor* arr, int num)
{
	for (unsigned int i = 0; i < array_Size; i++)
	{
		if (arr[i] == num)
		{
			return true;
		}
	}

	return false;
}

unsigned int multiQ::GetMinQuery() {return min_Query;}

unsigned int multiQ::GetMaxQuery() { return max_Query; }

unsigned int multiQ::GetAvgQuery() { return sum_Query / query_Count;}

unsigned int multiQ::GetTotalQueryCount(){ return query_Count;}

//re-examine 
void multiQ::Reset()
{
	isObjectActive = true;
	array_Size = INIT_ARRAY_SIZE;
	factorIndex = INIT_FACTOR_INDEX;
	query_Count = INIT_COUNT;
	min_Query = MIN_QUERY_VALUE;
	max_Query = MIN_QUERY_VALUE;
	sum_Query = INIT_COUNT;

	delete[] arrFactor;
	arrFactor = new factor[array_Size];
}

bool multiQ::IsEmpty(){ return ((int)factorIndex <= INIT_FACTOR_INDEX);}

multiQ& multiQ::operator+=(unsigned int x)
{
	for (unsigned int i = 0; i < factorIndex; i++)
	{
		arrFactor[i] += x;
	}

	return *this;
}

multiQ& multiQ::operator+=(const factor& fObj)
{
	PushFactorObj(fObj);
	return *this;
}

//Not sure, double check
multiQ& multiQ::operator++()
{
	bool inserted = false;
	factor newFactor(5);
	inserted = PushFactorObj(newFactor);
	
	return *this;
	
	/*
	for (unsigned int i = 0; i < factorIndex; i++)
	{
		++arrFactor[i];
	}
	return *this;*/
}

//Not sure, double check
multiQ& multiQ::operator++(int x)
{
	multiQ local(*this);
	operator++();
	return local;
}


bool multiQ::operator==(const multiQ& m)
{
	bool isEqual = true;

	if (factorIndex == m.factorIndex)
	{
		for (unsigned int i = 0; i < factorIndex; i++)
		{
			if (arrFactor[i] != m.arrFactor[i])
			{
				isEqual = false;
			}
		}
	}
	else
	{
		isEqual = false;
	}
	
	return isEqual;
}



/////////////////////// I/O OPERATORS/////////////////////////
ostream& operator<<(ostream& os, const multiQ& m)
{
	for (unsigned int i = 0; i < m.factorIndex; i++)
	{
		os << m.arrFactor[i];
	}

	return os;
}

