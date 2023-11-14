#include "monty.h"
/**
 * do_push - push node to the stack
 * @stack: stack head
 * @line_count: line_number
 * Return: no return
*/
void do_push(stack_t **stack, unsigned int line_count)
{
	int num, i = 0;

	if (value)
	{
		if (value[0] == '-')
			i++;
		for (; value[i] != '\0'; i++)
		{
			if (value[i] > 57 || value[i] < 48)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_count);
				fclose(file);
				free(line);
				free_stack(*stack);
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_count);
		fclose(file);
		free(line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	num = atoi(value);
	add_node_stack(stack, num);
}
