#include "monty.h"

/**
 * add_dnodeint - add node at the list
 * @head: linked list
 * @num: data
 * Return: new node
 */

stack_t *add_dnodeint(stack_t **head, const int num)
{
stack_t *newNode = malloc(sizeof(stack_t));

if (newNode == NULL)
{
printf("Error: malloc failed\n");
exit(EXIT_FAILURE);
}

newNode->n = num;
newNode->next = *head;
newNode->prev = NULL;

if (*head != NULL)
(*head)->prev = newNode;

*head = newNode;

return (newNode);
}
