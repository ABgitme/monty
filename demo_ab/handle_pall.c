#include "monty.h"

void _pall(stack_t **stack, unsigned int line_number)
{
    stack_t *p;

    NOTUSED(line_number);
    p = *stack;
    while (p != NULL)
    {
        printf("%d\n", p->n);
        p = p->next;
    }
}