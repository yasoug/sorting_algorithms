#include "sort.h"

/**
 * heap_struct - puts an array in a heap structure
 * @array: input array
 * @min: min value
 * @max: max value
 * @size: size of the array
 */

void heap_struct(int *array, int min, int max, size_t size)
{
	int root = min, tmp;
	int left = 2 * root + 1;
	int right = 2 * root + 2;

	if (left < max && array[left] > array[root])
		root = left;

	if (right < max && array[right] > array[root])
		root = right;

	if (min != root)
	{
		tmp = array[root];
		array[root] = array[min];
		array[min] = tmp;
		print_array(array, size);
		heap_struct(array, root, max, size);
	}
}

/**
 * heap_sort - sorts an array of integers
 * in ascending order using the Heap sort algorithm
 * @array: array to sort
 * @size: size of the array
 */

void heap_sort(int *array, size_t size)
{
	int i, tmp;

	for (i = size / 2 - 1; i >= 0; i--)
		heap_struct(array, i, size, size);

	i = size - 1;
	while (i > 0)
	{
		tmp = array[i];
		array[i] = array[0];
		array[0] = tmp;
		print_array(array, size);
		heap_struct(array, 0, i, size);
		i--;
	}
}
