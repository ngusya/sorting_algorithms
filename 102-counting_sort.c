#include "sort.h"

/**
 * counting_sort - will sort an array with the Counting sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int *count_arr, *out_arr, max, num, k, m;
	size_t j, l, n, o;

	if (size < 2)
		return;

	max = array[0];
	for (j = 1; j < size; j++)
		if (array[j] > max)
			max = array[j];

	count_arr = malloc(sizeof(size_t) * (max + 1));
	out_arr = malloc(sizeof(int) * size);

	for (k = 0; k <= max; k++)
		count_arr[k] = 0;
	for (l = 0; l < size; l++)
	{
		num = array[l];
		count_arr[num] += 1;
	}
	for (m = 1; m <= max; m++)
		count_arr[m] += count_arr[m - 1];
	print_array(count_arr, max + 1);
	for (n = 0; n < size; n++)
	{
		out_arr[count_arr[array[n]] - 1] = array[n];
		count_arr[array[n]]--;
	}
	for (o = 0; o < size; o++)
		array[o] = out_arr[o];

	free(count_arr);
	free(out_arr);
}
