#include "sort.h"

/**
 * print_parts - prints left, right, and merged parts
 * @arr: the input array
 * @side: left, right, or merged half
 * @start: starting index
 * @end: ending index
 */

void print_parts(int *arr, char *side, size_t start, size_t end)
{
	size_t i;

	printf("[%s]: ", side);
	for (i = start; i < end; i++)
	{
		if (i != (end - 1))
			printf("%d, ", arr[i]);
		else
			printf("%d\n", arr[i]);
	}
}

/**
 * _merge - recursively splits and merges parts
 * @array: array
 * @sortArr: tmp array to hold sorted elements
 * @l: start of the array
 * @r: end of the array
 */

void _merge(int *array, int *sortArr, size_t l, size_t r)
{
	size_t i, l_half, r_half;
	size_t mid = (l + r) / 2;

	if (r - l <= 1)
		return;

	_merge(array, sortArr, l, mid);
	_merge(array, sortArr, mid, r);
	printf("Merging...\n");
	print_parts(array, "left", l, mid);
	print_parts(array, "right", mid, r);
	l_half = l;
	r_half = mid;
	for (i = l; i < r; i++)
	{
		if ((l_half < mid) &&
		    (r_half == r || array[l_half] < array[r_half]))
		{
			sortArr[i] = array[l_half];
			l_half++;
		}
		else
		{
			sortArr[i] = array[r_half];
			r_half++;
		}
	}
	print_parts(sortArr, "Done", l, r);
	for (i = l; i < r; i++)
		array[i] = sortArr[i];
}

/**
 * merge_sort - sorts an array of integers
 * in ascending order using the Merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 */

void merge_sort(int *array, size_t size)
{
	int *sortArr;

	if (!(array) || size < 2)
		return;
	sortArr = malloc(sizeof(int) * size);
	if (!(sortArr))
		return;
	_merge(array, sortArr, 0, size);
	free(sortArr);
}
