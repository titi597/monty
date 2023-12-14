#include "monty.h"

/**
 * t_push - function that pushes node to the stack
 * @head: pointer to an array of head
 * @count: an array varaible
 */
void t_push(stack_t **head, unsigned int count)
{
	int n, m = 0, flags = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			m++;
		for (; bus.arg[m] != '\0'; m++)
		{
			if (bus.arg[m] > 57 || bus.arg[m] < 48)
				flags = 1;
		}
		if (flags == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);

	if (bus.lifi == 0)
	{
		add_node(head, n);
	}
	else
	{
		add_queue(head, n);
	}
}

/**
 * t_pall - function that print the stack pall
 * @head: pointer to an array of head
 * @count: an array variable
 */
void t_pall(stack_t **head, unsigned int count)
{
	stack_t *p;

	(void)count;

	p = *head;
	for (; p; printf("%d\n", p->n), p = p->next)
	{
		/* Loop body is empty as everything is now in loop statement */
	}
}
