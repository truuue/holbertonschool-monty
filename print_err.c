#include "monty.h"

/**
 * print_err - function that prints an error message and exits
 * @msg: print the standard error stream using fprintf
 *
 * Closes the program with a failure status using exit
 */
void print_err(char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(EXIT_FAILURE);
}

/**
 * print_err2 - function that prints an error message, free line copy and exits
 * @line_nb: the number of the line with error
 * @cmd: the string line with the command
 * @line_cpy: the string with the copy of the line
 *
 * Closes the program with a failure status using exit
 */
void print_err2(unsigned int line_nb, char *cmd, char *line_cpy)
{
	fprintf(stderr, "L%d: usage: %s integer\n", line_nb, cmd);
	free(line_cpy);
	global_status = (EXIT_FAILURE);
}
