#include "monty.h"

char *copy_and_cut(char *line)
{
    char *line_cpy = NULL;
    char *token = NULL;
    char *argument = NULL;
    unsigned int number = 0;
    const char *separators = " $";
    monty_stack_t **stack = NULL;

    *stack = malloc(sizeof(monty_stack_t));
    if (*stack == NULL)
    {
        return (NULL);
    }

    if (line != NULL)
    {
        line_cpy = strdup(line);
        token = strtok(line_cpy, separators);
        argument = strtok(NULL, separators);
        if (argument != NULL)
        {
            number = atoi(argument);
        }
        printf("token = [%s]\n", token);
        printf("number = [%d]\n", number);
        //ici nous scindons notre "line" afin d'avoir dans token = le nom des fonctions a appeler et dans number = la data a inserer dans les nodes
        get_ops(token)(&stack, number);
        //push(&stack, number); ceci fonctionne
    }
    return (token);
}
