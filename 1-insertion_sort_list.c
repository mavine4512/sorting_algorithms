#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly_linked list.
 * @h: A pointer to head of the doubly linked list
 * @n1: The first node to swap to
 * @n2: The second node to swap to
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	n2->next != NULL ? n2->next->prev = *n1 : NULL;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	(*n1)->prev != NULL ? (*n1)->prev->next = n2 : (*h = n2);
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list of ints
 *                     using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of ints
 *
 * Description: Print the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		for (; insert != NULL && iter->n < insert->n; insert = iter->prev)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
