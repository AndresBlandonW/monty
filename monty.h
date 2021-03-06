#ifndef Montyh_Header
#define Montyh_Header

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	int (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void free_all(char *current_line, FILE *file, stack_t *head);
void check_argc(int argc);
FILE *open_file(char *argv);
char *get_current_line(char *current_line, FILE *file, stack_t *head);
int (*get_inst(char *command, unsigned int line_number))();
int push(stack_t **stack, unsigned int line_number);
int pall(stack_t **stack, unsigned int line_number);

stack_t *add_node(stack_t **head, int n);
void free_stack(stack_t *head);
int pop(stack_t **head, unsigned int index);
int delete_node(stack_t **head, unsigned int index);
int pint(stack_t **head, unsigned int line_number);
int swap(stack_t **stack, unsigned int line_number);
int add(stack_t **head, unsigned int line_number);
int nop(stack_t **head, unsigned int line_number);
int sub(stack_t **head, unsigned int line_number);
int mul(stack_t **head, unsigned int line_number);
int divi(stack_t **head, unsigned int line_number);
int modu(stack_t **head, unsigned int line_number);

int pchar(stack_t **head, unsigned int line_number);

#endif
