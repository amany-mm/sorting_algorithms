#include "sort.h"


/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: array
 * @size: size
 * Return: None
 */
void radix_sort(int *array, size_t size)
{
	int *buffer, max, significant_digit;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);

	if (buffer == NULL)
		return;

	max = max_integer(array, size);

	/* Iterate through each significant digit */
	for (significant_digit = 1; max / significant_digit > 0;
		significant_digit *= 10)
	{
		/* Sort the array based on the least significant digit */
		lsd_radix_sort(array, size, significant_digit, buffer);

		print_array(array, size);
	}

	free(buffer);
}

/**
 * lsd_radix_sort - sorts least significant digit radix sort with counting sort
 * @array: array
 * @size: size
 * @sig_dig: significant digit to sort
 * @buffer: array copy to sort
* Return: None
 */
void lsd_radix_sort(int *array, size_t size, int sig_dig, int *buffer)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	/* Count frequency of each digit */
	for (i = 0; i < size; i++)
		count[(array[i] / sig_dig) % 10] += 1;

	/* Update count array to store the cumulative frequency */
	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the sorted array */
	for (i = size - 1; (int)i >= 0; i--)
	{
		buffer[count[(array[i] / sig_dig) % 10] - 1] = array[i];

		count[(array[i] / sig_dig) % 10] -= 1;
	}
	/* Copy sorted array back to original array */
	for (i = 0; i < size; i++)
		array[i] = buffer[i];
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
