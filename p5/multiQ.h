/*
-- Developer    : Don Dang
-- Project      : Project 5
-- Instructor   : Dr. Dingle
-- File Name    : multiQ.h
-- File Version : 1.1
-- Due Date	    : 5/24/2019
-- Course Name  : CPSC 3200
---------------------------------------------------------------------------------------------------------------
OVERVIEW:
 *  MultiQ.h takes values from client and creates an array of factor
 *  objects from the given size. The client can add and remove
 *  factor values which will result in factor objects being created and removed
 *  from the multiQ object.The client can enter a value into
 *  Query() and find out how many factor objects are a factor to the queried value.
 * ---------------------------------------------------------------------------------------------------------------
 * DESIGN DECISIONS AND ASSUMPTIONS:
 *  1 - Statistics that are kept track of include the largest successful query, the
 *      smallest successful query, the number of times the multiQ object was queried,
 *      the average of amount of factors returned from successful queries.
 *
 *  2 - Active status of multiQ objects depend on the active status of the encapsulated
 *      array of factor objects. If any factor object becomes unactive, the entire multiQ
 *      object then becomes inactive until the user resets the multiQ object.
 *
 *  3 - Can only use unsigned integers for adding a factor value and for Query since factor.cs
 *      can only take in positive integers.
 *
 *
 *  4 - Constructors will create an array to hold factor objects between the sizes of 2 and 5.
 *      The user will decide the size as long as the size remains within those bounds, if they
 *      exceed those bounds then the array will resize.
 * ---------------------------------------------------------------------------------------------------------------
 * INTERFACE INVARIANTS:
 *  1 - MultiQ objects remain active for as long as the client does not Query() the same value twice in succession.
 *
 *  2 - Reset():
 *
 *      At any time, the client can Reset() a multiQ object and it will reset the object to the state it was in
 *      immediately after construction.
 *
 *  3 - isFull:
 *
 *      At any time, the client can check to see if the array of factors is full using isFull.
 *
 *  4 - Query:
 *
 *      When using Query() the client must pass in a positive integer. Query() will only work effectively if the state of the object
 *      is active. 
 *
 *  5 - Statistics - Max, Min, Average, Query_Count, Sum_Query:
 *
 *      The user can access any statistic value they would like to know by the means of its accessor. The stats are kept track only
 *      when the object is active. Stats include the Max which returns the largest number of factors of any single Query(). Min, which
 *      returns the smallest number of factors of any single Query(). Mean, which returns the average number of factors that return from
 *      a Query() call. Query_Count which returns how many times Query() has been called while the object was active. Lastly, there is
 *      Reset_Count which returns the number of times an object has been reset. Stats will be all 0 if there were no queries or if the
 *      queries resulted in the queried values having no factors in the internal factor object array.
 *
 *  7 - isObjectActive:
 *
 *      The client can check at any time if an object is active or inactive. They should use the isActive Accessor.
 *
 *  8 - Push():
 *
 *      This method allows the client to add a positive factor value to the back of the array held by a multiQ object. When adding
 *      a factor value to the array, the client must be mindful if they are adding to a full array for Add() will not add a
 *      value to the array if it is full, it will simply ignore the request. Recommended that 0 is not entered since 0 is a factor
 *      to every other number.
 *
 *  9 - Pop():
 *
 *      This method allows the client to delete a factor value from the end of the array held by a multiQ object.
 *      From this, the client is responsible for checking whether the array is empty. 
 * ---------------------------------------------------------------------------------------------------------------------------------
 * CLASS INVARIANTS:
 *  1 - The constructor will create an array size between 2 and 5 to hold factor objects. The constructor will recieve a size
 *      of array from the client and create an array filled with empty factor objects. The private data members tracking statistics
 *      will be initialized and the size of the array holding factor objects from that point onward cannot change.
 *
 *  2 - Object is deemed inactive if any of the factor objects it holds in the array is inactive.
 *
 *  3 - If Min() gets called before any factor value is added into the factor_objArray, then it will give a default value of 0.
 *
 *  4 - Overloaded Operators:
 *
 *		Arithmetic operators (+, -) addition with multiQ and multiQ objects will result in a new multiQ that
 * 		adds all the values in their factor_objArray element wise (index 2 will be added to index 2. The new
 *		object factor array size will change to be as large as the size of the object with the largest factor
 * 		array. Subtraction will subtract element wise like addition does, however, if the multiQ factor array
 * 		that is on the far RHS has more elements than the other multiQ object, the extra factor objects will be
 * 		ignored.
 *
 *		Relational operators (==, !=) For multiQ compared to multiQ objects, the == will check to match every
 *		element in the factor_objArray. 0 will be returned if this is true and 0 if it is false. Comparisons of
 *		multiQ and factor, factor and multiQ, int and multiQ, and multiQ and int will check to see if any of the
 * 		encapsulated factor values int he factor_objArray of the multiQ is == to the singular encapsulated factor
 * 		or integer it is compared against. != simply checks the respective == operator and inverts the result. Again
 * 		returning 1 if true and 0 if false.
 *
 *		Unary operators (++, --) increments or decrements all the encapsulated_factor values in the multiQ factor_objArray.
 *
 *		Assignment operators (+=, -=) are destructive, meaning they will alter the state of an existing multiQ
 *		objects factor_objArray rather than creating and returning a new multiQ object. These operators are
 *		supported for multiQ objects with other multiQ objects, multiQ objects with integers, and integers with
 *		multiQ objects. These operators perform the same functionality as + and - but instead of returning a new
 * 		object, they are destructing, changing the object on the LHS. Supported for multiQ and multiQ operation
 * 		and multiQ and integer operation.
 *
 *		Bitwise operator (<<) will output the factor_objArray of a multiQ object when the object is called
 *		upon so there is no need for the dot operator or the -> when using heap allocated objects.
 * 		Example: cout << m1; will return the factor_objArray value of object m1.
 *
 * 		ATTENTION:
 *
 *		For all operators that use subtraction, (-, --, -=) the encapsulated values will not subtract a value if the
 *		resulting encapsulated factor values will be less than 1. In this case, the operator will reject the request.
 *		This does not apply for overloaded operators that return an integer (int - factor and int -= factor).
 * ------------------------------------------------------------------------------------------------------------



----------------------------------------------------------------------------------
-- WHEN     WHO		WHAT
   5/22/19  DD      Ported multiQ.cs to mltiQ.h
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

public:
	multiQ();
	~multiQ();
	multiQ(const multiQ& src);
	multiQ & operator=(const multiQ & src);
	
	factor** arrFactor;

	void PushFactorObj(int fValue);
	bool PopFactorObject();
	bool IsEmpty();
	int Query(unsigned int x);
	unsigned int GetMaxQuery();
	unsigned int GetMinQuery();
	unsigned int GetSumQuery();
	unsigned int GetAvgQuery();
	void Reset();
	
	multiQ& operator+=(unsigned int x);
	multiQ operator+(const multiQ&) const;
	multiQ& operator+=(factor& src);
	multiQ operator+(const factor& src) const;
	multiQ& operator+=(multiQ& src);
	multiQ operator+(int x) const;
	multiQ& operator++();
	multiQ& AddByOne();
	multiQ operator++(int x);
	bool operator==(const multiQ& b)const;
	bool operator!=(const multiQ & rhs);

	friend ostream& operator<<(ostream& os, const multiQ& m);
	friend multiQ operator+(int x, const multiQ& m);
};
#endif 



