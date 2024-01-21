#include "sort.h"

/**
  *bubble_sort - this uses the porpular bubble sort technique for sorting.
  *@array: the array to be sorted
  *@size: the size of the array
  *Return: nothing as it is a void function
  */
void bubble_sort(int *array, size_t size)
{
	int is_sorted;
	size_t a, b;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	for (a = 0; a <= size - 1; a++)
	{
		is_sorted = 0;
		for (b = 0; b < size - a - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				el_swap(array, b, b + 1);
				print_array(array, size);
				is_sorted = 1;
			}
		}
		if (is_sorted == 0)
			break;
	}
}

/**
*el_swap - helps to swap elemets in an array
*@array: the array to be worked on
*@a: the first index
*@b: the second index
*Return: nothing
*/

void el_swap(int *array, size_t a, size_t b)
{
	int tmp;

	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}
