#include "monty.h"
/**
*run - executes the opcode
*@line: line content
*@file: poiner to monty file
*@stack: head doubly linked list - stack
*@line_number: line number
* Return: no return
*/

int run(char *line, FILE *file, stack_t **stack, unsigned int line_number)
{
	int i = 0;
	char *cmd;
	instruction_t opcd[] = {
	{"push", _push},
	{"pall", _pall},
	{"pint", _pint},
	{"pop", _pop},
	{NULL, NULL}};

	NOTUSED(file);

	cmd = strtok(line, " \a\n\t");
	if (cmd && cmd[0] == '#')
		return (0);
	glob_buffer.args = strtok(NULL, " \a\n\t");
	while (opcd[i].opcode && cmd)
	{
		if (strcmp(opcd[i].opcode, cmd) == 0)
		{
			opcd[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (opcd[i].opcode && cmd == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmd);
		fclose(file);
		free(line);
		free_dlink(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
