#include "monty.h"

/**
 * add_dnodeint - add node at the list
 * @head: linked list
 * @n: data
 * Return: new node
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
        stack_t *newNode = malloc(sizeof(stack_t));

        if (newNode == NULL)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }

        newNode->n = n;
        newNode->next = *head;
        newNode->prev = NULL;

        if (*head != NULL)
                (*head)->prev = newNode;
        
        *head = newNode;

        return (newNode);
}