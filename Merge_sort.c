#include<stdio.h>
#include<conio.h>
void merge_sort(int[],int[],int,int);
void main()
{
	int a1[10],a2[10],n1,n2,i,j;
	printf("\nEnter Size of First Array :");
	scanf("%d",&n1);
	for(i=0;i<n1;i++)
	{
		printf("\nEnter %d Element :",i);
		scanf("%d",&a1[i]);
	}
	printf("\nEnter Size of Second Array :");
	scanf("%d",&n2);
	for(i=0;i<n2;i++)
	{
		printf("\nEnter %d Element :",i);
		scanf("%d",&a2[i]);
	}
	merge_sort(a1,a2,n1,n2);
	getch();
}
void merge_sort(int a1[],int a2[],int n1,int n2)
{
	int a3[20],i=0,j=0,k=0,size=n1+n2;
	while(k<size)
	{
		if(a1[i] < a2[j])
		{
			a3[k] = a1[i];
			k++;
			i++;
		}
		else if(a1[i] > a2[j])
		{
			a3[k] = a2[j];
			k++;
			j++;
		}
		else
		{
			a3[k] = a1[i];
			k++;
			i++;
			j++;
			size--;
		}
	}
	while(i < n1)
	{
		a3[k] = a1[i];
		k++;
		i++;
	}
	while(j < n2)
	{
		a3[k] = a2[j];
		k++;
		j++;
	}
	printf("\nAfter Sorting: ");
	for(i=0;i<k;i++)
	{
		printf("/t%d",a3[i]);
	}
}

