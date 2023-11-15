#include "monty.h"
/**
 * do_push - push node to the stack
 * @stack: stack head
 * @line_count: line_number
 * Return: no return
*/
void do_push(stack_t **stack, unsigned int line_number)
{
	int num, i = 0;

	if (globe_args.value)
	{
		if (globe_args.value[0] == '-')
			i++;
		for (; globe_args.value[i] != '\0'; i++)
		{
			if (globe_args.value[i] > 57 || globe_args.value[i] < 48)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				fclose(globe_args.file);
				free(globe_args.line);
				free_stack(*stack);
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(globe_args.file);
		free(globe_args.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	num = atoi(globe_args.value);
	add_node_stack(stack, num);
}
