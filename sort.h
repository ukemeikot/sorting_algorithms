#ifndef SORT_H
#define SORT_H
#include <stdlib.h>
#include <stdio.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void el_swap(int *array, size_t a, size_t b);
void insertion_sort_list(listint_t **list);
void list_swap(listint_t **head, listint_t *prev_node, listint_t *cur_node);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int split_arr(int *array, int left, int right, size_t size);
void sort(int *array, int start, int end, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_function(int *array, int *left, int *r, size_t size);
void merge_sort(int *array, size_t size);
#endif
