#include "sort.h"

void swap_ints(int *a, int *b);
void quick_sort_hoare(int *array, size_t size);
void hoare_sort(int *array, size_t size, int left, int right);
int hoare_partition(int *array, size_t size, int left, int right);

/**
 * swap_ints - Swap two integers in an array
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */

void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * hoare_partition - Order a subset of an array of integers.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: Starting index of the subset to order.
 * @right: Ending index of the subset to order.
 * Return: Final partition index.
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */

int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, top, bottom;

	pivot = array[right];
	for (top = left - 1, bottom = right + 1; top < bottom;)
	{
		do {
			top++;
		} while (array[top] < pivot);
		do {
			bottom--;
		} while (array[bottom] > pivot);

		if (top < bottom)
		{
			swap_ints(array + top, array + bottom);
			print_array(array, size);
		}
	}

	return (top);
}


/**
 * hoare_sort - Implemention of quicksort algorithm through recursion.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 * @left: Starting index of the array partition to order.
 * @right: Ending index of the array partition to order.
 * Description: Uses the Hoare partition scheme.
 */

void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending order.
 * @array: Array of integers.
 * @size: Size of the array.
 * Description: Uses the Hoare partition scheme.
 * Prints the array after each swap of two elements.
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
