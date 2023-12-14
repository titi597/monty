#include "monty.h"

/**
 * free_stack - function that prints and freeing stack
 * @head: pointer to an array of head
 */
void free_stack(stack_t *head)
{
	stack_t *aptr;

	for (aptr = head; head; aptr = head->next, free(head), head = aptr)
	{
		/* Loop body is empty as everything is now in the loop */
	}
}
