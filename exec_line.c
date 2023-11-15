#include "monty.h"
/**
*exec_line - runs the opcodes according the instraction
*@stack: pointer to pointer of head of list
*@line_count: the line number on which the opcode is found
*@file: pointer to monty file
*@line: buffer that content a line of instraction from file
*Return: 0 on success
*/
int exec_line(char *line, stack_t **stack, unsigned int line_count, FILE *file)
{
	instruction_t instructions[] = {
	{"pall", do_pall},
	{"push", do_push},
	{"pint", do_pint},
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
		exit(EXIT_FAILURE);
	}
	return (1);
}
