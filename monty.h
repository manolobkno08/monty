#ifndef _MONTY_H_
#define _MONTY_H_

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>

/**
 * struct variables - allocate strings of file
 * @stack_len: size of file
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct variables
{
	size_t stack_len;
} vars_t;

vars_t vars;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void get(char *token, stack_t **stack, unsigned int);
void func_push(stack_t **stack, unsigned int line_number);
void func_pall(stack_t **stack, unsigned int line_number);
void func_pint(stack_t **stack, unsigned int line_number);
void func_pop(stack_t **stack, unsigned int line_number);
void func_nop(stack_t **stack, unsigned int line_number);
void func_add(stack_t **stack, unsigned int line_number);
void func_swap(stack_t **stack, unsigned int line_number);
void free_stack(int status, void *arg);
void free_vars(int status, void *arg);
void close_f(int status, void *arg);

void func_sub(stack_t **stack, unsigned int line_number);
void func_div(stack_t **stack, unsigned int line_number);
void func_e(stack_t **stack, unsigned int line_number);

int main(int argc, char *argv[]);


#endif
