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


#include <stdlib.h> /*srand, rand*/
#include <iostream>

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
void TestFlipClass_With_FlipPwdCheck(flipPwdCheck* obj);
//void TestPwdCheckClass_With_FlipPwdCheck(flipPwdCheck* obj);
void TestMixedPassword_With_FlipPwdCheck(flipPwdCheck* obj);
void TestToggle_With_FlipPwdClass(flipPwdCheck* obj);

void InitFlipExcessCObject(flipExcessC* obj);
void TestExcessClass_With_FlipExcessClass(flipExcessC* obj);
//void TestFlipClass_With_FlipExcessClass(flipExcessC* obj);
void TestMixedPassword_With_FlipExcessClass(flipExcessC* obj);
void TestsToggle_With_FlipExcessCClass(flipExcessC* obj);



void InitFlipCompundCObject(flipCompundC* obj);
void TestFlipClass_With_FlipCompundCClass(flipCompundC* obj);
//void TestCompundCClass_With_FlipCompundCClass(flipCompundC* obj);
void TestMixedPassword_With_FlipCompundClass(flipCompundC* obj);


const int RAN_MIN = 2;
const int RAN_MAX = 20;
const int DEFAULT_ARR_SIZE = 3;
const int ARR_MULTIPLIER = 3;
const int REDUCED_LENGTH = 1;
const string ASTERISK = "******";
const string VALID_CHARS1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijkl";
const string VALID_CHARS2 = "mnopqrstuvwxyz0123456789#_<>!+*&@^=.?|$";
const string INVALID_CHARS = " ~(){}[]"; 
const bool ISVALIDPWD = true;
const int ONECYLE = 2;
const string NON_ASCII = "∆Êÿ¯≈Âﬂ∂";
const int DIVISOR = 2;


int main()
{
	srand(static_cast<unsigned>(time(0)));
	//ProgramIntro();

 // flipPwdCheck fPObj[DEFAULT_ARR_SIZE];
	//InitFlipPwdCheckObject(fPObj);
	////TestFlipClass_With_FlipPwdCheck(fPObj);
	//////TestPwdCheckClass_With_FlipPwdCheck(fPObj);
	//TestMixedPassword_With_FlipPwdCheck(fPObj);
	//TestToggle_With_FlipPwdClass(fPObj);

	flipExcessC fEObj[DEFAULT_ARR_SIZE];
	InitFlipExcessCObject(fEObj);
	//TestFlipClass_With_FlipExcessClass(fEObj);
	//TestExcessClass_With_FlipExcessClass(fEObj);
	//TestMixedPassword_With_FlipExcessClass(fEObj);
	TestsToggle_With_FlipExcessCClass(fEObj);

	//flipCompundC fCObj[DEFAULT_ARR_SIZE];
	//InitFlipCompundCObject(fCObj);
	//TestFlipClass_With_FlipCompundCClass(fCObj);
	////TestCompundCClass_With_FlipCompundCClass(fCObj);
	//TestMixedPassword_With_FlipCompundClass(fCObj);
	





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


////////////////////////////////////	FLIP PWDCHECK SECTION///////////////////////////////////////////

void InitFlipPwdCheckObject(flipPwdCheck* obj)
{
	cout << endl;
	cout << ASTERISK + "Begin Initialize FLIP PWDCHECK Objects" + ASTERISK << endl;
	cout << " - Generated " << DEFAULT_ARR_SIZE << " FlipPwdCheck Objects" << endl;
	cout << " - Stored " << DEFAULT_ARR_SIZE << " FlipPwdCheck Objects in a static array" << endl;
	cout << " - Fired flipPwdCheck constructors " << DEFAULT_ARR_SIZE << " times" << endl;
	string pwd = GenerateRandomPassword(true);
	int num; 
	cout << " - Generated password " << "'" << pwd << "'" << " pass to flip constructor" << endl;

	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		obj[i] = flipPwdCheck(num, pwd);
		cout << i + 1 << ")" << " Random password length " << num << " pass into pwdCheck constructor " << endl;
	}
	cout << ASTERISK + " End Initialize FLIP PWDCHECK Objects" + ASTERISK << endl;

}


