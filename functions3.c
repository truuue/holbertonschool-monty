#include "monty.h"

/**
 * mul - This function multiplies the second top element
 * of the stack with the top element of the stack
 * @stack: the stack with data
 * @line_nb: the line number with the command
 */
void mul(monty_stack_t **stack, unsigned int line_nb)
{
	monty_stack_t *temp = *stack;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_nb);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	temp->next->n = temp->next->n * temp->n;
	pop(stack, line_nb);
}
