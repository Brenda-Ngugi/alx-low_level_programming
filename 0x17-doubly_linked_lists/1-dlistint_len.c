#include "lists.h"
/**
 *dlistint_len - prints the number of elements in linked list
 *@h: Keeps track of the head of the list
 *Return: Count
 */
size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *current = h;
	int count = 0;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}
