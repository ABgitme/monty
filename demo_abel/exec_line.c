#include "monty.h"
int exec_line(char *line, stack_t **stack, unsigned int line_count, FILE *file)
{
	instruction_t instructions[] = {
	{"pall", do_pall},
	{"push", do_push},
	{NULL, NULL}
	};

	char *op_code;
	unsigned int i;

	op_code = strtok(line, " \n\t");
	value = strtok(NULL, " \n\t");
	i = 0;
	while (instructions[i].opcode && op_code)
	{
		if ((strcmp(instructions[i].opcode, op_code) == 0))
		{
			instructions[i].f(stack, line_count);
			return (0);
		}
		i++;
	}
	if (op_code && instructions[i].opcode == NULL)
	{
		fclose(file);
		free(line);
		free_stack(*stack);
		exit (EXIT_FAILURE);
	}
	return (1);
}
