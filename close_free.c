#include "monty.h"

void close_free(char *line, int fd, FILE *file, monty_stack_t *head)
{
	if (line != NULL)
		free(line);
	close(fd);
	fclose(file);
	free_stack(&head);
}
