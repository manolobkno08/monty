#include "monty.h"

/**
 * func_nop - function to remove elements top of list
 * @stack: double pointer to struct
 * @line_number: number of lines into the file
 * Return: Return print list
 */
void func_nop(stack_t **stack, unsigned int line_number)
{
	(void)(stack);
	(void)(line_number);
}

/**
 * func_swap - function
 * @stack: double pointer to struct
 * @line_number: number of lines into the file
 * Return: Return print list
 */
void func_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (vars.stack_len < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (vars.stack_len == 2)
	{
		*stack = (*stack)->next;
		return;
	}

	tmp = (*stack)->next;
	tmp->prev = (*stack)->prev;
	(*stack)->prev->next = tmp;
	(*stack)->prev = tmp;
	(*stack)->next = tmp->next;
	tmp->next->prev = *stack;
	tmp->next = *stack;
	*stack = tmp;
}

/**
 * close_f - function for free memory
 * @status: argument from function on_exit
 * @arg: argument from function on_exit
 * Return: nothing
 */

void close_f(int status, void *arg)
{
	FILE *close = (FILE *)arg;

	(void)(status);

	fclose(close);
}

/**
 * func_add - function to remove elements top of list
 * @stack: double pointer to struct
 * @line_number: number of lines into the file
 * Return: Return print list
 */
void func_add(stack_t **stack, unsigned int line_number)
{
	int n = 0;

	if (vars.stack_len < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = (*stack)->n;
	func_pop(stack, line_number);
	(*stack)->n += n;
}
