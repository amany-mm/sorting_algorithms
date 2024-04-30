#include "sort.h"


/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * using the Quick sort algorithm by implement the Hoare partition scheme.
 * @array: array
 * @size: size
 * Return: None
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}


/**
 * hoare_sort - uses quicksort algorithm through recursion
 * @array: array
 * @size: size
 * @left: starting index of array partition to order
 * @right: ending index of array partition to order
 * Return: None
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int above, below, pivot;

	if (right - left > 0)
	{
		pivot = array[right];

		for (above = left - 1, below = right + 1; above < below;)
		{
			do {
				above++;
			} while (array[above] < pivot);

			do {
				below--;
			} while (array[below] > pivot);

			if (above < below)
			{
				swap(array + above, array + below);
				print_array(array, size);
			}
		}
		/* Recursively call on left partition */
		hoare_sort(array, size, left, above - 1);
		/* Recursively call on right partition */
		hoare_sort(array, size, above, right);
	}
}


/**
 * swap - swap 2 elements
 * @left: left
 * @right: right
 */
void swap(int *left, int *right)
{
	int tmp = *left;

	*left = *right;
	*right  = tmp;
}
