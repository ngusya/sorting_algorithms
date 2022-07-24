#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using the
 * Selection sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 *
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t j, k, min;
	int swap;

	if (array == NULL || size < 2)
		return;

	for (j = 0; j < size - 1; j++)
	{
		min = j;
		for (k = j + 1; k < size; k++)
		{
			if (array[k] < array[min])
				min = k;
		}
		if (j != min)
		{
			swap = array[j];
			array[j] = array[min];
			array[min] = swap;
			print_array(array, size);
		}
	}
}
