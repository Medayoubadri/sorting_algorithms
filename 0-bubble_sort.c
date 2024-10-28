#include "sort.h"

/**
* bubble_sort - Sorts an array of integers in ascending order using Bubble Sort
* @array: Array of integers to be sorted
* @size: Size of the array
*
* Description: A highly refined sorting method that progressively compares
* and bubbles the largest elements to the end. Much like convincing a stubborn
* cat to come down from a tree - a slow process, full of repetitive moves.
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
		if (!swapped)
			break;
	}
}
