#include "monty.h"

/**
 * t_rotl - function that rotate the stack up
 * @head: pointer to an arrayhead
 * @count: an array variable
 */
void t_rotl(stack_t **head, __attribute__((unused)) unsigned int count)
{
	stack_t *tmp, *new_head;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	tmp = *head;
	new_head = (*head)->next;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->prev = tmp;
	(*head) = new_head;
	new_head->prev = NULL;
	tmp->next->prev = NULL;

	if (tmp->next != NULL)
	{
		tmp->next->next = NULL;
	}
}
/**
 * t_rotr - function that rotates the stack to downwards
 * @head: pointer to an array head
 * @count: an array variable
 */
void t_rotr(stack_t **head, __attribute__((unused)) unsigned int count)
{
	stack_t *d_copy, *llat, *new_head;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	d_copy = *head;
	llat = d_copy;

	while (llat->next != NULL)
	{
		llat = llat->next;
	}
	llat->next = *head;
	llat->prev->next = NULL;
	llat->prev = NULL;

	new_head = *head;
	while (new_head->next != NULL)
	{
		new_head = new_head->next;
	}
	new_head->prev = llat;
	*head = llat;
}
