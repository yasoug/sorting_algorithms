#include "sort.h"

/**
 * selection_sort - sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array: the array to sort
 * @size: the size
 */

void selection_sort(int *array, size_t size)
{
	int index = 0, min, tmp;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				index = j;
			}
		}
		if (min != array[i])
		{
			tmp = array[i];
			array[i] = array[index];
			array[index] = tmp;
			print_array(array, size);
		}
	}
}
