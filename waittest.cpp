#include "kbhit.h"
#include <iostream>
#include <cstdio>
using namespace std;

int Wait();

int main()
{
	int c;

	c=Wait();

	cout << endl << "Got: " << (char)c << endl;

	return(0);
}

int Wait()
{
	int c;
	cout << "Press any key: ";

#ifndef _WIN32
	changemode(1);
	while(!_kbhit())
	{
		c=getchar();
		break;
	}
	changemode(0);
#else
	while(1)
	{
		if(_kbhit())
		{
			c=_getch();
			break;
		}
	}
#endif
	return c;
}
