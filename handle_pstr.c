#include "monty.h"
/**
*_pstr - print the stack's int based of ascii value of char
*@stack: pointer to pointer of stack's head
*@line_number: line at which opcode is found
*
*/
void _pstr(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		putchar('\n');
		fprintf(stderr, "L%d: can't pstr, stack empty\n", line_number);
		free(glob_buffer.line_buf);
		free_dlink(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		while ((*stack)->next)
		{
			if ((*stack)->n < 'A' || (*stack)->n > 'z' || (*stack)->n == 0)
			{
				break;
			}
			else
			{
				putchar((*stack)->n);
			}
			*stack = (*stack)->next;
		}
		putchar('\n');
	}

}
