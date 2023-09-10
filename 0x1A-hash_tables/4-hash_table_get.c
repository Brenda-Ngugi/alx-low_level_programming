#include "hash_tables.h"
/**
 *hash_table_get - retrivs a value associated with a key
 *@ht: the hash table
 *@key: the key I am seaching for
 *Return: node's value
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL)
		return NULL;

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node && strcmp(node->key, key) != 0)
		node = node->next;

	if (node == NULL)
		return (NULL);
	else
		return (node->value);
}
