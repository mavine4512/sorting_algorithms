#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - A function that gets maximum value of integers in an array
 * @array: Array of integers
 * @size: size of array
 * Return: maximum integer
 */
int get_max(int *array, int size)
{
	int max, a = 1;

	max = array[0];
	for (; a < size; a++)
	{
		if (array[a] > max)
			max = array[a];
	}

	return (max);
}

/**
 * radix_counting_sort - A function that sorts significant digits of array
 * of an array of integers
 * @array: Array of integers
 * @size: size of array
 * @sig: significant digit
 * @buff: Buffer to store array
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t a;

	for (a = 0; a < size; a++)
	{
		count[(array[a] / sig) % 10] += 1;
	}
	for (a = 0; a < 10; a++)
		count[a] += count[a - 1];

	for (a = size - 1; (int)a >= 0; a--)
	{
		buff[count[(array[a] / sig) % 10] - 1] = array[a];
		count[(array[a] / sig) % 10] -= 1;
	}
	for (a = 0; a < size; a++)
		array[a] = buff[a];
}

/**
 * radix_sort - A function that sorts the arrays in ascending
 * orders
 * @array: Array of integers
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	max = get_max(array, size);
	sig = 1;
	while (max / sig > 0)
	{
		radix_counting_sort(array, size, sig, buffer);
		print_array(array, size);
		sig *= 10;
	}
	free(buffer);
}

