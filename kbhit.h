#ifndef _WIN32
	#ifndef KHBIT_H
	#define KHBIT_H
		void changemode(int);
		int  _kbhit(void);
	#endif
#else
	#include <stdio.h>
	#include <conio.h>
#endif
