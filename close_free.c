#include "monty.h"

/**
 * close_free - a function that frees line and stack and closes file
 * @line: a line string
 * @fd: file descriptor
 * @file: a pointer to a file
 * @head: a pointer to the top of the stack
 *
 * Return: nothing
 */
void close_free(char *line, int fd, FILE *file, monty_stack_t *head)
{
	if (line != NULL)
		free(line);
	close(fd);
	fclose(file);
	free_stack(&head);
}
