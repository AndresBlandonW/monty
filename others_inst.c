#include "monty.h"

/**
 * pint - the value at the top of the stack, followed by a new line.
 * @head: pointer to first node
 * @line_number: number of current line
 *
 * Return: 0 on succes, -1 on failure
 */
int pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		return (-1);
	}
	printf("%i\n", (*head)->n);
	return (0);
}

/**
  * pop - deletes the node at top of the stack
  * @stack: header pointer to stack
  * @line_number: number of the line
  * Return: 0 success, otherwise -1
  */
int pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		return (-1);
	}
	delete_node(stack, 0);
	return (0);
}
