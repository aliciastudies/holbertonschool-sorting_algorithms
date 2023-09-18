#include "sort.h"

/**
 * lomuto_partition - Implements Lomuto partition scheme
 * @array: Pointer to array
 * @low: Lower index
 * @high: Higher index
 * @size: Size of the array
 *
 * Return: The final partition index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_lomuto - Recursive Quick sort using Lomuto partition
 * @array: Pointer to array
 * @low: Lower index
 * @high: Higher index
 * @size: Size of the array
 */
void quick_sort_lomuto(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);

		quick_sort_lomuto(array, low, pi - 1, size);
		quick_sort_lomuto(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Main Quick sort function
 * @array: Pointer to array
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_lomuto(array, 0, size - 1, size);
}
