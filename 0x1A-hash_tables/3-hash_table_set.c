#include "hash_tables.h"
/**
 *hash_table_set - adds an element to the hash taable
 *@ht: the hash table
 *@key: of the item to be added
 *@value: item to be added
 *Return: success 1 else 0
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node;
	char *value_cp;
	unsigned long int index, i;

	if (ht == NULL || key == NULL)
		return (0);

	value_cp = strdup(value);
	index = key_index((const unsigned char *)key, ht->size);

	for (i = index; ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = value_cp;
			return (1);
		}
	}
	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (0);

	node->key =strdup(key);
	node->value = value_cp;
	node->next = ht->array[index];
	ht->array[index] = node;

	return (1);
}