void TestFlipClass_With_FlipPwdCheck(flipPwdCheck* obj)
{
	cout << endl;
	cout << ASTERISK + "Begin Test Flip Password With FlipPwdCheck Object" + ASTERISK << endl;
	cout << "Attempt to flip password " << DEFAULT_ARR_SIZE << " times with " << DEFAULT_ARR_SIZE << " different indexes " << endl;

	unsigned int rIndex;
	string strFlipped;
	for (unsigned int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		rIndex = rand() % RAN_MAX + RAN_MIN;
		cout << i + 1 << ")flip beginning " << rIndex << " characters in password" << endl;

		strFlipped = obj[i].flipChar(rIndex);
		cout << " Flipped password: " <<  strFlipped << endl;
	}

	cout << ASTERISK + "End Test Flip Password With FlipPwdCheck Object" + ASTERISK << endl;
}

//void TestPwdCheckClass_With_FlipPwdCheck(flipPwdCheck* obj)
//{
//	cout << endl;
//	cout << ASTERISK + "Begin Validate Password Length With FlipPwdCheck Object" + ASTERISK << endl;
//	cout << " - Passed in password has no forbidden characters" + ASTERISK << endl;
//
//	string strAlphaNum;
//	for (unsigned int i = 0; i < DEFAULT_ARR_SIZE; i++)
//	{
//		
//		strAlphaNum = GenerateRandomPassword(true);
//		if (obj[i].ValidatePassword(strAlphaNum))
//		{
//			cout << i + 1 << ")" << strAlphaNum <<" is a valid password" << endl;
//		}
//		else
//		{
//			cout << i + 1 << ")" << strAlphaNum << " is not a valid password" << endl;
//			cout << "reason(s):" << endl;
//			if (obj[i].GetObjectStatus())
//			{
//			  //pwdCheck object is active
//				if ((int)strAlphaNum.length() < obj[i].GetPasswordLength())
//				{
//					cout << "- password length doesn't meet minimum requirement" << endl;
//					cout << "  minimum lenght: " << obj[i].GetPasswordLength() << endl;
//					cout << "  password length: " << strAlphaNum.length() << endl;
//				}
//			}
//			else
//			{
//				cout << "- pwdCheck object is not active " << endl;
//			}
//			
//		}
//		
//	}
//
//	cout << ASTERISK + "End Validate Password Length With FlipPwdCheck Object" + ASTERISK << endl;
//}

void TestMixedPassword_With_FlipPwdCheck(flipPwdCheck* obj)
{
	cout << endl;
	cout << ASTERISK + "Begin Validate Mixed Password With FlipPwdCheck Object" + ASTERISK << endl;
	cout << " - validate mixed password in PwdCheck class" << endl;
	cout << " - Passed in password length is random" + ASTERISK << endl;
	cout << " - Passed in password may contains forbidden characters" + ASTERISK << endl;

	string strAlphaNum;
	for (unsigned int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{

		strAlphaNum = GenerateRandomPassword(false);
		if (obj[i].ValidatePassword(strAlphaNum))
		{

			if (obj[i].GetObjectStatus())
			{
				cout << i + 1 << ") PwdCheck is active" << endl;
			}
			else
			{
				cout << i + 1 << ") PwdCheck is inactive" << endl;
			}

			cout << strAlphaNum << " is a valid password" << endl;
		}
		else
		{
			if (obj[i].GetObjectStatus())
			{
				cout << i + 1 << ") PwdCheck is active" << endl;
			}
			else
			{
				cout << i + 1 << ") PwdCheck is inactive" << endl;
			}

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
					if (obj[i].GetIsCharForbidden())
					{
						cout << "- password contains forbidden characters" << endl;
					}
				}
			}
			else
			{
				cout << "- pwdCheck object is  inactive " << endl;
			}

		}

	}
	cout << ASTERISK + "End Validate Mixed Password With FlipPwdCheck Object" + ASTERISK << endl;
}


