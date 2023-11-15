#include "monty.h"
/**
* free_stack - frees a doubly linked list
* @h: head of the stack
*/
void free_stack(stack_t *h)
{
	stack_t *temp;

	temp = h;
	while (h)
	{
		temp = h->next;
		free(h);
		h = temp;
	}
}
