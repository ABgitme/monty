#include "monty.h"
/**
 * add_node_stack - add node to the head stack
 * @stack: head of the stack
 * @num: int value
*/
void add_node_stack(stack_t **stack, int num)
{

	stack_t *new_node, *temp;

	temp = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (temp)
	{
		temp->prev = new_node;
		new_node->next = temp;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		*stack = new_node;
	}
}
