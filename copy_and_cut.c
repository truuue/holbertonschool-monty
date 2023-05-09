#include "monty.h"

void copy_and_cut(char *line, int line_nb, monty_stack_t **stack)
{
	char *line_cpy = NULL;
	char *cmd = NULL;
	char *argument = NULL;
	unsigned int number = 0;
	const char *separators = " $";
	void (*op_func)(monty_stack_t **, unsigned int) = NULL;

	if (line != NULL)
	{
		line_cpy = strdup(line);
		cmd = strtok(line_cpy, separators);
		argument = strtok(NULL, separators);

		if (argument != NULL)
			number = atoi(argument);

		op_func = get_ops(cmd);

		if (op_func == 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_nb, cmd);
			exit(EXIT_FAILURE);
		}
		else
			op_func(stack, number);

	}

	return;
}
