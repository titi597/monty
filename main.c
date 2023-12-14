#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - main function for monty code
* @argc: an array of arguments
* @argv: pointer to an array
* Return: 0 (success)
*/
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t depth = 0;
	ssize_t rread = 1;
	stack_t *stacks = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (rread > 0)
	{
		content = NULL;
		rread = getline(&content, &depth, file);
		bus.content = content;
		count++;
		if (rread > 0)
		{
			t_execute(content, &stacks, count, file);
		}
		free(content);
	}
	free_stack(stacks);
	fclose(file);
	return (0);
}
