#include "monty.h"

/**
 * prt_char - Prints the top two char of the stack
 * @stack: Pointer to a head stack
 * @line_number: Interger line number
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
 * prt_str - Prints a string of the stack
 * @stack: Pointer to a head stack
 * @ln: Intergerline number
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
 * tack_rotl - Rotates the stack to the bottom
 * @stack: Pointer to a head stack
 * @ln: Interger line number
 */
void stack_rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *copy;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	copy = *stack;
	while (copy->next != NULL)
		copy = copy->next;

	copy->next = *stack;
	(*stack)->prev = copy;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * stack_rotr - Rotates the stack to the top
 * @stack: Pointer to a head stack
 * @ln: Interger line number
 */
void stack_rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *copy;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	copy = *stack;

	while (copy->next != NULL)
		copy = copy->next;

	copy->next = *stack;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*stack)->prev = copy;
	(*stack) = copy;
}
