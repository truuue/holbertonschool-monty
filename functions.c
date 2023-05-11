#include "monty.h"

/**
 * push - This function creates a node with the int given in parameter
 * @stack: the stack we need to fill
 * @number: the int/data to fill in the node
 */
void push(monty_stack_t **stack, unsigned int number)
{
	monty_stack_t *new_node = malloc(sizeof(monty_stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		global_status = EXIT_FAILURE;
		return;
	}

	new_node->n = number;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}

/**
 * pall - This function print all the data in the stack
 * @stack: the stack containing data
 * @number: unused here
 */
void pall(monty_stack_t **stack, unsigned int number)
{
	monty_stack_t *i = NULL;

	(void)number;
	if (stack == NULL)
	{
		printf("Stack is empty\n");
		global_status = (EXIT_FAILURE);
		return;
	}

	for (i = *stack; i != NULL; i = i->next)
	{
		printf("%d\n", i->n);
	}
}

/**
 * free_stack - This function frees the stack
 * @stack: the stack we need to free
 */
void free_stack(monty_stack_t **stack)
{
	monty_stack_t *current = *stack;
	monty_stack_t *next;

	if (*stack != NULL)
	{
		while (current != NULL)
		{
			next = current->next;
			free(current);
			current = next;
		}
		*stack = NULL;
	}
}

/**
 * pint - This function prints the value at the top of the stack,
 * followed by a new line
 * @stack: the stack with data
 * @line_nb: the line number with the command
 */
void pint(monty_stack_t **stack, unsigned int line_nb)
{
	if (*stack != NULL)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_nb);
		global_status = (EXIT_FAILURE);
		return;
	}
}

/**
 * pop - this function removes the top element of the stack.
 * @stack: the stack with data
 * @line_nb: the line number with the command
 */
void pop(monty_stack_t **stack, unsigned int line_nb)
{
	monty_stack_t *temp = NULL;

	if (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		if (*stack != NULL)
			(*stack)->prev = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_nb);
		global_status = (EXIT_FAILURE);
		return;
	}
}
