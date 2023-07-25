#include "sort.h"

/**
 * counting_sort - sorts an array of integers
 * in ascending order using the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */

void counting_sort(int *array, size_t size)
{
	size_t i;
	int j, k, l, *counts;

	if (array == NULL || size < 2)
		return;
	k = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	counts = malloc(sizeof(int) * (k + 1));
	if (counts == NULL)
		return;
	for (j = 0; j < (k + 1); j++)
		counts[j] = 0;
	for (i = 0; i < size; i++)
		counts[array[i]]++;
	for (j = 0; j < k; j++)
		counts[j + 1] += counts[j];
	print_array(counts, k + 1);
	for (i = 0, j = 0; j < k; j++)
	{
		if (!j && counts[j])
		{
			for (l = counts[j]; l > 0; l--)
				array[i++] = j;
		}
		if (counts[j + 1] > counts[j])
		{
			for (l = counts[j + 1] - counts[j]; l > 0; l--)
				array[i++] = (j + 1);
		}
	}
	free(counts);
}
