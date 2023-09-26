#include <stdio.h>
#include "sort.h"
/**
 * print_array - a program function that prints an array of integers
 * @array: The array itself
 * @size: The size of the array
 */
void print_array(const int *array, size_t size)
{
	size_t i = 0;

	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}

