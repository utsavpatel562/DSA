#include<stdio.h>
int fibo(int);
void main()
{
    int n,i=0,c;
    printf("\nEnter the number :");
    scanf("%d",&n);
    printf("Fibonacci series terms are : \n");

    for(c=1;c<=n;c++)
    {
       printf("%d\n",fibo(i));
       i++;
    }
}
    int fibo(int n)
    {
    if(n==0 || n==1)
    return n;
    else
    return (fibo(n-1) + fibo(n-2));
    }
