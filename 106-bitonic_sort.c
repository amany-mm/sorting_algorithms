#include "sort.h"


/**
 * bitonic_sort - sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 * @array: array
 * @size: size
 * Return: None
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}

/**
 * bitonic_merge - recursively sorts a bitonic sequence in ascending order
 * @array: array
 * @size: size
 * @start: starting index of sequence in array to sort
 * @sequence: sequence size to sort
 * @flow: direction to sort in
 * Return: None
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t sequence,
		char flow)
{
	size_t i, jump = sequence / 2;

	if (sequence > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
			    (flow == DOWN && array[i] < array[i + jump]))
				swap(array + i, array + i + jump);
		}

		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}


/**
 * bitonic_seq - converts array into a bitonic sequence
 * @array: array
 * @size: size
 * @start: start index of a block of building bitonic sequence
 * @seq: block size of building bitonic sequence
 * @flow: direction to sort bitonic sequence block in
 * Return: None
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);

		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
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
