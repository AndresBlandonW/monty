#include "monty.h"

int compile_file(char *filen, stack_t **stack)
{
        FILE *fp;
        char *line = NULL;
        size_t len = 0;
        unsigned int index = 0;
        ssize_t read;
        char *result;
        
        fp = fopen(filen, "r");
        if (fp == NULL)
        {
                printf("Error: Can't open file %s\n", filen);
                exit(EXIT_FAILURE);
        }

        while ((read = getline(&line, &len, fp)) != -1)
        {
                result = strtok(line, "\n \t\r");
                index++;

                if (result)
                        get_instruction(stack, result, index);
        }
        fclose(fp);
        if (line)
                free(line);
        return (EXIT_SUCCESS);
}