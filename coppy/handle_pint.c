#include "monty.h"
/**
*_pint - print data from the top of list
*@stack: pointer to pointer of head list
*@line_number: line at which opcode is read
*
*/
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *p;

	p = *stack;
	if (p == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(glob_buffer.file);
		free(glob_buffer.line_buf);
		free_dlink(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", p->n);
	}
}
