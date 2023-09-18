#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a doubly linked list
 * @list: double pointer to head node
 * @node1: pointer to the first node
 * @node2: pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion Sort algorithm.
 * @list: double pointer to head node of list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	for (current = (*list)->next; current; current = temp)
	{
		temp = current->next;
		while (current->prev && current->prev->n > current->n)
		{
			swap_nodes(list, current->prev, current);
			print_list((const listint_t *)*list);
		}
	}
}
