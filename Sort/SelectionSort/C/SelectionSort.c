#include <stdio.h>

void SelectionSort(int*, int);

int main()
{
	int elements[10];
	int size = 10;
	int i;
	
	printf("Enter 10 integer values: ");
	for(i = 0; i < size; ++i)
	{
		scanf("%d", &elements[i]);
	}
	
	SelectionSort(elements, size);
	
	printf("Sorted Elemets: ");
	for(i = 0; i < size; ++i)
	{
		printf("%d\t", elements[i]);
	}
	printf("\n");
	return 0;
}

/* Function which sort given elements by using Selection Sort algorithms */

void SelectionSort(int* elements, int size)
{
	int temp, i, j, min_idx;
	
	/* Loop to traverse through entire elements */
	for(i = 0; i < size; ++i)
	{
	    min_idx = i;
		/* Loop to find the index of minimum value in the rest of the array */
		for(j = i+1; j < size; ++j)
		{
			/* Compare elemets and find mimum index value */
			if(elements[j] < elements[min_idx])
			{
			    min_idx = j;
			}
		}
		
		//Swapping the current value with minimum index value.
		temp = elements[i];
		elements[i] = elements[min_idx];
		elements[min_idx] = temp;
	}
}
