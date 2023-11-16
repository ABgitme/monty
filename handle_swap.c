#include "monty.h"
/**
*_swap - swaps stack's top intigers
*@stack: pointer to pointer of head node
*@line_number: line at which opcode is located
*/
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(glob_buffer.line_buf);
		free_dlink(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = (*stack)->next;
		(*stack)->next = temp->next;
		(*stack)->prev = temp;
		temp->prev = NULL;
		temp->next = (*stack);
		*stack = temp;
	}
}
