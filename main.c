#include "monty.h"

int main(int argc, char** argv)
{
	int fd, line_nb = 0;
	char *line = NULL;
	size_t size = 0;
    	ssize_t nread;
	FILE *file = NULL;
	monty_stack_t *head = NULL;
	global_status = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	file = fdopen(fd, "r");
	if(file == NULL)
	{
		close(fd);
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line, &size, file)) != -1)
	{	
		line_nb++;
		copy_and_cut(line, line_nb, &head);
		free(line);
		line = NULL;
		if (global_status != 0)
			{
				close_free(NULL, fd, file, head);
				// close(fd);
				// fclose(file);
				// free_stack(&head);
				exit(EXIT_FAILURE);
			}
	}
	close_free(line, fd, file, head);
	// free(line);
	// close(fd);
	// fclose(file);
	// free_stack(&head);
	if (global_status != 0)
		exit(EXIT_FAILURE);
	return (0);
}
