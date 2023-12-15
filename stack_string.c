#include "monty.h"

/**
 * prt_char - Prints the char at the top of the stack
 * @stack: head of the stack
 * @line_number: Interger num
 */
void prt_char(stack_t **stack, unsigned int line_number)
{
	int line_count;

	if (stack == NULL || *stack == NULL)
		stack_string_error(11, line_number);

	line_count = (*stack)->n;
	if (line_count < 0 || line_count > 127)
		stack_string_error(10, line_number);
	printf("%c\n", line_count);
}

/**
 * prt_str - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void prt_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int line_count;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		line_count = tmp->n;
		if (line_count <= 0 || line_count > 127)
			break;
		printf("%c", line_count);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * stack_rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void stack_rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * stack_rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void stack_rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
