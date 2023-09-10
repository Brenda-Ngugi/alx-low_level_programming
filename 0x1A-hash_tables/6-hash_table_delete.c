#include "hash_tables.h"

/**
 *hash_table_delete - function that deletes a hash table
 *@ht: hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *node, *current;
	unsigned long int i;

	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			node = ht->array[i];

			while (node != NULL)
			{
				current = node->next;
				free(node->value);
				free(node->key);
				free(node);
				node = current;
			}
		}
	}
	free(ht->array);
	free(ht);
}
