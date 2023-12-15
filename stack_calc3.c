#include "monty.h"

/**
 * stack_nop - Does nothing to the stack
 * @stack: Pointer to head stack
 * @line_number: Interger line number
 */
void stack_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 *stack_ swap - Swaps the top two elements of the stack.
 * @stack: Pointer to a head stack
 * @line_number: Interger line number
 */
void stack_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *copy;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	copy = (*stack)->next;
	(*stack)->next = copy->next;
	if (copy->next != NULL)
		copy->next->prev = *stack;
	copy->next = *stack;
	(*stack)->prev = copy;
	copy->prev = NULL;
	*stack = copy;
}

/**
 * stack_add - Adds the top two elements of the stack.
 * @stack: Pointer to the head stack
 * @line_number: Interger line number
 */
void stack_add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * stack_sub - subtracts the top two elements of the stack.
 * @stack: Pointer to a head stack
 * @line_number: Interger line number
 */
void stack_sub(stack_t **stack, unsigned int line_number)
{
	int sub_result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "sub");


	(*stack) = (*stack)->next;
	sub_result = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sub_result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * stack_div - Divides the top two elements of the stack.
 * @stack: Pointer to a head stack
 * @line_number: Interger line number
 */
void stack_div(stack_t **stack, unsigned int line_number)
{
	int div_result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "div");

	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	div_result = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = div_result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
