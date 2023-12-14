#include "search_algos.h"
/**
 *binary_search_recursive - recursively searches for an item
 *@array: pointer to first element of the array
 *@left: holds the first index
 *@right: holds the last index
 *@value: value to search for
 *Return: index of the item
 */

int binary_search_recursive(int *array, int left, int right, int value)
{
	int mid = left + (right - left) / 2;
	int i;

	if (left > right)
		return (-1);

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");

	if (array[mid] == value)
		return (mid);
	else if (array[mid] < value)
	{
		return (binary_search_recursive(array, mid + 1, right, value));
	}
		return (binary_search_recursive(array, left, mid - 1, value));
}
/**
 *binary_search - function that searches for a value in a sorted array
 *@array: pointer to first element of the array
 *@size: number of elements in the array
 *@value: value to search for
 *Return: index of the item
 */


int binary_search(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
	{
		return (-1);
	}

	return (binary_search_recursive(array, 0, size - 1, value));
}
