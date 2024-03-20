//Implement push & pop algorithm on circular queue.
//CODE:-

#include<stdio.h>
#define max 5
void push(int []);
void pop(int []);
void display(int []);
int f = -1, r = -1;
void main()
{
	int S[max],choice;
	do
	{
	printf("\nEnter Your Choice :");
	printf("\n(1) Push\n(2) Pop\n(3) Display\n(4) Exit\nEnter Choice From given above :");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1 : push(S);
		         break;
		case 2 : pop(S);
		         break;
		case 3 : display(S);
		         break;
		default: exit(0);
	}
  }while(choice>0&&choice<4);
}
void push(int s[])
{
	int x;
	if((r==max-1 && f==0) || (r==f-1))
	{
		printf("Queue is Overflow!!!.\n");
	}
	else
	{
		if(f==-1 && r==-1)
		{
			f++;
			r++;
		}
		else if(r==max-1 && f!=0)
		{
			r = 0;
		}
		else
		{
			r++;
		}
		printf("\nEnter Value to Be Pushed :");
		scanf("%d",&x);
		s[r] = x;
	}
}
void pop(int s[])
{
	if(f==-1)
	{
		printf("\nQueue is Underflow!!!");
	}
	else
	{
		printf("%d is Popped.",s[f]);
		if(f==r)
		{
			f = -1;
			r = -1;
		}
		else if(f == max-1)
		{
			f = 0;
		}
		else
		{
			f++;
		}
	}
}
void display(int s[])
{
	int i;
	if(f < r)
	{
		for(i=f;i<=r;i++)
		{
			printf("\nS[%d] = %d",i,s[i]);
		}
	}
	else
	{
		for(i=f;i<max;i++)
		{
			printf("\nS[%d] = %d",i,s[i]);
		}
		for(i=0;i<=r;i++)
		{
			printf("\nS[%d] = %d",i,s[i]);
		}
	}
	printf("\n");
}
