/*
 * Linux implementation of the windows _khbit() function
 * Taken from http://cboard.cprogramming.com/c-programming/63166-kbhit-linux.html
 * Purpose: Read input from the keyboard.
 * Usage: Use within a while() loop to search for a keypress.
 * Return value: 1 if a key has been pressed or 0 if it has not
 * Example:
 *
 * int c;
 * do
 * {
 *	   c=_khbit()
 * } while(!c)
 * Note that this WILL NOT be included on windows systems, which already have a khbit() function in their libraries.
 */
#ifndef _WIN32

#include <cstdio>
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include "kbhit.h"

void changemode(int dir)
{
	static struct termios oldt, newt;

	if (dir == 1)
	{
		tcgetattr(STDIN_FILENO, &oldt);
		newt = oldt;
		newt.c_lflag &= ~(ICANON | ECHO);
		tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	}
	else
		tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

int _kbhit(void)
{
	struct timeval tv;
	fd_set rdfs;

	tv.tv_sec = 0;
	tv.tv_usec = 0;

	FD_ZERO(&rdfs);
	FD_SET(STDIN_FILENO, &rdfs);

	select(STDIN_FILENO + 1, &rdfs, NULL, NULL, &tv);
	return FD_ISSET(STDIN_FILENO, &rdfs);

}

#endif
