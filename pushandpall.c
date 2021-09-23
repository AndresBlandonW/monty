#include "monty.h"


void push(stack_t **stack, unsigned int line_number)
{
        char *result;
	int i;
	int num;
	result = strtok(NULL, "\n \t\r");
	printf(result);
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


void pall(stack_t **stack, unsigned int line_number)
{
        char *result;
	int i;
	int num;

	result = strtok(NULL, " \n");
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