#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using the Bubble sort algorithm
 * @array: array to sort
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, newsize;
	int tmp, swap;

	for (newsize = size, swap = 1; newsize > 0 && swap; newsize--)
	{
		swap = 0;
		for (i = 0; (i + 1) < newsize; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;
				print_array(array, size);
				swap = 1;
			}
		}
	}
}
