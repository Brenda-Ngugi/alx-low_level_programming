#include "hash_tables.h"
/**
 *key_index - function that gives the index of a key
 *@key: the key
 *@size: the size of the array
 *Return: index
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_code, index;

	hash_code = hash_djb2(key);
	index = hash_code % size;

	return (index);
}
