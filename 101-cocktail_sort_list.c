#include "sort.h"

/**
 * swap - swaps nodes
 * @list: list of integers
 * @f: first node to swap
 * @s: second node to swap
 */

void swap(listint_t **list, listint_t *f, listint_t *s)
{
	if (!(f->prev))
	{
		f->next = s->next;
		if (s->next)
			s->next->prev = f;
		s->next = f;
		s->prev = NULL;
		f->prev = s;
		*list = s;
	}
	else
	{
		s->prev->next = s->next;
		if (s->next)
			s->next->prev = s->prev;
		f->prev->next = s;
		s->prev = f->prev;
		f->prev = s;
		s->next = f;
	}
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: doubly linked list to sort
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *node, *nextnode;
	int swapped;

	if (list == NULL || !(*list) || (*list)->next == NULL)
		return;

	node = (*list);
	do {
		swapped = 0;
		while (node->next)
		{
			nextnode = node->next;
			if (nextnode && node->n > nextnode->n)
			{
				swap(list, node, nextnode);
				swapped = 1;
				print_list((*list));
			}
			else
				node = node->next;
		}
		node = node->prev;
		while (node->prev)
		{
			nextnode = node->prev;
			if (nextnode && node->n < nextnode->n)
			{
				swap(list, nextnode, node);
				swapped = 1;
				print_list((*list));
			}
			else
				node = node->prev;
		}
		node = node->next;
	} while (swapped);
}
