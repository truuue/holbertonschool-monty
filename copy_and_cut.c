#include "monty.h"
/**
 * copy_and_cut - This function copy the input and separate the string
 * @line: the original line
 * @line_nb: the counter of lines reads
 * @stack: the stack we need to fill
 */
void copy_and_cut(char *line, int line_nb, monty_stack_t **stack)
{
	char *line_cpy = NULL;
	char *cmd = NULL;
	char *argument = NULL;
	unsigned int number = 0;
	const char *separators = " $\n";
	void (*op_func)(monty_stack_t **, unsigned int) = NULL;
	int i, check_digit;
	char *push = "push";
	// char *pall = "pall";

	if (line != NULL)
	{
		line_cpy = strdup(line);
		if (line_cpy == NULL)
		{
			global_status = EXIT_FAILURE;
			return;
		}
		cmd = strtok(line_cpy, separators);
		argument = strtok(NULL, separators);
		if (cmd == NULL && argument == NULL)
		{
			free(line_cpy);
			return;
		}

		// if ((strcmp(cmd, pall) == 0) && argument != NULL)

		if ((strcmp(cmd, push) == 0) && argument == NULL)
		{
			fprintf(stderr, "L%d: usage: %s integer\n", line_nb, cmd);
			free(line_cpy);
			global_status = (EXIT_FAILURE);
			return;
		}
		else if ((strcmp(cmd, push) == 0) && argument != NULL)
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
