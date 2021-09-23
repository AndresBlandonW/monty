#include "monty.h"

monties_t mty;

int main(int argc, char **argv)
{
        stack_t *head;
	stack_i(&head);

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

void stack_i(stack_t **head)
{
	*head = NULL;
	mty.add = head;
}