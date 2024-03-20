//Implement factorial & Fibonacci Series code using recursion function//

#include<stdio.h>
int facto(int);
void main()
{
   int n,ans;
   printf("\nEnter the number for Factorial :");
   scanf("%d",&n);
   
   ans = facto(n);
   
   printf("%d",ans);
}
   int facto(int n)
{
   if(n==1)
   return 1;
   else
   return (facto(n-1)*n);
}