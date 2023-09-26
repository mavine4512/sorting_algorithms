#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
 * max_heapify - A function that turns a binary tree to binary heap
 * @array: Array of integers
 * @size: size of array
 * @base: index of base row
 * @root: root node of tree
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t right, left, arge;

	left = 2 * root + 1;
	right = 2 * root + 2;
	arge = root;

	arge = (left < base && array[left] > array[arge]) ? left : arge;
	arge = (right < base && array[right] > array[arge]) ? right : arge;

	if (arge != root)
	{
		swap_ints(array + root, array + arge);
		print_array(array, size);
		max_heapify(array, size, base, arge);
	}
}

/**
 * heap_sort - A function that sorts arrays in heap sort algorithm
 * @array: Array of integers
 * @size: Size of array
 * Description: uses sift-down heap sort
 */
void heap_sort(int *array, size_t size)
{
	int a;

	if (array == NULL || size < 2)
		return;
	a = (size / 2) - 1;
	while (a >= 0)
	{
		max_heapify(array, size, size, a);
		a--;
	}
	for (a = size - 1; a > 0; a--)
	{
		swap_ints(array, array + a);
		print_array(array, size);
		max_heapify(array, size, a, 0);
	}
}

