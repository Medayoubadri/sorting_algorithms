#include "sort.h"
#include <stdio.h>

/**
 * swap_elements - Swaps two elements in an array and prints the array
 * @array: The array of integers
 * @size: The size of the array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap_elements(int *array, size_t size, int *a, int *b)
{
	if (a != b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
		print_array(array, size);
	}
}

/**
 * partition - Lomuto partition scheme for Quick Sort
 * @array: The array to partition
 * @low: Starting index of the partition
 * @high: Ending index of the partition (pivot)
 * @size: The size of the entire array
 *
 * Return: The final index of the pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap_elements(array, size, &array[i], &array[j]);
			i++;
		}
	}
	swap_elements(array, size, &array[i], &array[high]);
	return (i);
}

/**
 * quick_sort_recursive - Recursively sorts the array using Quick Sort
 * @array: The array to sort
 * @low: Starting index of the current partition
 * @high: Ending index of the current partition
 * @size: The size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 * @array: Array of integers to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
