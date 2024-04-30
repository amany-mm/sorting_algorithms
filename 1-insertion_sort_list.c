#include "sort.h"

/**
 * swap_linked_list - Function to Swap 2 nodes in a doubly-linked list
 * @head: Pointer to first node
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: None
 */
void swap_linked_list(listint_t **head, listint_t **first, listint_t *second)
{
	(*first)->next = second->next;
	if (second->next != NULL)
		second->next->prev = *first;

	second->prev = (*first)->prev;
	second->next = *first;

	if ((*first)->prev != NULL)
		(*first)->prev->next = second;
	else
		*head = second;

	(*first)->prev = second;
	*first = second->prev;
}


/**
 * insertion_sort_list - Function that sorts d-linked list with insertion sort
 * @list: The list to sort
 * Return: None
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *insert_node, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;


	for (i = (*list)->next; i != NULL; i = tmp)
	{
		tmp = i->next;
		insert_node = i->prev;
		while (insert_node != NULL && i->n < insert_node->n)
		{
			swap_linked_list(list, &insert_node, i);
			print_list((const listint_t *)*list);
		}
	}
}
