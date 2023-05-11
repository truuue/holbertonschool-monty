#include "monty.h"

/**
 * main - a program that interpretes Monty ByteCodes files
 * @argc: number of arguments on command line
 * @argv: array of pointers to the strings which are those arguments
 *
 * Description: The Monty program takes only one argument which is the name
 * of the .m file, and runs the bytecodes line by line and stop
 * if either: it executed properly every line of the file,
 * it finds an error in the file, an error occured
 * Return: always 0
 */
int main(int argc, char **argv)
{
	int fd;
	unsigned int line_nb = 0;
	char *line = NULL;
	size_t size = 0;
	ssize_t nread;
	FILE *file = NULL;
	monty_stack_t *head = NULL;

	global_status = 0;
	if (argc != 2)
		print_err("USAGE: monty file");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	file = fdopen(fd, "r");
	if (file == NULL)
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
			exit(EXIT_FAILURE);
		}
	}
	close_free(line, fd, file, head);
	if (global_status != 0)
		exit(EXIT_FAILURE);
	return (0);
}
