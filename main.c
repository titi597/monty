#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * main - Entry point for the interpreter.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: Exit status.
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	char *opcode;

	/* Example: Assuming the first argument is the opcode (push/pall) */
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s opcode [arguments]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	opcode = argv[1];

	if (strcmp(opcode, "push") == 0)
		push(&stack, 0);
	else if (strcmp(opcode, "pall") == 0)
		pall(&stack, 0);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", 0, opcode);
		exit(EXIT_FAILURE);
	}
	return (0);
}
