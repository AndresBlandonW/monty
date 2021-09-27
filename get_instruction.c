#include "monty.h"
/**
 * get_inst - finds the command
 * @command: command
 * @line_number: line number
 * Return: pointer to function
 */

int (*get_inst(char *command, unsigned int line_number))()
{
	int i;

	instruction_t array_instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"mul", mul},
		{"div", divi},
		{"mod", modu},
		{"pchar", pchar},
		{NULL, NULL}};

	for (i = 0; array_instructions[i].opcode != NULL; i++)
	{
		if (strcmp(command, array_instructions[i].opcode) == 0)
			return (array_instructions[i].f);
	}
	/* if not found then error message and exit*/
	fprintf(stderr, "L%i: unknown instruction %s\n", line_number, command);
	return (NULL);
}
