#include "monty.h"
/**
*_pchar - print the ascii representation of top stack's data
*@stack: pointer to pointer of stack's head
*@line_number: line at which opcode is found
*
*/
void _pchar(stack_t **stack, unsigned int line_number)
{

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(glob_buffer.line_buf);
		free_dlink(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		if ((*stack)->n < 'A' || (*stack)->n > 'z')
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			free(glob_buffer.line_buf);
			free_dlink(*stack);
			exit(EXIT_FAILURE);
		}
		else
		{
			putchar((*stack)->n);
			putchar('\n');
		}
	}
}
