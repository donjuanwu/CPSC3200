#include <iostream>
#include <stdlib.h>

#include "flip.h";

using namespace std;

int main()
{

	cout << "Welcome, P4." << endl;
	cout<<"	Hello darkness my old friend!" << endl;



	//Testing Flip Validation
	string password = "Seattle";
	int flipIndex = 3;
	cout << "Sent it password: " << password << endl;
	cout << "Length to reverse is: " << flipIndex << endl;
	flip fObject(password);
	string flipped = fObject.flipChar(flipIndex);

	cout << "Flipped password: " << flipped << endl;

	return 0;
}