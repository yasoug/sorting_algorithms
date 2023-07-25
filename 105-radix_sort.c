#include "sort.h"

/**
 * max_num - max number in an array
 * @array: input array
 * @size: size of the array
 * Return: max number
 */

int max_num(int *array, size_t size)
{
	unsigned int i;
	int max = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] > (int)max)
			max = array[i];
	}
	return (max);
}

/**
 * count_sort - counting sort algorithm
 * @array: input array
 * @size: size of the array
 * @pow: power of 10
 */

void count_sort(int *array, size_t size, int pow)
{
	int *copy;
	int counting[10];
	unsigned int i = 0, tmp;

	copy = malloc(size * sizeof(int));
	if (copy == NULL)
		return;

	for (i = 0; i < 10; i++)
		counting[i] = 0;

	for (i = 0; i < size; i++)
		counting[(array[i] / pow) % 10]++;

	for (i = 1; i < 10; i++)
		counting[i] += counting[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		tmp = (array[i] / pow) % 10;
		copy[counting[tmp] - 1] = array[i];
		counting[tmp]--;
	}

	for (i = 0; i < size; i++)
		array[i] = copy[i];

	free(copy);
}

/**
 * radix_sort - sorts an array of integers
 * in ascending order using the Radix sort algorithm
 * @array: array to sort
 * @size: size of the array
 */

void radix_sort(int *array, size_t size)
{
	int pow = 1;
	int max = max_num(array, size);

	if (size == 0 || size == 1)
		return;

	while (max / pow > 0)
	{
		count_sort(array, size, pow);
		print_array(array, size);
		pow = pow * 10;
	}
}
