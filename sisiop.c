#include "monty.h"

/**
 * moules_noodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void moules_noodes(stack_t **stack, unsigned int line_number)
{
	int popo;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	popo = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = popo;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mood_noodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void mood_noodes(stack_t **stack, unsigned int line_number)
{
	int popo;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "mod");


	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	popo = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = popo;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
