#include "monty.h"

/**
  * push - push a node to the stack
  * @stack: head pointer to the stack
  * @line_number: the number of the current line
  * Return: 0 if success, -1 if an error ocurred
  */

int push(stack_t **stack, unsigned int line_number)
{
	char *number;
	int i;
	int real_number;

	number = strtok(NULL, " \n");
	if (number == NULL)
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		return (-1);
	}
	for (i = 0; number[i] != '\0'; i++)
	{
		if (number[i] == '-' && i == 0)
			continue;
		if (isdigit(number[i]) == 0)
		{
			fprintf(stderr, "L%i: usage: push integer\n", line_number);
			return (-1);
		}
	}

	real_number = atoi(number);

	/* ADD THE NEW NODE */
	add_node(stack, real_number);

	return (0);
}

/**
  * pall - prints all the stack
  * @stack: head pointer to srack
  * @line_number: number of the current line
  * Return: 0 if success, -1 if an error ocurred
  */

int pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current;

	if ((*stack) == NULL)
		return (0);
	current = (*stack);
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	return (0);
}
