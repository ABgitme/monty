#include "monty.h"

/**
*_pstr - print the stack's int based of ascii value of char
*@stack: pointer to pointer of stack's head
*@line_number: line at which opcode is found
*
*/
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	char ch;

	tmp = *stack;
	NOTUSED(line_number);
	if (*stack)
	{
		while (tmp && (tmp->n != 0))
		{
			if (tmp->n >32 && tmp->n < 127)
			{
				ch = (char) tmp->n;
				printf("%c", ch);
			}
			else
				break;
			tmp = tmp->next;
		}
		printf("\n");
	}
	else
	{
		printf("\n");
	}

}
