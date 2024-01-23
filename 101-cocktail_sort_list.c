#include "sort.h"
/**
 * cocktail_sort_list - sorts a list using the cocktail sort algorithm
 * @list: list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head;
	int flag = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		for (head = *list; head->next != NULL; head = head->next)
		{
			if (head->n > head->next->n)
			{
				list_swap(list, head, head->next);
				print_list(*list);
				flag = 1;
				head = head->prev;
			}
		}
		if (flag == 0)
			break;
		flag = 0;
		for (; head->prev != NULL; head = head->prev)
		{
			if (head->n < head->prev->n)
			{
				list_swap(list, head->prev, head);
				print_list(*list);
				flag = 1;
				head = head->next;
			}
		}
	} while (flag == 1);
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
