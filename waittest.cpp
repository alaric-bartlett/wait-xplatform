#include "kbhit.h"
#include <iostream>
using namespace std;

int main()
{
	int c;

	cout << "Press a key: ";

	c=Wait();

	cout << endl << "Got: " << (char)c << endl;

	return(0);
}

