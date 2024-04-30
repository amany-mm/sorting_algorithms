#include "sort.h"

/**
 * swap_linked_list - swap two nodes in a doubly linked list
 * @head: Pointer to first node
 * @left: Pointer to the left node
 * @right: Pointer to the right node
 * Return: None
 */
void swap_linked_list(listint_t **head, listint_t **left, listint_t *right)
{
	(*left)->next = right->next;

	if (right->next != NULL)
		right->next->prev = *left;

	right->prev = (*left)->prev;
	right->next = *left;

	if ((*left)->prev != NULL)
		(*left)->prev->next = right;
	else
		*head = right;

	(*left)->prev = right;
	*left = right->prev;
}


/**
 * insertion_sort_list - Function that sorts d-linked list with insertion sort
 * @list: The list to sort
 * Return: None
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *idx, *tmp, *insert_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	idx = (*list)->next;

	while (idx != NULL)
	{

		tmp = idx->next;

		insert_node = idx->prev;

		while (insert_node != NULL && idx->n < insert_node->n)
		{
			swap_linked_list(list, &insert_node, idx);

			print_list((const listint_t *)*list);
		}

		/* Update idx to the next node */
		idx = tmp;
	}
}
