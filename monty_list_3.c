#include "monty.h"

/**
 * func_sub - subtract second node from top node
 * @stack: top of list
 * @line_number: line of command
 */
void func_sub(stack_t **stack, unsigned int line_number)
{
	int n = 0;

	if (vars.stack_len < 2)
	{
		printf("L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	func_pop(stack, line_number);
	(*stack)->n -= n;
}
