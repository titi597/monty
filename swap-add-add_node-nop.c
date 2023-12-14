#include "monty.h"

/**
 * t_swap - adding the elements of the stack.
 * @head: pointer to an array head
 * @count: an array variable
 */
void t_swap(stack_t **head, unsigned int count)
{
	stack_t *p;
	int len = 0, aptr;

	for (p = *head; p; p = p->next, len++)
	{
		/* Loop body is empty as everything is now in the loop */
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	for (p = *head, aptr = p->n; len > 1; len--)
	{
		p->n = p->next->n;
		p->next->n = aptr;
	}
}
/**
 * t_add - adding the elements of the stack.
 * @head: pointer to an array variables
 * @count: an array
 */
void t_add(stack_t **head, unsigned int count)
{
	stack_t *p;
	int len = 0, aptr;

	for (p = *head; p; p = p->next, len++)
	{
		/* Loop body is empty as everything is now in the loop */
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	p = *head;
	aptr = p->n + p->next->n;
	*head = p->next;
	(*head)->n = aptr;
	free(p);
}

/**
 * add_node - adding node to the stack
 * @head: pointer to na array head
 * @n: variable n which is an array
 */
void add_node(stack_t **head, int n)
{
	stack_t *new_node, *aptr;

	aptr = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (aptr)
		aptr->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

/**
 * t_nop - function that prints nothing
 * @head: pointer to an array head
 * @count: an array variable
 */
void t_nop(stack_t **head, unsigned int count)
{
	(void)count;
	(void)head;
	/* Function body is empty as there is no operation for f_nop */
}
