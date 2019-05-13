/*
-- Developer    : Don Dang
-- Project      : Project 4
-- Instructor   : Dr. Dingle
-- File Name    : p4.cpp
-- File Version : 1.0
-- Due Date	    : 5/15/2019
-- Course Name  : CPSC 3200
----------------------------------------------------------------------------
OVERVIEW:
	 This driver will sequentially perform the following test cases:
	 1) InitPwdObject(rand)
			- Create a heterogenous array and initialized pwdCheck, compundC and excessC objects
			- Return the heterogenous arary back to the calling function
	 2) TestPasswordLength(arrPwdObj, rand)
			- Specific test to see if password meet the minimum password length defined during
				firing each object constructor
	 3) TestPwdClassWithInValidPassword(arrPwdObj, rand)
			- Specific test to see if password has invalid characters. These invalid characters
				were initialized during firing constructor of the pwdCheck
	 4) TestCheckPassword(arrPwdObj, rand)
			- General password test to determine if password meet each class specific password conditions
	 5) TestForbiddenCharsInPwd(arrPwdObj, rand, NON_ASCII)
			- Update the initialized forbidden characters during firing pwdCheck constructor with new
				NON ASCII characters
			- Determine if password contains any of these forbidden characters
	 6) TestToggleObject(arrPwdObj,rand)
			- Toggle the state of each initialized object in the heterogenous array.

---------------------------------------------------------------------------------
Design Decisions and Assumptions:
- All objects initialized with password length greater than 0
- Password length is randomly generated using RAND_MIN & RAND_MAX values
- Password is randomly generated from a predefined string using random generator
- Objects are added to heterogenous array in group of 1/3.
	First third is reserved for pwdCheck object
	Second third is reserved for compundC object
	Third third is reserved for excessC object
- Down cast was used when need access to compundC and excessC object's public functions
- Every invalid password validation will be displayed with failed reasons
- This design applies to compundC
	Each toggle = K cycle * 2
	Max validation = password length * K cycle * 2
- Initialization of excessC object status is inactive.


DATA MEMBERS DICTIONARY:
 enum ObjectName                       -- Use to display objet name
				{
						pwdClass = 0,
						compundC = 1,
						excessC = 2
				};
				const int RAND_MIN = 2          -- Minimum random value
				const int RAND_MAX = 20;        -- Maximum random value
				const int ARR_SIZE = 3;         -- Default array size
				const int ARR_MULTIPLIER = 3;   -- Multiplier to increase array size
				const int REDUCED_LENGTH = 1;   -- Decrement value
				const string ASTERISK = "***************";  -- Prefix and suffix to aling caption
				const string VALID_CHARS ="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijkl" +
						"mnopqrstuvwxyz0123456789#_<>!+*&@^=.?|\\";
				const string INVALID_CHARS = " ~(){}[]ƻ����߶";   -- Mixed invalid character
				const int ONECYLE = 2;                             -- indicate one cycle
				const string NON_ASCII = "������߶";               -- NON-ASCII characters


----------------------------------------------------------------------------------
Notes:
-Run make file by doing the followings:
1. Log into putty
2. Go to directory where project files are stored -> projects -> p4
3. Type "make main"
4. Execute ./main
----------------------------------------------------------------------------------
-- WHEN     WHO		WHAT
	 5/12/19	DD  	Created p4.cpp
	 
*/

#include <iostream>
#include <stdlib.h> /*srand, rand*/

#include "pwdCheck.h"
#include "flip.h"
#include "flipPwdCheck.h"
#include "excessC.h"
#include "flipExcessC.h"
#include "compundC.h"
#include "flipCompundC.h"

using namespace std;

void ProgramIntro();
//flipPwdCheck* InitFlipPwdCheckObject();


