#include "sort.h"

/**
  *selection_sort - sorts arrays using selection sort
  *@array: the array to be sorted
  *@size: the size of the aray
  */

void selection_sort(int *array, size_t size)
{
	unsigned int a, b;

	if (size < 2)
		return;

	for (a = 0; a < size; a++)
	{
		unsigned int x = a;
		int temp = array[a];

		for (b = a + 1; b < size; b++)
		{
			if (array[b] < temp)
				temp = array[b], x = b;
		}
		if (x != a)
		{
			array[x] = array[a];
			array[a] = temp;
			print_array(array, size);
		}
	}
}
