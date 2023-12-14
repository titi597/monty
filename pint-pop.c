#include "monty.h"

/**
 * t_pint - function printing the pint
 * @head: pointer to an arry head
 * @count: an array varaible
 */
void t_pint(stack_t **head, unsigned int count)
{
	for (; *head == NULL;)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/**
 * t_pop - function printing the pop
 * @head: pointer to an array head
 * @count: an array varaible
 */
void t_pop(stack_t **head, unsigned int count)
{
	stack_t *p;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	p = *head;
	*head = p->next;
	free(p);
}
