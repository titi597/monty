#include "monty.h"

/**
 * t_rotl - function that rotate the stack up
 * @head: pointer to an arrayhead
 * @count: an array variable
 */
void t_rotl(stack_t **head, __attribute__((unused)) unsigned int count)
{
	stack_t *tmp, *aptr;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	tmp = *head;
	aptr = (*head)->next;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->prev = tmp;
	(*head) = aptr;
	aptr->prev = NULL;
	tmp->next = NULL;
}
/**
 * t_rotr - function that rotates the stack to downwards
 * @head: pointer to an array head
 * @count: an array variable
 */
void t_rotr(stack_t **head, __attribute__((unused)) unsigned int count)
{
	stack_t *d_copy, *llat;

	d_copy = *head;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	llat = d_copy;
	for (; llat->next; llat = llat->next)
	{
		/* Loop body is empty as everything is now in the loop */
	}
	llat->next = *head;
	llat->prev->next = NULL;
	llat->prev = NULL;

	while ((*head)->next != NULL)
	{
		(*head)->prev = llat;
		(*head) = (*head)->next;
	}
	(*head)->prev = llat;
}
