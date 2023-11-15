#include "monty.h"
/**
*do_pint - print all value of list
*@stack: pointer to ponter of the head node
*@line_count: line number
*
*/
void do_pint(stack_t **stack, unsigned int line_count)
{
	if (!stack || !(*stack))
	{
		printf("L<%d>: can't pint, stack empty\n", line_count);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
