#include "monty.h"
/**
*_sub - subtract the top value from the second top value of list
*@stack: pointer to pointer of head list
*@line_number: line at which opcode is read
*/
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int sub = 0;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free(glob_buffer.line_buf);
		free_dlink(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = (*stack);
		*stack = (*stack)->next;
		sub = (*stack)->n - temp->n;
		(*stack)->n = sub;
		(*stack)->prev = NULL;
		free(temp);
	}

}
