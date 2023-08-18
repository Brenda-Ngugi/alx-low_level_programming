#include "lists.h"
/**
 *sum_dlistint - adds all the contents of a linked list
 *@head: pointer to the starting point og the linked list
 *Return: NULL if list is empty, Sum if list isn't empty
 */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *current;
	int sum;

	current = head;
	sum = 0;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}
	return (sum);
}
