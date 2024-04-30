#include "sort.h"


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


/**
 * partition_logic - partition logic
 * @arr: int arr
 * @low: low
 * @high: high
 * @size: arr size
 * Return: index of pivot
 */
int partition_logic(int arr[], int low, int high, size_t size)
{
	int i, j, pivot;

	/* Choose pivot element as last element of partition */
	pivot = arr[high];

	i = (low - 1);


	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;

			/* swap to move smaller element to left */
			swap(&arr[i], &arr[j]);

			if (i != j)
				print_array(arr, size); /* Print array after each swap */
		}
	}

	/* swap pivot to correct position */
	if (arr[i + 1] != arr[high])
	{
		swap(&(arr[i + 1]), &(arr[high]));

		print_array(arr, size);
	}
	return (i + 1); /* index of pivot */
}


/**
 * recursive_quick_sort - recursive quick sort
 * @array: int array
 * @low: low
 * @high: last
 * @size: array size
 */
void recursive_quick_sort(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{

		pivot_index = partition_logic(array, low, high, size);

		/*
		* Recursively sort, smaller element than the pivot move to left,
		* and higher element move to right
		*/
		/* sort to left of pivot */
		recursive_quick_sort(array, low, pivot_index - 1, size);

		/* sort to right of pivot */
		recursive_quick_sort(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: integers arrays
 * @size: array size
 * Return: None
 */
void quick_sort(int *array, size_t size)
{
	/* Base case */
	if (size <= 1)
		return;

	/* helper fn of recursive logic quick sort */
	recursive_quick_sort(array, 0, size - 1, size);
}

