#include "sort.h"
/**
 * merge_function - merge_functions left and r arrays into original array
 * @array: pointer to array
 * @size: size of the array
 * @left: pointer to left_array array
 * @r: pointer to right_array array
 **/
void merge_function(int *array, int *left, int *r, size_t size)
{
	int a = 0, j = 0, k = 0;
	int size_l, size_r;

	size_l = size / 2;
	size_r = size - size_l;
	printf("Merging...\n");
	printf("[left_array]: ");
	print_array(left, size_l);
	printf("[right_array]: ");
	print_array(r, size_r);

	while (a < size_l && j < size_r)
	{
		if (left[a] < r[j])
			array[k++] = left[a++];
		else
			array[k++] = r[j++];
	}

	while (a < size_l)
		array[k++] = left[a++];

	while (j < size_r)
		array[k++] = r[j++];
	printf("[Done]: ");
	print_array(array, size);
}
/**
 * merge_function_sort - sorts an array of integers in ascending order using
 * the merge_function sort algorithm
 * @array: pointer to array
 * @size: size of the array
 **/
void merge_function_sort(int *array, size_t size)
{
	size_t middle = 0, a;
	int left_array[1000];
	int right_array[1000];

	if (!array)
		return;

	if (size < 2)
		return;

	middle = size / 2;
	/*left_array = (int*)malloc(sizeof(int) * middle);*/
	/*right_array = (int*)malloc(sizeof(int) * (size - middle));*/

	for (a = 0; a < middle; a++)
		left_array[a] = array[a];

	for (a = middle; a < size; a++)
		right_array[a - middle] = array[a];

	merge_function_sort(left_array, middle);
	merge_function_sort(right_array, size - middle);
	merge_function(array, left_array, right_array, size);
}

