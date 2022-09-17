#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @head: pointer to top of stack
 * @line_number: line of instruction
 *
 * Return: void
 */
void add(stack_t **head, unsigned int line_number)
{
stack_t *current = *head;

if (current == NULL || current->next == NULL)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
current->next->n += current->n;
*head = current->next;
(*head)->prev = NULL;
free(current);
}

/**
 * nop - Does nothing
 * @stack: pointer to the top of stack
 * @line_number: line of instruction
 */
void nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}