////////////////////////////////////	FLIP EXCESS SECTION///////////////////////////////////////////
void InitFlipExcessCObject(flipExcessC* obj)
{
	string pwd = GenerateRandomPassword(true);
	int num;
	bool isActive;
	string strObjStatus = "inactive";
	
	cout << endl;
	cout << ASTERISK + "Begin Initialize FLIP EXCESSC Objects" + ASTERISK << endl;
	cout << " - Generated " << DEFAULT_ARR_SIZE << " FlipExcessC Objects" << endl;
	cout << " - Stored " << DEFAULT_ARR_SIZE << " FlipExcessC Objects in a static array" << endl;
	cout << " - Fired flipExcessC constructors " << DEFAULT_ARR_SIZE << " times" << endl;	
	cout << " - Generated password " << "'" << pwd << "'" << " pass to flip constructor" << endl;

	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		num = rand() % RAN_MAX + RAN_MIN;
		if (num % DIVISOR)
		{
			isActive = false;
			strObjStatus = "inactive";
		}
		else
		{
			isActive = true;
			strObjStatus = "active";
		}
	
		
		cout << i + 1 <<")Random password length " << num << " and status " "'" << strObjStatus << "' pass to excessC constructor" << endl;
		obj[i] = flipExcessC(num, isActive, pwd);
	}
	cout << ASTERISK + " End Initialize FLIP EXCESSC Objects" + ASTERISK << endl;

}

