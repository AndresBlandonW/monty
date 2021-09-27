#include "monty.h"

/**
 * main - the monty bytecode interpreter
 * @argc: number arguments
 * @argv: value of arguments
 * Return: success or failure
 */
int main(int argc, char **argv)
{
	stack_t *head;

	instack(&head);
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (!argv[1])
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	compile_file(argv[1], &head);
	exit(EXIT_SUCCESS);
}

/**
 * instack - initialize
 * @head: top of stack
 */
void instack(stack_t **head)
{
	*head = NULL;
}


/**
 * free_all - free all memory
 */
void free_all(void)
{
	stack_t *tmp1, *tmp2 = NULL;

	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
}
