#include "sort.h"

/**
  * selection_sort - sorts an array of integers in ascending
  * order using the Selection sort algorithm
  * @array: pointer to array to be sorted
  * @size: number of elements in array
  * Return: void
  */
void selection_sort(int *array, size_t size)
{
	size_t outer;
	size_t inner;
	size_t min; /* tracking the min value */
	int temp;

	if (array == NULL || size < 1)
	{
		return;
	}
	outer = 0;
	while (outer < size - 1)
	{
		min = outer;
		inner = outer + 1;
		while (inner < size)
		{
			if (array[inner] < array[min])
			/* if inner is less than min, update min */
			{
				min = inner;
			}
			inner = inner + 1;
		}
		if (min != outer)
/* checks if min has been updated during inner loop. if yes, swap new min  */
		{
			temp = array[outer];
			array[outer] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
		outer = outer + 1;
	}
}
