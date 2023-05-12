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

/**
 * swap - This function swap the first and the newest node
 * @stack: the stack with data
 * @line_nb: the line number with the command
 */
void swap(monty_stack_t **stack, unsigned int line_nb)
{
	monty_stack_t *temp = *stack;
	int k = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_nb);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	k = temp->n;
	temp->n = temp->next->n;
	temp->next->n = k;
}
/**
 * add - This function adds the two newest data
 * @stack: the stack with data
 * @line_nb: the line number with the command
 */
void add(monty_stack_t **stack, unsigned int line_nb)
{
	monty_stack_t *temp = *stack;
	int total = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_nb);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	total = temp->n + temp->next->n;
	temp->next->n = total;
	pop(stack, line_nb);
}

/**
 * sub - This function sub the two newest data
 * @stack: the stack with data
 * @line_nb: the line number with the command
 */
void sub(monty_stack_t **stack, unsigned int line_nb)
{
	monty_stack_t *temp = NULL;
	int total = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_nb);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	total = temp->next->n - temp->n;
	temp->next->n = total;
	pop(stack, line_nb);
}

/**
 * _div - This function divides the second top element
 * of the stack by the top element of the stack.
 * @stack: the stack with data
 * @line_nb: the line number with the command
 */
void _div(monty_stack_t **stack, unsigned int line_nb)
{
	monty_stack_t *temp = *stack;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_nb);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_nb);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	temp->next->n = temp->next->n / temp->n;
	pop(stack, line_nb);
}
