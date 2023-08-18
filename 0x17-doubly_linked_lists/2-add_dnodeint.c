#include "lists.h"
/**
 *add_dnodeint - adds a node at the beginning of a linked lists
 *@head: head of the linked list
 *@n: data to add to new node
 *Return: Null if failed, new if succesfull
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));

	if (new == NULL)
	{
		return (NULL);
	}
	new->n = n;
	new->next = *head;
	new->prev = NULL;

	if (*head != NULL)
	{
		(*head)->prev = new;
	}
	*head = new;
	return (new);
}
