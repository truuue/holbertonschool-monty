#include "monty.h"

/**
 * _isdigit - a function that checks for for a digit (0 through 9).
 * @c: a character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	if ((c >= 48 && c <= 57) || (c == '-'))
		return (1);
	else
		return (0);
}

int check_digit(char *cmd, char *argument, int line_nb, char *line_cpy)
{
	char *push = "push";
	int i;
	int check_digit;

	if (cmd == NULL && argument == NULL)
	{
		free(line_cpy);
		return (1);
	}

	if ((strcmp(cmd, push) == 0) && argument == NULL)
	{
		print_err2(line_nb, cmd, line_cpy);
		return (1);
	}
	else if ((strcmp(cmd, push) == 0) && argument != NULL)
	{
		for (i = 0; argument[i] != '\0'; i++)
		{
			check_digit = _isdigit(argument[i]);
			if (check_digit == 0)
			{
				print_err2(line_nb, cmd, line_cpy);
				return (1);
			}
		}
	}
	return (0);
}
