#include "sort.h"

/**
* swap - Swaps two elements in an array and prints the array
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
* lomuto_partition - Lomuto partition scheme for Quick Sort
* @array: The array to partition
* @low: Starting index of the partition
* @high: Ending index of the partition (pivot)
* @size: The size of the entire array
*
* Return: The final index of the pivot
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];

	int i = low - 1;

	int j;

	for (j = low; j <= high - 1; j++)
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
	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
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
		int partition_index = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, partition_index - 1, size);
		quick_sort_recursive(array, partition_index + 1, high, size);
	}
}

/**
* quick_sort - Sorts an array of integers in ascending order using Quick Sort
* @array: Array of integers to be sorted
* @size: Size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
