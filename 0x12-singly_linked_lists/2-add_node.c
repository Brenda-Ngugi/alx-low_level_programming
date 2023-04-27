#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - add new node begining of list_t
 * @head: pointer to structure
 * @str: string
 * Return: the adrres of new element
 */

list_t *add_node(list_t **head, const char *str)
{
list_t *nodenew;
unsigned int length = 0;

	nodenew = malloc(sizeof(list_t));
	if (nodenew == NULL)
	{
		free(nodenew);
		return (NULL);
	}
	nodenew->str = strdup(str);
	while (str[length] != '\0')
	{
		length++;
	}
	nodenew->len = length;
	if (*head != NULL)
		nodenew->next = *head;
	if (*head == NULL)
		nodenew->next = NULL;
	*head = nodenew;
	return (*head);
}
