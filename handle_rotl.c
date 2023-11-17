#include "monty.h"

/**
*_rotl - rotates the stack to the top.
*@stack: pointer to pointer of stack's head
*@line_number: line at which opcode is found
*
*/

void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1, *tmp2;

	NOTUSED(line_number);
	tmp2 = tmp1 = *stack;
	if (tmp1 && tmp1->next)
	{
		while (tmp2->next)
		{
			tmp2 = tmp2->next;
		}
		*stack = tmp1->next;
		tmp1->next->prev = NULL;
		tmp2->next = tmp1;
		tmp2->next->next = NULL;
	}
	else
		return;
}
