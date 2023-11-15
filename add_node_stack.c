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
		fprintf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (temp)
		temp->prev = new_node;
	new_node->n = num;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}
