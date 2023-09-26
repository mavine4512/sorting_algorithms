#include "sort.h"

/**
 * swap_ints - Swap tow int in an array
 * @a: first int to swap
 * @b: second int to swap
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sort an array on numbers in ascending order
 * @array: array to sort
 * @size: number of elements.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly ==  false)
	{
		bubbly = true;
		i = 0;
		while (i < len - 1)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
			i++;
		}
		len--;
	}
}

