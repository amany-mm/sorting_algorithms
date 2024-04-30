#include "deck.h"

/**
 * sort_deck - sorts a deck of cards
 * @deck: 1st node pointer of deck_node_t list
 * Return: None
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	sort_kind(deck);
	sort_value(deck);
}


/**
 * _strcmp - compares 2 strings
 * @first: 1st string
 * @second: 2nd string
 * Return: positive if first is greater,
 * 0 if equal, negative if first is less
 */
int _strcmp(const char *first, const char *second)
{
	while (*first && *second && *first == *second)
	{
		first++;
		second++;
	}

	if (*first != *second)
		return (*first - *second);

	return (0);
}

/**
 * card_value - returns card value
 * @card: deck_node_t card pointer
 * Return: numerical value of card
 */
char card_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * sort_kind - sorts cards based on kind with insertion sort
 * @deck: head of a deck_node_t pointer
 * Return: None
 */
void sort_kind(deck_node_t **deck)
{
	deck_node_t *i, *tmp, *shuf;

	for (i = (*deck)->next; i != NULL; i = tmp)
	{
		tmp = i->next;
		shuf = i->prev;

		while (shuf != NULL && shuf->card->kind > i->card->kind)
		{
			shuf->next = i->next;

			if (i->next != NULL)
				i->next->prev = shuf;

			i->prev = shuf->prev;
			i->next = shuf;

			if (shuf->prev != NULL)
				shuf->prev->next = i;
			else
				*deck = i;

			shuf->prev = i;
			shuf = i->prev;
		}
	}
}


/**
 * sort_value - sorts cards based on value with insertion sort
 * @deck: head pointer of a deck_node_t
 * Return: None
 */
void sort_value(deck_node_t **deck)
{
	deck_node_t *i, *tmp, *shuf;

	for (i = (*deck)->next; i != NULL; i = tmp)
	{
		tmp = i->next;
		shuf = i->prev;
		while (shuf != NULL && shuf->card->kind == i->card->kind &&
				card_value(shuf) > card_value(i))
		{
			shuf->next = i->next;
			if (i->next != NULL)
				i->next->prev = shuf;

			i->prev = shuf->prev;
			i->next = shuf;
			if (shuf->prev != NULL)
				shuf->prev->next = i;
			else
				*deck = i;

			shuf->prev = i;
			shuf = i->prev;
		}
	}
}
