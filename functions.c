#include "monty.h"

int push (monty_stack_t **stack, unsigned int number)
{
  monty_stack_t *new_node = malloc(sizeof(monty_stack_t));
   printf("number in functions = [%d]\n", number);

if (new_node == NULL)
  {
    return (1);
  }
new_node ->n = number;
new_node->next = *stack;
new_node->prev = NULL;
stack = &new_node;
 printf("number in struct = [%d]\n", new_node->n);

 //pall(*stack); //ceci est un test pour verifier si le print fonctionne

return (0);
}

int pall(monty_stack_t *stack)
{
    if (stack == NULL)
    {
        printf("Stack is empty\n");
        return (1);
    }

    monty_stack_t *i;
    for (i = stack; i != NULL; i = i->next)
    {
        printf("%d\n", i->n);
    }
    return(0);
}

