#include "monty.h"
/**
*_push - push to node
*@stack: pointer to pointer to head of list
*@line_number: line at which bytecode is read
*/
void _push(stack_t **stack, unsigned int line_number)
{
	int n;

	if (isDigit(glob_buffer.args) == 0 || glob_buffer.args == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(glob_buffer.file);
		free(glob_buffer.line_buf);
		free_dlink(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		n = atoi(glob_buffer.args);
		add_stack(stack, n);
	}
}
