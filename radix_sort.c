// This program is of Radix Sort //
// CODE:-
#include<stdio.h>
#include<conio.h>
void radixsort(int[],int);
void countSort(int[],int,int);
int main()
{
	int i,arr[30],N;
	printf("Enter size of List :");
	scanf("%d",&N);
	printf("\nEnter Your Number :\n");
	for(i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
	}
	radixsort(arr,N);
	for(i=0;i<N;i++)
		printf("\n%d",arr[i]);
	return 0;
}
void radixsort(int arr[],int n)
{
	int max,i,exp;
	max = arr[0];
	for(i=1;i<n;i++)
	{
		if(arr[i] > max)
			max = arr[i];
	}
	for(exp = 1; max / exp > 0; exp *= 10)
		countSort(arr,n,exp);
}
void countSort(int arr[],int n,int exp)
{
	int output[n];
	int i,count[10] = { 0 };
	for(i=0;i<n;i++)
		count[(arr[i] / exp) % 10]++;
	
	for(i=1;i<10;i++)
		count[i] += count[i - 1];
    for(i = n - 1; i >= 0;i--)
    {
		output[count[(arr[i] / exp)% 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
    for(i=0;i<n;i++)
        arr[i] = output[i];		
}