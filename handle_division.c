#include "monty.h"
/**
*_div - divide the seconde top int by the first top int of list
*@stack: pointer to pointer of head
*@line_number: line at which the opcode is located
*/
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int div = 0;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free(glob_buffer.line_buf);
		free_dlink(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = *stack;
		*stack = (*stack)->next;
		if (temp->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			free(glob_buffer.line_buf);
			free_dlink(*stack);
			exit(EXIT_FAILURE);
		}
		div = (*stack)->n / temp->n;
		(*stack)->n = div;
		(*stack)->prev = NULL;
		free(temp);
	}
}
