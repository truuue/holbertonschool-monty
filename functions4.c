#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: double pointer to the beginning of the stack
 * @line_number: current line number in the Monty file
 */
void rotr(monty_stack_t **stack, unsigned int line_nb)
{
	monty_stack_t *temp;
    (void)line_nb;

    temp = *stack;
	if (temp == NULL || temp->next == NULL)
		return;

	while (temp->next)
		temp = temp->next;

    temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev->next = NULL;
	temp->prev = NULL;
	*stack = temp;
}