void TestExcessClass_With_FlipExcessClass(flipExcessC* obj)
{
	cout << endl;
	cout << ASTERISK + "Begin Validate Password Length With FlipExcess Object" + ASTERISK << endl;
	cout << "- Passed in password has no forbidden characters" << endl;
	string strAlphaNum;
	for (unsigned int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{

		strAlphaNum = GenerateRandomPassword(true);
		if (obj[i].ValidatePassword(strAlphaNum))
		{
			cout << i + 1 <<")" << strAlphaNum << " is a valid password" << endl;
		}
		else
		{
			cout << i + 1 << ")" << strAlphaNum << " is not a valid password" << endl;
			cout << "reason(s):" << endl;
			if (obj[i].GetObjectStatus())
			{
				//ExcessC object is active
				if ((int)strAlphaNum.length() < obj[i].GetPasswordLength())
				{
					cout << "- password length doesn't meet minimum requirement" << endl;
					cout << "  minimum lenght: " << obj[i].GetPasswordLength() << endl;
					cout << "  password length: " << strAlphaNum.length() << endl;
				}
				
			}
			else
			{
				cout << "- ExcessC object is not active " << endl;
			}

		}

	}

	cout << ASTERISK + "End Validate Password Length With FlipExcess Object" + ASTERISK << endl;
}

//void TestFlipClass_With_FlipExcessClass(flipExcessC* obj)
//{
//	cout << endl;
//	cout << ASTERISK + "Begin Test FLIP Password With FlipExcess Object" + ASTERISK << endl;
//	cout << "Attempt to flip password " << DEFAULT_ARR_SIZE << " times with " << DEFAULT_ARR_SIZE << " different indexes " << endl;
//
//	unsigned int rIndex;
//	string strFlipped;
//	for (unsigned int i = 0; i < DEFAULT_ARR_SIZE; i++)
//	{
//		rIndex = rand() % RAN_MAX + RAN_MIN;
//		cout << i + 1 << ") flip beginning " << rIndex << " characters in password" << endl;
//
//		strFlipped = obj[i].flipChar(rIndex);
//		cout << " Flipped password:" << strFlipped << endl;
//	}
//
//	cout << ASTERISK + "End Test FLIP Password With FlipExcess Object" + ASTERISK << endl;
//}

void TestMixedPassword_With_FlipExcessClass(flipExcessC* obj)
{
	cout << endl;
	cout << ASTERISK + "Begin Validate Mixed Password With FlipExcessC Object" + ASTERISK << endl;
	cout << " - validate mixed password in ExcessC class" << endl;
	cout << " - Passed in password length is random" + ASTERISK << endl;
	cout << " - Passed in password may contains forbidden characters" + ASTERISK << endl;
	cout << endl;
	string strAlphaNum;
	for (unsigned int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{

		strAlphaNum = GenerateRandomPassword(false);
		if (obj[i].GetExObjectStatus())
		{
			cout << i + 1 << ") ExcessC object is active" << endl;
		}
		else
		{
			cout << i + 1 << ") ExcessC object is inactive" << endl;
		}


		if (obj[i].ValidatePassword(strAlphaNum))
		{
			cout << strAlphaNum << " is a valid password" << endl;
		}
		else
		{
			cout << strAlphaNum << " is not a valid password" << endl;
			cout << "reason(s):" << endl;


			if (obj[i].GetExObjectStatus())
			{
				if (!obj[i].GetIsInteger())
				{
					cout << "- password doesn't contain a digit at the end" << endl;
				}
				else if (!obj[i].GetIsMixedCase())
				{
					cout << "- password doesn't contain mixed case" << endl;
				}
				else
				{
					cout << "- password doesn't contain '$' sign" << endl;
				}
			
			}
			else
			{
				if (obj[i].GetObjectStatus())
				{
					//check pwd length
					if ((int)strAlphaNum.length() < obj[i].GetPasswordLength())
					{
						cout << "- password length doesn't meet minimum requirement" << endl;
						cout << "  minimum lenght: " << obj[i].GetPasswordLength() << endl;
						cout << "  password length: " << strAlphaNum.length() << endl;
					}
					else if (obj[i].GetIsCharForbidden()) //check is forbidden password
					{
						cout << "- password contains forbidden character(s)" << endl;
					}

				}
				else
				{
					cout << "- PwdCheck object is inactive" << endl;
				}
				
			}
		}

	}
	cout << ASTERISK + "End Validate Mixed Password With FlipExcessC Object" + ASTERISK << endl;
}



////////////////////////////////////	FLIP COMPUNDC SECTION///////////////////////////////////////////
void InitFlipCompundCObject(flipCompundC* obj)
{
	string pwd = GenerateRandomPassword(true);
	unsigned int len;
	unsigned int toggleNum;

	cout << endl;
	cout << ASTERISK + "Begin Initialize FLIP CompundC Objects" + ASTERISK << endl;
	cout << " - Generated " << DEFAULT_ARR_SIZE << " FlipCompundC Objects" << endl;
	cout << " - Stored " << DEFAULT_ARR_SIZE << " FlipCompundC Objects in a static array" << endl;
	cout << " - Fired flipCompundC constructors " << DEFAULT_ARR_SIZE << " times" << endl;
	cout << " - Generated password " << "'" << pwd << "'" << " pass to flip constructor" << endl;

	for (unsigned int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		len = rand() % RAN_MAX + RAN_MIN;
		toggleNum = rand() % RAN_MAX + RAN_MIN;
	
		cout << i + 1 << ")Random password length " << len << " and toggle limit " << toggleNum << " pass to compundC constructor" << endl;
		obj[i] = flipCompundC(len, toggleNum, pwd);
	}
	cout << ASTERISK + " End Initialize FLIP CompundC Objects" + ASTERISK << endl;
}

void TestFlipClass_With_FlipCompundCClass(flipCompundC* obj)
{
	cout << endl;
	cout << ASTERISK + "Begin Test FLIP Password With FlipCompundC Object" + ASTERISK << endl;
	cout << "Attempt to flip password " << DEFAULT_ARR_SIZE << " times with " << DEFAULT_ARR_SIZE << " different indexes " << endl;
	unsigned int rIndex;
	string strFlipped;
	for (unsigned int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		rIndex = rand() % RAN_MAX + RAN_MIN;
		cout << i + 1 << ") flip beginning " << rIndex << " characters in password" << endl;

		strFlipped = obj[i].flipChar(rIndex);
		cout << " Flipped password: " << strFlipped << endl;
	}

	cout << ASTERISK + "End Test FLIP Password With FlipCompundC Object" + ASTERISK << endl;
}
//
//void TestCompundCClass_With_FlipCompundCClass(flipCompundC* obj)
//{
//	cout << endl;
//	cout << ASTERISK + "Begin Validate Password With FlipCompundC Object" + ASTERISK << endl;
//	cout << "- Passed in password has no forbidden characters" << endl;
//
//	string strAlphaNum;
//	for (unsigned int i = 0; i < DEFAULT_ARR_SIZE; i++)
//	{
//		strAlphaNum = GenerateRandomPassword(true);
//		if (obj[i].ValidatePassword(strAlphaNum))
//		{
//			cout << i + 1 << ")" << strAlphaNum << " is a valid password" << endl;
//		}
//		else
//		{
//			cout << i + 1 << ")" << strAlphaNum << " is not a valid password" << endl;
//			cout << "reason(s):" << endl;
//			if (obj[i].GetObjectStatus())
//			{
//				//CompundC object is active
//				if ((int)strAlphaNum.length() < obj[i].GetPasswordLength())
//				{
//					cout << "- password length doesn't meet minimum requirement" << endl;
//					cout << "  minimum lenght: " << obj[i].GetPasswordLength() << endl;
//					cout << "  password length: " << strAlphaNum.length() << endl;
//				}
//			
//			}
//			else
//			{
//				cout << "- CompundC object is not active " << endl;
//			}
//
//		}
//
//	}
//
//	cout << ASTERISK + "End Validate Password With FlipCompundC Object" + ASTERISK << endl;
//}

void TestMixedPassword_With_FlipCompundClass(flipCompundC* obj)
{
	cout << endl;
	cout << ASTERISK + "Begin Validate Mixed Password With FlipCompundC Object" + ASTERISK << endl;
	cout << " - validate mixed password in CompundC class" << endl;
	cout << " - Passed in password length is random" + ASTERISK << endl;
	cout << " - Passed in password may contains forbidden characters" + ASTERISK << endl;
	cout << endl;
	string strAlphaNum;
	for (unsigned int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{

		strAlphaNum = GenerateRandomPassword(false);
		if (!obj[i].IsObjectLocked())
		{
			cout << i + 1 << ") CompundC object is not locked" << endl;

			if (obj[i].ValidatePassword(strAlphaNum))
			{
				cout << strAlphaNum << " is a valid password" << endl;
			}
			else //not valid password
			{
				cout << strAlphaNum << " is not a valid password" << endl;
				cout << "reason(s):" << endl;

				if (!obj[i].GetObjectStatus())
				{
					
					cout << "- PwdCheck object is not active " << endl;
				}
				else
				{
					//PwdCheck is active
					if ((int)strAlphaNum.length() < obj[i].GetPasswordLength())
					{
						cout << "- password length doesn't meet minimum requirement" << endl;
						cout << "  minimum lenght: " << obj[i].GetPasswordLength() << endl;
						cout << "  password length: " << strAlphaNum.length() << endl;
					}
					if (obj[i].GetIsCharForbidden())
					{
							cout << "- password contains forbidden characters" << endl;
					}
					if (!obj[i].IsRepeatedChar(strAlphaNum))
					{
						cout << "- password doesn't contain repeated characters" << endl;
					}
				}
			}


		}
		else
		{
			cout << i + 1 << ") CompundC object is locked" << endl;
		}
	}
	cout << ASTERISK + "End Validate Mixed Password With FlipCompundC Object" + ASTERISK << endl;
}

//////////////////////////////TOGGLE WITH DISTINCT ARRAY OBJECTS///////////////////////////////////////
void TestToggle_With_FlipPwdClass(flipPwdCheck* obj)
{

	cout << endl;
	cout << ASTERISK + "Begin Test Toggle With FlipPwdCheck Objects" + ASTERISK << endl;
	//cout << " - Passed in password may contains forbidden characters" + ASTERISK << endl;
	//cout << endl;

	string strPassword; 
	bool pStatus;
	int toggledMax;
	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		toggledMax = obj[i].GetPasswordLength();
		pStatus = obj[i].GetObjectStatus();
		cout << i + 1 << ") PwdCheck object at index " << i << " current status = " << (obj[i].GetObjectStatus() ? "active" : "inactive") << endl;
		cout << " - password length " << toggledMax << endl;
		while (pStatus == obj[i].GetObjectStatus())
		{
			strPassword = GenerateRandomPassword(false);
			obj[i].ValidatePassword(strPassword);
			
		}

		cout << " - pwdCheck object at index " << i << " was toggled" << endl;
		cout << " - toggled at " << toggledMax << " requests " << endl; 
		cout << " - updated status = " << (obj[i].GetObjectStatus() ? "active" : "inactive") << endl;

	}

	cout << endl;
	cout << " Attempted to untoggled the previous PwdCheck objects...." << endl;
	cout << endl;

	for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		toggledMax = obj[i].GetPasswordLength();
		pStatus = obj[i].GetObjectStatus();
		cout << i + 1 << ") PwdCheck object at index " << i << " current status = " << (obj[i].GetObjectStatus() ? "active" : "inactive") << endl;
		cout << " - password length " << toggledMax << endl;
		while (pStatus == obj[i].GetObjectStatus())
		{
			strPassword = GenerateRandomPassword(false);
			obj[i].ValidatePassword(strPassword);

		}

		cout << " - pwdCheck object at index " << i << " was toggled" << endl;
		cout << " - toggled at " << toggledMax << " requests " << endl;
		cout << " - updated status = " << (obj[i].GetObjectStatus() ? "active" : "inactive") << endl;

	}


	cout << ASTERISK + "End Test Toggle With FlipPwdCheck Objects" + ASTERISK << endl;
}


void TestsToggle_With_FlipExcessCClass(flipExcessC* obj)
{
	cout << endl;
	cout << ASTERISK + "Begin Test Toggle With FlipExcessC Objects" + ASTERISK << endl;
	
	bool exIsActive;
	int cToggledLimit;
	string strPassword;

	for (unsigned int i = 0; i < DEFAULT_ARR_SIZE; i++)
	{
		exIsActive = obj[i].GetExObjectStatus();

		if (exIsActive)
		{
			cout << i + 1 << ") ExcessC object at index " << i << " current status = " << (exIsActive ? "active" : "inactive") << endl;
			cout << " - by design when ExcessC status = " << (exIsActive ? "active" : "inactive") << endl;
			cout << " - ExcessC object state can't be toggled " << endl;
		}
		else
		{
			cout << i + 1 << ") ExcessC object at index " << i << " current status = " << (exIsActive ? "active" : "inactive") << endl;
			cToggledLimit = obj[i].GetPasswordLength();
			while (exIsActive == obj[i].GetObjectStatus())
			{
				strPassword = GenerateRandomPassword(false);
				obj[i].ValidatePassword(strPassword);
			}
			cout << " - ExcessC object at index " << i << " was toggled" << endl;
			cout << " - toggled at " << cToggledLimit << " requests " << endl;
			cout << " - updated status = " << (obj[i].GetObjectStatus() ? "active" : "inactive") << endl;
		}
	}

	cout << ASTERISK + "End Test Toggle With FlipExcessC Objects" + ASTERISK << endl;
}


