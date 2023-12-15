#include "monty.h"


/**
 * stack_addnode - Adds a node to the stack.
 * @new_node: Pointer to the current node
 * @ln: line number
 */
void stack_addnode(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *copy;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	copy = head;
	head = *new_node;
	head->next = copy;
	copy->prev = head;
}


/**
 * print_stack - prints a node to the stack.
 * @stack: Pointer to a head stack
 * @line_number: line number of  the opcode.
 * Return: Nothing
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *copy;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	copy = *stack;
	while (copy != NULL)
	{
		printf("%d\n", copy->n);
		copy = copy->next;
	}
}

/**
 * stack_pop_top - removes a node from the top of the stack
 * @stack: Pointer to a head stack
 * @line_number: Interger line number
 */
void stack_pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *copy;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	copy = *stack;
	*stack = copy->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(copy);
}

/**
 * stack_top - Prints the top node of the stack.
 * @stack: Pointer to a head stack
 * @line_number: Interger line number
 * Return: Nothing
 */
void stack_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
