#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: integer array
 * @size: array size
 * Return: None
 */
void counting_sort(int *array, size_t size)
{
	int i, max, *current, *sorted;

	if (array == NULL || size < 2)
		return;
	sorted = malloc(sizeof(int) * size);

	if (sorted == NULL)
		return;

	max = max_integer(array, size);
	current = malloc(sizeof(int) * (max + 1));

	if (current == NULL)
	{
		free(sorted);
		return;
	}
    /*  initialize array to all zeros */
	for (i = 0; i < (max + 1); i++)
		current[i] = 0;
    /* count occurrences of each integer in array */
	for (i = 0; i < (int)size; i++)
		current[array[i]] += 1;
    /* accumulate counts to obtain positions */
	for (i = 0; i < (max + 1); i++)
		current[i] += current[i - 1];

	print_array(current, max + 1);
    /* place integers in the sorted array */
	for (i = 0; i < (int)size; i++)
	{
		sorted[current[array[i]] - 1] = array[i];
		current[array[i]] -= 1;
	}
    /* copy sorted array back to the original array */
	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(current);
}

/**
 * max_integer - return maximum of integer array
 * @array:  array
 * @size: size
 * Return: maximum integer
 */
int max_integer(int *array, int size)
{
	int i, max;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
