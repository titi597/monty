#include "monty.h"

/**
 * t_sub - operations that acts  subtraction
 * @head: pointer to an array head
 * @count: an array varaible
 */
void t_sub(stack_t **head, unsigned int count)
{
	stack_t *aptr;
	int dict, node;

	for (aptr = *head, node = 0; aptr != NULL; aptr = aptr->next, node++)
	{
		/* Loop body is empty as everything is now in the loop */
	}
	if (node < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aptr = *head;
	dict = aptr->next->n - aptr->n;
	*head = aptr->next;
	(*head)->n = dict;
	free(aptr);
}
/**
 * t_div - function that divides the elements of the stack.
 * @head: pointer to an array head
 * @count: an array variable
 */
void t_div(stack_t **head, unsigned int count)
{
	stack_t *p;
	int len = 0, aptr;

	for (p = *head; p; p = p->next, len++)
	{
		/* Loop body is empty as everything is now in the loop */
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	for (p = *head; len > 1; len--)
	{
		if (p->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", count);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}

		aptr = p->next->n / p->n;
		p->next->n = aptr;
		*head = p->next;
		free(p);
	}
}

/**
 * t_mul - function that multiplies the elements of the stack.
 * @head: pointer to an array head
 * @count: an array variable
 */
void t_mul(stack_t **head, unsigned int count)
{
	stack_t *p;
	int len = 0, aptr;

	for (p = *head; p; p = p->next, len++)
	{
		/* Loop body is empty as everything is now in the loop */
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	for (p = *head; len > 1; len--)
	{
		aptr = p->next->n * p->n;
		p->next->n = aptr;
		*head = p->next;
		free(p);
	}
}

/**
 * t_mod - function that computes the remainder element of the stack
 * @head: pointer to an array head
 * @count: an aary variable
 */
void t_mod(stack_t **head, unsigned int count)
{
	stack_t *p;
	int len = 0, aptr;

	for (p = *head; p; p = p->next, len++)
	{
		/* Loop body is empty as everything is now in the loop */
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	for (p = *head; len > 1; len--)
	{
		if (p->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", count);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
		aptr = p->next->n % p->n;
		p->next->n = aptr;
		*head = p->next;
		free(p);
	}
}
