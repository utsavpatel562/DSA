//To Implement Insertion Sort 
//CODE:~

#include<stdio.h>
#include<conio.h>
void Insertion_sort(int[],int);
void main()
{
	int i,a[50],N;
	printf("\nEnter the Size of List =");
	scanf("%d",&N);
	printf("\nEnter Numbers:\n");
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	Insertion_sort(a,N);
	printf("\nYour Sorted List:\n");
	for(i=0;i<N;i++)
	{
		printf("%d\n",a[i]);
	}
	getch();
}
void Insertion_sort(int array[],int N)
{
	int i,j,key;
	for(i=1;i<=N-1;i++)
	{
		key=array[i];
		j=i;
		while(j>0 && array[j-1]>key)
		{
			array[j]=array[j-1];
			j--;
		}
		array[j]=key;
	}
}