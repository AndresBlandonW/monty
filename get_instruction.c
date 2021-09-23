#include "monty.h"

/**
 * get_instruction - s
 * @stack: s
 * @inst: s
 * @line_number: s
 **/
void get_instruction(stack_t **stack, char *inst, unsigned int index)
{
	int i = 0;
	instruction_t array_inst[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	for (i = 0; array_inst[i].opcode; i++)
	{
		if (strcmp(inst, array_inst[i].opcode) == 0)
		{
			array_inst[i].f(stack, index);
			return;
		}
	}
	if (strlen(inst) != 0 && inst[0] != '#')
	{
		printf("L%u: unknown instruction %s\n", index, inst);
		exit(EXIT_FAILURE);
	}
}

