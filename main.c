#include "monty.h"

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *line = NULL;
	FILE *file;
	size_t size = 0;
	ssize_t r_line = 0;
	stack_t *stack = NULL;
	unsigned int line_count = 1;

	NOTUSED(stack);
	glob_buffer.line_buf = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	glob_buffer.file = file;
	while ((r_line = getline(&line, &size, file)) > 0)
	{
		glob_buffer.line_buf = line;
		if (r_line > 0)
		{
			run(line, file, &stack, line_count);
		}
		free(line);
		line = NULL;
		line_count++;
	}
	free(line);
	free_dlink(stack);
	fclose(file);

	return (0);
}
