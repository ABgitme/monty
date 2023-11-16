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
