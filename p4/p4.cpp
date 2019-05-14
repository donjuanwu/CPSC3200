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
				const string INVALID_CHARS = " ~(){}[]∆ªÿ¯≈Âﬂ∂";   -- Mixed invalid character
				const int ONECYLE = 2;                             -- indicate one cycle
				const string NON_ASCII = "∆Êÿ¯≈Âﬂ∂";               -- NON-ASCII characters


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
string GenerateRandomPassword(bool isValid);


void InitFlipPwdCheckObject(flipPwdCheck* obj);
void TestFlipClass(flipPwdCheck* obj);
void TestPwdCheckClass(flipPwdCheck* obj);

void InitFlipExcessCObject(flipExcessC* obj);



const int RAN_MIN = 2;
const int RAN_MAX = 20;
const int DEFAULT_ARR_SIZE = 3;
const int ARR_MULTIPLIER = 3;
const int REDUCED_LENGTH = 1;
const string ASTERISK = "******";
const string VALID_CHARS1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijkl";
const string VALID_CHARS2 = "mnopqrstuvwxyz0123456789#_<>!+*&@^=.?|\\";
const string INVALID_CHARS = " ~(){}[]∆ªÿ¯≈Âﬂ∂";
const bool ISVALIDPWD = true;
const int ONECYLE = 2;
const string NON_ASCII = "∆Êÿ¯≈Âﬂ∂";


int main()
{
	srand(static_cast<unsigned>(time(0)));

  //flipPwdCheck fpObj[DEFAULT_ARR_SIZE];
	//InitFlipPwdCheckObject(fpObj);
	//TestFlipClass(fpObj);
	//TestPwdCheckClass(fpObj);
	
	flipExcessC feObj[DEFAULT_ARR_SIZE];
	InitFlipExcessCObject(feObj);




	//ProgramIntro();


	

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
	
	/*excessC exObject(flipIndex, false);


	bool isExCheck = exObject.ValidatePassword(password);
	if (isExCheck)
	{
		cout << "Password is validated with exCessCheck" << endl;
	}
	else
	{
		cout << "Password is not validated with exCessCheck" << endl;
	}*/


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


void InitFlipPwdCheckObject(flipPwdCheck* obj)
{
	cout << endl;
	cout << ASTERISK + "Begin Initialize FLIP PWDCHECK OBJECTS" + ASTERISK << endl;
	cout << " - Generated " << DEFAULT_ARR_SIZE << " FlipPwdCheck Objects" << endl;
	cout << " - Store " << DEFAULT_ARR_SIZE << " FlipPwdCheck Objects in a stack array" << endl;
	string pwd = GenerateRandomPassword(true);
	int num; 
	cout << " - Generated password " << "'" << pwd << "'" << " to pass to flip constructor" << endl;

	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		obj[i] = flipPwdCheck(num, pwd);
		cout << " - " << i + 1 << ")" << " random password length " << num << " to pass into pwdCheck constructor " << endl;
	}
	cout << ASTERISK + " End Initialize FLIP PWDCHECK OBJECTS" + ASTERISK << endl;

}

string GenerateRandomPassword(bool isValidPwd)
{
	string strGenPwd;
	string strStringRepo = VALID_CHARS1 + VALID_CHARS2;
	if (!isValidPwd)
	{
		strStringRepo = VALID_CHARS1 + VALID_CHARS2 + INVALID_CHARS;
	}

	unsigned int strLen = (unsigned)strStringRepo.length();
	unsigned int pwdLen = (unsigned)rand() % RAN_MAX + RAN_MIN;
	for (unsigned int i = 0; i < pwdLen; i++)
	{
		strGenPwd += strStringRepo[rand() % strLen + 1];
	}

	return strGenPwd;
}

void TestFlipClass(flipPwdCheck* obj)
{
	cout << endl;
	cout << ASTERISK + "Begin test FLIP class" + ASTERISK << endl;

	unsigned int rIndex;
	string strFlipped;
	for (unsigned int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		rIndex = rand() % RAN_MAX + RAN_MIN;
		cout << "- flip beginning " << rIndex << " characters in password" << endl;

		strFlipped = obj[i].flipChar(rIndex);
		cout << " Flipped password " << "'" << strFlipped << "'" << endl;
	}

	cout << ASTERISK + "End test FLIP class" + ASTERISK << endl;
}

void TestPwdCheckClass(flipPwdCheck* obj)
{
	cout << endl;
	cout << ASTERISK + "Begin test PwdCheck class" + ASTERISK << endl;

	string strAlphaNum;
	for (unsigned int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		
		strAlphaNum = GenerateRandomPassword(true);
		if (obj[i].ValidatePassword(strAlphaNum))
		{
			cout << strAlphaNum <<" is a valid password" << endl;
		}
		else
		{
			cout << strAlphaNum << " is not a valid password" << endl;
			cout << "reason(s):" << endl;
			if (obj[i].GetObjectStatus())
			{
			  //pwdCheck object is active
				if ((int)strAlphaNum.length() < obj[i].GetPasswordLength())
				{
					cout << "- password length doesn't meet minimum requirement" << endl;
					cout << "  minimum lenght: " << obj[i].GetPasswordLength() << endl;
					cout << "  password length: " << strAlphaNum.length() << endl;
				}
				else
				{
					//password length is valid
					if (obj[i].GetIsCharForbidden())
					{
						cout << "- password contains invalid character(s)" << endl;
					}
					
				}
			}
			else
			{
				cout << "- pwdCheck object is not active " << endl;
			}
			
		}
		
	}

	cout << ASTERISK + "End test PwdCheck class" + ASTERISK << endl;
}

void InitFlipExcessCObject(flipExcessC* obj)
{
	cout << endl;
	cout << ASTERISK + "Begin Initialize FLIP EXCESSC OBJECTS" + ASTERISK << endl;
	cout << " - Generated " << DEFAULT_ARR_SIZE << " FlipExcessC Objects" << endl;
	cout << " - Store " << DEFAULT_ARR_SIZE << " FlipExcessC Objects in a stack array" << endl;
	string pwd = GenerateRandomPassword(true);
	int num;
	bool isActive;
	cout << " - Generated password " << "'" << pwd << "'" << " to pass to flip constructor" << endl;

	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		cout << " - Random number " << "'" << num << "'" << " to pass to excessC constructor" << endl;
		if (i % 2)
		{
			isActive = false;
		}
		else
		{
			isActive = true;
		}
		cout << " - Generated random status " << "'" << isActive << "'" << " to pass to excessC constructor" << endl;
		obj[i] = flipExcessC(num, isActive, pwd);
		cout << " - " << i + 1 << ")" << " random password length " << num << " to pass into pwdCheck constructor " << endl;
	}
	cout << ASTERISK + " End Initialize FLIP EXCESSC OBJECTS" + ASTERISK << endl;

}