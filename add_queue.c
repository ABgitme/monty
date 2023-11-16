#include "monty.h"
/**
 * add_queue - add queue to the head tail of stack
 * @head: head of the stack
 * @val: value to add
 * Return: no return
*/
void add_queue(stack_t **head, int val)
{
	stack_t *new_node, *tmp;

	tmp = *head;

	new_node = (stack_t *)malloc(sizeof(stack_t));

	new_node->n = val;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (tmp == NULL)
		{
			*head = new_node;
			new_node->prev = NULL;
		}
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			new_node->prev = tmp;
			tmp->next = new_node;
		}
	}
}
