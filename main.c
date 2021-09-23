#include "monty.h"

/**
 * main - entry into interpreter
 * @argc: argc counter
 * @argv: arguments
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	unsigned int line_number = 0;
	char *token = NULL, *buffer = NULL;
	size_t line_len = 0;
	FILE *files = NULL;

	/*cabeza de nodos puntero*/
	stack_t *h = NULL;
	/*validar si los argumentos son correctos*/
	vars.stack_len = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	files = fopen(argv[1], "r");
	if (files == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	on_exit(free_stack, &h);
	on_exit(free_vars, &buffer);
	on_exit(close_f, files);

	while (getline(&buffer, &line_len, files) != -1)
	{
		line_number++;
		token = strtok(buffer, "\n\t\r ");
		if (token != NULL && token[0] != '#')
		{
			get(token, &h, line_number);
		}
	}
	exit(EXIT_SUCCESS);
}
