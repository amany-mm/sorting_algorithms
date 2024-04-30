#include "sort.h"


/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: array
 * @size: size
 * Return: None
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, array + i);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}


/**
 * heapify - heapify a subtree
 * @array: array
 * @size: size
 * @base: base row of the binary tree index
 * @root: root node
 * Return: None
 */
void heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t largest, left, right;

	largest = root;
	left = 2 * root + 1;
	right = 2 * root + 2;

	if (left < base && array[left] > array[largest])
		largest = left;

	if (right < base && array[right] > array[largest])
		largest = right;

	/* swap and continue heapifying if root is not largest */
	if (largest != root)
	{
		swap(array + root, array + largest);
		print_array(array, size);

		/* recursively heapify affected sub-tree */
		heapify(array, size, base, largest);
	}
}


/**
 * swap - swap position of 2 elements in list
 * @left: left
 * @right: right
 * Return: None
 */
void swap(int *left, int *right)
{
	int tmp;

	tmp = *left;

	*left = *right;
	*right = tmp;
}
