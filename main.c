#include "monty.h"

int main(int argc, char** argv)
{
	int fd;
	int line_nb = 0;
	char *line = NULL;
	size_t size = 0;
    	ssize_t nread;
	FILE *file = NULL;

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
	while ((nread = getline(&line, &size, file)) != -1)
	{
		line_nb++;
		copy_and_cut(line, line_nb);
	}
		
	free(line);
	close(fd);
	return (0);
}
