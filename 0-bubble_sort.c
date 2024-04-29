#include "sort.h"

/**
 * swap - Function to swap position of 2 elements in list
 * @left: left element
 * @right: right element
 *
 * Return: None
 */
void swap(int *left, int *right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}



/**
 * bubble_sort - sort an array of integers
 * @array: The array of integers to sort
 * @size: Size of the array
 *
 * Return: None
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		swapped = false;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array + j, array + j + 1);

				print_array(array, size);

				swapped = true;

			}
		}

		/* If no two elements were swapped by inner loop, then break */
		if (swapped == false)
			break;

	}

}
