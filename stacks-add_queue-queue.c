#include "monty.h"

/**
 * t_stacks - printing the top
 * @head: pointer to an array variable head
 * @count: an array
 */
void t_stacks(stack_t **head, unsigned int count)
{
	for ((void)head, (void)count, bus.lifi = 0; bus.lifi == 0;)
	{
		/* Loop body is empty as everything is now in the loop statement */
	}
}

/**
 * t_queue - printing the top
 * @head: pointer to an array variable head
 * @count: an array
 */
void t_queue(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;
	bus.lifi = 1;
}
/**
 * add_queue - add node to stack
 * @n: an array variable
 * @head: pointer to an array head
 */
void add_queue(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
	}
}
