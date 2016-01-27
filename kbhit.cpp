/*
 * Linux implementation of the windows khbit() function
 * Taken from http://cboard.cprogramming.com/c-programming/63166-kbhit-linux.html
 * Purpose: Read input from the keyboard.
 * Usage: Use within a while() loop to search for a keypress.
 * Return value: 1 if a key has been pressed or 0 if it has not
 * Example:
 *
 * int c;
 * do
 * {
 *	   c=khbit()
 * } while(!c)
 * Note that _kbhit() and changemode() WILL NOT be included on windows systems, 
 * which already have a khbit() function in their libraries.
 */
#include "kbhit.h"

#ifndef _WIN32

#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>

/*
 * Function: changemode
 * Purpose: Switch off(or on) the icanon flag for the terminal 
 *          Basically, tells the terminal whether or not to print the key to the output stream after it is pressed.
 * Return type: void
 * Arguments: int dir: 1 or 0 to indicate operation
 */
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

/*
 * Function: _kbhit()
 * Purpose: Read state of keyboard
 * Return type: int, 1 or 0 depending on whether a key has been pressed
 * Arguments: None
 */
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

/*
 * Function: Wait()
 * Purpose: Wait for a keypress, then return keypress to user
 * Return type: Int
 * Arguments: None
 */
int Wait()
{
	int c;

#ifndef _WIN32
	changemode(1);
	while (!_kbhit())
	{
		c = getchar();
		break;
	}
	changemode(0);
#else
	while (1)
	{
		if (_kbhit())
		{
			c = _getch();
			break;
		}
	}
#endif
	return c;
}
