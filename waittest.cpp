#include "kbhit.h"
#include <iostream>
using namespace std;

//Function: main()
//Purpose: Simple demonstration of the Wait() function from kbhit.cpp
int main()
{
	int c;

	cout << "Press a key: ";

	c=Wait();

	cout << endl << "Got: " << (char)c << endl;

	return(0);
}

