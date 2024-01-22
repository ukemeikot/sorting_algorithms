#include "sort.h"

/**
  *selection_sort - sorts arrays using selection sort
  *@array: the array to be sorted
  *@size: the size of the aray
  */
void selection_sort(int *array, size_t size)
{
	size_t min, a, b, tmp;

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
			tmp = array[min];
			array[min] = array[a];
			array[a] = tmp;
			print_array(array, size);
		}
	}
}

