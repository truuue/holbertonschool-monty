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

/**
 * mod - computes the rest of the div of the sec top element of the stack
 * by the top element of the stack.
 * @stack: double pointer to the beginning of the stack
 * @line_nb: line number of the opcode
 */
void mod(monty_stack_t **stack, unsigned int line_nb)
{
	monty_stack_t *top, *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_nb);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	temp = top->next;
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_nb);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	temp->n %= top->n;
	*stack = temp;
	free(top);
}

/**
 * pchar - prints the ascii value of the integer at the top of the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void pchar(monty_stack_t **stack, unsigned int line_number)
{
	int value;

	if (*stack == NULL)
	{
		print_err2(line_number, "pchar", NULL);
		return;
	}

	value = (*stack)->n;
	if (value < 0 || value > 127)
	{
		print_err2(line_number, "pchar", NULL);
		return;
	}
	printf("%c\n", value);
}

