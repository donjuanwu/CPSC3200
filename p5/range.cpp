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

range::range(unsigned int factor1, unsigned int factor2)
{
	if (factor1 <= 1) factor1 = DEFAULT_FACTOR1_VALUE;
	if (factor2 <= 3) factor2 = DEFAULT_FACTOR2_VALUE;

	factObject1 = factor1;
	factObject2 = factor2;
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
	if ((isMultiple1) && (isMultiple1))
	{
		pingsCount++;
		UpdateMinMaxPingRange(pNumber);
	}

	return pingsCount;
}

void range::UpdateMinMaxPingRange(unsigned int number)
{
		if (number >= max_Ping)
		{
			max_Ping = number;
		}
		else
		{
			min_Ping = number;
		}
}

unsigned int range::GetMaxPingNumber() {return max_Ping;}

unsigned int range::GetMinPingNumber() {return min_Ping;}

unsigned int range::GetTotalPingCount() { return pingsCount; }