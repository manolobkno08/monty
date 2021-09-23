#include "monty.h"

/**
 * get - matches command to appropriate function
 * @token: var received to execute funcion
 * @stack: structure of stack
 * @line_number: number of lines into the file
 * Return: result of function match
 */

void get(char *token, stack_t **stack, unsigned int line_number)
{
	instruction_t instr[] = {
		{"push", func_push},
		{"pall", func_pall},
		{"pint", func_pint},
		{"add", func_add},
		{"swap", func_swap},
		{"pop", func_pop},
		{"sub", func_sub},
		{"div", func_div},
		{"nop", func_nop},
		{NULL, NULL}
	};
	int iter;

	for (iter = 0; instr[iter].opcode != NULL; iter++)
	{
		if (strcmp(instr[iter].opcode, token) == 0)
		{
			instr[iter].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
	exit(EXIT_FAILURE);
}

/**
 * free_stack - function for free memory
 * @status: argument from function on_exit
 * @arg: argument from function on_exit
 * Return: nothing
 */
void free_stack(int status, void *arg)
{
	stack_t *next;
	stack_t **stack;

	(void)(status);

	stack = (stack_t **)arg;
    /* return if empty list */
	if (*stack)
	{
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}

	while (*stack != NULL)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
	vars.stack_len = 0;
}

/**
 * free_vars - function for free memory
 * @status: argument from function on_exit
 * @arg: argument from function on_exit
 * Return: nothing
 */

void free_vars(int status, void *arg)
{
	char **buffer = arg;

	(void)(status);
	if (*buffer != NULL)
	{
		free(*buffer);
	}
}
