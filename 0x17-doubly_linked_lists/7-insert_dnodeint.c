#include "lists.h"
/**
 *insert_dnodeint_at_index - inserts a node at a given index
 *@h: pointer to the h of the linked list
 *@idx: index to insert node
 *@n: data to insert into the node
 *Return: Address of new node or NULL
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{

	dlistint_t *new, *current;
	unsigned int count;

	new = malloc(sizeof(dlistint_t));
	if (h == NULL)
	{
		return (NULL);
	}

	if (new == NULL)
	{
		return (NULL);
	}

	new->n = n;

	if (idx == 0)
	{
		new->prev = NULL;
		new->next = *h;

		if (*h != NULL)
			(*h)->prev = new;

		*h = new;
		return (new);
	}

	current = *h;
	count = 0;

	while (current != NULL && count < idx - 1)
	{
		current = current->next;
		count++;
	}

	if (current == NULL)
	{
		free(new);
		return (NULL);
	}

	new->prev = current;
	new->next = current->next;

	if (current->next != NULL)
	{
		current->next->prev = new;
	}

	current->next = new;

	return (new);
}