const int RAN_MIN = 10;
const int RAN_MAX = 20;
const int DEFAULT_ARR_SIZE = 3;
const int ARR_MULTIPLIER = 3;
const int REDUCED_LENGTH = 1;
const string ASTERISK = "***************";
const string CHARS1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijkl";
const string CHARS2 = "mnopqrstuvwxyz0123456789#_<>!+*&@^=.?|\\";
const string INVALID_CHARS = " ~(){}[]ƻ����߶";
const int ONECYLE = 2;
const string NON_ASCII = "������߶";


int main()
{
//	srand(time(0));
	//flipPwdCheck fpObj[DEFAULT_ARR_SIZE];


	//ProgramIntro();
/*****************PASSWORD AND  LENGTH TO BE USED FOR TEST****************/
	string password = "ecli[";
	int flipIndex = 4;
	cout << "Sent in password: " << password << endl;
	cout << "Length to reverse is: " << flipIndex << endl;
	

	//flipPwdCheck[] obj;
	//flipPwdCheck ob1(flipIndex, password);

	
	/////////////////////////////////////////////////////////////////////////////////////
	//////////////////////SECTION: PWDCHECK, FLIP & FLIPPWDCHECK/////////////////////////
	////////////////////////////////////////////////////////////////////////////////////
	/**************************TEST pwdCheck class******************************/
	/*pwdCheck pwdObject(flipIndex);
	bool isPwdCheck = pwdObject.ValidatePassword(password);
	if (isPwdCheck)
	{
		cout << "Password is validated with pwdCheck" << endl;
	}
	else
	{
		cout << "Password is not validated with pwdCheck" << endl;
	}
*/

	/**************************TEST flip class*********************************/
	//flip fObject(password);
	//string flipped = fObject.flipChar(flipIndex);
	//cout << "Flipped password: " << flipped << endl;


	/****************************TEST flipPwdCheck class***************************/
	//flipPwdCheck* flipPwdCheckObj = new flipPwdCheck(flipIndex, password);
	//bool isFlipped = flipPwdCheckObj->flipPwdCheckCharacter(flipIndex);

	//if (isFlipped)
	//{
	//	cout << "Password is flipped " << endl;
	//}

	/////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////SECTION: EXCESSC & FLIPEXCESSC/////////////////////////
	////////////////////////////////////////////////////////////////////////////////////
  /******************************TEST excessC class*********************************/
	
	excessC exObject(flipIndex, false);


	bool isExCheck = exObject.ValidatePassword(password);
	if (isExCheck)
	{
		cout << "Password is validated with exCessCheck" << endl;
	}
	else
	{
		cout << "Password is not validated with exCessCheck" << endl;
	}


	return 0;
}

void ProgramIntro()
{
	cout << "P4's goal is to design the C++ classes needed to support the notion" << endl;
	cout << "of child classes inheriting from pwdcheck subtypes (from P3)" << endl;
	cout << "and a Flip type as described below.  " << endl;
	cout << "A Flip object encapsulates a string; it primary functionality" << endl;
	cout << "is to accept an integer, say x, as input and 'flip' the first xth" << endl;
	cout << "characters of its encapsulated string, e.g. if 'eclipse' is encapsulated" << endl;
	cout << " 'ilcepse' would be returned when 4 passed." << endl;
	cout << "FlipPwdCheck is-a pwdCheck and is-a Flip. Hence, the functionality of" << endl;
	cout << "both parent types must be supported and should address any overlapping" << endl;
	cout << "notions of state and output. Accomodate the existence of 3 different" << endl;
	cout << "pwdCheck (sub) types - pwdCheck, excessC and compundC." << endl;
	cout << endl;

}

//
//flipPwdCheck* InitFlipPwdCheckObject()
//{
//	//flipPwdCheck* obj[DEFAULT_ARR_SIZE];
//
//	flipPwdCheck fPwd(1, "test");
//	flipPwdCheck obj[DEFAULT_ARR_SIZE]; // = new flipPwdCheck[DEFAULT_ARR_SIZE];
//	string test = "test";
//	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
//	{
//		//obj[i] = fPwd;
//	}
//
//	return obj;
//
//}