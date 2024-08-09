#include "sort.h"

/**
 * swap - Swaps two integer values.
 *
 * @a: Pointer to the first value
 * @b: Pointer to the second value
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - Partitions the array using the Lomuto partition scheme.
 *
 * @array: Pointer to the array of integers to partition
 * @size: Size of the array
 * Return: The index of the pivot after partitioning
 */
size_t partition(int array[], size_t size)
{
	int pivot;
	size_t i;
	size_t j;

	i = 0;
	pivot = array[size - 1];

	for (j = 0; j < size - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != size - 1)
	{
		swap(&array[i + 1], &array[size - 1]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_rec - Helper function to perform Quick Sort recursively.
 *
 * @array: Pointer to the array of integers to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 */
void quick_sort_rec(int *array, int low, int high)
{
	size_t pivot_index;

	if (low < high)
	{
		pivot_index = partition(array + low, high - low + 1) + low;

		quick_sort_rec(array, low, pivot_index - 1);
		quick_sort_rec(array, pivot_index + 1, high);
	}
}
/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm with Lomuto partition scheme.
 *
 * @array: Pointer to the array of integers to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1);
}
