#include "monty.h"

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

void free_stack(monty_stack_t **stack)
{
	monty_stack_t *current = *stack;
	monty_stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*stack = NULL;
}
