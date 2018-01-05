#include <stdio.h>

void BubbleSort(int*, int);

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
	
	BubbleSort(elements, size);
	
	printf("Sorted Elemets: ");
	for(i = 0; i < size; ++i)
	{
		printf("%d\t", elements[i]);
	}
	printf("\n");
	return 0;
}

/* Function which sort given elements by using Bubble Sort algorithms */

void BubbleSort(int* elements, int size)
{
	int temp, i, j;
	
	/* Loop to traverse through entire elements */
	for(i = 0; i < size; ++i)
	{
		/* Loop to compare adjacent elements and swap if neccessary */
		for(j = 0; j < size - i - 1; ++j)
		{
			/* Compare adjacent elements, swap them if not in ascending order */
			if(elements[j] > elements[j+1])
			{
				temp = elements[j];
				elements[j] = elements[j+1];
				elements[j+1] = temp;
			}
		}
	}
}
