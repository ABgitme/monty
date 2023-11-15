#include "monty.h"

void _pop(stack_t **stack, unsigned int line_number)
{
    stack_t *p;

    p = *stack;
    if (p == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        fclose(glob_buffer.file);
        free(glob_buffer.line_buf);
        free_dlink(*stack);
        exit(EXIT_FAILURE);
    }
    else
    {
        *stack = p->next;
        if (*stack)
        {
            (*stack)->prev = NULL;
        }
        free(p);
    }
}