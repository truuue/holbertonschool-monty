#include "monty.h"

void copy_and_cut(char *line, int line_nb)
{
	char *line_cpy = NULL;
	char *cmd = NULL;
	char *argument = NULL;
	unsigned int number = 0;
	const char *separators = " $";
	void (*op_func)(monty_stack_t **, unsigned int) = NULL;
	monty_stack_t **stack = NULL;
	monty_stack_t *head = NULL;

	head = malloc(sizeof(monty_stack_t));
	if (head == NULL)
		return;
	stack = &head;

	if (line != NULL)
	{
		line_cpy = strdup(line);
		cmd = strtok(line_cpy, separators);
		argument = strtok(NULL, separators);

		if (argument != NULL)
			number = atoi(argument);

		// printf("cmd = [%s]\n", cmd);
		// printf("number = [%d]\n", number);
		op_func = get_ops(cmd);

		if (op_func == 0)
			printf("Commande inconnue à la ligne %d\n", line_nb);
		else
			op_func(stack, number);

	}

	return;
}
