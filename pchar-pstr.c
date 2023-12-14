#include "monty.h"

/**
 * t_pchar - function that Implement the pchar opcode
 * @head: pointer to an array of head
 * @count: an array variable
 */
void t_pchar(stack_t **head, unsigned int count)
{
	stack_t *p;

	p = *head;

	if (!p)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if (p->n > 127 || p->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", p->n);
}

/**
 * t_pstr - function that Implement the pstr opcode
 * @head: pointer to an array head
 * @count: an array varaible
 */
void t_pstr(stack_t **head, unsigned int count)
{
	stack_t *p;

	(void)count;

	for (p = *head; p && p->n != 0; p = p->next)
	{
		if (p->n > 0 && p->n <= 127)
		{
			printf("%c", p->n);
		}
		else
		{
			break;
		}
	}
	printf("\n");
}
