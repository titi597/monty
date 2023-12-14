#include "monty.h"

/**
 * t_execute - function that executes the code
 * @stack: pointer to an array of head
 * @count: an array varaivle count
 * @file: pointer to an array file
 * @content: pointer to an array content
 * Return: an array
 */
int t_execute(char *content, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t opst[] = {
		{"push", t_push}, {"pall", t_pall}, {"pint", t_pint}, {"pop", t_pop},
		{"swap", t_swap}, {"add", t_add}, {"nop", t_nop}, {"sub", t_sub},
		{"div", t_div}, {"mul", t_mul}, {"mod", t_mod}, {"pchar", t_pchar},
		{"pstr", t_pstr}, {"rotl", t_rotl}, {"rotr", t_rotr},
		{"queue", t_queue}, {"stack", t_stacks}, {NULL, NULL}
	};

	unsigned int j = 0;
	char *ptr;

	ptr = strtok(content, " \n\t");
	if (ptr && ptr[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	for (; opst[j].opcode && ptr; j++)
	{
		if (strcmp(ptr, opst[j].opcode) == 0)
		{
			if (strcmp(ptr, "queue") == 0)
			{
				bus.lifi = 1;
			}
			else if (strcmp(ptr, "stack") == 0)
			{
				bus.lifi = 0;
			}
			opst[j].f(stack, count);
			return (0);
		}
	}
	if (ptr && opst[j].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, ptr);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
