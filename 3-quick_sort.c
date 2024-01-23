#include "sort.h"
/**
  * quick_sort - quicksort algorithm
  * @array: array to be sorted
  * @size: size of array
  */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sort(array, 0, size - 1, size);
}

/**
  * sort - recursive sorting algorithm
  * @array: array
  * @start: leftmost index
  * @end: rightmost index
  * @size: full size of array
  */
void sort(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start < end)
	{
		pivot = split_arr(array, start, end, size);
		sort(array, start, pivot - 1, size);
		sort(array, pivot + 1, end, size);
	}
}

/**
  * split_arr - split array
  * @array: array
  * @left: leftmost index
  * @right: rightmost index
  * @size: full array size
  * Return: pivot index
  */
int split_arr(int *array, int left, int right, size_t size)
{
	int a, b, pivot, tmp;

	pivot = array[right];
	a = left;

	for (b = left; b < right; b++)
	{
		if (array[b] < pivot)
		{
			if (a != b)
			{
				tmp = array[b];
				array[b] = array[a];
				array[a] = tmp;
				print_array(array, size);
			}
			a++;
		}
	}
	if (array[a] != array[right])
	{
		tmp = array[a];
		array[a] = array[right];
		array[right] = tmp;
		print_array(array, size);
	}

	return (a);
}
