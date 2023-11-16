#include "monty.h"

/**
*_rotr - rotates the stack to the top.
*@stack: pointer to pointer of stack's head
*@line_number: line at which opcode is found
*
*/

void _rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp1, *tmp2;

    NOTUSED(line_number);
    tmp2 = tmp1 = *stack;
    if (tmp1 && tmp1->next)
    {
    while(tmp2->next)
    {
        tmp2 = tmp2->next;
    }
    *stack = tmp2;
    tmp2->prev->next = NULL;
    (*stack)->next = tmp1;
    (*stack)->prev = NULL;
    }
    else
        return;
}