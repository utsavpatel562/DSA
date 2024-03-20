//This Program is Bubble Sort//
//Code:~

#include<stdio.h>
#include<conio.h>
void Bubble_sort(int[],int);
void main()
{
   int i,a[50],N;
   printf("Enter the size of List :");
   scanf("%d",&N);
   printf("\nEnter the Numbers\n");
   
   for(i=0;i<N;i++)
   {
       scanf("%d",&a[i]);
   }
   Bubble_sort(a,N);
   getch();
}
void Bubble_sort(int array[],int N)
{
   int i,j,temp;
   for(i=1;i<N;i++)
   {
       for(j=0;j<N-i;j++)
	   {
		   if(array[j]>array[j+1])
		   {
			   temp = array[j];
			   array[j] = array[j+1];
			   array[j+1] = temp;
		   }
	   }
   }
   printf("\nSorted Array is Given Below:");
   for(i=0;i<N;i++)
   {
	   printf("\n%d",array[i]);
   }	   
}