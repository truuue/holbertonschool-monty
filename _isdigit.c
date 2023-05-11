#include "monty.h"

/**
 * _isdigit - a function that checks if a char is a digit (0 through 9)
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

/**
 * check_digit - function that checks that there is an argument
 * and that the argument is a digit
 * @cmd: is compared to the string "push" to see if the command is a push
 * @argument: represents the argument associated with the cmd
 * @line_nb: used to print err messages in case there is issue with instruction
 * @line_cpy: is used for cpy the line variable
 *
 * Return: if a character is not a digit the function prints an error message
 * with the line number, command, and line copy, then return 1
 * if none of the above conditions are met, the function returns 0
 */
int check_digit(char *cmd, char *argument, unsigned int line_nb, 
char *line_cpy)
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
