#include "monty.h"

/**
 * stack_mul - Multiplies the top two elements of the stack.
 * @stack: head stack
 * @line_number: line number
 */
void stack_mul(stack_t **stack, unsigned int line_number)
{
	int mul;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	 mul = (*stack)->n * (*stack)->prev->n;
	(*stack)->n =  mul;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * stack_mod - gives the modulous of the top two elements of the stack.
 * @stack: head stack
 * @line_number: the line number of of the opcode.
 */
void stack_mod(stack_t **stack, unsigned int line_number)
{
	int mod;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "mod");


	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	 mod = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = mod;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
