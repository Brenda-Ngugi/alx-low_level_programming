#include "lists.h"
/**
 *get_dnodeint_at_index - gets a node at a given index
 *@head: starting point of the list in memory
 *@index: the node to retrieve
 *Return: Node if index is in range, NULL if it is out of range
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current;
	unsigned int count;

	current = head;
	count = 0;

	while (current != NULL)
	{
		if (count == index)
			return (current);

		current = current->next;
		count++;
	}
	return (NULL);
}
