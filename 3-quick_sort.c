#include "sort.h"
void swap_integers(int *a, int *b);
int lomuto_part(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_integers - A function that swaps integers
 * @a: first int
 * @b: second int
 */
void swap_integers(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_part - A function that partitions lomuta scheme
 * @array: Array of integers
 * @size: size of array
 * @left: first index of subset
 * @right: last index of subset
 * Return: partition index
 */
int lomuto_part(int *array, size_t size, int left, int right)
{
	int *pivot, top, bottom;

	pivot = array + right;
	top = bottom = left;
	while (bottom < right)
	{
		if (array[bottom] < *pivot)
		{
			if (top < bottom)
			{
				swap_integers(array + bottom, array + top);
				print_array(array, size);
			}
			top++;
		}
		bottom++;
	}
	if (array[top] > *pivot)
	{
		swap_integers(array + top, pivot);
		print_array(array, size);
	}
	return (top);
}

/**
 * lomuto_sort - A program function that implements quicksort
 * @array: Array of integers
 * @size: size of array
 * @left: first index
 * @right: last index
 * Description: Lomuto partition scheme
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int p;

	if (right - left > 0)
	{
		p = lomuto_part(array, size, left, right);
		lomuto_sort(array, size, left, p - 1);
		lomuto_sort(array, size, p + 1, right);
	}
}

/**
 * quick_sort - A  function that sorts array of integers using the
 * algorithm
 * @array: Array of integers
 * @size: Size of the array
 * Description: uses Lomuto Partition Scheme
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

