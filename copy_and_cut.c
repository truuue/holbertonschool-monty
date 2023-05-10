#include "monty.h"

void copy_and_cut(char *line, int line_nb, monty_stack_t **stack)
{
	char *line_cpy = NULL;
	char *cmd = NULL;
	char *argument = NULL;
	unsigned int number = 0;
	const char *separators = " $\n";
	void (*op_func)(monty_stack_t **, unsigned int) = NULL;

	if (line != NULL)
	{
		line_cpy = strdup(line);
		cmd = strtok(line_cpy, separators);
		argument = strtok(NULL, separators);
		if (cmd == NULL && argument == NULL)
			return;
		if (argument != NULL)
			number = atoi(argument);

		op_func = get_ops(cmd);

		if (op_func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s", line_nb, cmd);
			free(line_cpy);
			global_status = (EXIT_FAILURE);
			return;
		}
		else
			op_func(stack, number);

	}
	free(line_cpy);

	return;
}
