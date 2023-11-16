#include "monty.h"
/**
*_mod - finds remaindr of (divition of the seconde top int by
*the first top int of list)
*@stack: pointer to pointer of head
*@line_number: line at which the opcode is located
*/
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int mod = 0;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
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
		if (temp->n < 0)
			temp->n *= -1;
		if ((*stack)->n >= 0)
			mod = (*stack)->n % temp->n;
		else
			mod = (*stack)->n % temp->n + temp->n;

		(*stack)->n = mod;
		(*stack)->prev = NULL;
		free(temp);
	}
}
