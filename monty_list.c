#include "monty.h"
#include <ctype.h>

/**
 * integer - function
 * @str: str
 * Return: no return
 */

static int integer(char *str)
{
	int i = 0;

	for (; str[i]; i++)
	{
		if (isdigit(str[i]))
		{
			return (1);
		}
	}
	return (0);
}

/**
 * func_push - function to add elements to list
 * @stack: double pointer to struct
 * @line_number:number of lines into the file
 * Return: Return count
 */
void func_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *arg;

	arg = strtok(NULL, " \n\t\r");
	if (arg == NULL || integer(arg) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(arg);
	if (*stack == NULL)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
	}
	else
	{
		(*stack)->prev->next = new_node;
		new_node->prev = (*stack)->prev;
		(*stack)->prev = new_node;
		new_node->next = *stack;
	}
	*stack = new_node;
	vars.stack_len++;
}
/**
 * func_pall - function to print all the elements of a list_t list
 * @stack: double pointer to struct
 * @line_number: number of lines into the file
 * Return: Return print list
 */
void func_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	(void)(line_number);

	while (node != NULL)
	{
		fprintf(stdout, "%d\n", node->n);
		node = node->next;
		if (node == *stack)
			return;
	}
}

/**
 * func_pint - function to print all the elements of a list_t list
 * @stack: double pointer to struct
 * @line_number: number of lines into the file
 * Return: Return print list
 */
void func_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (vars.stack_len == 0)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", node->n);
}

/**
 * func_pop - function to remove elements top of list
 * @stack: double pointer to struct
 * @line_number: number of lines into the file
 * Return: Return print list
 */
void func_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (vars.stack_len == 0)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		node = *stack;
		(*stack)->next->prev = (*stack)->prev;
		(*stack)->prev->next = (*stack)->next;
		if (vars.stack_len != 1)
		{
			*stack = (*stack)->next;
		}
		else
		{
			*stack = NULL;
		}
		free(node);
		vars.stack_len--;
	}
}
