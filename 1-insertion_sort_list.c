#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: doubly linked list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *j, *k, *tmp;

	if (!list || !*list || !(*list)->next)
		return;
	j = (*list)->next;
	while (j)
	{
		k = j;
		j = j->next;
		while (k && k->prev && k->prev->n > k->n)
		{
			tmp = k->prev;
			tmp->next = k->next;
			if (k->next)
				k->next->prev = tmp;
			k->next = tmp;
			k->prev = tmp->prev;
			if (tmp->prev)
				tmp->prev->next = k;
			else
				*list = k;
			tmp->prev = k;
			print_list(*list);
		}
	}
}
