#include "monty.h"
/**
*_pall - print data of list
*@stack: pointer to pointer of head
*@line_number: line on which bytecode is found
*/
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *p;

	NOTUSED(line_number);
	p = *stack;
	if (p == NULL)
		return;
	while (p != NULL)
	{
		printf("%d\n", p->n);
		p = p->next;
	}
}
