// This program is of Selection Sort
//CODE:-
#include<stdio.h>
#include<conio.h>
void Selection_sort(int[],int);
void main()
{
	int i,a[50],N;
	printf("Enter Size of List :");
	scanf("%d",&N);
	printf("\nEnter the Numbers :\n");
	
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	Selection_sort(a,N);
	getch();
}
void Selection_sort(int array[],int N)
{
	int i,j,min,temp;
	for(i=0;i<N;i++)
	{
		min = i;
		for(j=i+1;j<N;j++)
		{
			if(array[min] > array[j])
			{
				min = j;
			}
		}
		if(min!=j)
		{
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;
		}
	}
	printf("\nSorted Array is Given Below:");
	for(i=0;i<N;i++)
	{
		printf("\n%d",array[i]);
	}
}
