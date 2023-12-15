#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
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

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void open_file(char *file_name);
int parse_line(char *buffer, int line_number, int format);
void read_file(FILE *);
int len_chars(FILE *);
void find_func(char *, char *, int, int);

stack_t *create_node(int n);
void free_nodes(void);
void print_stack(stack_t **, unsigned int);
void stack_addnode(stack_t **, unsigned int);
void queue_addnode(stack_t **, unsigned int);

void func_call(op_func, char *, char *, int, int);

void stack_top(stack_t **, unsigned int);
void stack_pop_top(stack_t **, unsigned int);
void stack_nop(stack_t **, unsigned int);
void stack_swap(stack_t **, unsigned int);

void stack_add(stack_t **, unsigned int);
void stack_sub(stack_t **, unsigned int);
void stack_div(stack_t **, unsigned int);
void stack_mul(stack_t **, unsigned int);
void stack_mod(stack_t **, unsigned int);

void prt_char(stack_t **, unsigned int);
void prt_str(stack_t **, unsigned int);
void stack_rotl(stack_t **, unsigned int);

void stack_error(int error_code, ...);
void more_err(int error_code, ...);
void stack_string_error(int error_code, ...);
void stack_rotr(stack_t **, unsigned int);

#endif
