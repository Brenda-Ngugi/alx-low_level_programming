#include "search_algos.h"

/**
 *linear_search -  for a value in an array using linear search
 *@array: emacs pointer to the first element of the array to search in
 *@size: number of elements in array
 *@value: value to search for
 *Return: First occurence of value
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (size == 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
