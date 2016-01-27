#ifndef _WIN32
	#ifndef KHBIT_H
	#define KHBIT_H
		void changemode(int);
		int  _kbhit(void);
	#endif
#else
	#include <cstdio>
	#include <conio.h>
#endif

int Wait();
