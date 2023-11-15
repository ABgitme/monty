#include "monty.h"

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	size_t size = 0;
	ssize_t r_line = 0;
	stack_t *stack = NULL;
	unsigned int line_count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL || argv[1] == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((r_line = getline(&line, &size, file)) > 0)
	{
		line_count++;
		if (r_line > 0)
		{
			exec_line(line, &stack, line_count, file);
		}
		free(line);
		line = NULL;
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
