#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: double pointer to the beginning of the stack
 * @line_nb: current line number in the Monty file
 */
void rotr(monty_stack_t **stack, unsigned int line_nb)
{
	monty_stack_t *last = NULL, *second_last = NULL;
	(void)line_nb;

	if (!*stack || !(*stack)->next)
		return;

	last = *stack;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}

	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}
