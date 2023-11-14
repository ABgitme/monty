#include "monty.h"
/**
 * do_pall - prints the linked list stack
 * @stack: pointer to stack head
 * @line_count: line_number
 * Return: no return
*/
void do_pall(stack_t **stack, unsigned int line_count)
{
	stack_t *temp;
	(void) line_count;
	temp = *stack;
	if (temp == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
