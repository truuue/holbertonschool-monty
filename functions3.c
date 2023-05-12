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

void mod(monty_stack_t **stack, unsigned int line_nb)
{
	monty_stack_t *top, *second_top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_nb);
                free_stack(stack);
                exit(EXIT_FAILURE);
	}

	top = *stack;
	second_top = top->next;

	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_nb);
                free_stack(stack);
                exit(EXIT_FAILURE);
	}

	second_top->n %= top->n;
	*stack = second_top;
	free(top);
}
