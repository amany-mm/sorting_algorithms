#ifndef SORT_H
#define SORT_H

#include<stdlib.h>
#include <stdio.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;



/**
 * enum bool - Enumerate Boolean values
 * @false: 0
 * @true: 1
 */
typedef enum bool
{
	false = 0,
	true
} bool;


/* Prototypes of helpers print_array and print_list */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Prototypes of Bubble Sort */
void bubble_sort(int *array, size_t size);
void swap(int *left, int *right);

/* Prototypes of Insert sort */
void insertion_sort_list(listint_t **list);
void swap_linked_list(listint_t **head, listint_t **first, listint_t *second);

/* Prototype of Selection sort */
void selection_sort(int *array, size_t size);

/* Prototypes of Quick sort */
void quick_sort(int *array, size_t size);
void recursive_quick_sort(int *array, int low, int high, size_t size);
int partition_logic(int arr[], int low, int high, size_t size);

/* Prototype of Shell sort */
void shell_sort(int *array, size_t size);

/* Prototypes of Cocktail shaker sort */
void cocktail_sort_list(listint_t **list);
void swap_right(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_left(listint_t **list, listint_t **tail, listint_t **shaker);

/* Prototypes of Counting sort */
void counting_sort(int *array, size_t size);
int max_integer(int *array, int size);

/* Prototypes of Merge sort */
void merge_sort(int *array, size_t size);
void top_down_merge_sort(int *array, int *buffer, size_t top, size_t down);

/* Prototypes of Heap sort */
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size, size_t base, size_t root);

/* Prototypes for Radix sort */
void radix_sort(int *array, size_t size);
void lsd_radix_sort(int *array, size_t size, int sig, int *buff);

#endif
