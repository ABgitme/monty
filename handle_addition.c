#include "monty.h"
/**
*_add - add top two int of stack
*@stack: pointer to pointer of head list
*@line_number: line at which opcode is found
*/
void _add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *temp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(glob_buffer.line_buf);
		free_dlink(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = *stack;
		*stack = (*stack)->next;
		sum = temp->n + (*stack)->n;
		(*stack)->n = sum;
		(*stack)->prev = NULL;
		free(temp);
	}
}
