#include "sort.h"
/**
 * bubble_sort - sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 * @array: the array to sort
 * @size: the size
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = size, j;
	int tmp, flag;

	if (array == NULL || size < 2)
		return;

	while (i)
	{
		flag = 0;
		for (j = 0; j < i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;
				print_array(array, size);
				flag = 1;
			}
		}
		i--;
		if (!flag)
			break;
	}
}
