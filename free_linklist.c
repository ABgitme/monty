#include "monty.h"
/**
 * free_dlink - frees a dlistint_t list.
 * @head: pointer to the list.
 **/
void free_dlink(stack_t *head)
{
	stack_t *current, *next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}