#include "sort.h"
/**
 * selection_sort -  sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	int idx = 0;
	int tmp, min;

	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];

				idx = j;
			}
		}

		if (min != array[i])
		{
			tmp = array[i];

			array[i] = array[idx];

			array[idx] = tmp;

			print_array(array, size);
		}
	}
}
