#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start,
		size_t seq, char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - A program function that swaps two integers
 * in an array
 * @a: first array
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
 * bitonic_merge - A program function that sorts bitonic sequence
 * @array: Array of integers
 * @size: size of array
 * @start: start index
 * @seq: sequence to sort
 * @flow: direction to sort
 */
void bitonic_merge(int *array, size_t size, size_t start,
		size_t seq, char flow)
{
	size_t a, jump = seq / 2;

	if (seq > 1)
	{
		a = start;
		while (a < start + jump)
		{
			if ((flow == UP && array[a] > array[a + jump]) ||
					(flow == DOWN && array[a] < array[a + jump]))
				swap_ints(array + a, array + a + jump);
			a++;
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}

}

/**
 * bitonic_seq - A program function that converts array of integers
 * @array: Array of integers
 * @size: size of array
 * @start: start index
 * @seq: sequence to sort
 * @flow: direction to sort
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - a program function that sorts array in bitonic sort algorithm
 * @array: Array of integers
 * @size: size of array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bitonic_seq(array, size, 0, size, UP);
}

