#include "monty.h"
/**
 * add_stack - add queue to the head tail of stack
 * @head: head of the stack
 * @n: value to add
 * Return: no return
*/
void add_stack(stack_t **head, int val)
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
        }
        else
        {
            new_node->next = tmp;
            tmp->prev = new_node;
            *head = new_node;
        }
    }
}