#include "sort.h"
/**
  *insertion_sort_list - this function sorts list using insertion sort
  *@list: the list to be sorted
  *Return: nothing as it is a void function
  */
void insertion_sort_list(listint_t **list)
{
	listint_t *c_node, *first_node;
	int check_swap;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	c_node = (*list)->next;
	first_node = *list;
	while (c_node != NULL)
	{
		check_swap = 0;
		while (c_node != first_node && c_node->n < c_node->prev->n)
		{
			list_swap(list, c_node->prev, c_node);
			print_list(*list);
			first_node = *list;
			check_swap = 1;
		}
		if (check_swap == 0)
			c_node = c_node->next;
	}
}

/**
  *list_swap - swaps the nodes in a doubly linked linked list
  *@head: the list
  *@prev_node: the nde to be swapped
  *@cur_node: the node to be swapped
  *Return: nothing
  */
void list_swap(listint_t **head, listint_t *prev_node, listint_t *cur_node)
{
	listint_t *prev_n_prev;

	prev_n_prev = prev_node->prev;
	prev_node->next = cur_node->next;
	prev_node->prev = cur_node;
	if (cur_node->next != NULL)
		cur_node->next->prev = prev_node;
	cur_node->next = prev_node;
	cur_node->prev = prev_n_prev;
	if (prev_node == *head)
		*head = cur_node;
	else
		prev_n_prev->next = cur_node;
}
