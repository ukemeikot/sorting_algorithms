#include "sort.h"
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
/**
  *selection_sort - sorts arrays using selection sort
  *@array: the array to be sorted
  *@size: the size of the aray
  */
void selection_sort(int *array, size_t size)
{
	size_t min, a, b;

	if (size < 2)
		return;
	for (a = 0; a < size - 1; a++)
	{
		min = a;
		for (b = a + 1; b < size; b++)
		{
			if (array[b] < array[min])
				min = b;
		}
		if (min != a)
		{
			el_swap(array, a, min);
			print_array(array, size);
		}
	}
}

