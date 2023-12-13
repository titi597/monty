#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int value;
	stack_t *new_node;

	if (!stack)
	{
		fprintf(stderr, "Error: Stack not initialized.\n");
		exit(EXIT_FAILURE);
	}
	arg = strtok(NULL, " \n");

	if (!arg || !isdigit((unsigned char)*arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(arg);

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
