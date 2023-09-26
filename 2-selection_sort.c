#include "sort.h"

/**
 * swap_ints - A program function that swaps two integers
 * @a: first integer
 * @b: second integer
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - A program function that sorts array in an ascending
 * order
 * @array: The array
 * @size: The size of an array
 */
void selection_sort(int *array, size_t size)
{
	int *mn;
	size_t a = 0, b;

	if (array == NULL || size < 2)
		return;

	while (a < size - 1)
	{
		mn = array + a;
		for (b = a + 1; b < size; b++)
		{
			mn = (array[b] < *mn) ? (array + b) : mn;

		}
		if ((array + a) != mn)
		{
			swap_ints(array + a, mn);
			print_array(array, size);
		}
		a++;
	}
}

