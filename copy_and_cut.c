#include "monty.h"
/**
 * copy_and_cut - This function finds the command and its argument in
 * the line
 * @line: the original line
 * @line_nb: the number of the line containing the command
 * @stack: the stack we need to fill
 */
void copy_and_cut(char *line, unsigned int line_nb, monty_stack_t **stack)
{
	char *line_cpy = NULL, *cmd = NULL, *argument = NULL, *push = "push";
	int number = 0;
	const char *separators = " $\n";
	void (*op_func)(monty_stack_t **, unsigned int) = NULL;
	int flag;

	if (line != NULL)
	{
		line_cpy = strdup(line);
		if (*line_cpy == '#')
		{
			free(line_cpy);
			return;
		}
		cmd = strtok(line_cpy, separators);
		argument = strtok(NULL, separators);
		flag = check_digit(cmd, argument, line_nb, line_cpy);
		if (flag == 1)
			return;
		if (argument != NULL)
			number = atoi(argument);
		op_func = get_ops(cmd);
		if (op_func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_nb, cmd);
			free(line_cpy);
			global_status = (EXIT_FAILURE);
			return;
		}
		else
		{
			if (strcmp(cmd, push) == 0)
				op_func(stack, number);
			else
				op_func(stack, line_nb);
		}
	}
	free(line_cpy);
}
