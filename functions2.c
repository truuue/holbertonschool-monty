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

void swap(monty_stack_t **stack, unsigned int line_nb)
{
	monty_stack_t *temp = *stack;
	int k = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_nb);
		free_stack(stack);
		global_status = (EXIT_FAILURE);
	}
	k = temp->n;
	temp->n = temp->next->n;
	temp->next->n = k;
}
