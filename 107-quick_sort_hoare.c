#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - A function that swaps integers
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
 * hoare_partition - A program function that uses hoare partition
 * scheme
 * @array: Array of integers
 * @size: size of array
 * @left: start index
 * @right: end index
 * Return: partition index
 * Description: prints array after swapping
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, top, bottom;

	pivot = array[right];
	top = left - 1;
	bottom = right + 1;

	while (1)
	{
		while (array[++top] < pivot)
			;
		while (array[--bottom] > pivot)
			;
		if (top >= bottom)
			break;

		swap_ints(array + top, array + bottom);
		print_array(array, size);
	}
	return (top);
}

/**
 * hoare_sort - A function that uses recursion usin quicksort algorithm
 * @array: Array of integers
 * @size: Size of array
 * @left: start index
 * @right: end index
 * Description: Hoare partition scheme
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int p;

	if (right - left > 0)
	{
		p = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, p - 1);
		hoare_sort(array, size, p, right);
	}
}

/**
 * quick_sort_hoare - A function that sorts arrays using the algorithm
 * @array: Array of integers
 * @size: size of array
 * Description: Hoare partition scheme
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}

