#include "sort.h"
#include <stdio.h>

/**
 * partition - finds the partition for the quicksort using the Lomuto scheme
 * @array: array to sort
 * @left: starting index of the partition to sort
 * @right: ending index of the partition to sort
 * @size: size of the array
 *
 * Return: index of the partition
 */
size_t partition(int *array, ssize_t left, ssize_t right, size_t size)
{
	ssize_t j, k;
	int swap, pivot;

	pivot = array[right];
	j = left - 1;
	for (k = left; k < right; k++)
	{
		if (array[k] < pivot)
		{
			j++;
			if (j != k)
			{
				swap = array[j];
				array[j] = array[k];
				array[k] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[right] < array[j + 1])
	{
		swap = array[j + 1];
		array[j + 1] = array[right];
		array[right] = swap;
		print_array(array, size);
	}
	return (j + 1);
}

/**
 * quicksort - sorts a partition of an array of integers
 * @array: array to sort
 * @left: lowest index of the partition to sort
 * @right: highest index of the partition to sort
 * @size: size of the array
 *
 * Return: void
 */
void quicksort(int *array, ssize_t left, ssize_t right, size_t size)
{
	ssize_t pivot;

	if (left < right)
	{
		pivot = partition(array, left, right, size);
		quicksort(array, left, pivot - 1, size);
		quicksort(array, pivot + 1, right, size);

	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
