#include "sort.h"

/**
 * bubble_sort - sorts an array of ints in ascending order
 * using the bubble sort algorithm
 * @array: pointer to array to be sorted
 * @size: number of elements in array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t outer; /* tracks how many have been sorted */
	size_t inner;
	int temp;

	if (array == NULL || size < 2)
	{
		return;
	}
	outer = 0;
	while (outer < size - 1)
	{
		inner = 0;
		while (inner < (size - outer) - 1) /* exclude sorted indexes */
		{
			if (array[inner] > array[inner + 1])
			{
				temp = array[inner];
				array[inner] = array[inner + 1];
				array[inner + 1] = temp;
				print_array(array, size);
				/* if left is greater than right, swap values */
			}
			inner = inner + 1;
		}
		outer = outer + 1;
	}
}
