#include "kbhit.h"
#include <iostream>
using namespace std;

//Function: main()
//Purpose: Simple demonstration of the Wait() function from kbhit.cpp
int main()
{
	int c;

/* Version 1 */
//	cout << "Press a key: ";
//	c=Wait();

/* Version 2 */
	c=Wait("Press a key:");

	cout << endl << "Got: " << (char)c << endl;

	return(0);
}

