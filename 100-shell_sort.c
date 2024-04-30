#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: array
 * @size: size
 * Return: None
 */
void shell_sort(int *array, size_t size)
{
	size_t tmp, gap, i, j;

	/* use the Knuth's sequence to calculate the init gap  */
	gap = 1;

	while (gap < size)
		gap = (gap * 3) + 1;

	gap = (gap - 1) / 3;

	/* apply shell sort with calculated gap */
	while (gap > 0)
	{
		for (i = 0; i < size; i++)
		{
			/* apply insertion sort for the elements separated by the gap */
			for (j = i; j < size - gap; j += gap)
			{
				if (array[j] > array[j + gap])
					swap(&array[j], &array[j + gap]);


				tmp = j;

				while (tmp >= gap)
				{
					if (array[tmp] < array[tmp - gap])
						swap(&array[tmp], &array[tmp - gap]);

					tmp -= gap;
				}
			}
		}

		gap = (gap - 1) / 3; /* Reduce gap using Knuth's seq */

		print_array(array, size);
	}
}

/**
 * swap - swap 2 elements
 * @left: left
 * @right: right
 */
void swap(int *left, int *right)
{
	int temp = *left;

	*left = *right;
	*right = temp;
}
