#include <stdio.h>
#include <stdlib.h>

/**
 * _isdigit - a function that checks for for a digit (0 through 9).
 * @c: a character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

