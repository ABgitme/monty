#include "monty.h"

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	globe_args.value = NULL;
	globe_args.line = NULL;
	globe_args.file = NULL;

	size_t size = 0;
	ssize_t r_line = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	globe_args.file = fopen(argv[1], "r");
	if (globe_args.file == NULL || argv[1] == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((r_line = getline(&globe_args.line, &size, globe_args.file)) > 0)
	{
		line_number++;
		if (r_line > 0)
		{
			exec_line(globe_args.line, &stack, line_number, globe_args.file);
		}
		free(globe_args.line);
		
	}
	free_stack(stack);
	fclose(globe_args.file);
	return (0);
}
