#include "monty.h"

/**
 * print_err - function that takes a pointer to a char msg as input
 * @msg: print the standard error stream using fprintf
 *
 * close the program with a failure status using exit
 */
void print_err(char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(EXIT_FAILURE);
}
