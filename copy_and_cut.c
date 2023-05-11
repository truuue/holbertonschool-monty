#include "monty.h"

void copy_and_cut(char *line, int line_nb, monty_stack_t **stack)
{
	char *line_cpy = NULL;
	char *cmd = NULL;
	char *argument = NULL;
	unsigned int number = 0;
	const char *separators = " $\n";
	void (*op_func)(monty_stack_t **, unsigned int) = NULL;
	int i, check_digit;

	if (line != NULL)
	{
		line_cpy = strdup(line);
		cmd = strtok(line_cpy, separators);
		argument = strtok(NULL, separators);
		if (cmd == NULL && argument == NULL)
		{
			free(line_cpy);
			return;
		}

		if (argument != NULL)
		{
			for (i = 0; argument[i] != '\0'; i++)
			{
				if ((check_digit = _isdigit(argument[i]) == 0))
				{
					fprintf(stderr, "L%d: usage: %s integer\n", line_nb, cmd);
					free(line_cpy);
					global_status = (EXIT_FAILURE);
					return;
				}
			}
			number = atoi(argument);
		}

		op_func = get_ops(cmd);

		if (op_func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_nb, cmd);
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
