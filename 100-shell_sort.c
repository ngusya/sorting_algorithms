#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the
 * Shell sort algorithm
 * @array: array to sort
 * @size: size of the array to sort
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t j, k, gap = 1;
	int insert;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (j = gap; j < size; j++)
		{
			insert = array[j];
			for (k = j; k >= gap && array[k - gap] > insert; k = k - gap)
				array[k] = array[k - gap];
			array[k] = insert;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
