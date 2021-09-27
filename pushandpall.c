#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the first node
 * @line_number: value of new node
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *result;
	int i;
	int num;

	result = strtok(NULL, "\n \t\r");
	if (result == NULL)
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; result[i] != '\0'; i++)
	{
		if (result[i] == '-' && i == 0)
			continue;

		if (isdigit(result[i]) == 0)
		{
			fprintf(stderr, "L%i: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	num = atoi(result);

	add_dnodeint(stack, num);
}

/**
 * pall - prints all values on the stack
 * @stack: double pointer to the first node
 * @line_number: value of new node
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode = *stack;

	(void)(line_number);
	while (newNode != NULL)
	{
		printf("%d\n", newNode->n);
		newNode = newNode->next;
	}
}
