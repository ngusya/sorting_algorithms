/*
 * File: 0-bubble_sort.c
 * Auth: Mwovi Kelvin
 */

#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using the
 * Bubble sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, new_j;
	int swap;

	if (array == NULL || size < 2)
		return;

	j = size;
	while (j > 0)
	{
		new_j = 0;
		for (i = 0; i < j - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap = array[i];
				array[i] = array[i + 1];
				array[i + 1] = swap;
				new_j = i + 1;
				print_array(array, size);
			}
		}
		j = new_j;
	}
}
