#include "sort.h"
#include <stdio.h>

/**
* swap - Swaps two elements in an array
* @a: Pointer to the first element
* @b: Pointer to the second element
*/
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
* lomuto_partition - Partitions the array using the Lomuto partition scheme
* @array: The array to partition
* @low: The starting index of the partition
* @high: The ending index of the partition
* @size: The size of the entire array
*
* Return: The index of the pivot after partitioning
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];

	int i = low - 1;

	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
* quick_sort_recursive - Recursively applies Quick Sort to partitions
* @array: The array to sort
* @low: The starting index of the current partition
* @high: The ending index of the current partition
* @size: The size of the entire array
*/
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
* quick_sort - Sorts an array of integers in ascending order using Quick Sort
* @array: Array of integers to be sorted
* @size: Size of the array
*
* Description: Implements the Lomuto partition scheme, selecting the last
* element as pivot. Recursively sorts partitions on either side of the pivot.
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
