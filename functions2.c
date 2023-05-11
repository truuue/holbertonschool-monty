#include "monty.h"

/**
 * nop - This function doesn't do anything
 * @stack: the stack with data
 * @line_nb: the line number with the command
 */
void nop(monty_stack_t **stack, unsigned int line_nb)
{
	(void)**stack;
	(void)line_nb;
}
