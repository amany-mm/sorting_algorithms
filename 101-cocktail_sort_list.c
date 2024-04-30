#include "sort.h"


/**
 * cocktail_sort_list -  sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: ptr to 1st doubly linked list node
 * Return: None
 */
void cocktail_sort_list(listint_t **list)
{
	bool shaken = false;
	listint_t *shaker, *tail;


	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	/*  apply Cocktail shaker sort algorithm */
	while (shaken == false)
	{
		shaken = true;

		/* apply forward pass of Cocktail shaker sort */
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{

			if (shaker->n > shaker->next->n)
			{
				swap_right(list, &tail, &shaker);

				print_list((const listint_t *)*list);
				shaken = false;
			}
		}

		/* apply backward pass of Cocktail shaker sort */
		for (shaker = shaker->prev; shaker != *list; shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_left(list, &tail, &shaker);

				print_list((const listint_t *)*list);
				shaken = false;
			}
		}
	}
}


/**
 * swap_left - swap with node on the left in list
 * @list: 1st node pointer
 * @tail: last node pointer
 * @shaker: current node pointer to swap pointer
 * Return: None
 */
void swap_left(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp_node = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp_node;

	else
		*tail = tmp_node;

	tmp_node->next = (*shaker)->next;

	(*shaker)->prev = tmp_node->prev;

	if (tmp_node->prev != NULL)
		tmp_node->prev->next = *shaker;

	else
		*list = *shaker;

	(*shaker)->next = tmp_node;

	tmp_node->prev = *shaker;

	*shaker = tmp_node;
}

/**
 * swap_right - swap with node on right in list
 * @list: 1st node pointer
 * @tail: last node pointer
 * @shaker: current node to swap pointer
 * Return: None
 */
void swap_right(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;

	else
		*list = tmp;

	tmp->prev = (*shaker)->prev;

	(*shaker)->next = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = *shaker;

	else
		*tail = *shaker;

	(*shaker)->prev = tmp;

	tmp->next = *shaker;

	*shaker = tmp;
}
